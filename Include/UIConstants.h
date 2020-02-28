#ifndef _UI_CONSTANTS_H_
#define _UI_CONSTANTS_H_

//--------------------------------------------------------------------------
#include "DomainUtility.h"
#include <map>
#include "..\..\dbcore\DBConstants.h"

//--------------------------------------------------------------------------
typedef enum eStatus
{
	esRemoved,
	esAdded,
	esPreExist,
	esChanged
}
EStatus;

typedef std::vector<CString> VEC_STRINGS;
typedef std::vector<CString>::iterator VEC_STRINGS_IT;

typedef std::vector<int> VEC_INTS;
typedef std::vector<int>::iterator VEC_INTS_IT;

//--------------------------------------------------------------------------
typedef std::vector<CDomainUser> VEC_DOMAIN_USERS;
typedef std::vector<CDomainUser>::iterator VEC_DOMAIN_USERS_IT;
typedef std::vector<CDomainUser>::const_iterator VEC_DOMAIN_USERS_CONST_IT;

//--------------------------------------------------------------------------
typedef struct sDomainUsers
{
	sDomainUsers()
	{
		m_nUserLastIndex = m_nGroupLastIndex = 0;
	}

	CString m_strDomain;
	CString m_strDomainServer;
	VEC_DOMAIN_USERS m_vecDomainUsers;

	DWORD m_nUserLastIndex;
	DWORD m_nGroupLastIndex;
}
sDomainUsers;

//--------------------------------------------------------------------------
typedef std::map<CString, sDomainUsers > MAP_DOMAIN_USERS;
typedef std::map<CString, sDomainUsers >::iterator MAP_DOMAIN_USERS_IT;
typedef std::map<CString, sDomainUsers >::const_iterator MAP_DOMAIN_USERS_CONST_IT;

//	---------------------------------------------------------------------------------
static const int DBCORE_LIST_COL0 = 0;
static const int DBCORE_LIST_COL1 = 1;
static const int DBCORE_LIST_COL2 = 2;
static const int DBCORE_LIST_COL3 = 3;

//--------------------------------------------------------------------------
static const int DBCORE_ICON_HEIGHT = 16;
static const int DBCORE_ICON_WIDTH = 16;
static const int DBCORE_NUMBER_OF_ICONS = 8;
static const int DBCORE_NUMBER_OF_ICONS_TO_GROW = 0;

//	---------------------------------------------------------------------------------
static int DBCORE_USER_IMAGE = 1;
static int DBCORE_GROUP_IMAGE = 2;
static int DBCORE_ROLE_IMAGE = 3;
static int DBCORE_SQL_USER_IMAGE = 4;

#endif // _UI_CONSTANTS_H_