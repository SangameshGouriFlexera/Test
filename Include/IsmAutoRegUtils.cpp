// IsmAutoRegUtils.cpp: implementation of the IsmAutoRegUtils Utility functions
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IsmAutoRegUtils.h"
#include "RegistryUtilities.h" //BeCommon

//////////////////////////////////////////////////////////////////////
// IsmAutoRegUtils implementation
//////////////////////////////////////////////////////////////////////
void IsmAutoRegUtils::GetRootValue(const stringx& bstrRegKeyPath, msidbRegistryRoot *eRootKey)
{
	stringx bstrParentKey(bstrRegKeyPath);
    int nPos = bstrParentKey.find_first_of(REGKEY_SEPARATOR);
	//If nPos == -1 then we will get the complete name itself.
	stringx bstrRootKeyName = bstrParentKey.substr(0, nPos);

	if (bstrRootKeyName == HKEY_CLASSES_ROOT_STRING)
		*eRootKey = msidbRegistryRootClassesRoot;
	else if (bstrRootKeyName == HKEY_CURRENT_USER_STRING)
		*eRootKey = msidbRegistryRootCurrentUser;
	else if (bstrRootKeyName == HKEY_LOCAL_MACHINE_STRING)
		*eRootKey = msidbRegistryRootLocalMachine;
	else if (bstrRootKeyName == HKEY_USERS_STRING)
		*eRootKey = msidbRegistryRootUsers;
	else if (bstrRootKeyName == HKEY_USER_SELECTABLE_STRING)
		*eRootKey = static_cast<msidbRegistryRoot>(-1);
	else
	{
		ATLASSERT(false);
	}
}

void IsmAutoRegUtils::GetRootString(msidbRegistryRoot eRoot, BSTR* bstrRootName)
{
    stringx bstrTemp;
    switch (eRoot)
    {
        case msidbRegistryRootClassesRoot:
            bstrTemp = HKEY_CLASSES_ROOT_STRING;
            break;
        case msidbRegistryRootCurrentUser:
            bstrTemp = HKEY_CURRENT_USER_STRING;
            break;
        case msidbRegistryRootLocalMachine:
            bstrTemp = HKEY_LOCAL_MACHINE_STRING;
            break;
        case msidbRegistryRootUsers:
            bstrTemp = HKEY_USERS_STRING;
            break;
        case -1:
            bstrTemp = HKEY_USER_SELECTABLE_STRING;
            break;
        default:
            ATLASSERT(false);
    }
    hrx hr = bstrTemp.copy_to(bstrRootName);
}

void IsmAutoRegUtils::GetSubKeyName(const stringx& bstrRegKeyPath, BSTR *bstrSubKeyName)
{
    int nPos = FindFirstBackSlash(bstrRegKeyPath);

	if (nPos != stringx::npos)
	{
		*bstrSubKeyName = (bstrRegKeyPath.substr(nPos + 1)).copy();
	}
	else
	{
        hrx hr = bstrRegKeyPath.copy_to(bstrSubKeyName);
	}
}

// populates lDepth with the number of backslashes in bstrRegKeyPath
void IsmAutoRegUtils::GetLeafKeyDepth(const stringx& bstrRegKeyPath, long *lDepth)
{
    int nPos = 0;
    long lLocDepth = 0;
    while ((nPos = FindFirstBackSlash(bstrRegKeyPath, nPos + 1)) && (nPos != stringx::npos))
    {
        lLocDepth++;
    }
    *lDepth = lLocDepth;
}

bool IsmAutoRegUtils::PathsAreEqualAtShortest(const stringx& bstrPath1, const stringx& bstrPath2)
{
    long lLenStr1 = bstrPath1.length();
    long lLenStr2 = bstrPath2.length();

    stringx bstrTmp;
    if (lLenStr1 > lLenStr2)
    {
        stringx bstrTmp = bstrPath1.substr(0, lLenStr2);
        if (bstrTmp == bstrPath2)
        {
            return true;
        }
    }
    else if (lLenStr2 > lLenStr1)
    {
        stringx bstrTmp = bstrPath2.substr(0, lLenStr1);
        if (bstrTmp == bstrPath1)
        {
            return true;
        }
    }
    return false;
}

void IsmAutoRegUtils::GetPathAtDepth(const stringx& bstrRegKeyPath, long lDepth, BSTR* bstrResult)
{
    hrx hr;
    int nPos = 0;
    while ((nPos = FindFirstBackSlash(bstrRegKeyPath, nPos + 1)) && (nPos != stringx::npos) && lDepth > 0)
    {
        lDepth--;
    }

    if (nPos != stringx::npos)
	{
        *bstrResult = bstrRegKeyPath.substr(0, nPos).copy();
	}
	else
	{
        hr = bstrRegKeyPath.copy_to(bstrResult);
	}
}

void IsmAutoRegUtils::GetLeafKeyAtDepth(const stringx& bstrRegKeyPath, long lDepth, BSTR* bstrResult)
{
    int nPosFirstSlash = 0; // first one we care about
    while ((nPosFirstSlash = FindFirstBackSlash(bstrRegKeyPath, nPosFirstSlash + 1)) && (nPosFirstSlash != stringx::npos) && lDepth > 1)
    {
        lDepth--;
    }

    if (nPosFirstSlash != stringx::npos)
	{
        int nPosSecondSlash = FindFirstBackSlash(bstrRegKeyPath, nPosFirstSlash + 1);

        if (nPosSecondSlash != stringx::npos)
    	{
            *bstrResult = bstrRegKeyPath.substr(nPosFirstSlash + 1, nPosSecondSlash - nPosFirstSlash - 1).copy();
        }
        else
        {
            *bstrResult = bstrRegKeyPath.substr(nPosFirstSlash + 1).copy();
        }
	}
	else
	{
        hrx hr = bstrRegKeyPath.copy_to(bstrResult);
	}
}

void IsmAutoRegUtils::GetSubPathAtDepth(const stringx& bstrRegKeyPath, long lDepth, BSTR* bstrResult)
{
    int nPosFirstSlash = stringx::npos;
    while (lDepth > 1 && (nPosFirstSlash = FindFirstBackSlash(bstrRegKeyPath, nPosFirstSlash + 1)) && (nPosFirstSlash != stringx::npos))
    {
        lDepth--;
    }

    if (nPosFirstSlash != stringx::npos)
	{
        *bstrResult = bstrRegKeyPath.substr(nPosFirstSlash + 1).copy();
	}
	else
	{
        hrx hr = bstrRegKeyPath.copy_to(bstrResult);
	}
}

// the incomming string doesn't have the root on it.
stringx IsmAutoRegUtils::UpdateKeyName(const stringx& bstrOrigRecordKey, const stringx& bstrNewKeyName, long lDepth)
{
    stringx bstrResult;
    int nPosFirstSlash = 0; // first one we care about

    // if depth is n, get n-1 and n backslashes, replace everything between them
    while (lDepth > 1 && (nPosFirstSlash = FindFirstBackSlash(bstrOrigRecordKey, nPosFirstSlash)) && (nPosFirstSlash != stringx::npos))
    {
        lDepth--;
    }

    if (nPosFirstSlash != stringx::npos)
	{
        int nPosSecondSlash = FindFirstBackSlash(bstrOrigRecordKey, nPosFirstSlash);
        if (nPosFirstSlash)
        {
            ATLASSERT (nPosFirstSlash != stringx::npos);
            bstrResult = (BSTR) bstrOrigRecordKey.substr(0, nPosFirstSlash + 1);
        }            
        bstrResult += bstrNewKeyName;

        if (nPosSecondSlash != stringx::npos)
    	{
            bstrResult += bstrOrigRecordKey.substr(nPosSecondSlash, bstrOrigRecordKey.length() - nPosSecondSlash + 1);
        }
	}
	else
	{
        bstrResult = bstrNewKeyName;
	}
    return bstrResult;
}

IsmAuto::EnumRegistryDataType IsmAutoRegUtils::FilterTypePrefix(const stringx& bstrValue, BSTR* bstrDisplayValue)
{
	//Binary Value if #x is prefix
	//ExpandString Value if #% is prefix
	//DWORD Value if # is prefix, unless multiple #'s are prefixes
	//For Rest it is string Value
	int nSize = bstrValue.size();
	if(nSize >= 2 && (bstrValue[0] == _T('#')) && (bstrValue[1] == _T('x')))
	{
        RegistryUtilities::FormatFormattedString(bstrValue.substr(2, nSize - 2), 0).copy_to(bstrDisplayValue);
		return IsmAuto::erdtBinary;
	}
	else if(nSize >= 2 && (bstrValue[0] == _T('#')) && (bstrValue[1] == _T('%')))
	{
		RegistryUtilities::FormatFormattedString(bstrValue.substr(2, nSize - 2), 0).copy_to(bstrDisplayValue);
		return IsmAuto::erdtExpandString;
	}
	else if(nSize >= 2 && (bstrValue[0] == _T('#')) && (bstrValue[1] == _T('#')))
	{
		if (IsValidRegStringID(bstrValue))
			RegistryUtilities::FormatFormattedString(bstrValue, 0).copy_to(bstrDisplayValue);
		else
			RegistryUtilities::FormatFormattedString(bstrValue.substr(1, nSize - 1), 0).copy_to(bstrDisplayValue); // string starting with '#'
		return IsmAuto::erdtString;
	}
	else if(bstrValue[0] == _T('#'))
	{
        RegistryUtilities::FormatFormattedString(bstrValue.substr(1, nSize - 1), 0).copy_to(bstrDisplayValue);
		return IsmAuto::erdtInteger;
	}
	else
	{
        RegistryUtilities::FormatFormattedString(bstrValue, 0).copy_to(bstrDisplayValue);
		return IsmAuto::erdtString;
	}
}

stringx IsmAutoRegUtils::FormatRegValue(IsmAuto::EnumRegistryDataType erdtDataType, const stringx& bstrValue)
{
    stringx bstrFormattedValue;
	switch(erdtDataType)
	{
	case IsmAuto::erdtBinary:
		bstrFormattedValue = L"#x";
		bstrFormattedValue += RegistryUtilities::FormatFormattedString(bstrValue, 0);
		break;
	case IsmAuto::erdtInteger:
		bstrFormattedValue = L"#";
		if(bstrValue.length() <= 0)
			bstrFormattedValue += L"0";
		else
			bstrFormattedValue += RegistryUtilities::FormatFormattedString(bstrValue, 0);
		break;
	case IsmAuto::erdtString:
		{
			if ((bstrValue[0] == _T('[')) && (bstrValue[1] == _T('#')) && (bstrValue[bstrValue.length()-1] == _T(']')))
				bstrFormattedValue = bstrValue;
			else
			{
				int iLength = bstrValue.length();
				if ((bstrValue[0] == _T('#')) && !IsValidRegStringID(bstrValue))
					bstrFormattedValue = L"#";

				bstrFormattedValue += RegistryUtilities::FormatFormattedString(bstrValue, 0);
			}
		}
        
		break;
	case IsmAuto::erdtMultiString:
		//Right now I don't convert \0 to [~] but niether do Office Customization Kit.
        bstrFormattedValue = RegistryUtilities::FormatFormattedString(bstrValue, 0);
		break;
	case IsmAuto::erdtExpandString:
		bstrFormattedValue = L"#%";
		bstrFormattedValue += RegistryUtilities::FormatFormattedString(bstrValue, 0);
        break;
	default :
		return E_UNEXPECTED;
	}
    return bstrFormattedValue;
}

// return the first backslash you find that is not part of an MSI escape sequence "[\ ]"
stringx::size_type IsmAutoRegUtils::FindFirstBackSlash(const stringx &sValue, stringx::size_type nPos)
{
    ATLASSERT('\\' != sValue.first_char());

    while (stringx::npos != nPos)
    {
        nPos = sValue.find(REGKEY_SEPARATOR, nPos + 1);
	    if (nPos != stringx::npos)
	    {
            if (!IsInEscapeSequence(sValue, nPos, REGKEY_SEPARATOR))
            {
                return nPos;
            }
        }
    }
    return stringx::npos;
}

bool IsmAutoRegUtils::IsInEscapeSequence(const stringx &sValue, stringx::size_type &nPos, const stringx &sFind)
{
    ATLASSERT(nPos > 0);
    if ('[' == sValue[nPos - 1])
    {
        // if there's a ']' after nPos, then it's in an escape sequence
        int nPosClosed = sValue.find(L"]", nPos + 1);
        if (nPosClosed != stringx::npos && nPosClosed > nPos)
        {
            // continue looking after the escape sequence
            nPos = nPosClosed;
            return true;
        }
    }

    return false;
}

bool IsmAutoRegUtils::IsValidRegStringID(const stringx& sValue)
{
	// because the registry view does not handle ##, we need to do this.
	int nSize = sValue.length();
	if (nSize > 4 && 
		sValue[0] == _T('#') &&
		sValue[1] == _T('#') &&
		sValue[nSize - 2] == _T('#') &&
		sValue[nSize - 1] == _T('#') &&
		sValue.substr(2, nSize - 4).find('#') == stringx::npos)
		return true;
	return false;
}