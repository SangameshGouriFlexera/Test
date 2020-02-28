#pragma once

#include <tuple>

namespace is {
namespace Win10 {
enum class ReleaseName
{
	Threshold1,
	Threshold2,
	Redstone1,
	Msix,
};

enum class PlatformName
{
	x86,
	x64,
	ARM,
	ARM64,
};

typedef std::tuple<USHORT, USHORT, USHORT, USHORT> SdkVersionTuple;

inline SdkVersionTuple SdkVersion(USHORT major = 0, USHORT minor = 0, USHORT build = 0, USHORT revision = 0)
{
	static_assert(sizeof(SdkVersionTuple) == 8, "SdkVersionTuple has unexpected size");
	SdkVersionTuple version;
	std::get<0>(version) = major;
	std::get<1>(version) = minor;
	std::get<2>(version) = build;
	std::get<3>(version) = revision;
	return version;
}

// Convert dotted quad L"1.2.3.4" to USHORT SdkVersionTuple
inline SdkVersionTuple SdkVersion(LPCWSTR szVersion)
{
	SdkVersionTuple version;
	LPCWSTR pszToken = szVersion;
	LPWSTR pszDone = nullptr;
	DWORD dwToken = 0;
	for (int i = 0; i < 4; ++i)
	{
		dwToken = _tcstoul(pszToken, &pszDone, 10);
		if ((!pszDone || '.' == *pszDone || '\0' == *pszDone) && (dwToken || !GetLastError()) && dwToken <= 0xffff)
		{
			auto wVersion = static_cast<USHORT>(dwToken);
			switch (i)
			{
			case 0: std::get<0>(version) = wVersion; break;
			case 1: std::get<1>(version) = wVersion; break;
			case 2: std::get<2>(version) = wVersion; break;
			case 3: std::get<3>(version) = wVersion; break;
			}
			if (pszDone && '\0' != *pszDone)
				pszToken = pszDone + 1;
			else
				break;
		}
		else
		{
			std::get<0>(version) = std::get<1>(version) = std::get<2>(version) = std::get<3>(version) = 0;
			break;
		}
	}
	return version;
}

// Convert named version to SdkVersionTuple
inline SdkVersionTuple SdkVersion(ReleaseName sdk)
{
	switch (sdk)
	{
	case ReleaseName::Threshold1: return SdkVersion(10, 0, 10240, 0);
	case ReleaseName::Threshold2: return SdkVersion(10, 0, 10586, 0);
	case ReleaseName::Redstone1: return SdkVersion(10, 0, 14393, 0);
	case ReleaseName::Msix: return SdkVersion(10, 0, 17682, 0);
	}
	return SdkVersion();
}

// Convert OSVERSIONINFO to SdkVersionTuple
inline SdkVersionTuple SdkVersion(LPOSVERSIONINFO pOSVI)
{
	return SdkVersion(static_cast<USHORT>(pOSVI->dwMajorVersion), static_cast<USHORT>(pOSVI->dwMinorVersion), static_cast<USHORT>(pOSVI->dwBuildNumber), 0);
}

// Convert OSVERSIONINFOEX to SdkVersionTuple
inline SdkVersionTuple SdkVersion(LPOSVERSIONINFOEX pOSVI)
{
	return SdkVersion(static_cast<USHORT>(pOSVI->dwMajorVersion), static_cast<USHORT>(pOSVI->dwMinorVersion), static_cast<USHORT>(pOSVI->dwBuildNumber), 0);
}

class SdkFinder
{
public:
	SdkFinder()
		: m_lStatus(ERROR_SUCCESS)
	{
	}

	bool FindSDK(ReleaseName minimumSDK)
	{
		CRegKey regSdk;
		m_lStatus = regSdk.Open(HKEY_LOCAL_MACHINE, GetRegistryKey(minimumSDK), KEY_READ);
		if (ERROR_SUCCESS != m_lStatus)
			return false;

		ULONG ulBufferSize = MAX_PATH;
		m_lStatus = regSdk.QueryStringValue(GetVersionValueName(minimumSDK), m_sSdkProductVersion.get_buffer(ulBufferSize), &ulBufferSize);
		if (ERROR_SUCCESS != m_lStatus)
			return false;

		if (SdkVersion(m_sSdkProductVersion) < SdkVersion(minimumSDK))
		{
			m_lStatus = ERROR_FILE_NOT_FOUND;
			return false;
		}

		ulBufferSize = MAX_PATH * 2;
		m_lStatus = regSdk.QueryStringValue(GetPathValueName(minimumSDK), m_sSdkPath.get_buffer(ulBufferSize), &ulBufferSize);
		if (ERROR_SUCCESS != m_lStatus)
			return false;

		if (m_sSdkPath.empty() || -1 == ::GetFileAttributes(m_sSdkPath))
		{
			m_lStatus = ERROR_FILE_NOT_FOUND;
			return false;
		}

		return true;
	}

	stringxi GetBinPath(PlatformName platform = PlatformName::x86, ReleaseName sdk = ReleaseName::Redstone1)
	{
		stringxi sPath;
		if (ERROR_SUCCESS == m_lStatus)
		{
			sPath = m_sSdkPath ^ L"bin";

			if(ReleaseName::Msix == sdk)
				sPath = FindFrameworkDirWithProductVer(sPath);

			switch (platform)
			{
			case PlatformName::x86: sPath ^= L"x86\\"; break;
			case PlatformName::x64: sPath ^= L"x64\\"; break;
			case PlatformName::ARM: sPath ^= L"arm\\"; break;
			case PlatformName::ARM64: sPath ^= L"arm64\\"; break;
			default: sPath.clear(); break;
			}
			if (-1 == ::GetFileAttributes(sPath))
				sPath.clear();
		}
		return sPath;
	}

private:
	LPCWSTR GetRegistryKey(ReleaseName sdk) const
	{
		switch (sdk)
		{
		case ReleaseName::Threshold1:
		case ReleaseName::Threshold2:
		case ReleaseName::Redstone1:
		case ReleaseName::Msix:
			return L"Software\\Microsoft\\Microsoft SDKs\\Windows\\v10.0";
		}

		return L"";
	}

	LPCWSTR GetVersionValueName(ReleaseName sdk) const
	{
		switch (sdk)
		{
		case ReleaseName::Threshold1:
		case ReleaseName::Threshold2:
		case ReleaseName::Redstone1:
		case ReleaseName::Msix:
			return L"ProductVersion";
		}

		return L"";
	}

	LPCWSTR GetPathValueName(ReleaseName sdk) const
	{
		switch (sdk)
		{
		case ReleaseName::Threshold1:
		case ReleaseName::Threshold2:
		case ReleaseName::Redstone1:
		case ReleaseName::Msix:
			return L"InstallationFolder";
		}

		return L"";
	}

	stringxi FindFrameworkDirWithProductVer(const stringxi& sPath)
	{
		stringxi sFindMe = sPath ^ L"*.*";

		WIN32_FIND_DATA w32FD;
		HANDLE hFindFile = ::FindFirstFile(sFindMe, &w32FD);
		if (INVALID_HANDLE_VALUE != hFindFile)
		{
			do
			{
				stringxi sFileName = w32FD.cFileName;
				if ((w32FD.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
					sFileName != L"." && sFileName != L"..")
				{
					if (sFileName.startswith(m_sSdkProductVersion))
					{
						return (sPath ^ w32FD.cFileName);
					}
				}
			} while (::FindNextFile(hFindFile, &w32FD));

			::FindClose(hFindFile);
		}

		return sPath;
	}

	stringxi m_sSdkPath;
	stringxi m_sSdkProductVersion;
	LONG m_lStatus;
};
} // namespace Win10
} // namespace is
