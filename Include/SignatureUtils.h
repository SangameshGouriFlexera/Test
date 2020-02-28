#pragma once

namespace ISSignatureUtils
{
	enum EnumCertificateDigestType {
		ecdtAutomatic,
		ecdtSha1,
		ecdtSha256
	};

	static bool IsStoreCertReference(const stringxi& sCertInfo)
	{
		return sCertInfo.startswith(L"*");
	}

	static EnumCertificateDigestType GetDigestType(const stringxi& sDigestType)
	{
		if(sDigestType == L"sha1")
			return ecdtSha1;
		else if(sDigestType == L"sha256" || sDigestType == L"sha2")
			return ecdtSha256;
		else
			return ecdtAutomatic;
	}

	static void ParseCertStoreInfo(const stringxi& sCertInfo, stringxi& sStore, stringxi& sLocation, stringxi& sSubject, stringxi& sEncThumbprint, EnumCertificateDigestType& eDigestType)
	{
		stringxi sValue(sCertInfo);

		if(sValue.startswith(L"*"))
		{
			//
			// Original Format:
			// *Store Name*Location (User/Machine):Cert Subject
			//
			// Updated format:
			// *Store Name*Local (User/Machine):<|Thumbprint><||><Cert Subject>?DigestType
			//
			// Where <|Thumbprint> prefixes a hex string of a cert thumbprint with |. Or, 
			// the old Cert Subject is still allowed. These are mutually exclusive.
			//
			// The tail of the subject can now include ?DigestType. Type can be 'auto',
			// 'sha1', or 'sha256'. If this is omitted, 'auto' is the default value, which
			// indicates that the existing behavior of picking the digest is based on the
			// certificate hash type.
			//

			//
			// Remove the first *, find the second one and copy the store name string.
			//
			sValue.erase(0, 1);

			stringxi::size_type nPos = sValue.find(L"*");
			if(nPos != stringxi::npos)
			{
				sStore = sValue.substr(0, nPos);
			}
			else
			{
				//
				// Default to MY if none specified since it's most likely to be the store
				// where a cert was imported to.
				//
				sStore = L"MY";
			}

			//
			// Find the : to get the location string.
			//
			stringxi::size_type nPosOriginal = ++nPos;
			nPos = sValue.find(L":");
			if(nPos != stringxi::npos)
			{
				sLocation = sValue.substr(nPosOriginal, nPos - nPosOriginal);
			}
			else
			{
				//
				// Default to current user location for the cert store since that is
				// the default from the certificate import wizard.
				//
				sLocation = L"User";
			}

			stringxi sTempSubject = sValue.substr(nPos + 1);
			stringxi::size_type nPosDigestType = sTempSubject.find(L"?");

			if(nPosDigestType != stringxi::npos)
			{
				stringxi sTempType = sTempSubject.substr(nPosDigestType + 1);

				eDigestType = GetDigestType(sTempType);
				sTempSubject = sTempSubject.substr(0, nPosDigestType);
			}
			else
			{
				eDigestType = ecdtAutomatic;
			}

			if(sTempSubject.startswith(L"|"))
			{
				sTempSubject.erase(0, 1);
				sEncThumbprint = sTempSubject;

				sSubject = L"";
			}
			else
			{
				sSubject = sTempSubject;

				sEncThumbprint = L"";
			}
		}
	}

	static bool ParseCertFileInfo(const stringxi& sCertFileInfo, stringxi& sFile, EnumCertificateDigestType& eDigestType)
	{
		if(IsStoreCertReference(sCertFileInfo))
			return false;

		//
		// New file format:
		// <File>?DigestType
		// 
		// See ParseCertStoreInfo for the values accepted for DigestType. As with the
		// cert store reference the type is optional and defaults to 'auto'.
		//

		stringxi::size_type nPos = sCertFileInfo.find(L"?");
		if(nPos != stringxi::npos)
		{
			stringxi sDigest = sCertFileInfo.substr(nPos + 1);

			eDigestType = GetDigestType(sDigest);
			sFile = sCertFileInfo.substr(0, nPos);
		}
		else
		{
			eDigestType = ecdtAutomatic;
			sFile = sCertFileInfo;
		}

		return true;
	}
};