#pragma once
#include "stringx.h"

class CZip
{
public:
	CZip(const stringxi& sZipFile);
	bool ExtractAllFiles(const stringxi& sDestFolderIn);
	bool ExtractPSRReportFile(const stringxi& sDestFolderIn, const stringxi& sProductName);

private:
	stringxi m_sZipFile;
};