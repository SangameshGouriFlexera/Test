// RegistryUtilities.cpp: implementation of the Registry Utility functions
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RegistryUtilities.h"

// MsiCommon
#include "MsiDBUtils.h"

#define MSI_FORMATTED_STRING_OPEN L"["
#define MSI_FORMATTED_STRING_CLOSE L"]"
static const stringx ESCAPED_OPENBRACE = L"[\\[]";
static const stringx ESCAPED_CLOSEBRACE = L"[\\]]";

stringx RegistryUtilities::FormatFormattedString(const stringx& strString, int nStartPos)
{
    // if there's a (non escape sequenced) open bracked followed by an close bracket, 
    // make sure there's only text inside it
    if (nStartPos != stringx::npos)
    {
        stringx strReturn(strString);
        long lstrReturnLength = strReturn.length();
        if (lstrReturnLength > 0)
        {
            stringx::size_type nPosOpen = strReturn.find(MSI_FORMATTED_STRING_OPEN, nStartPos);
            stringx::size_type nPosClosed = strReturn.find(MSI_FORMATTED_STRING_CLOSE, nStartPos);

            int nPosFirstFound;
            if ((stringx::npos == nPosClosed) && (stringx::npos == nPosOpen) )
            {
                nPosFirstFound = stringx::npos;
            }
            else
            {
                if (nPosOpen != stringx::npos)
                {
                    if (nPosClosed != stringx::npos)
                    {
                        if (nPosOpen < nPosClosed)
                        {
                            if (nPosClosed - nPosOpen > 1)
                            {
                                // check for identifier
								bool bAllowValue = false;
                                tstring tstrIdentifierCandidate = strReturn.substr(nPosOpen + 1, nPosClosed - nPosOpen -1);
								if (!tstrIdentifierCandidate.compare(_T("~")))
								{
									bAllowValue = true;
								}
								else
								{
									tstring tstrOrig(tstrIdentifierCandidate);
									MsiDBUtils::GetValidIdentifier(tstrIdentifierCandidate, nPosClosed - nPosOpen -1);
									if (!tstrOrig.compare(tstrIdentifierCandidate))
									{
										bAllowValue = true;
									}
								}
								if (bAllowValue)
								{
                                    return FormatFormattedString(strReturn, nPosClosed + 1);
                                }
                            }
                            nPosFirstFound = nPosOpen;
                        }
                        else
                        {
                            nPosFirstFound = nPosClosed;
                        }
                    }
                    else
                    {
                        nPosFirstFound = nPosOpen;
                    }
                }
                else
                {
                    nPosFirstFound = nPosClosed;
                }
            }
                                        
            if (nPosFirstFound != stringx::npos)
            {
				if (nPosOpen == nPosFirstFound)
                {
                    if (lstrReturnLength - ESCAPED_OPENBRACE.length() + 1 > nPosOpen)
					{
						// Make sure we don't have [\[] since this is already formatted 
						// and we don't have [! followed by ] later in the string
						// because that could indicate a format of [!FileKey]
						// and we don't have [% followed by ] later 
						// because that could indicate a path variable 1-E4MZ4
						// We could also have [$ or [#.
						if (((strReturn[nPosOpen + 1] != '\\') || (strReturn[nPosOpen + 3] != ']')) && 
							((strReturn[nPosOpen + 1] != '!') && strReturn.find(L"]", nPosOpen) != stringx::npos) &&
							((strReturn[nPosOpen + 1] != '$') && strReturn.find(L"]", nPosOpen) != stringx::npos) &&
							((strReturn[nPosOpen + 1] != '%') && strReturn.find(L"]", nPosOpen) != stringx::npos) &&
							((strReturn[nPosOpen + 1] != '#') && strReturn.find(L"]", nPosOpen) != stringx::npos))
						{
							strReturn.replace(nPosOpen, 1, ESCAPED_OPENBRACE);
						}
						else if(strReturn[nPosOpen + 1] == '!' ||
							strReturn[nPosOpen + 1] == '$' ||
							strReturn[nPosOpen + 1] == '%' ||
							strReturn[nPosOpen + 1] == '#')
						{
							//	We found one of the following:
							//    [!
							//    [$
							//    [%
							//    [#
							// so only start searching again after the closing bracket
							// in this string
							nPosFirstFound = strReturn.find(MSI_FORMATTED_STRING_CLOSE, nPosOpen);
							if (-1 == nPosFirstFound)
								return strString;
						}
						nPosFirstFound += ESCAPED_OPENBRACE.length() - 1;
					}
					else
					{
						strReturn.replace(nPosOpen, 1, ESCAPED_OPENBRACE);
						nPosFirstFound += ESCAPED_OPENBRACE.length() - 1;
					}
                }
                else if (nPosClosed == nPosFirstFound)
                {
                    strReturn.replace(nPosClosed, 1, ESCAPED_CLOSEBRACE);
                    nPosFirstFound += ESCAPED_CLOSEBRACE.length() - 1;
                }
                strReturn = FormatFormattedString(strReturn, nPosFirstFound + 1);
            }
            return strReturn;
        }
    }
    return strString;
}

stringx RegistryUtilities::UnFormatFormattedString(const stringx& strString)
{
    stringx strReturn(strString);
    strReturn.replace_all(ESCAPED_OPENBRACE, MSI_FORMATTED_STRING_OPEN);
    strReturn.replace_all(ESCAPED_CLOSEBRACE, MSI_FORMATTED_STRING_CLOSE);
    return strReturn;
}