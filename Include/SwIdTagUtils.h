#pragma once
#include <vector>
#include "stringx.h"

namespace SwIdTagUtils
{
	std::vector<stringxi> GetExistingSwIdTagFiles(const stringxi& sDir);
	bool AtLeastOneTagSelected(const stringxi& sDir);
	void CreateOrUpdateSwIdTag(const stringx& sName, const stringx& sVersion, const stringx& sProductGuid, const stringx& sPublisher, const stringxi& sDir);
	bool HaveWritePermissions(const stringxi& sFolder);
}
