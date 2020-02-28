#pragma once
#include <cmath>

namespace ConversionUtils
{
/// @brief  The BinaryToDecimal function
/// 
/// Convert a binary value stored in a string to its decimal equivalent
/// 
/// @param  sValue a parameter of type const CString&
/// @return long
/// 
	static long BinaryToDecimal(const CString& sValue)
	{
		long lReturn = 0;
		for(int iter = sValue.GetLength();iter > 0; iter --)
		{
			long lBit = _ttol(CString(sValue.GetAt(iter-1)));
			
			if(!(lBit == 1 || lBit == 0))
			{
				ASSERT(_T("The string to convert does not appear to be a binary value")==0);
				return 0;
			}

			if(lBit == 1)
			{
				lReturn += pow(2,sValue.GetLength()-iter);
			}
		}
		return lReturn;
	}
}
