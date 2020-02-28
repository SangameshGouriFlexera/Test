#ifndef GlobalProgIds_H
#define GlobalProgIds_H

	#ifdef ISEXPRESS
		#define PROGID_STOREPROJECT L"ISExpNewStore.Project"
		#define PROGID_STOREPROJECT_1 L"ISExpNewStore.Project.1"
		//Or IsExpIsmAuto.Project
	#elif ISADMIN
		#define PROGID_STOREPROJECT L"ISAdmNewStore.Project"
		#define PROGID_STOREPROJECT_1 L"ISAdmNewStore.Project.1"
	#else
		#define PROGID_STOREPROJECT L"ISNewStore.Project"
		#define PROGID_STOREPROJECT_1 L"ISNewStore.Project_1"
	#endif

#endif