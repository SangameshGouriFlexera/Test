#pragma once
#include <vector>
#include <map>
//#include "MSXMLWrapper.h"
#include "IsmAutoWrapper.h"

typedef map<stringx, stringx>	VARMAP;

class CMsiVariableConverter  
{
public:
	CMsiVariableConverter(IsmAuto::IProjectRootLoyalty* pProjectRoot);
	virtual ~CMsiVariableConverter();

	stringx Convert(const stringx& s);
	long Convert(const stringx& s, stringx& sConverted);
	
	stringx GetDefaultDestination(bool bEndWithSlash = false);

	stringx GetComponentPath(const stringx& sCompKey);
	stringx GetEnvironmentValue(const stringxi& sEnvKey);
	stringx GetFilePath(const stringx& sFileKey);

protected:
	enum EnumFormattedDataType
	{
		efdtUnknown,
		efdtLongFileName,
		efdtShortFileName,
		efdtCompTargetDir
	};


protected:
	CComPtr<IsmAuto::IProjectRootLoyalty> m_spProjectRoot;
	VARMAP m_mapDirectories;
	VARMAP m_mapProperties;

	void LoadDirectories();
	void AddSpecialDirectories();
	void AddSpecialDirectory(const stringx& sDir);
	void LoadProperties();

	void ExtractVariables(const stringx& s, std::vector<stringx>& vecTokens);
	stringx ConvertVariable(const stringx& sVar);
	stringx	ConvertInstallerKey(const stringx& sValue);
	//void LoadDefaultProperties();
	
	friend class CMsiVariableConverterTest;
    
private:
	stringx m_sDefaultDestination;
	stringx m_sDefaultDestinationWithSlash;

};
