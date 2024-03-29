// Created by Microsoft (R) C/C++ Compiler Version 12.00.8472.0 (b57753a1).
//
// -----------------------------------------
// MODIFIED by Jeff 02/22/00:
//		IFile renamed to IScrFile
//		IFolder renamed to IScrFolder
// -----------------------------------------
//
// C++ source equivalent of Win32 type library c:\winnt\system32\scrrun.dll
// compiler-generated file created 02/22/00 at 08:40:31 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace Scripting {

//
// Forward references and typedefs
//

struct __declspec(uuid("42c642c1-97e1-11cf-978f-00a02463e06f")) IDictionary;
struct __declspec(uuid("0ab5a3d0-e5b6-11d0-abf5-00a0c90fffc0")) IFileSystem;
struct __declspec(uuid("c7c3f5a0-88a3-11d0-abcb-00a0c90fffc0")) IDrive;
struct __declspec(uuid("c7c3f5a1-88a3-11d0-abcb-00a0c90fffc0")) IDriveCollection;
struct __declspec(uuid("c7c3f5a2-88a3-11d0-abcb-00a0c90fffc0")) IScrFolder;
struct __declspec(uuid("c7c3f5a3-88a3-11d0-abcb-00a0c90fffc0")) IFolderCollection;
struct __declspec(uuid("c7c3f5a4-88a3-11d0-abcb-00a0c90fffc0")) IScrFile;
struct __declspec(uuid("c7c3f5a5-88a3-11d0-abcb-00a0c90fffc0")) IFileCollection;
struct __declspec(uuid("53bad8c1-e718-11cf-893d-00a0c9054228")) ITextStream;
struct __declspec(uuid("aadc65f6-cff1-11d1-b747-00c04fc2b085")) IScriptEncoder;

struct /* coclass */ Dictionary;
struct /* coclass */ FileSystemObject;
struct /* coclass */ Drive;
struct /* coclass */ Drives;
struct /* coclass */ Folder;
struct /* coclass */ Folders;
struct /* coclass */ File;
struct /* coclass */ Files;
struct /* coclass */ TextStream;
struct /* coclass */ Encoder;


//
// Type library items
//

enum CompareMethod
{
    BinaryCompare = 0,
    TextCompare = 1,
    DatabaseCompare = 2
};

enum IOMode
{
    ForReading = 1,
    ForWriting = 2,
    ForAppending = 8
};

enum Tristate
{
    TristateTrue = -1,
    TristateFalse = 0,
    TristateUseDefault = -2,
    TristateMixed = -2
};

enum FileAttribute
{
    Normal = 0,
    ReadOnly = 1,
    Hidden = 2,
    System = 4,
    Volume = 8,
    Directory = 16,
    Archive = 32,
    Alias = 64,
    Compressed = 2048
};

struct __declspec(uuid("42c642c1-97e1-11cf-978f-00a02463e06f"))
IDictionary : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall putref_Item (
        VARIANT * Key,
        VARIANT * pRetItem ) = 0;
    virtual HRESULT __stdcall put_Item (
        VARIANT * Key,
        VARIANT * pRetItem ) = 0;
    virtual HRESULT __stdcall get_Item (
        VARIANT * Key,
        VARIANT * pRetItem ) = 0;
    virtual HRESULT __stdcall Add (
        VARIANT * Key,
        VARIANT * Item ) = 0;
    virtual HRESULT __stdcall get_Count (
        long * pCount ) = 0;
    virtual HRESULT __stdcall Exists (
        VARIANT * Key,
        VARIANT_BOOL * pExists ) = 0;
    virtual HRESULT __stdcall Items (
        VARIANT * pItemsArray ) = 0;
    virtual HRESULT __stdcall put_Key (
        VARIANT * Key,
        VARIANT * _arg2 ) = 0;
    virtual HRESULT __stdcall Keys (
        VARIANT * pKeysArray ) = 0;
    virtual HRESULT __stdcall Remove (
        VARIANT * Key ) = 0;
    virtual HRESULT __stdcall RemoveAll ( ) = 0;
    virtual HRESULT __stdcall put_CompareMode (
        enum CompareMethod pcomp ) = 0;
    virtual HRESULT __stdcall get_CompareMode (
        enum CompareMethod * pcomp ) = 0;
    virtual HRESULT __stdcall _NewEnum (
        IUnknown * * ppunk ) = 0;
    virtual HRESULT __stdcall get_HashVal (
        VARIANT * Key,
        VARIANT * HashVal ) = 0;
};

struct __declspec(uuid("ee09b103-97e0-11cf-978f-00a02463e06f"))
Dictionary;
    // [ default ] interface IDictionary

enum DriveTypeConst
{
    Unknown = 0,
    Removable = 1,
    Fixed = 2,
    Remote = 3,
    CDRom = 4,
    RamDisk = 5
};

enum SpecialFolderConst
{
    WindowsFolder = 0,
    SystemFolder = 1,
    TemporaryFolder = 2
};

struct __declspec(uuid("0ab5a3d0-e5b6-11d0-abf5-00a0c90fffc0"))
IFileSystem : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall get_Drives (
        struct IDriveCollection * * ppdrives ) = 0;
    virtual HRESULT __stdcall BuildPath (
        BSTR Path,
        BSTR Name,
        BSTR * pbstrResult ) = 0;
    virtual HRESULT __stdcall GetDriveName (
        BSTR Path,
        BSTR * pbstrResult ) = 0;
    virtual HRESULT __stdcall GetParentFolderName (
        BSTR Path,
        BSTR * pbstrResult ) = 0;
    virtual HRESULT __stdcall GetFileName (
        BSTR Path,
        BSTR * pbstrResult ) = 0;
    virtual HRESULT __stdcall GetBaseName (
        BSTR Path,
        BSTR * pbstrResult ) = 0;
    virtual HRESULT __stdcall GetExtensionName (
        BSTR Path,
        BSTR * pbstrResult ) = 0;
    virtual HRESULT __stdcall GetAbsolutePathName (
        BSTR Path,
        BSTR * pbstrResult ) = 0;
    virtual HRESULT __stdcall GetTempName (
        BSTR * pbstrResult ) = 0;
    virtual HRESULT __stdcall DriveExists (
        BSTR DriveSpec,
        VARIANT_BOOL * pfExists ) = 0;
    virtual HRESULT __stdcall FileExists (
        BSTR FileSpec,
        VARIANT_BOOL * pfExists ) = 0;
    virtual HRESULT __stdcall FolderExists (
        BSTR FolderSpec,
        VARIANT_BOOL * pfExists ) = 0;
    virtual HRESULT __stdcall GetDrive (
        BSTR DriveSpec,
        struct IDrive * * ppdrive ) = 0;
    virtual HRESULT __stdcall GetFile (
        BSTR FilePath,
        struct IScrFile * * ppfile ) = 0;
    virtual HRESULT __stdcall GetFolder (
        BSTR FolderPath,
        struct IScrFolder * * ppfolder ) = 0;
    virtual HRESULT __stdcall GetSpecialFolder (
        enum SpecialFolderConst SpecialFolder,
        struct IScrFolder * * ppfolder ) = 0;
    virtual HRESULT __stdcall DeleteFile (
        BSTR FileSpec,
        VARIANT_BOOL Force ) = 0;
    virtual HRESULT __stdcall DeleteFolder (
        BSTR FolderSpec,
        VARIANT_BOOL Force ) = 0;
    virtual HRESULT __stdcall MoveFile (
        BSTR Source,
        BSTR Destination ) = 0;
    virtual HRESULT __stdcall MoveFolder (
        BSTR Source,
        BSTR Destination ) = 0;
    virtual HRESULT __stdcall CopyFile (
        BSTR Source,
        BSTR Destination,
        VARIANT_BOOL OverWriteFiles ) = 0;
    virtual HRESULT __stdcall CopyFolder (
        BSTR Source,
        BSTR Destination,
        VARIANT_BOOL OverWriteFiles ) = 0;
    virtual HRESULT __stdcall CreateFolder (
        BSTR Path,
        struct IScrFolder * * ppfolder ) = 0;
    virtual HRESULT __stdcall CreateTextFile (
        BSTR FileName,
        VARIANT_BOOL Overwrite,
        VARIANT_BOOL Unicode,
        struct ITextStream * * ppts ) = 0;
    virtual HRESULT __stdcall OpenTextFile (
        BSTR FileName,
        enum IOMode IOMode,
        VARIANT_BOOL Create,
        enum Tristate Format,
        struct ITextStream * * ppts ) = 0;
};

struct __declspec(uuid("c7c3f5a0-88a3-11d0-abcb-00a0c90fffc0"))
IDrive : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall get_Path (
        BSTR * pbstrPath ) = 0;
    virtual HRESULT __stdcall get_DriveLetter (
        BSTR * pbstrLetter ) = 0;
    virtual HRESULT __stdcall get_ShareName (
        BSTR * pbstrShareName ) = 0;
    virtual HRESULT __stdcall get_DriveType (
        enum DriveTypeConst * pdt ) = 0;
    virtual HRESULT __stdcall get_RootFolder (
        struct IScrFolder * * ppfolder ) = 0;
    virtual HRESULT __stdcall get_AvailableSpace (
        VARIANT * pvarAvail ) = 0;
    virtual HRESULT __stdcall get_FreeSpace (
        VARIANT * pvarFree ) = 0;
    virtual HRESULT __stdcall get_TotalSize (
        VARIANT * pvarTotal ) = 0;
    virtual HRESULT __stdcall get_VolumeName (
        BSTR * pbstrName ) = 0;
    virtual HRESULT __stdcall put_VolumeName (
        BSTR pbstrName ) = 0;
    virtual HRESULT __stdcall get_FileSystem (
        BSTR * pbstrFileSystem ) = 0;
    virtual HRESULT __stdcall get_SerialNumber (
        long * pulSerialNumber ) = 0;
    virtual HRESULT __stdcall get_IsReady (
        VARIANT_BOOL * pfReady ) = 0;
};

struct __declspec(uuid("c7c3f5a1-88a3-11d0-abcb-00a0c90fffc0"))
IDriveCollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall get_Item (
        VARIANT Key,
        struct IDrive * * ppdrive ) = 0;
    virtual HRESULT __stdcall get__NewEnum (
        IUnknown * * ppenum ) = 0;
    virtual HRESULT __stdcall get_Count (
        long * plCount ) = 0;
};

struct __declspec(uuid("c7c3f5a2-88a3-11d0-abcb-00a0c90fffc0"))
IScrFolder : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall get_Path (
        BSTR * pbstrPath ) = 0;
    virtual HRESULT __stdcall get_Name (
        BSTR * pbstrName ) = 0;
    virtual HRESULT __stdcall put_Name (
        BSTR pbstrName ) = 0;
    virtual HRESULT __stdcall get_ShortPath (
        BSTR * pbstrPath ) = 0;
    virtual HRESULT __stdcall get_ShortName (
        BSTR * pbstrName ) = 0;
    virtual HRESULT __stdcall get_Drive (
        struct IDrive * * ppdrive ) = 0;
    virtual HRESULT __stdcall get_ParentFolder (
        struct IScrFolder * * ppfolder ) = 0;
    virtual HRESULT __stdcall get_Attributes (
        enum FileAttribute * pfa ) = 0;
    virtual HRESULT __stdcall put_Attributes (
        enum FileAttribute pfa ) = 0;
    virtual HRESULT __stdcall get_DateCreated (
        DATE * pdate ) = 0;
    virtual HRESULT __stdcall get_DateLastModified (
        DATE * pdate ) = 0;
    virtual HRESULT __stdcall get_DateLastAccessed (
        DATE * pdate ) = 0;
    virtual HRESULT __stdcall get_Type (
        BSTR * pbstrType ) = 0;
    virtual HRESULT __stdcall Delete (
        VARIANT_BOOL Force ) = 0;
    virtual HRESULT __stdcall Copy (
        BSTR Destination,
        VARIANT_BOOL OverWriteFiles ) = 0;
    virtual HRESULT __stdcall Move (
        BSTR Destination ) = 0;
    virtual HRESULT __stdcall get_IsRootFolder (
        VARIANT_BOOL * pfRootFolder ) = 0;
    virtual HRESULT __stdcall get_Size (
        VARIANT * pvarSize ) = 0;
    virtual HRESULT __stdcall get_SubFolders (
        struct IFolderCollection * * ppfolders ) = 0;
    virtual HRESULT __stdcall get_Files (
        struct IFileCollection * * ppfiles ) = 0;
    virtual HRESULT __stdcall CreateTextFile (
        BSTR FileName,
        VARIANT_BOOL Overwrite,
        VARIANT_BOOL Unicode,
        struct ITextStream * * ppts ) = 0;
};

struct __declspec(uuid("c7c3f5a3-88a3-11d0-abcb-00a0c90fffc0"))
IFolderCollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall Add (
        BSTR Name,
        struct IScrFolder * * ppfolder ) = 0;
    virtual HRESULT __stdcall get_Item (
        VARIANT Key,
        struct IScrFolder * * ppfolder ) = 0;
    virtual HRESULT __stdcall get__NewEnum (
        IUnknown * * ppenum ) = 0;
    virtual HRESULT __stdcall get_Count (
        long * plCount ) = 0;
};

struct __declspec(uuid("c7c3f5a4-88a3-11d0-abcb-00a0c90fffc0"))
IScrFile : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall get_Path (
        BSTR * pbstrPath ) = 0;
    virtual HRESULT __stdcall get_Name (
        BSTR * pbstrName ) = 0;
    virtual HRESULT __stdcall put_Name (
        BSTR pbstrName ) = 0;
    virtual HRESULT __stdcall get_ShortPath (
        BSTR * pbstrPath ) = 0;
    virtual HRESULT __stdcall get_ShortName (
        BSTR * pbstrName ) = 0;
    virtual HRESULT __stdcall get_Drive (
        struct IDrive * * ppdrive ) = 0;
    virtual HRESULT __stdcall get_ParentFolder (
        struct IScrFolder * * ppfolder ) = 0;
    virtual HRESULT __stdcall get_Attributes (
        enum FileAttribute * pfa ) = 0;
    virtual HRESULT __stdcall put_Attributes (
        enum FileAttribute pfa ) = 0;
    virtual HRESULT __stdcall get_DateCreated (
        DATE * pdate ) = 0;
    virtual HRESULT __stdcall get_DateLastModified (
        DATE * pdate ) = 0;
    virtual HRESULT __stdcall get_DateLastAccessed (
        DATE * pdate ) = 0;
    virtual HRESULT __stdcall get_Size (
        VARIANT * pvarSize ) = 0;
    virtual HRESULT __stdcall get_Type (
        BSTR * pbstrType ) = 0;
    virtual HRESULT __stdcall Delete (
        VARIANT_BOOL Force ) = 0;
    virtual HRESULT __stdcall Copy (
        BSTR Destination,
        VARIANT_BOOL OverWriteFiles ) = 0;
    virtual HRESULT __stdcall Move (
        BSTR Destination ) = 0;
    virtual HRESULT __stdcall OpenAsTextStream (
        enum IOMode IOMode,
        enum Tristate Format,
        struct ITextStream * * ppts ) = 0;
};

struct __declspec(uuid("c7c3f5a5-88a3-11d0-abcb-00a0c90fffc0"))
IFileCollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall get_Item (
        VARIANT Key,
        struct IScrFile * * ppfile ) = 0;
    virtual HRESULT __stdcall get__NewEnum (
        IUnknown * * ppenum ) = 0;
    virtual HRESULT __stdcall get_Count (
        long * plCount ) = 0;
};

struct __declspec(uuid("53bad8c1-e718-11cf-893d-00a0c9054228"))
ITextStream : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall get_Line (
        long * Line ) = 0;
    virtual HRESULT __stdcall get_Column (
        long * Column ) = 0;
    virtual HRESULT __stdcall get_AtEndOfStream (
        VARIANT_BOOL * EOS ) = 0;
    virtual HRESULT __stdcall get_AtEndOfLine (
        VARIANT_BOOL * EOL ) = 0;
    virtual HRESULT __stdcall Read (
        long Characters,
        BSTR * Text ) = 0;
    virtual HRESULT __stdcall ReadLine (
        BSTR * Text ) = 0;
    virtual HRESULT __stdcall ReadAll (
        BSTR * Text ) = 0;
    virtual HRESULT __stdcall Write (
        BSTR Text ) = 0;
    virtual HRESULT __stdcall WriteLine (
        BSTR Text ) = 0;
    virtual HRESULT __stdcall WriteBlankLines (
        long Lines ) = 0;
    virtual HRESULT __stdcall Skip (
        long Characters ) = 0;
    virtual HRESULT __stdcall SkipLine ( ) = 0;
    virtual HRESULT __stdcall Close ( ) = 0;
};

struct __declspec(uuid("0d43fe01-f093-11cf-8940-00a0c9054228"))
FileSystemObject;
    // [ default ] interface IFileSystem

struct __declspec(uuid("c7c3f5b1-88a3-11d0-abcb-00a0c90fffc0"))
Drive;
    // [ default ] interface IDrive

struct __declspec(uuid("c7c3f5b2-88a3-11d0-abcb-00a0c90fffc0"))
Drives;
    // [ default ] interface IDriveCollection

struct __declspec(uuid("c7c3f5b3-88a3-11d0-abcb-00a0c90fffc0"))
Folder;
    // [ default ] interface IFolder

struct __declspec(uuid("c7c3f5b4-88a3-11d0-abcb-00a0c90fffc0"))
Folders;
    // [ default ] interface IFolderCollection

struct __declspec(uuid("c7c3f5b5-88a3-11d0-abcb-00a0c90fffc0"))
File;
    // [ default ] interface IFile

struct __declspec(uuid("c7c3f5b6-88a3-11d0-abcb-00a0c90fffc0"))
Files;
    // [ default ] interface IFileCollection

struct __declspec(uuid("0bb02ec0-ef49-11cf-8940-00a0c9054228"))
TextStream;
    // [ default ] interface ITextStream

struct __declspec(uuid("aadc65f6-cff1-11d1-b747-00c04fc2b085"))
IScriptEncoder : IDispatch
{
    //
    // Raw methods provided by interface
    //

    virtual HRESULT __stdcall EncodeScriptFile (
        BSTR szExt,
        BSTR bstrStreamIn,
        long cFlags,
        BSTR bstrDefaultLang,
        BSTR * pbstrStreamOut ) = 0;
};

struct __declspec(uuid("32da2b15-cfed-11d1-b747-00c04fc2b085"))
Encoder;
    // [ default ] interface IScriptEncoder

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_Scripting =
    {0x420b2830,0xe718,0x11cf,{0x89,0x3d,0x00,0xa0,0xc9,0x05,0x42,0x28}};
extern "C" const GUID __declspec(selectany) IID_IDictionary =
    {0x42c642c1,0x97e1,0x11cf,{0x97,0x8f,0x00,0xa0,0x24,0x63,0xe0,0x6f}};
extern "C" const GUID __declspec(selectany) CLSID_Dictionary =
    {0xee09b103,0x97e0,0x11cf,{0x97,0x8f,0x00,0xa0,0x24,0x63,0xe0,0x6f}};
extern "C" const GUID __declspec(selectany) IID_IFileSystem =
    {0x0ab5a3d0,0xe5b6,0x11d0,{0xab,0xf5,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) IID_IDrive =
    {0xc7c3f5a0,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) IID_IDriveCollection =
    {0xc7c3f5a1,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) IID_IScrFolder =
    {0xc7c3f5a2,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) IID_IFolderCollection =
    {0xc7c3f5a3,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) IID_IScrFile =
    {0xc7c3f5a4,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) IID_IFileCollection =
    {0xc7c3f5a5,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) IID_ITextStream =
    {0x53bad8c1,0xe718,0x11cf,{0x89,0x3d,0x00,0xa0,0xc9,0x05,0x42,0x28}};
extern "C" const GUID __declspec(selectany) CLSID_FileSystemObject =
    {0x0d43fe01,0xf093,0x11cf,{0x89,0x40,0x00,0xa0,0xc9,0x05,0x42,0x28}};
extern "C" const GUID __declspec(selectany) CLSID_Drive =
    {0xc7c3f5b1,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) CLSID_Drives =
    {0xc7c3f5b2,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) CLSID_Folder =
    {0xc7c3f5b3,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) CLSID_Folders =
    {0xc7c3f5b4,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) CLSID_File =
    {0xc7c3f5b5,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) CLSID_Files =
    {0xc7c3f5b6,0x88a3,0x11d0,{0xab,0xcb,0x00,0xa0,0xc9,0x0f,0xff,0xc0}};
extern "C" const GUID __declspec(selectany) CLSID_TextStream =
    {0x0bb02ec0,0xef49,0x11cf,{0x89,0x40,0x00,0xa0,0xc9,0x05,0x42,0x28}};
extern "C" const GUID __declspec(selectany) IID_IScriptEncoder =
    {0xaadc65f6,0xcff1,0x11d1,{0xb7,0x47,0x00,0xc0,0x4f,0xc2,0xb0,0x85}};
extern "C" const GUID __declspec(selectany) CLSID_Encoder =
    {0x32da2b15,0xcfed,0x11d1,{0xb7,0x47,0x00,0xc0,0x4f,0xc2,0xb0,0x85}};

} // namespace Scripting

#pragma pack(pop)
