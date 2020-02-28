#if !defined(NEWSCHEMAHELPER_H)
#define NEWSCHEMAHELPER_H

HRESULT PkgRowIDFromGUID(const CComPtr<_Connection> &spDBConnUnknown, const CString& strPackageCode, long * plPkgRowID);

#endif // #if !defined(NEWSCHEMAHELPER_H)

