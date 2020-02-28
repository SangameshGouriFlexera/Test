// IsmAutoRegUtils.h: IsmAutoRegistry Utility functions
//
//////////////////////////////////////////////////////////////////////

namespace IsmAutoRegUtils
{
    
    static const stringx HKEY_CLASSES_ROOT_STRING = L"HKEY_CLASSES_ROOT";
    static const stringx HKEY_CURRENT_USER_STRING = L"HKEY_CURRENT_USER";
    static const stringx HKEY_LOCAL_MACHINE_STRING = L"HKEY_LOCAL_MACHINE";
    static const stringx HKEY_USERS_STRING = L"HKEY_USERS";
    static const stringx HKEY_USER_SELECTABLE_STRING = L"HKEY_USER_SELECTABLE";

    static const stringx DEFAULT_REGKEY_VALUENAME1 = L"*";
    static const stringx DEFAULT_REGKEY_VALUENAME2 = L"+";
    static const stringx DEFAULT_REGKEY_VALUENAME3 = L"-";
    static const stringx REGKEY_SEPARATOR = L"\\";

    static const long ISATTRIBUTE_REGISTRY_AUTOMATIC = 0x1;

    static const long MSI_FIELD_ID_REGISTRY_REGISTRY = 1;
    static const long MSI_FIELD_ID_REGISTRY_ROOT = 2;
    static const long MSI_FIELD_ID_REGISTRY_KEY = 3;
    static const long MSI_FIELD_ID_REGISTRY_NAME = 4;
    static const long MSI_FIELD_ID_REGISTRY_VALUE = 5;
    static const long MSI_FIELD_ID_REGISTRY_COMPONENT = 6;
    static const long MSI_FIELD_ID_REGISTRY_ISATTRIBUTES = 7;
        
    void GetRootValue(const stringx& bstrRegKeyPath, msidbRegistryRoot *eRootKey);
    void GetRootString(msidbRegistryRoot eRoot, BSTR* bstrRootName);
    void GetSubKeyName(const stringx& bstrRegKeyPath, BSTR* bstrSubKeyName);
    void GetLeafKeyDepth(const stringx& bstrRegKeyPath, long *lDepth);
    void GetPathAtDepth(const stringx& bstrRegKeyPath, long lDepth, BSTR* bstrResult);
    void GetLeafKeyAtDepth(const stringx& bstrRegKeyPath, long lDepth, BSTR* bstrResult);
    void GetSubPathAtDepth(const stringx& bstrRegKeyPath, long lDepth, BSTR* bstrResult);
    bool PathsAreEqualAtShortest(const stringx& bstrPath1, const stringx& bstrPath2);
    stringx UpdateKeyName(const stringx& bstrOrigRecordKey, const stringx& bstrNewKeyName, long lDepth);
    IsmAuto::EnumRegistryDataType FilterTypePrefix(const stringx& bstrValue, BSTR* bstrDisplayValue);
    stringx FormatRegValue(IsmAuto::EnumRegistryDataType erdtDataType, const stringx& bstrValue);
    stringx::size_type FindFirstBackSlash(const stringx &sValue, stringx::size_type nPos = 0);
    bool IsInEscapeSequence(const stringx &sValue, stringx::size_type &nPos, const stringx &sFind);
	bool IsValidRegStringID(const stringx &sValue);
}