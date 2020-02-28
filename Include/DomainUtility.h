#ifndef _DOMAIN_UTILITY_H__
#define _DOMAIN_UTILITY_H__

//--------------------------------------------------------------------------
#include <Lm.h>
#include <LmAccess.h>
#include "Ntsecapi.h"
#include <vector>
#include <map>
#include <atlbase.h>

#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS                  ((NTSTATUS)0x00000000L)
#define STATUS_MORE_ENTRIES             ((NTSTATUS)0x00000105L)
#define STATUS_NO_MORE_ENTRIES          ((NTSTATUS)0x8000001AL)
#endif

//--------------------------------------------------------------------------
typedef	NTSTATUS (CALLBACK* ENUMERATE_DOMAINSPROC)(LSA_HANDLE, PLSA_ENUMERATION_HANDLE, PVOID *, ULONG, PULONG);

typedef	NTSTATUS (CALLBACK* LSAOPENPOLICY)(PLSA_UNICODE_STRING SystemName,PLSA_OBJECT_ATTRIBUTES ObjectAttributes,
	ACCESS_MASK DesiredAccess, PLSA_HANDLE PolicyHandle);

typedef	ULONG (CALLBACK *LSANTSTATUSTOWINERROR)(NTSTATUS Status);

typedef	NTSTATUS (CALLBACK *LSAQUERYINFORMATIONPOLICY)(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass,
		PVOID *Buffer);

typedef NTSTATUS (CALLBACK *LSAFREEMEMORY)(PVOID Buffer);

typedef NET_API_STATUS (CALLBACK *NETGETDCNAME)(LPCWSTR servername, LPCWSTR domainname,  
		LPBYTE *bufptr);

typedef NET_API_STATUS (CALLBACK *NETAPIBUFFERFREE)(LPVOID Buffer);

typedef NET_API_STATUS (CALLBACK *NETQUERYDISPLAYINFORMATION)(LPCWSTR ServerName,            
		DWORD Level, DWORD Index, DWORD EntriesRequested, DWORD PreferredMaximumLength,  
		LPDWORD ReturnedEntryCount, PVOID *SortedBuffer);

typedef NET_API_STATUS (CALLBACK *NETGETDISPLAYINFORMATION)(LPCWSTR ServerName,            
		DWORD Level, LPCWSTR Prefix, LPDWORD Index);

typedef NET_API_STATUS (CALLBACK *NETLOCALGROUPENUM)(LPCWSTR servername,      
		DWORD level, LPBYTE *bufptr, DWORD prefmaxlen, LPDWORD entriesread, LPDWORD totalentries,    
		LPDWORD resumehandle);

typedef NET_API_STATUS (CALLBACK *NETLOCALGROUPGETMEMBERS)(LPCWSTR servername,    
		LPCWSTR localgroupname, DWORD level, LPBYTE *bufptr, DWORD prefmaxlen, LPDWORD entriesread,       
		LPDWORD totalentries, LPDWORD resumehandle);

typedef NET_API_STATUS (CALLBACK *NETGROUPGETUSERS)(LPCWSTR servername, LPCWSTR groupname,       
		DWORD level, LPBYTE *bufptr, DWORD prefmaxlen, LPDWORD entriesread, LPDWORD totalentries,
		LPDWORD ResumeHandle);

typedef NTSTATUS (CALLBACK *LSACLOSE)(LSA_HANDLE ObjectHandle);

//--------------------------------------------------------------------------
#define DOMAIN_INDEX_GROUP   3
#define DOMAIN_INDEX_USER    1

typedef enum eDomainUserType
{
	edutLocalDomainUser,
	edutGlobalDomainUser,
	edutGlobalDomainGroup,
	edutLocalDomainGroup
}
EDomainUserType;

//--------------------------------------------------------------------------
class CDomainUser
{
public:
	CDomainUser() : m_bIsSelected(false)
	{
	}

	CString m_strDomain;
	CString m_strUser;
	CString m_strComment;
	bool m_bIsSelected;
	bool m_bIsGroup;
	EDomainUserType m_eUserType;
};

//--------------------------------------------------------------------------
namespace DomainUtility
{
	static const int MAX_LEN = 1024;

	//--------------------------------------------------------------------------
	class CGroupMember
	{
	public:
		CString m_strDomain;
		CString m_strMember;
		bool m_bIsGroup;
	};

	//--------------------------------------------------------------------------
	static ULONG LsaNtStatusToWinErrorWrapper(HMODULE hLib, NTSTATUS Status)
	{
		LSANTSTATUSTOWINERROR lpfnLSANTSTATUSTOWINERROR = (LSANTSTATUSTOWINERROR)::GetProcAddress( hLib,  "LsaNtStatusToWinError");
		if (lpfnLSANTSTATUSTOWINERROR)
			return (*lpfnLSANTSTATUSTOWINERROR)(Status);

		return 0;
	}

	//	------------------------------------------------------------------------
	static NTSTATUS LsaCloseWrapper(HMODULE hLib, LSA_HANDLE ObjectHandle)
	{
		LSACLOSE lpfnLSACLOSE = (LSACLOSE)::GetProcAddress( hLib,  "LsaClose");
		if(lpfnLSACLOSE != NULL)
			return (*lpfnLSACLOSE)(ObjectHandle);

		return STATUS_SUCCESS;
	}

	//--------------------------------------------------------------------------
	static BOOL LsaOpenPolicyWrapper(HMODULE hLib, PLSA_UNICODE_STRING SystemName,
		PLSA_OBJECT_ATTRIBUTES ObjectAttributes, ACCESS_MASK DesiredAccess, PLSA_HANDLE PolicyHandle)
	{
		LSAOPENPOLICY lpfnLSAOPENPOLICY = (LSAOPENPOLICY)::GetProcAddress( hLib,  "LsaOpenPolicy");
		if(lpfnLSAOPENPOLICY != NULL)
		{
			NTSTATUS Status = (*lpfnLSAOPENPOLICY)(SystemName, ObjectAttributes, DesiredAccess, PolicyHandle);

			if(Status != STATUS_SUCCESS)
			{
				SetLastError( LsaNtStatusToWinErrorWrapper(hLib, Status) );
				return FALSE;
			}
		}

		return TRUE;
	}

	//	------------------------------------------------------------------------
	static BOOL LsaQueryInformationPolicyWrapper(HMODULE hLib, LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass,
		PVOID *Buffer)
	{
		LSAQUERYINFORMATIONPOLICY lpfnLSAQUERYINFORMATIONPOLICY = (LSAQUERYINFORMATIONPOLICY)::GetProcAddress( hLib,  "LsaQueryInformationPolicy");
		if(lpfnLSAQUERYINFORMATIONPOLICY != NULL)
		{
			NTSTATUS Status = (*lpfnLSAQUERYINFORMATIONPOLICY)(PolicyHandle, InformationClass, Buffer);
			if(Status != STATUS_SUCCESS)
			{
				SetLastError( LsaNtStatusToWinErrorWrapper(hLib, Status) );
				return FALSE;
			}
		}

		return TRUE;
	}

	//	------------------------------------------------------------------------
	static NTSTATUS LsaFreeMemoryWrapper(HMODULE hLib, PVOID Buffer)
	{
		LSAFREEMEMORY lpfnLSAFREEMEMORY = (LSAFREEMEMORY)::GetProcAddress( hLib,  "LsaFreeMemory");
		if(lpfnLSAFREEMEMORY != NULL)
			return (*lpfnLSAFREEMEMORY)(Buffer);

		return STATUS_SUCCESS;
	}


	//	------------------------------------------------------------------------
	static BOOL NetGetDCNameWrapper(HMODULE hLib, LPCWSTR servername, LPCWSTR domainname,  
		LPBYTE *bufptr)
	{
		NETGETDCNAME lpfnNETGETDCNAME = (NETGETDCNAME)::GetProcAddress( hLib,  "NetGetDCName");
		if(lpfnNETGETDCNAME != NULL)
		{
			if (NERR_Success == (*lpfnNETGETDCNAME)(servername, domainname, bufptr))
				return TRUE;
		}

		return FALSE;
	}

	//	------------------------------------------------------------------------
	static NET_API_STATUS NetApiBufferFreeWrapper(HMODULE hLib, LPVOID Buffer)
	{
		NETAPIBUFFERFREE lpfnNETAPIBUFFERFREE = (NETAPIBUFFERFREE)::GetProcAddress( hLib,  "NetApiBufferFree");
		if(lpfnNETAPIBUFFERFREE != NULL)
			return (*lpfnNETAPIBUFFERFREE)(Buffer);

		return NERR_Success;
	}

	//	------------------------------------------------------------------------
	static NET_API_STATUS NetGetDisplayInformationIndexWrapper(HMODULE hLib, LPCWSTR ServerName,            
		DWORD Level, LPCWSTR Prefix, LPDWORD Index)
	{
		NETGETDISPLAYINFORMATION lpfnNETGETDISPLAYINFORMATION = (NETGETDISPLAYINFORMATION)::GetProcAddress( hLib,  "NetGetDisplayInformationIndex");
		if(lpfnNETGETDISPLAYINFORMATION != NULL)
			return (*lpfnNETGETDISPLAYINFORMATION)(ServerName, Level, Prefix, Index);

		return NERR_Success;
	}

	//	------------------------------------------------------------------------
	static NET_API_STATUS NetQueryDisplayInformationWrapper(HMODULE hLib, LPCWSTR ServerName,            
		DWORD Level, DWORD Index, DWORD EntriesRequested, DWORD PreferredMaximumLength,  
		LPDWORD ReturnedEntryCount, PVOID *SortedBuffer)
	{
		NETQUERYDISPLAYINFORMATION lpfnNETQUERYDISPLAYINFORMATION = (NETQUERYDISPLAYINFORMATION)::GetProcAddress( hLib,  "NetQueryDisplayInformation");
		if(lpfnNETQUERYDISPLAYINFORMATION != NULL)
			return (*lpfnNETQUERYDISPLAYINFORMATION)(ServerName, Level, Index, EntriesRequested, PreferredMaximumLength,  
				ReturnedEntryCount, SortedBuffer);

		return NERR_Success;
	}

	//	------------------------------------------------------------------------
	static NET_API_STATUS NetLocalGroupEnumWrapper(HMODULE hLib, LPCWSTR servername,      
		DWORD level, LPBYTE *bufptr, DWORD prefmaxlen, LPDWORD entriesread, LPDWORD totalentries,    
		LPDWORD resumehandle)
	{
		NETLOCALGROUPENUM lpfnNETLOCALGROUPENUM = (NETLOCALGROUPENUM)::GetProcAddress( hLib,  "NetLocalGroupEnum");
		if(lpfnNETLOCALGROUPENUM != NULL)
			return (*lpfnNETLOCALGROUPENUM)(servername, level, bufptr, prefmaxlen, entriesread, totalentries,    
				resumehandle);

		return NERR_Success;
	}

	//	------------------------------------------------------------------------
	static NET_API_STATUS NetLocalGroupGetMembersWrapper(HMODULE hLib, LPCWSTR servername,    
		LPCWSTR localgroupname, DWORD level, LPBYTE *bufptr, DWORD prefmaxlen, LPDWORD entriesread,       
		LPDWORD totalentries, LPDWORD resumehandle)
	{
		NETLOCALGROUPGETMEMBERS lpfnNETLOCALGROUPGETMEMBERS = (NETLOCALGROUPGETMEMBERS)::GetProcAddress( hLib,  "NetLocalGroupGetMembers");
		if(lpfnNETLOCALGROUPGETMEMBERS != NULL)
			return (*lpfnNETLOCALGROUPGETMEMBERS)(servername, localgroupname, level, bufptr, prefmaxlen, entriesread,       
					totalentries, resumehandle);

		return NERR_Success;
	}

	//	------------------------------------------------------------------------
	static NET_API_STATUS NetGroupGetUsersWrapper(HMODULE hLib, LPCWSTR servername, LPCWSTR groupname,       
		DWORD level, LPBYTE *bufptr, DWORD prefmaxlen, LPDWORD entriesread, LPDWORD totalentries,
		LPDWORD ResumeHandle)
	{
		NETGROUPGETUSERS lpfnNETGROUPGETUSERS = (NETGROUPGETUSERS)::GetProcAddress( hLib,  "NetGroupGetUsers");
		if(lpfnNETGROUPGETUSERS != NULL)
			return (*lpfnNETGROUPGETUSERS)(servername, groupname, level, bufptr,
					prefmaxlen, entriesread, totalentries, ResumeHandle);

		return NERR_Success;
	}

	//--------------------------------------------------------------------------
	// This function will get the domain name for the local machine
	//--------------------------------------------------------------------------
	static BOOL GetLocalDomain(CString& strLocalDomain)
	{
		LSA_HANDLE PolicyHandle = NULL;
		HMODULE hLib = NULL;
		BOOL bRetVal = FALSE;

		try
		{
			hLib = ::LoadLibrary(_T("Advapi32.DLL"));
			if(! hLib)
				return bRetVal;

			PLSA_UNICODE_STRING Server = NULL;

			LSA_OBJECT_ATTRIBUTES ObjectAttributes;
			ZeroMemory(&ObjectAttributes, sizeof(ObjectAttributes));

			if (! LsaOpenPolicyWrapper(hLib, Server, &ObjectAttributes, POLICY_VIEW_LOCAL_INFORMATION, &PolicyHandle))
				return bRetVal;

			PPOLICY_ACCOUNT_DOMAIN_INFO AccountDomain = NULL;
			if (! LsaQueryInformationPolicyWrapper(hLib, PolicyHandle, PolicyAccountDomainInformation, reinterpret_cast<void**>(&AccountDomain)))
				return bRetVal;

			if(AccountDomain != NULL)
			{
				PLSA_UNICODE_STRING UnicodeString = &AccountDomain->DomainName;

				strLocalDomain = UnicodeString->Buffer;

				bRetVal = TRUE;

				LsaFreeMemoryWrapper(hLib, AccountDomain);
			}
		}
		catch(...)
		{
		}

		if(PolicyHandle != INVALID_HANDLE_VALUE)
			LsaCloseWrapper(hLib, PolicyHandle);

		if(hLib)
			::FreeLibrary(hLib);

		return bRetVal;
	}

	//--------------------------------------------------------------------------
	// This function will get the domain name for the Primary machine
	//--------------------------------------------------------------------------
	static BOOL GetPrimaryDomain(CString& strPrimaryDomain)
	{
		LSA_HANDLE PolicyHandle = NULL;
		HMODULE hLib = NULL;
		BOOL bRetVal = FALSE;

		try
		{
			hLib = ::LoadLibrary(_T("Advapi32.DLL"));
			if(! hLib)
				return bRetVal;

			PLSA_UNICODE_STRING Server = NULL;

			LSA_OBJECT_ATTRIBUTES ObjectAttributes;
			ZeroMemory(&ObjectAttributes, sizeof(ObjectAttributes));

			if (! LsaOpenPolicyWrapper(hLib, Server, &ObjectAttributes, POLICY_VIEW_LOCAL_INFORMATION, &PolicyHandle))
				return bRetVal;

			PPOLICY_PRIMARY_DOMAIN_INFO PrimaryDomain = NULL;
			if (! LsaQueryInformationPolicyWrapper(hLib, PolicyHandle, PolicyPrimaryDomainInformation, reinterpret_cast<void**>(&PrimaryDomain)))
				return bRetVal;

			if(PrimaryDomain != NULL)
			{
				PLSA_UNICODE_STRING UnicodeString = &PrimaryDomain->Name;

				strPrimaryDomain = UnicodeString->Buffer;

				bRetVal = TRUE;

				LsaFreeMemoryWrapper(hLib, PrimaryDomain);
			}
		}
		catch(...)
		{
		}

		if(PolicyHandle != INVALID_HANDLE_VALUE)
			LsaCloseWrapper(hLib, PolicyHandle);

		if(hLib)
			::FreeLibrary(hLib);

		return bRetVal;
	}

	//--------------------------------------------------------------------------
	static BOOL EnumerateTrustedDomains(std::map<CString, CString>& mapTrustedDomains)
	{
		LSA_HANDLE PolicyHandle = NULL;
		HMODULE hLib = NULL;
		BOOL bRetVal = FALSE;

		try
		{
			hLib = ::LoadLibrary(_T("Advapi32.DLL"));
			if(! hLib)
				return bRetVal;

			PLSA_UNICODE_STRING Server = NULL;
			LSA_OBJECT_ATTRIBUTES ObjectAttributes;
			ZeroMemory(&ObjectAttributes, sizeof(ObjectAttributes));

			if (! LsaOpenPolicyWrapper(hLib, Server, &ObjectAttributes, POLICY_VIEW_LOCAL_INFORMATION, &PolicyHandle))
				return bRetVal;

			ENUMERATE_DOMAINSPROC lpfnEnumDomainsProc = (ENUMERATE_DOMAINSPROC)::GetProcAddress( hLib,  "LsaEnumerateTrustedDomainsEx");

			NTSTATUS Status = STATUS_SUCCESS;

			if(lpfnEnumDomainsProc != NULL)
			{
				LSA_ENUMERATION_HANDLE lsaEnumHandle = NULL;
				PTRUSTED_DOMAIN_INFORMATION_EX TrustInfo = NULL;
				ULONG ulReturned = 0;

				do
				{
					Status = (*lpfnEnumDomainsProc)(PolicyHandle, &lsaEnumHandle, reinterpret_cast<void**>(&TrustInfo), 32000, &ulReturned);

					if( (Status != STATUS_SUCCESS) && (Status != STATUS_MORE_ENTRIES) && (Status != STATUS_NO_MORE_ENTRIES) )
					{
						bRetVal = FALSE;
						SetLastError( LsaNtStatusToWinErrorWrapper(hLib, Status) );
						return bRetVal;
					}
					
					for(ULONG ulCounter = 0 ; ulCounter < ulReturned ; ulCounter++)
					{
						PLSA_UNICODE_STRING UnicodeString = &TrustInfo[ulCounter].Name;

						CString strTrustedDomainName = UnicodeString->Buffer;

						mapTrustedDomains[strTrustedDomainName] = strTrustedDomainName;
					}

					bRetVal = TRUE;

					if(TrustInfo != NULL)
						LsaFreeMemoryWrapper(hLib, TrustInfo);
				}
				while (Status != STATUS_NO_MORE_ENTRIES);
			}
			else
			{
				lpfnEnumDomainsProc = (ENUMERATE_DOMAINSPROC)::GetProcAddress( hLib,  "LsaEnumerateTrustedDomains" );

				if(lpfnEnumDomainsProc != NULL)
				{
					LSA_ENUMERATION_HANDLE lsaEnumHandle = NULL;
					PLSA_TRUST_INFORMATION TrustInfo = NULL;
					ULONG ulReturned = 0;

					do
					{
						Status = (*lpfnEnumDomainsProc)(PolicyHandle, &lsaEnumHandle, reinterpret_cast<void**>(&TrustInfo), 32000, &ulReturned);

						if( (Status != STATUS_SUCCESS) && (Status != STATUS_MORE_ENTRIES) && (Status != STATUS_NO_MORE_ENTRIES) )
						{
							bRetVal = FALSE;
							SetLastError( LsaNtStatusToWinErrorWrapper(hLib, Status) );
							return bRetVal;
						}

						for(ULONG ulCounter = 0 ; ulCounter < ulReturned ; ulCounter++)
						{
							PLSA_UNICODE_STRING UnicodeString = &TrustInfo[ulCounter].Name;

							CString strTrustedDomainName = UnicodeString->Buffer;

							mapTrustedDomains[strTrustedDomainName] = strTrustedDomainName;
						}

						bRetVal = TRUE;

						if(TrustInfo != NULL)
							LsaFreeMemoryWrapper(hLib, TrustInfo);
					}
					while (Status != STATUS_NO_MORE_ENTRIES);
				}
			}
		}
		catch(...)
		{
		}

		if(PolicyHandle != INVALID_HANDLE_VALUE)
			LsaCloseWrapper(hLib, PolicyHandle);

		if(hLib)
			::FreeLibrary(hLib);

		return bRetVal;
	}

	//--------------------------------------------------------------------------
	// Given the Domain Name this function return the Domain Controller
	//--------------------------------------------------------------------------
	static BOOL GetDomainServer(const CString& strDomain, CString& strServer)
	{
		ASSERT(strDomain.GetLength() != 0);

		BOOL bRetVal = FALSE;

		if(!strDomain.IsEmpty())
		{
			// Always check if the domain whose PDC is to be found is a Local domain or not
			// If not then go ahead and call ::NetGetDCName API. This API is very slow and takes
			// quite some time for local domains. For optimization I always check for local domain
			// and return right away
			CString strLocalDomain;
			BOOL bLocalDomain = DomainUtility::GetLocalDomain(strLocalDomain);

			if(strDomain.CompareNoCase(strLocalDomain) == 0 || strDomain.CompareNoCase(_T("BUILTIN")) == 0)
			{
				strServer = _T("");
				bRetVal = TRUE;
			}
			else
			{
				USES_CONVERSION;

				HMODULE hLib = LoadLibrary(_T("Netapi32.DLL"));
				if (! hLib)
					return bRetVal;

				// Get the Name of the Primary Domain Controller for a given domain
				LPWSTR lpszServerName = NULL;
#ifdef _UNICODE
				LPCWSTR lpwszDomain = strDomain;
#else
				LPCWSTR lpwszDomain = A2W(strDomain);
#endif
				if (NetGetDCNameWrapper(hLib, NULL, lpwszDomain, (LPBYTE*)&lpszServerName))
				{
					strServer = (LPCWSTR)lpszServerName;
					bRetVal = TRUE;
				}

				if(lpszServerName != NULL)
					NetApiBufferFreeWrapper(hLib, lpszServerName);

				if (hLib)
					::FreeLibrary(hLib);
			}
		}
		return bRetVal;
	}

	//--------------------------------------------------------------------------
	static BOOL GetTextualSid(PSID pSid, LPTSTR szTextualSid, LPDWORD dwBufferLen)
	{
	   // Test if SID passed in is valid.
	   if(!IsValidSid(pSid))
		  return FALSE;

	   // Obtain SidIdentifierAuthority.
	   PSID_IDENTIFIER_AUTHORITY psia = GetSidIdentifierAuthority(pSid);

	   // Obtain sidsubauthority count.
	   DWORD dwSubAuthorities = *GetSidSubAuthorityCount(pSid);

	   // Compute buffer length.
	   // S-SID_REVISION- + identifierauthority- + subauthorities- + NULL
	   DWORD dwSidSize = (15 + 12 + (12 * dwSubAuthorities) + 1) * sizeof(TCHAR);

	   // Check provided buffer length.
	   // If not large enough, indicate proper size and setlasterror
	   if (*dwBufferLen < dwSidSize) {

		 *dwBufferLen = dwSidSize;

		 SetLastError(ERROR_INSUFFICIENT_BUFFER);

		 return FALSE;
	   }

	   // Prepare S-SID_REVISION-.
	   DWORD dwSidRev = SID_REVISION;
	   dwSidSize = wsprintf(szTextualSid, _T("S-%lu-"), dwSidRev);

	   // Prepare SidIdentifierAuthority.
	   if ((psia->Value[0] != 0) || (psia->Value[1] != 0))
	   {
		  dwSidSize += wsprintf(szTextualSid + lstrlen(szTextualSid),
				_T("0x%02hx%02hx%02hx%02hx%02hx%02hx"),
				(USHORT) psia->Value[0],
				(USHORT) psia->Value[1],
				(USHORT) psia->Value[2],
				(USHORT) psia->Value[3],
				(USHORT) psia->Value[4],
				(USHORT) psia->Value[5]);

	   }
	   else
	   {
		  dwSidSize += wsprintf(szTextualSid + lstrlen(szTextualSid),
				_T("%lu"),
				(ULONG) (psia->Value[5]      ) +
				(ULONG) (psia->Value[4] <<  8) +
				(ULONG) (psia->Value[3] << 16) +
				(ULONG) (psia->Value[2] << 24));
	   }

	   // Loop through SidSubAuthorities.
	   for (DWORD dwCounter = 0; dwCounter < dwSubAuthorities; dwCounter++)
	   {
		  dwSidSize += wsprintf(szTextualSid + dwSidSize, TEXT("-%lu"),
				*GetSidSubAuthority(pSid, dwCounter));
	   }
	   return TRUE;
	}

	//--------------------------------------------------------------------------
	static PSID GetBinarySid(LPCTSTR szTextualSid)
	{
		PSID  pSid = 0;

		BYTE  nByteAuthorityCount = 0;
		DWORD dwSubAuthority[8] = {0, 0, 0, 0, 0, 0, 0, 0};

		SID_IDENTIFIER_AUTHORITY identAuthority;
		ZeroMemory(&identAuthority, sizeof(identAuthority));

		TCHAR buffer[MAX_LEN] = {0};
		lstrcpy(buffer, szTextualSid);

		// S-SID_REVISION- + identifierauthority- + subauthorities- + NULL

		// Skip S
		LPTSTR ptr = NULL;

		if (!(ptr = _tcschr(buffer, _T('-'))))
		{
			return pSid;
		}

		// Skip -
		ptr++;

		// Skip SID_REVISION
		if (!(ptr = _tcschr(ptr, _T('-'))))
		{
			return pSid;
		}

		// Skip -
		ptr++;

		// Skip identifierauthority

		LPTSTR ptr1 = NULL;
		if (!(ptr1 = _tcschr(ptr, _T('-'))))
		{
			return pSid;
		}
		*ptr1= 0;

		if ((*ptr == '0') && (*(ptr+1) == 'x'))
		{
			_stscanf(ptr, _T("0x%02hx%02hx%02hx%02hx%02hx%02hx"),
				&identAuthority.Value[0],
				&identAuthority.Value[1],
				&identAuthority.Value[2],
				&identAuthority.Value[3],
				&identAuthority.Value[4],
				&identAuthority.Value[5]);
		}
		else
		{
			DWORD value;

			_stscanf(ptr, _T("%lu"), &value);

			identAuthority.Value[5] = (BYTE)(value & 0x000000FF);
			identAuthority.Value[4] = (BYTE)((value & 0x0000FF00) >> 8);
			identAuthority.Value[3] = (BYTE)((value & 0x00FF0000) >> 16);
			identAuthority.Value[2] = (BYTE)((value & 0xFF000000) >> 24);
		}

		// Skip -
		*ptr1 = '-';
		ptr = ptr1;
		ptr1++;

		for (int i = 0; i < 8; i++)
		{
			// get subauthority
			if (!(ptr = _tcschr(ptr, '-')))
			{
				break;
			}
			*ptr=0;
			ptr++;
			nByteAuthorityCount++;
		}
#if _MSC_VER < 1400
		for (i = 0; i < nByteAuthorityCount; i++)
#else
		for (int i = 0; i < nByteAuthorityCount; i++)
#endif
		{
			// Get subauthority.
			_stscanf(ptr1, _T("%lu"), &dwSubAuthority[i]);
			ptr1 += lstrlen(ptr1) + 1;
		}

		if (!AllocateAndInitializeSid(&identAuthority,
			nByteAuthorityCount,
			dwSubAuthority[0],
			dwSubAuthority[1],
			dwSubAuthority[2],
			dwSubAuthority[3],
			dwSubAuthority[4],
			dwSubAuthority[5],
			dwSubAuthority[6],
			dwSubAuthority[7],
			&pSid))
		{
			pSid = 0;
		}

		return pSid;
	} 

	//--------------------------------------------------------------------------
	static BOOL GetUserSIDType(const CString& strUser, SID_NAME_USE& eUse)
	{
		TBYTE szUserSID[MAX_LEN] = {0};
		DWORD dwSIDSize = MAX_LEN;

		TCHAR szDomainName[MAX_LEN] = {0};
		DWORD dwDomainSize = MAX_LEN;

		return ::LookupAccountName(NULL, strUser, &szUserSID, &dwSIDSize, szDomainName, &dwDomainSize, &eUse);
	}

	//--------------------------------------------------------------------------
	static BOOL GetUserSIDType(PSID userSID, SID_NAME_USE& eUse)
	{
		TCHAR szAccountName[MAX_LEN] = {0};
		DWORD dwAccountSize = MAX_LEN;

		TCHAR szDomainName[MAX_LEN] = {0};
		DWORD dwDomainSize = MAX_LEN;

		return ::LookupAccountSid(NULL, userSID, szAccountName, &dwAccountSize, szDomainName, &dwDomainSize, &eUse);
	}

	//--------------------------------------------------------------------------
	static BOOL GetUserSidAndDomain(CString strUserName, CString& strUserSID, CString& strDomain)
	{
		BOOL bRetVal = TRUE;

		if(strUserName.IsEmpty())
		{
			DWORD dwSize = MAX_LEN;
			bRetVal = ::GetUserName(strUserName.GetBuffer(dwSize), &dwSize);
			strUserName.ReleaseBuffer();
		}

		if(bRetVal)
		{
			TBYTE userSID[MAX_LEN] = {0};
			DWORD dwSIDSize = MAX_LEN;

			DWORD dwDomainSize = MAX_LEN;

			SID_NAME_USE eUse;

			bRetVal = ::LookupAccountName(NULL, strUserName, &userSID, &dwSIDSize, strDomain.GetBuffer(dwDomainSize),
											&dwDomainSize, &eUse);

			strDomain.ReleaseBuffer();

			if(bRetVal)
			{
				dwSIDSize = MAX_LEN;

				bRetVal = DomainUtility::GetTextualSid(userSID, strUserSID.GetBuffer(MAX_LEN), &dwSIDSize);
				strUserSID.ReleaseBuffer();
			}
		}
		return bRetVal;
	}

	//--------------------------------------------------------------------------
	static BOOL GetUserAccountAndDomain(PSID userSid, CString& strAccountName, CString& strDomain)
	{
		BOOL bRetVal = FALSE;

		if(::IsValidSid(userSid))
		{
			DWORD dwAccountSize = MAX_LEN;
			DWORD dwDomainSize = MAX_LEN;
			SID_NAME_USE eUse;

			bRetVal = ::LookupAccountSid(NULL, userSid, strAccountName.GetBuffer(dwAccountSize), &dwAccountSize,
											strDomain.GetBuffer(dwDomainSize), &dwDomainSize, &eUse);

			strAccountName.ReleaseBuffer();
			strDomain.ReleaseBuffer();
		}
		return bRetVal;
	}

	//--------------------------------------------------------------------------
	static BOOL EnumerateDomains(std::map<CString, CString>& mapDomains)
	{
		ASSERT(mapDomains.size() == 0);

		BOOL bRetVal = FALSE;

		try
		{
			CString strLocalDomain;
			bRetVal = DomainUtility::GetLocalDomain(strLocalDomain);

			if(bRetVal && !strLocalDomain.IsEmpty())
				mapDomains[strLocalDomain] = strLocalDomain;

			CString strPrimaryDomain;
			bRetVal = DomainUtility::GetPrimaryDomain(strPrimaryDomain);

			if(bRetVal && !strLocalDomain.IsEmpty())
				mapDomains[strPrimaryDomain] = strPrimaryDomain;

			bRetVal = EnumerateTrustedDomains(mapDomains);
		}
		catch(...)
		{
		}
		return bRetVal;
	}

	//--------------------------------------------------------------------------
	static void GetDomainUserIndex(const CString& strDomain, const CString& strDomainServer, 
									 LPCWSTR Prefix, DWORD& dwUserIndex, DWORD dwType)
	{
		ASSERT(strDomain.GetLength() != 0);

		if(strDomain.IsEmpty())
			return;

		HMODULE hLib = LoadLibrary(_T("NetApi32.DLL"));
		if (! hLib)
			return;

		USES_CONVERSION;
#ifdef _UNICODE
		LPCWSTR lpszServerName = strDomainServer;
#else
		LPCWSTR lpszServerName = A2W(strDomainServer);
#endif

		NET_API_STATUS nStatus = NetGetDisplayInformationIndexWrapper(hLib, lpszServerName, dwType, Prefix, &dwUserIndex);
		if ( nStatus != ERROR_MORE_DATA && nStatus != ERROR_SUCCESS  && nStatus != ERROR_NO_MORE_ITEMS)
            ASSERT(0);

		if (hLib != NULL)
			::FreeLibrary(hLib);
	}

	//--------------------------------------------------------------------------
	static void GetDomainUsers(const CString& strDomain, const CString& strDomainServer, 
									DWORD& dwUserIndex, std::vector<CDomainUser>& vecDomainUsers)
	{
		ASSERT(strDomain.GetLength() != 0);

		if(strDomain.IsEmpty())
			return;

		HMODULE hLib = LoadLibrary(_T("NetApi32.DLL"));
		if (! hLib)
			return;

		DWORD dwEntriesRequested = 0;
		DWORD dwReturnedEntryCount = 0;
		void *pUserInfo = NULL;

		BOOL bIsLocalDomain = strDomainServer.IsEmpty();

		USES_CONVERSION;
#ifdef _UNICODE
		LPCWSTR lpszServerName = strDomainServer;
#else
		LPCWSTR lpszServerName = A2W(strDomainServer);
#endif

		NET_API_STATUS nStatus = NetQueryDisplayInformationWrapper(hLib, lpszServerName, 1, dwUserIndex, 100, MAX_PREFERRED_LENGTH,
												&dwReturnedEntryCount, &pUserInfo);

		if ( nStatus != ERROR_MORE_DATA && nStatus != ERROR_SUCCESS )
		{
			if(hLib != NULL)
				::FreeLibrary(hLib);

			return;
		}

		NET_DISPLAY_USER *pNetUserInfo = static_cast<NET_DISPLAY_USER*>(pUserInfo);

		CDomainUser oDomainUser;
		oDomainUser.m_strDomain = strDomain;
		oDomainUser.m_bIsGroup = false;
		oDomainUser.m_eUserType = bIsLocalDomain ? edutLocalDomainUser : edutGlobalDomainUser;

		CString strUserSID;
		CString strLocalDomain;

		for(DWORD nCount = 0; nCount < dwReturnedEntryCount; nCount++)
		{
			BOOL bAdd = TRUE;

			if ( dwReturnedEntryCount > 0 )
				dwUserIndex = ((NET_DISPLAY_USER *)pUserInfo)[dwReturnedEntryCount - 1].usri1_next_index;
			
			oDomainUser.m_strUser = pNetUserInfo->usri1_name;
			oDomainUser.m_strComment = pNetUserInfo->usri1_comment;

			if(oDomainUser.m_eUserType == edutLocalDomainUser)
			{
				bAdd = DomainUtility::GetUserSidAndDomain(oDomainUser.m_strUser, strUserSID, strLocalDomain);
				oDomainUser.m_strDomain = strLocalDomain;
			}

			if(bAdd)
				vecDomainUsers.push_back(oDomainUser);

			++pNetUserInfo;
		}

		if ( pUserInfo != NULL )
			NetApiBufferFreeWrapper(hLib, pUserInfo );

		pUserInfo = NULL;

		if (hLib != NULL)
			::FreeLibrary(hLib);
	}

	//--------------------------------------------------------------------------
	static void EnumerateDomainUsers(const CString& strDomain, std::vector<CDomainUser>& vecDomainUsers)
	{
		ASSERT(strDomain.GetLength() != 0);

		// Get the name of the Primary Domain Controller for a given domain. If the domain is
		// local then GetDomainServer returns the name of the local machine
		CString strServer;
		BOOL bDomainServerFound = DomainUtility::GetDomainServer(strDomain, strServer);

		// Once domain server is found go and get all the domain users
		if(bDomainServerFound)
		{
			DWORD dwIndex = 0;
			DWORD dwEntriesRequested = 0;
			DWORD dwReturnedEntryCount = 0;
			void *pUserInfo = NULL;

			HMODULE hLib = LoadLibrary(_T("NetApi32.DLL"));
			if (! hLib)
				return;

			USES_CONVERSION;

			NET_API_STATUS nStatus = NERR_Success;

			BOOL bIsLocalDomain = strServer.IsEmpty();

#ifdef _UNICODE
		LPCWSTR lpszServerName = strServer;
#else
		LPCWSTR lpszServerName = A2W(strServer);
#endif			

			do
			{
				nStatus = NetQueryDisplayInformationWrapper(hLib, lpszServerName, 1, dwIndex, 1000, MAX_PREFERRED_LENGTH,
														&dwReturnedEntryCount, &pUserInfo);
				if ( nStatus != ERROR_MORE_DATA && nStatus != ERROR_SUCCESS )
					break;

				NET_DISPLAY_USER *pNetUserInfo = static_cast<NET_DISPLAY_USER*>(pUserInfo);

				CDomainUser oDomainUser;
				oDomainUser.m_strDomain = strDomain;
				oDomainUser.m_bIsGroup = false;
				oDomainUser.m_eUserType = bIsLocalDomain ? edutLocalDomainUser : edutGlobalDomainUser;

				CString strUserSID;
				CString strLocalDomain;

				for(DWORD nCount = 0; nCount < dwReturnedEntryCount; nCount++)
				{
					BOOL bAdd = TRUE;

					if ( dwReturnedEntryCount > 0 )
						dwIndex = ((NET_DISPLAY_USER *)pUserInfo)[dwReturnedEntryCount - 1].usri1_next_index;
					
					oDomainUser.m_strUser = pNetUserInfo->usri1_name;
					oDomainUser.m_strComment = pNetUserInfo->usri1_comment;

					if(oDomainUser.m_eUserType == edutLocalDomainUser)
					{
						bAdd = DomainUtility::GetUserSidAndDomain(oDomainUser.m_strUser, strUserSID, strLocalDomain);
						oDomainUser.m_strDomain = strLocalDomain;
					}

					if(bAdd)
						vecDomainUsers.push_back(oDomainUser);

					++pNetUserInfo;
				}

				if ( pUserInfo != NULL )
					NetApiBufferFreeWrapper(hLib, pUserInfo );

				pUserInfo = NULL;

			}while ( nStatus == ERROR_MORE_DATA );

			if (hLib)
				::FreeLibrary(hLib);
		}
	}

	//--------------------------------------------------------------------------
	static void EnumerateLocalDomainGroups(const CString& strLocalDomain, std::vector<CDomainUser>& vecLocalDomainUsers)
	{
		ASSERT(strLocalDomain.GetLength() != 0);

		LPLOCALGROUP_INFO_1 pLocalGroupInfo = NULL;
		DWORD dwEntriesRead = 0;
		DWORD dwTotalEntries = 0;
		DWORD dwResumeHandle = 0;

		HMODULE hLib = LoadLibrary(_T("NetApi32.DLL"));
		if (! hLib)
			return;

		// This API will return all the local groups
		NET_API_STATUS nStatus = NetLocalGroupEnumWrapper(hLib, NULL, 1, (LPBYTE*)&pLocalGroupInfo, MAX_PREFERRED_LENGTH,
														&dwEntriesRead, &dwTotalEntries, &dwResumeHandle);

		if(nStatus == NERR_Success)
		{
			LPLOCALGROUP_INFO_1 pTempLocalGroupInfo = pLocalGroupInfo;

			if(pTempLocalGroupInfo != NULL)
			{	
                CDomainUser oDomainUser;
				oDomainUser.m_bIsGroup = true;
				oDomainUser.m_eUserType = edutLocalDomainGroup;

				CString strUserSID;
				CString strDomain;
				for (DWORD nCount = 0; nCount < dwEntriesRead; nCount++)
				{
					BOOL bAdd = TRUE;

					oDomainUser.m_strUser = pTempLocalGroupInfo->lgrpi1_name;

					bAdd = DomainUtility::GetUserSidAndDomain(oDomainUser.m_strUser, strUserSID, strDomain);
				    oDomainUser.m_strDomain = strDomain;

					oDomainUser.m_strComment = pTempLocalGroupInfo->lgrpi1_comment;

					if(bAdd)
						vecLocalDomainUsers.push_back(oDomainUser);

					++pTempLocalGroupInfo;
				}
			}

			if(pLocalGroupInfo != NULL)
				NetApiBufferFreeWrapper(hLib, pLocalGroupInfo);
		}

		if (hLib)
			::FreeLibrary(hLib);
	}

	//--------------------------------------------------------------------------
	static void GetGlobalDomainGroups(const CString& strDomain, const CString& strDomainServer,
										DWORD& dwGroupIndex, std::vector<CDomainUser>& vecDomainGroups)
	{
		ASSERT(strDomain.GetLength() != 0);

		if(strDomain.IsEmpty() || strDomainServer.IsEmpty())
			return;

		HMODULE hLib = LoadLibrary(_T("NetApi32.DLL"));
		if (! hLib)
			return;

		DWORD dwEntriesRequested = 0;
		DWORD dwReturnedEntryCount = 0;
		void *pGroupInfo = NULL;

		// Get the Name of the Primary Domain Controller for a given domain
		USES_CONVERSION;
#ifdef _UNICODE
		LPCWSTR lpszServerName = strDomainServer;
#else
		LPCWSTR lpszServerName = A2W(strDomainServer);
#endif

		// This API does not to return Local Groups if lpszServerName is NULL. This is a known issue
		// with this API
		NET_API_STATUS nStatus = NetQueryDisplayInformationWrapper(hLib, lpszServerName, 3, dwGroupIndex, 100, MAX_PREFERRED_LENGTH,
												&dwReturnedEntryCount, &pGroupInfo);

		if ( nStatus != ERROR_MORE_DATA && nStatus != ERROR_SUCCESS )
		{
			if(hLib != NULL)
				::FreeLibrary(hLib);

			return;
		}

		NET_DISPLAY_GROUP *pNetGroupInfo = static_cast<NET_DISPLAY_GROUP*>(pGroupInfo);

		CDomainUser oDomainUser;
		oDomainUser.m_strDomain = strDomain;
		oDomainUser.m_bIsGroup = true;
		oDomainUser.m_eUserType = edutGlobalDomainGroup;

		for(DWORD nCount = 0; nCount < dwReturnedEntryCount; nCount++)
		{
			if ( dwReturnedEntryCount > 0 )
				dwGroupIndex = ((NET_DISPLAY_GROUP *)pGroupInfo)[dwReturnedEntryCount - 1].grpi3_next_index;
			
			oDomainUser.m_strUser = pNetGroupInfo->grpi3_name;
			oDomainUser.m_strComment = pNetGroupInfo->grpi3_comment;

			vecDomainGroups.push_back(oDomainUser);

			++pNetGroupInfo;
		}

		if ( pGroupInfo != NULL )
			NetApiBufferFreeWrapper(hLib, pGroupInfo );

		pGroupInfo = NULL;

		if (hLib)
			::FreeLibrary(hLib);
	}

	//--------------------------------------------------------------------------
	static void EnumerateDomainGroups(const CString& strDomain, std::vector<CDomainUser>& vecDomainGroups)
	{
		ASSERT(strDomain.GetLength() != 0);

		// First check if the Domain is a local domain or not. We should always check this first
		// as NetGetDCName API is slow and will fail for local domain. So to improve performance
		// always check for local domain and return right away.
		CString strLocalDomain;
		BOOL bLocalDomain = DomainUtility::GetLocalDomain(strLocalDomain);

		if(bLocalDomain && (strDomain.CompareNoCase(strLocalDomain) == 0))
		{
			DomainUtility::EnumerateLocalDomainGroups(strLocalDomain, vecDomainGroups);
		}
		else
		{
			USES_CONVERSION;

			HMODULE hLib = LoadLibrary(_T("NetApi32.DLL"));
			if (! hLib)
				return;

			// Get the Name of the Primary Domain Controller for a given domain
			LPWSTR lpszServerName = NULL;

#ifdef _UNICODE
				LPCWSTR lpwszDomain = strDomain;
#else
				LPCWSTR lpwszDomain = A2W(strDomain);
#endif

			// If success then go ahead and get all the global groups for the given domain.
			if(NetGetDCNameWrapper(hLib, NULL, lpwszDomain, (LPBYTE*)&lpszServerName))
			{
				DWORD dwIndex = 0;
				DWORD dwEntriesRequested = 0;
				DWORD dwReturnedEntryCount = 0;
				void *pGroupInfo = NULL;
				NET_API_STATUS nStatus= NERR_Success;

				do
				{
					// This API does not to return Local Groups if lpszServerName is NULL. This is a known issue
					// with this API
					nStatus = NetQueryDisplayInformationWrapper(hLib, lpszServerName, 3, dwIndex, 1000, MAX_PREFERRED_LENGTH,
															&dwReturnedEntryCount, &pGroupInfo);

					if ( nStatus != ERROR_MORE_DATA && nStatus != ERROR_SUCCESS )
						break;

					NET_DISPLAY_GROUP *pNetGroupInfo = static_cast<NET_DISPLAY_GROUP*>(pGroupInfo);

					CDomainUser oDomainUser;
					oDomainUser.m_strDomain = strDomain;
					oDomainUser.m_bIsGroup = true;
					oDomainUser.m_eUserType = edutGlobalDomainGroup;

					for(DWORD nCount = 0; nCount < dwReturnedEntryCount; nCount++)
					{
						if ( dwReturnedEntryCount > 0 )
							dwIndex = ((NET_DISPLAY_GROUP *)pGroupInfo)[dwReturnedEntryCount - 1].grpi3_next_index;
						
						oDomainUser.m_strUser = pNetGroupInfo->grpi3_name;
						oDomainUser.m_strComment = pNetGroupInfo->grpi3_comment;

						vecDomainGroups.push_back(oDomainUser);

						++pNetGroupInfo;
					}

					if ( pGroupInfo != NULL )
						NetApiBufferFreeWrapper(hLib, pGroupInfo );

					pGroupInfo = NULL;

				}while ( nStatus == ERROR_MORE_DATA );
			}
			if (lpszServerName != NULL)
				NetApiBufferFreeWrapper(hLib, lpszServerName );

			if (hLib)
				::FreeLibrary(hLib);
		}
	}

	//--------------------------------------------------------------------------
	static void EnumerateDomainUsersAndGroups(const CString& strDomain, std::vector<CDomainUser>& vecDomainUsersAndGroups)
	{
		ASSERT(strDomain.GetLength() != 0);

		DomainUtility::EnumerateDomainGroups(strDomain, vecDomainUsersAndGroups);

		DomainUtility::EnumerateDomainUsers(strDomain, vecDomainUsersAndGroups);
	}

	//--------------------------------------------------------------------------
	static BOOL EnumerateLocalGroupMembers(const CString& strLoginName, std::vector<CGroupMember>& vecMembers)
	{
		ASSERT(strLoginName.GetLength() != 0);

		BOOL bRetVal = FALSE;

		HMODULE hLib = LoadLibrary(_T("NetApi32.DLL"));
		if (! hLib)
			return bRetVal;

		CString strFinalGroupName = strLoginName;
		int nPos = strLoginName.Find(_T("\\"));

		if(nPos != -1)
			strFinalGroupName = strLoginName.Mid(++nPos);

		LPLOCALGROUP_MEMBERS_INFO_1 pLocalGroup = NULL;

		DWORD dwEntriesRead = 0;
		DWORD dwTotalEntries = 0;
		DWORD dwResumeHandle = 0;

		// First argument for ::NetLocalGroupGetMembers API is NULL for Local Groups
		USES_CONVERSION;

#ifdef _UNICODE
		LPCWSTR lpwFinalGroupName = strFinalGroupName;
#else
		LPCWSTR lpwFinalGroupName = A2W(strFinalGroupName);
#endif

		NET_API_STATUS nStatus = NetLocalGroupGetMembersWrapper(hLib, NULL, lpwFinalGroupName, 1, (LPBYTE*)&pLocalGroup, MAX_PREFERRED_LENGTH,
																	&dwEntriesRead, &dwTotalEntries, &dwResumeHandle);

		if(nStatus == NERR_Success)
		{
			LPLOCALGROUP_MEMBERS_INFO_1 pTempLocalGroup = pLocalGroup;

			if(pTempLocalGroup != NULL)
			{
				for (DWORD nCount = 0; nCount < dwEntriesRead; nCount++)
				{
					if(!(pTempLocalGroup->lgrmi1_sidusage == SidTypeDeletedAccount
						|| pTempLocalGroup->lgrmi1_sidusage == SidTypeUnknown))
					{

						CGroupMember groupMember;
						DomainUtility::GetUserAccountAndDomain(pTempLocalGroup->lgrmi1_sid, groupMember.m_strMember, groupMember.m_strDomain);
						groupMember.m_bIsGroup = (pTempLocalGroup->lgrmi1_sidusage == SidTypeUser) ? false : true;

						vecMembers.push_back(groupMember);
					}

					++pTempLocalGroup;
				}
			}
			bRetVal = TRUE;
		}

		if(pLocalGroup != NULL)
			NetApiBufferFreeWrapper(hLib, pLocalGroup);

		if (hLib)
			::FreeLibrary(hLib);

		return bRetVal;
	}

	//--------------------------------------------------------------------------
	static BOOL EnumerateGlobalGroupMembers(const CString& strLoginName, std::vector<CGroupMember>& vecMembers)
	{
		ASSERT(strLoginName.GetLength() != 0);

		BOOL bRetVal = FALSE;

		HMODULE hLib = LoadLibrary(_T("NetApi32.DLL"));
		if (! hLib)
			return bRetVal;

		CString strSid;
		CString strDomain;

		// From the Group find the Domain and SID of the group
		BOOL bAccountFound = DomainUtility::GetUserSidAndDomain(strLoginName, strSid, strDomain);

		if(bAccountFound)
		{
			// Get the real groupName after removing the DomainName
			CString strFinalGroupName = strLoginName;
			int nPos = strLoginName.Find(_T("\\"));

			if(nPos != -1)
				strFinalGroupName = strLoginName.Mid(++nPos);

			LPGROUP_USERS_INFO_0 pGlobalGroup = NULL;

			DWORD dwEntriesRead = 0;
			DWORD dwTotalEntries = 0;
			DWORD dwResumeHandle = 0;

			// Now find the Primary Domain Controller for the given domain
			CString strServer;
			DomainUtility::GetDomainServer(strDomain, strServer);

			USES_CONVERSION;

#ifdef _UNICODE
			LPCWSTR lpwFinalGroupName = strFinalGroupName;
			LPCWSTR lpwServer= strServer;
#else			
			LPCWSTR lpwFinalGroupName = A2W(strFinalGroupName);
			LPCWSTR lpwServer = A2W(strServer);
#endif
			
			NET_API_STATUS nStatus = NetGroupGetUsersWrapper(hLib, lpwServer, lpwFinalGroupName, 0, (LPBYTE*)&pGlobalGroup, MAX_PREFERRED_LENGTH, &dwEntriesRead,
															&dwTotalEntries, &dwResumeHandle);

			if(nStatus == NERR_Success)
			{
				LPGROUP_USERS_INFO_0 pTempGlobalGroup = pGlobalGroup;

				if(pTempGlobalGroup != NULL)
				{
					// Enumerate for all the users found in the group
					CGroupMember groupMember;
					groupMember.m_strDomain = strDomain;
					groupMember.m_bIsGroup = false;

					for (DWORD i = 0; i < dwEntriesRead; i++)
					{
						groupMember.m_strMember = pTempGlobalGroup->grui0_name;

						vecMembers.push_back(groupMember);

						++pTempGlobalGroup;
					}
				}
				bRetVal = TRUE;
			}

			if(pGlobalGroup != NULL)
				NetApiBufferFreeWrapper(hLib, pGlobalGroup);
		}

		if (hLib)
			::FreeLibrary(hLib);

		return bRetVal;
	}

	//--------------------------------------------------------------------------
	static CString GetLoggedInUserName()
	{
		// Get the User Name
		CString strUserName;
		DWORD dwSize = 1024;

		::GetUserName(strUserName.GetBuffer(1024), &dwSize);
		strUserName.ReleaseBuffer();

		return strUserName;
	}

	//--------------------------------------------------------------------------
	static CString GetLoggedInUserSID()
	{
		CString strUserSID;

		HANDLE hToken = NULL;
		DWORD dwSize = 0;
		PTOKEN_USER ptiUser = NULL;

		if(!OpenThreadToken(GetCurrentThread(), TOKEN_QUERY, TRUE, &hToken))
		{
			if(!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
				goto Quit;
		}

		if(!GetTokenInformation(hToken, TokenUser, NULL, 0, &dwSize))
		{
			if(GetLastError() != ERROR_INSUFFICIENT_BUFFER)
				goto Quit;
		}

		ptiUser = (PTOKEN_USER)HeapAlloc(GetProcessHeap(), 0, dwSize);

		if(ptiUser != NULL)
		{
			if(GetTokenInformation(hToken, TokenUser, ptiUser, dwSize, &dwSize))
			{
				DWORD dwSize = 1024;
				DomainUtility::GetTextualSid(ptiUser->User.Sid, strUserSID.GetBuffer(1024), &dwSize);
				strUserSID.ReleaseBuffer();
			}
		}

		Quit:
		  // Free resources.
		  if (hToken != NULL)
			CloseHandle(hToken);

		  if (ptiUser != NULL)
			HeapFree(GetProcessHeap(), 0, ptiUser);

		return strUserSID;
	}

	//--------------------------------------------------------------------------
	static CString GetLoggedInUserDomain()
	{
		CString strDomainName;

		CString strUserSID = DomainUtility::GetLoggedInUserSID();

		if(!strUserSID.IsEmpty())
		{
			PSID userBinarySID = DomainUtility::GetBinarySid(strUserSID);

			if(userBinarySID != NULL)
			{
				CString strUserName;

				DomainUtility::GetUserAccountAndDomain(userBinarySID, strUserName, strDomainName);

				::FreeSid(userBinarySID);
			}
		}
		return strDomainName;
	}


    //--------------------------------------------------------------------------
	static bool UserGroupElementDuplicated(std::vector<CString>& vecGroups, CString& strElement)
    {
	    std::vector<CString>::iterator itBegin = vecGroups.begin();
	    std::vector<CString>::iterator itEnd = vecGroups.end();

	    while(itBegin != itEnd)
        {
            if (itBegin->Compare(strElement) == 0)
                return true;
            ++itBegin;
        }

        return false;
    }

	//--------------------------------------------------------------------------
	static void GetLoggedInUserGroups(std::vector<CString>& vecGroups)
	{
		HANDLE hToken = NULL;
		DWORD dwSize = 0;
		PTOKEN_GROUPS ptiGroups = NULL;

		if(!OpenThreadToken(GetCurrentThread(), TOKEN_QUERY, TRUE, &hToken))
		{
			if(!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
				goto Quit;
		}

		if(!GetTokenInformation(hToken, TokenGroups, NULL, 0, &dwSize))
		{
			if(GetLastError() != ERROR_INSUFFICIENT_BUFFER)
				goto Quit;
		}

		ptiGroups = (PTOKEN_GROUPS)HeapAlloc(GetProcessHeap(), 0, dwSize);

		if(ptiGroups != NULL)
		{
			if(GetTokenInformation(hToken, TokenGroups, ptiGroups, dwSize, &dwSize))
			{
				for(DWORD dwCount = 0; dwCount < ptiGroups->GroupCount; dwCount++)
				{
					CString strGroupName;
					CString strDomainName;

					DomainUtility::GetUserAccountAndDomain(ptiGroups->Groups[dwCount].Sid, strGroupName, strDomainName);

					if(!strDomainName.IsEmpty())
						strDomainName += _T("\\");

					strDomainName += strGroupName;

                    if (!strDomainName.IsEmpty() && !UserGroupElementDuplicated(vecGroups, strDomainName))
					    vecGroups.push_back(strDomainName);
				}
			}
		}

		Quit:
		// Free resources.
		if (hToken != NULL)
			CloseHandle(hToken);

		if (ptiGroups != NULL)
			HeapFree(GetProcessHeap(), 0, ptiGroups);
	}
};


#endif //_DOMAIN_UTILITY_H__