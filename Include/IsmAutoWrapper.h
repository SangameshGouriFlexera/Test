#ifndef ISMAUTOWRAPPER_H
#define ISMAUTOWRAPPER_H

#ifndef AS
// This ifdef allows ISUIConflictServices.dll to build. For some reason without it the compiler
// complains about a redefinition of _Collection. On the other hand VirtualConverter build needs ISUtil.
// Get definition of _Collection, which is required by ismmupdater.h
namespace ISUtil
{
    #include "ISUtil.h"
}
using ISUtil::_Collection;
#endif

// Don't let ismmupdater.h initialize any GUIDs
#undef DEFINE_GUID
#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    EXTERN_C const GUID FAR name

// ismauto.h requires ismmupdater.h
namespace ISMMUpdater
{
    #include "ismmupdater.h"
}

// Make sure the GUIDs are initialized only once
#undef DEFINE_GUID
#ifdef INIT_ISMAUTO_GUIDS
#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        EXTERN_C const GUID name \
                = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
#else
#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    EXTERN_C const GUID FAR name
#endif

// IsmAuto.h doesn't know about the namespace
using ISMMUpdater::IMMDependencies;
using ISMMUpdater::IMMDependency;
using ISMMUpdater::IMMExclusions;
using ISMMUpdater::IMMExclusion;
using ISMMUpdater::IMMCatalog;
using ISMMUpdater::IMMFiles;
using ISMMUpdater::IMMFile;
using ISMMUpdater::IMergeModule;
using ISMMUpdater::IMergeModule2;
using ISMMUpdater::IMergeModules;
using ISMMUpdater::IMMDialog;
using ISMMUpdater::IMMDialogs;
using ISMMUpdater::IMMCustomAction;
using ISMMUpdater::IMMCustomActions;

struct __declspec(uuid("980BA856-BF42-4180-9159-E102A6933222")) ISMMUpdater::IMMCatalog;
struct __declspec(uuid("D6D6F702-1AC4-4FEA-8D43-DA8CA057964D")) ISMMUpdater::IMMDependencies;
struct __declspec(uuid("167EFB3F-C0EF-4DE4-80B5-EAAFC63AF617")) ISMMUpdater::IMMDependency;
struct __declspec(uuid("45D084AB-5BC8-4849-864B-72D303CC63CE")) ISMMUpdater::IMMExclusions;
struct __declspec(uuid("E50A9726-01BB-4D4B-83F5-C9F6A38F22BA")) ISMMUpdater::IMMExclusion;
struct __declspec(uuid("D7DA1253-5BD4-45BE-81CA-E9D65676F981")) ISMMUpdater::IMergeModule;
struct __declspec(uuid("1418BBED-19CC-44CF-A389-4366E8E092C3")) ISMMUpdater::IMergeModule2;
struct __declspec(uuid("7E74B784-44E3-40BF-B86D-C47D50361D2A")) ISMMUpdater::IMergeModules;
struct __declspec(uuid("FE484E0F-CD46-4AE0-9047-35B6C2A09DCE")) ISMMUpdater::IMMDialog;
struct __declspec(uuid("2721DF98-1462-44C6-BE8F-D55E4FC15FB3")) ISMMUpdater::IMMDialogs;
struct __declspec(uuid("7E929716-D4BF-407D-9EA9-C7EF54DEA432")) ISMMUpdater::IMMCustomAction;
struct __declspec(uuid("CF3BCF1A-F2B1-4571-BF04-E69F5198B1F4")) ISMMUpdater::IMMCustomActions;
struct __declspec(uuid("537262E7-59C4-47EC-AA7F-5D5C9A9BA128")) ISMMUpdater::IMMFiles;
struct __declspec(uuid("B4D69704-F8C5-4AC1-8315-89208220952F")) ISMMUpdater::IMMFile;
struct __declspec(uuid("66DBE347-1A37-40E2-90F5-C515E07E372C")) ISMMUpdater::IMMCatalogNeptune;
struct __declspec(uuid("9BC0C990-5624-47C9-8E87-F08489BA9AEA")) ISMMUpdater::IMMCatalogManagerNeptune;
struct __declspec(uuid("6BF8F505-8594-4c27-A901-3EF1AD63B90C")) ISMMUpdater::IMMCatalogTriton;
struct __declspec(uuid("3D0B69E6-E799-4d24-9124-AAA51B9BA987")) ISMMUpdater::IMMGalleryTriton;
struct __declspec(uuid("EDB661BF-F632-4894-847C-51E736F8C76A")) ISMMUpdater::IMMGalleryDownloadFilesTriton;
struct __declspec(uuid("0A15F59A-64D3-4e47-B3B3-417846CF0D98")) ISMMUpdater::IMMGalleryDownloadFileTriton;
struct __declspec(uuid("E2061477-341A-4771-9854-24C975C2C876")) ISMMUpdater::IMMGalleryProteusSP;
struct __declspec(uuid("BCAD53BE-F5CA-4075-8E7E-6B78F95CE9F0")) ISMMUpdater::IMergeModulePluto;


namespace IsmAuto
{
    #include "IsmAuto.h"
}

#define DEFINE_ISMAUTO_INTERFACE(_iid, _interface)\
	struct __declspec(uuid(#_iid)) IsmAuto::_interface;

struct __declspec(uuid("00020404-0000-0000-C000-000000000046")) IsmAuto::IVBEnumVARIANT;
struct __declspec(uuid("DAC633E5-3A5E-4AF0-B19E-0CBE007C5D63")) IsmAuto::IAction;
struct __declspec(uuid("7D8F9784-8326-409F-97C6-6F45326C0746")) IsmAuto::IActions;
struct __declspec(uuid("92312797-158B-4FE1-99D8-73BE257B0D5A")) IsmAuto::IAppId;
struct __declspec(uuid("533F6BBB-82F4-4493-8D74-E35E2BC8A86B")) IsmAuto::IAppIds;
struct __declspec(uuid("244E05B2-25BF-45B3-8AF8-ABBC30869A03")) IsmAuto::IAppSearch;
struct __declspec(uuid("B2D3C115-6424-4028-BED0-940FECA049C2")) IsmAuto::IAppSearches;
struct __declspec(uuid("87CA88E2-8615-444A-BE78-B0A12AA1F6C0")) IsmAuto::IRegLocator;
struct __declspec(uuid("480A4B3A-8079-407D-950F-77F44BB4BCEC")) IsmAuto::IRegLocator2;
struct __declspec(uuid("20F88549-5889-445E-9436-E9212B36FC88")) IsmAuto::IRegLocators;
struct __declspec(uuid("7C1492E4-4F2A-4B08-877E-6986DA79F256")) IsmAuto::IIniLocator;
struct __declspec(uuid("5FCCD58C-852A-4B82-8FE1-D474FAEB6E9A")) IsmAuto::IIniLocators;
struct __declspec(uuid("90869B0B-6AAE-4DD4-B0B1-7CA8BCEBC605")) IsmAuto::ICompLocator;
struct __declspec(uuid("A653CABE-7E2B-4FDC-AA1B-4C3442E956D9")) IsmAuto::ICompLocators;
struct __declspec(uuid("FF2A66E1-D77C-45CF-B8B2-7C23DB091183")) IsmAuto::IDrLocator;
struct __declspec(uuid("A0F23B15-BD47-48b7-A73A-508EC474CFB6")) IsmAuto::IDrLocatorIxtapa;
struct __declspec(uuid("FEDA7C90-0C53-499A-9A20-32FC1BCAC9C2")) IsmAuto::IDrLocators;
struct __declspec(uuid("EE127D7D-CE49-4291-B228-1620C1F59B57")) IsmAuto::ISignature;
struct __declspec(uuid("C31C00A4-3695-4978-BC2C-AFA432E80995")) IsmAuto::ISignatures;
struct __declspec(uuid("E76610A4-31F4-4ED0-A118-758BD4BF9DEC")) IsmAuto::IAppSearch2;
struct __declspec(uuid("B4626493-1A3D-421e-ACBA-580F1EE25CBE")) IsmAuto::IAppSearchPluto;
struct __declspec(uuid("A50057F6-8F91-4A6D-A7AD-CFD8422D4788")) IsmAuto::IBinary;
struct __declspec(uuid("E603CE6E-84D9-4A90-AA5E-76B89FE5B647")) IsmAuto::IBinaries;
struct __declspec(uuid("8757629A-D2D8-4513-B184-9FBBD72628F2")) IsmAuto::IIsProperty;
struct __declspec(uuid("F4121EF2-C985-42E7-8B4E-D37B0D04F6D2")) IsmAuto::IIsProperties;
struct __declspec(uuid("7CC96B5A-A0F1-4577-9F5C-CD9CD88430E1")) IsmAuto::IBusinessObject;
struct __declspec(uuid("F2E2C049-1F80-49C0-ACED-E765F3022D84")) IsmAuto::IBusinessObject2;
struct __declspec(uuid("443D3CE8-14E2-4430-A725-8F705EEB36FA")) IsmAuto::IBusinessObjectProteus;
struct __declspec(uuid("443D3CE9-14E2-4430-A725-8F705EEB36FA")) IsmAuto::IBusinessObjectPlutoSP1;
struct __declspec(uuid("6CEDEA1F-12CF-439E-A27E-6AAAAEAB9773")) IsmAuto::IBusinessObjectEx;
struct __declspec(uuid("F424667F-33FF-44d7-BD7F-7166647A2C77")) IsmAuto::IBusinessObjectIxtapa;
struct __declspec(uuid("187FFC20-BFB3-4240-9D02-8C666919908E")) IsmAuto::ICollection;
struct __declspec(uuid("CE10C530-1D90-4584-8B82-1299E7225CA6")) IsmAuto::IIsStrings;
struct __declspec(uuid("4EB7F535-65BA-43D5-B6D3-FDC852FAF0ED")) IsmAuto::IIsStrings2;
struct __declspec(uuid("C3EC8A79-4E66-42E0-BEAC-21AA30C55416")) IsmAuto::IWhereClause;
struct __declspec(uuid("E838BC1E-F109-481D-A87C-5109BDC13F02")) IsmAuto::IChainPackages;
struct __declspec(uuid("C987B583-9101-4CBD-B324-C38C6AB66C1A")) IsmAuto::IChainPackageJustice;
struct __declspec(uuid("1CFA8CA7-5990-4B2F-9657-22BCCB8BD919")) IsmAuto::IChainPackageLoyalty;
struct __declspec(uuid("FD07CFCA-E796-400E-B27D-7992DF3740C5")) IsmAuto::IChainPackageDatas;
struct __declspec(uuid("0E0E627D-9750-4AC2-BA5D-466046812994")) IsmAuto::IChainPackageDataJustice;
struct __declspec(uuid("7FA407D1-6C0F-44CC-8151-85F73934E2F3")) IsmAuto::ICEFileExt;
struct __declspec(uuid("83E07666-DBB4-4518-9A8A-66573AFD218C")) IsmAuto::ICEFileExts;
struct __declspec(uuid("6CA0787F-78C6-44D3-975C-B885A72A23B1")) IsmAuto::ICERegEntry;
struct __declspec(uuid("CE89AEFA-1EF3-48B2-9019-7D0066A43FF8")) IsmAuto::ICERegEntries;
struct __declspec(uuid("506D165E-4BAC-4CE4-B5CC-DEE1E873FE25")) IsmAuto::ICESetupFile;
struct __declspec(uuid("07833DB6-CD36-436D-829A-C8A829DBACCF")) IsmAuto::ICESetupFiles;
struct __declspec(uuid("66C5C00B-E488-4735-87B4-FBC74AE7F5AC")) IsmAuto::ICEShtCut;
struct __declspec(uuid("318224A1-325E-4fe1-8967-F3414987A8AB")) IsmAuto::ICEShtCutLoyaltySP;
struct __declspec(uuid("720A162D-62CF-40DB-B8FE-A1BA95A468A4")) IsmAuto::ICEShtCuts;
struct __declspec(uuid("FB31629E-3C38-4799-BD09-AEFF9A9AE03E")) IsmAuto::ICEFile;
struct __declspec(uuid("67BB797F-16A6-422F-BC19-836888CB4830")) IsmAuto::ICEFiles;
struct __declspec(uuid("7D5C5533-2967-41C1-9BB9-BCCE3481FEC0")) IsmAuto::ICEDir;
struct __declspec(uuid("A594E9A8-340C-4E54-9299-A8EC7B986528")) IsmAuto::ICEDirs;
struct __declspec(uuid("59BD8294-FC75-45FA-8356-53209D987106")) IsmAuto::ICEApp;
struct __declspec(uuid("004C6A8E-1E79-4445-9A43-DDC8022FAD37")) IsmAuto::ICEAppProteus;
struct __declspec(uuid("9C25AF67-3548-4269-82EE-AC86FA09964D")) IsmAuto::ICEAppIndore;
struct __declspec(uuid("E03C0D06-2A21-450f-8270-5460C29A0E29")) IsmAuto::ICEAppJustice;
struct __declspec(uuid("1DF28E9E-D97F-4C7A-90B3-4501E312491B")) IsmAuto::ICEApps;
struct __declspec(uuid("772D45FF-7E3D-4ED8-9BE4-82F19357F150")) IsmAuto::ICECabFile;
struct __declspec(uuid("00831F35-66C3-4F98-862B-5B2D4E7AF02C")) IsmAuto::ICECabFiles;
struct __declspec(uuid("10FFE7F6-E748-44d7-B9AD-9EC2FFB7250A")) IsmAuto::ICERedist;
struct __declspec(uuid("7309775F-9850-46f9-89E1-78C54437EB2F")) IsmAuto::ICERedists;
struct __declspec(uuid("02723335-C716-44CB-AEF5-6E8CC0204A0F")) IsmAuto::ICheckedODBCComponents;
struct __declspec(uuid("7C033867-1F3E-426B-8AAE-F53606CC1DB3")) IsmAuto::IContext;
struct __declspec(uuid("6C4F0B97-47C2-4BDB-B82E-BE521A0568D5")) IsmAuto::IContexts;
struct __declspec(uuid("12CFD607-EA10-4E38-9FE6-17124E19F47B")) IsmAuto::IClass;
struct __declspec(uuid("8322FE74-52A6-45D3-B668-4E2853D95849")) IsmAuto::IClass2;
struct __declspec(uuid("E01B466E-5F39-48D1-BDA1-78E52E26849F")) IsmAuto::IClasses;
struct __declspec(uuid("4A2D7026-28C8-41C3-9119-2118A900EFC7")) IsmAuto::IISCatalogCollectionNeptune;
struct __declspec(uuid("7D46A5F5-0C80-4F77-A603-9FF9534A2424")) IsmAuto::IISCatalogCollectionsNeptune;
struct __declspec(uuid("392B9F05-27BB-4C32-A1FD-A6B876FB951D")) IsmAuto::IISCatalogAttributeNeptune;
struct __declspec(uuid("C2B7CCFD-0BD2-4487-8A03-3B878AA9F4FE")) IsmAuto::IISCatalogAttributesNeptune;
struct __declspec(uuid("06B2F695-0419-47D2-AF78-95824800EB96")) IsmAuto::IISCatalogObjectNeptune;
struct __declspec(uuid("51C0E79D-FE32-4BAF-B0E6-2528CB36E23F")) IsmAuto::IISCatalogObjectsNeptune;
struct __declspec(uuid("FD8137C1-C459-4DCD-A141-661D20089D18")) IsmAuto::IISComPlusApplicationNeptune;
struct __declspec(uuid("8EFF68B3-1798-489B-B8DC-48749E5D6AE0")) IsmAuto::IISComPlusApplicationsNeptune;
struct __declspec(uuid("4E64EE68-C418-4B1D-880C-7A55F9593D13")) IsmAuto::IComponentSubfolderNeptune;
struct __declspec(uuid("C7819B60-C801-425D-B086-6295E5A08930")) IsmAuto::IComponentSubfoldersNeptune;
struct __declspec(uuid("8127ACC9-8746-4F41-A8B1-A3EB96622242")) IsmAuto::IComponent;
struct __declspec(uuid("37308DCD-3F85-43B2-AE92-62FB81B70292")) IsmAuto::IComponent2;
struct __declspec(uuid("CD030CB7-1230-4244-ACBA-D6EFE895B966")) IsmAuto::IComponentNeptune;
struct __declspec(uuid("E170AFDC-FDFD-4669-A439-4CB4EADDC0C7")) IsmAuto::IComponentNeptunePDC;
struct __declspec(uuid("D130D9CA-E08A-440e-9DDD-FFE604B2D91B")) IsmAuto::IComponentProteusSP2;
struct __declspec(uuid("A555A381-5D56-4fb0-B09A-73D7579C24DC")) IsmAuto::IComponentIxtapa;
struct __declspec(uuid("18DB88B2-15E8-4ad5-89F2-18663BF6252E")) IsmAuto::IComponentIndore;
struct __declspec(uuid("B2B542CE-1DD1-47B3-B5C5-A631F9786CAB")) IsmAuto::IComponents;
struct __declspec(uuid("6B6405EC-DAFA-49b2-822F-12948266B475")) IsmAuto::IComponentsIronwood;
struct __declspec(uuid("FEB87AF1-2D25-47A9-A21B-33FCBF74D373")) IsmAuto::IComponentChild;
struct __declspec(uuid("E9B81729-9461-4184-9AA9-3C2AE3105173")) IsmAuto::IISComponentExtended;
struct __declspec(uuid("3A55B523-54B5-4AB2-95AF-B747EC01726F")) IsmAuto::IISComponentExtendeds;
struct __declspec(uuid("3E7A5463-E5B9-4B30-8405-DE966C9ECC60")) IsmAuto::ILightComponentEntry;
struct __declspec(uuid("91E07862-BABD-44ff-8D88-72F7CA75C7B5")) IsmAuto::ILightComponentEntryIndore;
struct __declspec(uuid("D21F71A3-FCC0-4272-BA31-801FDA5B242E")) IsmAuto::ILightComponent;
struct __declspec(uuid("9A5AB5E0-43DE-45b0-80F9-8EF6C0F3D871")) IsmAuto::ILightComponentIndore;
struct __declspec(uuid("8139FFFE-C31E-4098-AD03-E1EE217BD12A")) IsmAuto::ICondition;
struct __declspec(uuid("57226CB2-FBEC-4434-8ECB-8927FDD8326D")) IsmAuto::IConditions;
struct __declspec(uuid("33F9027C-5F6B-4D41-B8AD-9BD4ECDEAAA5")) IsmAuto::ICreateFolder;
struct __declspec(uuid("78E15B00-C6D3-4540-B7F6-356235F33FBB")) IsmAuto::ICreateFolderIndoreSP1;
struct __declspec(uuid("6C60AFA6-8E60-46FE-B7CD-34ABEBC4040B")) IsmAuto::ICreateFolders;
struct __declspec(uuid("4531C59F-8AC0-4748-A9FF-7EE73FA48DFF")) IsmAuto::ICustomAction;
struct __declspec(uuid("84EB0B81-339D-4DD4-A324-053DFCAB7D30")) IsmAuto::ICustomAction2;
struct __declspec(uuid("35269922-4873-4045-9204-A30801C035BE")) IsmAuto::ICustomActionProteus;
struct __declspec(uuid("906A901E-284B-4999-9619-6BCC5F9FBCD9")) IsmAuto::ICustomActions;
struct __declspec(uuid("8905CCDF-8B57-4226-A9E6-003F12349817")) IsmAuto::IISInstallScriptAction;
struct __declspec(uuid("CE2A9E06-4E78-46B6-BD8B-1857CED029DD")) IsmAuto::IISDLLWrapper;
struct __declspec(uuid("B0ABF882-D3C5-410C-BD08-8046397373D8")) IsmAuto::IISDLLWrappers;
struct __declspec(uuid("1F670D5A-19F6-498E-814E-3B9E82DBA5E4")) IsmAuto::IISInstallScriptActions;
struct __declspec(uuid("8C37740E-99BE-4DE6-92DB-FCCD91B3ECA5")) IsmAuto::IDialog;
struct __declspec(uuid("53DC9382-52BB-49B3-88B2-2F4CE7D8C673")) IsmAuto::IDialog2;
struct __declspec(uuid("53DC9383-52BB-49B3-88B2-2F4CE7D8C673")) IsmAuto::IDialogNeptune;
struct __declspec(uuid("E319902D-2B57-446b-86A4-86049AB89FBE")) IsmAuto::IDialogIxtapa;
struct __declspec(uuid("677D7B1E-508B-45bd-8048-5793326FAD10")) IsmAuto::IDialogJustice;
struct __declspec(uuid("AB3DFD17-A9BD-4413-944E-368C284F3B95")) IsmAuto::IDialogLoyalty;
struct __declspec(uuid("4E5D6F25-E886-4AD6-AE59-09392735F10B")) IsmAuto::IDialogs;
struct __declspec(uuid("BA76920C-0A01-4D26-A968-749081247B41")) IsmAuto::IControl;
struct __declspec(uuid("A39D62E2-10BD-487F-A480-1814B4DBC0C7")) IsmAuto::IControl2;
struct __declspec(uuid("A39D62F2-10BD-487F-A480-1814B4DBC0C7")) IsmAuto::IControlNeptune;
struct __declspec(uuid("F829BF91-7539-4d85-A3DA-1632E2A1BBF5")) IsmAuto::IControlMajesty;
struct __declspec(uuid("236EC4F7-C3B7-416C-9C4F-C12B59A7ED21")) IsmAuto::IControls;
struct __declspec(uuid("B233E984-CB3C-4FD9-9371-4532C28FDAE5")) IsmAuto::IControlCondition;
struct __declspec(uuid("F03EF9B8-90FF-4C03-9D0A-40D81A6A0856")) IsmAuto::IControlConditions;
struct __declspec(uuid("CEB55130-204D-4099-82C6-21239A3EB83C")) IsmAuto::IControlEvent;
struct __declspec(uuid("A2F834B6-D79D-471A-A8C1-F0735B50C15C")) IsmAuto::IControlEvents;
struct __declspec(uuid("98DF263B-C96B-4062-A025-33A173868092")) IsmAuto::IEventMapping;
struct __declspec(uuid("B7A61A52-B1DD-4046-B56E-DA32CD936B9D")) IsmAuto::IEventMappings;
struct __declspec(uuid("BB289B02-E37D-47D9-823C-26CE36FEA11C")) IsmAuto::ICheckBox;
struct __declspec(uuid("530C9C74-DAA2-4A08-B113-E34BFF67FD61")) IsmAuto::ICheckBox2;
struct __declspec(uuid("373F7BEC-09D5-47B4-9DA2-3EE1F93910F9")) IsmAuto::ICheckBoxes;
struct __declspec(uuid("CFBA3FE6-6F28-4CC5-A9C2-40733D5ADEC1")) IsmAuto::IComboBox;
struct __declspec(uuid("472FEACB-7E03-486C-A173-C41BC56D6C74")) IsmAuto::IComboBox2;
struct __declspec(uuid("288BD6E2-361E-4BC6-8DFA-A84CB7D0830F")) IsmAuto::IComboBoxRow;
struct __declspec(uuid("63D1ACF6-D901-4B48-8F5B-E882D4896E3D")) IsmAuto::IComboBoxes;
struct __declspec(uuid("531A6C2C-6642-40E3-8433-49CD01917695")) IsmAuto::IComboBoxRows;
struct __declspec(uuid("D5920E5E-4909-47B4-B90A-B1F23C1635C4")) IsmAuto::IListBox;
struct __declspec(uuid("F2218550-DE48-4C40-A482-492F5C9C7054")) IsmAuto::IListBox2;
struct __declspec(uuid("956FBE78-BA6F-4C3C-BFC8-72565A07171B")) IsmAuto::IListBoxRow;
struct __declspec(uuid("4A91563C-34AC-46A9-BF44-E86E236D5AF0")) IsmAuto::IListBoxes;
struct __declspec(uuid("D70E6CA0-41CD-404C-B94B-6B015A81C6A8")) IsmAuto::IListBoxRows;
struct __declspec(uuid("C9DB6820-411A-48E2-AFCF-02DF46915E8E")) IsmAuto::IListView;
struct __declspec(uuid("470890BD-5181-4F38-AC85-9D808C95E7BD")) IsmAuto::IListView2;
struct __declspec(uuid("CB54DAD8-11D8-41BA-B90C-4EE434BBB825")) IsmAuto::IListViewRow;
struct __declspec(uuid("4860E504-9A80-47E4-B3C6-44DE8DC55B21")) IsmAuto::IListViewRow2;
struct __declspec(uuid("CC37C2A0-DBCE-4AA3-A8A7-396CD3C7547F")) IsmAuto::IListViews;
struct __declspec(uuid("FA6E5083-5F5E-4766-AE56-7F457EE7F133")) IsmAuto::IListViewRows;
struct __declspec(uuid("ACC0FD0C-6367-4B0F-8029-10174F9D3A73")) IsmAuto::IRadioButtonRows;
struct __declspec(uuid("7AF70A23-6DA9-4718-B3B3-2D4BFA5E9041")) IsmAuto::IRadioButtonRow;
struct __declspec(uuid("561D5A89-CA78-4d0b-8086-0FE05BBF0474")) IsmAuto::IRadioButtonRowNeptune;
struct __declspec(uuid("074C87DB-C605-45D5-AC32-DC16B1E0D794")) IsmAuto::IRadioButton;
struct __declspec(uuid("49D9528E-517E-464D-AA5D-67743B2DF725")) IsmAuto::IRadioButton2;
struct __declspec(uuid("686D010E-C12E-494c-8865-A374C7B7CD27")) IsmAuto::IRadioButtonNeptune;
struct __declspec(uuid("C58029AA-00DA-427A-AFEA-96495A416FA2")) IsmAuto::IRadioButtons;
struct __declspec(uuid("3B955C30-E417-4415-A0F3-D42EA87F2C95")) IsmAuto::IRadioButtons2;
struct __declspec(uuid("5BB71D2D-CD0A-485B-A7B8-428E4A82522C")) IsmAuto::IDirectory;
struct __declspec(uuid("B485B235-FA16-45A9-8295-4C96D1C9B0F0")) IsmAuto::IDirectory2;
struct __declspec(uuid("EEC31244-95D2-4b7f-BEE8-583FE4155553")) IsmAuto::IDirectoryJustice;
struct __declspec(uuid("95AA7CD6-AAE0-4926-9A1A-9ED5BE92DDA6")) IsmAuto::IDirectoryOpus;
struct __declspec(uuid("E24A7EE1-E8E4-41DD-98D4-00ED3B16A5C5")) IsmAuto::IDirectoryQi;
struct __declspec(uuid("AAAA61FE-C5FE-4C20-8A6F-19DE319F5BBE")) IsmAuto::IDirectories;
struct __declspec(uuid("34DA3704-8495-457F-8FC0-264639F47A62")) IsmAuto::IEnvironment;
struct __declspec(uuid("A3E1444B-991E-43da-BE37-0916123EE715")) IsmAuto::IEnvironmentIbiza;
struct __declspec(uuid("348486F1-A1D0-4B53-8DB8-CD8BB26237D5")) IsmAuto::IEnvironments;
struct __declspec(uuid("93C08895-6995-4701-8118-A70C14E84FEC")) IsmAuto::IError;
struct __declspec(uuid("2CE58F62-323F-48D4-83A1-86EE2E6D937D")) IsmAuto::IErrors;
struct __declspec(uuid("4194F818-74BC-4106-ACD9-A622AA380D16")) IsmAuto::IFeature;
struct __declspec(uuid("C84D2B51-C44F-4416-9B76-DE6F7DBD4091")) IsmAuto::ICallbackModuleAdd;
struct __declspec(uuid("3D21D876-6FD9-4532-8225-25E232BAD849")) IsmAuto::IFeature2;
struct __declspec(uuid("CA6831AA-8F86-4EA1-8132-AE512D56101D")) IsmAuto::IFeatureNeptune;
struct __declspec(uuid("590C32B2-3082-402c-8767-5D17C698F364")) IsmAuto::IFeaturePluto;
struct __declspec(uuid("80FDFACD-6476-43C8-9DDC-99052E186C52")) IsmAuto::IFeatures;
struct __declspec(uuid("3099553D-F59B-4FB1-94B4-81999DFD77B2")) IsmAuto::IISFeatureExtended;
struct __declspec(uuid("4A87A43A-DE99-429B-B2C2-679787B01B29")) IsmAuto::IISFeatureExtendeds;
struct __declspec(uuid("2AD4895F-74AC-47FB-8736-05B9186D42C9")) IsmAuto::IISRequiredFeature;
struct __declspec(uuid("CAFFF1C1-2ABE-4676-A710-5A8C2B6AD647")) IsmAuto::IISRequiredFeatures;
struct __declspec(uuid("5BF3F7B9-D0A8-4240-85E1-062339393D03")) IsmAuto::IFile;
struct __declspec(uuid("48FBCC92-B566-42DF-B382-B8863CD712FC")) IsmAuto::IFile2;
struct __declspec(uuid("FF77D7DE-510B-406e-BA9C-A0F24F1A91F8")) IsmAuto::IFileNeptune;
struct __declspec(uuid("F54E4B27-47C2-4617-8ED2-1E3993B50167")) IsmAuto::IFileNeptunePDC;
struct __declspec(uuid("A3023C7D-4B40-4164-82FE-697031A3A33B")) IsmAuto::IFileProteusSP;
struct __declspec(uuid("aa97da8e-eff5-4d84-a330-1028ecf5585e")) IsmAuto::IFileIxtapa;
struct __declspec(uuid("F33FD392-CF2B-4dc5-8C90-04D2E8580E58")) IsmAuto::IFileIndoreSP1;
struct __declspec(uuid("E4983EE2-9E20-45A4-8F2D-F346EA1255A2")) IsmAuto::IFiles;
struct __declspec(uuid("BB649237-D984-452A-A8EC-8AB5D6ABF2CD")) IsmAuto::IFileEvent;
struct __declspec(uuid("F737BEC7-EAC2-40e0-B799-CB9E9CF952B7")) IsmAuto::IFileEventNeptune;
struct __declspec(uuid("515FB43B-A713-4E3C-A15D-6D114F3A62EE")) IsmAuto::IFileHeader;
struct __declspec(uuid("50AE6A49-CC5A-4289-A027-38007E99AAD3")) IsmAuto::IFileHeader2;
struct __declspec(uuid("2E99B996-93F4-417E-8AF3-82855F80C506")) IsmAuto::IFileHeaderEx;
struct __declspec(uuid("65D361B6-4A8E-440d-BC49-D6BCA7F5BE55")) IsmAuto::IFileHeaderJustice;
struct __declspec(uuid("958F8810-C99B-4d13-872A-FC3125685B12")) IsmAuto::IFileHeaderExJustice;
struct __declspec(uuid("13764C5A-12E5-485F-821A-ED882BA7D0C3")) IsmAuto::IFileLinking;
struct __declspec(uuid("9AAA1D41-8787-451D-85B9-CE20FC58C1EB")) IsmAuto::IFileLinking2;
struct __declspec(uuid("5429C52F-C871-4FF6-B84E-807E337EC2EE")) IsmAuto::IFileLinkingJustice;
struct __declspec(uuid("8818B33C-76DE-4798-9FAD-FD5D02FF96F4")) IsmAuto::IFileLinkings;
struct __declspec(uuid("4F5DE8B0-6DDB-4524-AE14-6F95290195C5")) IsmAuto::IISSelfReg;
struct __declspec(uuid("CDE6903B-66B0-4B4D-A344-5CE4441A4A09")) IsmAuto::IISSelfRegs;
struct __declspec(uuid("2779991D-B7D9-4CA3-86A4-29CA1639303D")) IsmAuto::ILightFileEntry;
struct __declspec(uuid("76EB6EFD-7C78-4C7A-A39A-B86D55E87687")) IsmAuto::ILightFile;
struct __declspec(uuid("DEA13FED-094B-4384-8F4D-29CA7518177B")) IsmAuto::IFileExtension;
struct __declspec(uuid("7B16B0C9-72C9-4CA5-B2E3-6251F73083CD")) IsmAuto::IFileExtension2;
struct __declspec(uuid("2A4196CA-D049-40FC-A715-359F49B49EAB")) IsmAuto::IFileExtensions;
struct __declspec(uuid("5A6C863D-4C23-4C19-B7E2-602892788E4F")) IsmAuto::IFileExtensionVerb;
struct __declspec(uuid("5747B57F-8B4B-4b3a-804C-8FB97A212E5E")) IsmAuto::IFileExtensionVerbIndoreSP1;
struct __declspec(uuid("2D01F79D-CF2C-4810-AC8E-6D7C0996AAB9")) IsmAuto::IFileExtensionVerbs;
struct __declspec(uuid("15C24EDB-B0BA-4525-AF78-1C023F0614A6")) IsmAuto::IMIMEType;
struct __declspec(uuid("619696BE-8D12-4E43-9C02-A22E3FE0AA0D")) IsmAuto::IMIMETypes;
struct __declspec(uuid("E938889E-E222-4454-B846-6360DB3FC343")) IsmAuto::IProgID;
struct __declspec(uuid("3254FBE6-5B71-4AC9-9F77-74FA5862112F")) IsmAuto::IProgID2;
struct __declspec(uuid("5D782E41-34A1-4C87-88B5-1F27037AF305")) IsmAuto::IProgIDs;
struct __declspec(uuid("C767FC09-154C-4089-83E0-54847A7E5B6B")) IsmAuto::IFileUtil;
struct __declspec(uuid("4C253E72-321F-43C3-86CD-FF7E6A13B4DC")) IsmAuto::IFont;
struct __declspec(uuid("8CDAC856-21F1-41EA-A453-B688280D2D1E")) IsmAuto::IFonts;
struct __declspec(uuid("81A24503-F85E-4666-BBB4-C187835CA529")) IsmAuto::IIcon;
struct __declspec(uuid("27295EC5-9BBD-49CC-8EC0-B79BEA3B58D3")) IsmAuto::IIcon2;
struct __declspec(uuid("904F3D2A-2F7F-4A31-94E7-7E8DC9B9A16C")) IsmAuto::IIcons;
struct __declspec(uuid("DD661A1B-D809-4132-BCC3-D21878923171")) IsmAuto::IFlatIniFile;
struct __declspec(uuid("C7D92D2D-4BDA-4A70-86F9-CC6879DEBE98")) IsmAuto::IFlatIniFiles;
struct __declspec(uuid("CA2D2DDE-4C85-4AF1-B9FA-2A8B3FC19F33")) IsmAuto::IIniFile;
struct __declspec(uuid("A394B89B-CAC4-421C-9D38-5FAC087CE012")) IsmAuto::IIniFiles;
struct __declspec(uuid("F28DBC62-1353-4C48-8E37-7D96E95622AC")) IsmAuto::IIniSection;
struct __declspec(uuid("70D8FA1B-FA39-47B6-9E22-77F4E160B1F0")) IsmAuto::IIniSections;
struct __declspec(uuid("A8F23209-81A3-4963-A7E2-DA4D90E2EA8A")) IsmAuto::IIniEntry;
struct __declspec(uuid("03C6B837-497F-4BAD-ADCB-149CEF2BB5C4")) IsmAuto::IIniEntries;
struct __declspec(uuid("17BDC79A-506D-4855-BE14-7679734907A0")) IsmAuto::ILightINIEntry;
struct __declspec(uuid("18EADE22-5726-404B-83C4-E552FE473794")) IsmAuto::ILightINI;
struct __declspec(uuid("C01E2CC2-91C5-4DEE-B5FD-B2EA0F3E9CAC")) IsmAuto::IISDependency;
struct __declspec(uuid("8894F5BA-01CF-411D-8ACD-DF2D8A52E70B")) IsmAuto::IISDependencies;
struct __declspec(uuid("93CFA494-DEF5-48A1-8271-BCE8536D9EB1")) IsmAuto::IRegistryFileImporterEvents;
struct __declspec(uuid("4DA6F9DB-FCE7-49DB-82D2-C5F579281426")) IsmAuto::IRegistryFileImporterEvents2;
struct __declspec(uuid("F49B6CF0-DAE5-49F0-A4A3-4F7DDB3A9AE1")) IsmAuto::IRegistryFileImporter;
struct __declspec(uuid("F49B6CF1-DAE5-49F0-A4A3-4F7DDB3A9AE1")) IsmAuto::IRegistryFileImporterPro;
struct __declspec(uuid("2C93F3D0-C8B1-40F3-A498-4D0344430FD7")) IsmAuto::ICustomActionEvents;
struct __declspec(uuid("5CCC7DAE-4171-45D5-B03E-1CEC947DF98A")) IsmAuto::ICustomActionEvents2;
struct __declspec(uuid("B1CF6EA0-E781-48E3-B86C-02609C8DB907")) IsmAuto::IIsmAutoStringTableEvents;
struct __declspec(uuid("4C34D7DE-B25B-435F-8A55-63AB5862F19A")) IsmAuto::ILanguage;
struct __declspec(uuid("3B4EE170-B291-4861-9292-97B27DC4040B")) IsmAuto::ILanguage2;
struct __declspec(uuid("C043013F-40FD-4993-A5A6-0DF9F91C866C")) IsmAuto::ILanguageNeptune;
struct __declspec(uuid("F5255AB5-56FA-42A6-BCD6-0D0CEFCE77F6")) IsmAuto::ILanguageLoyalty;
struct __declspec(uuid("575C2C45-7487-40e1-8769-0BBE2174C502")) IsmAuto::ILanguageJack;
struct __declspec(uuid("C97A4DB7-EFC5-4F99-98E5-AE2D39AA4CE7")) IsmAuto::ILanguages;
struct __declspec(uuid("A504AC91-33D1-46B4-B3FA-6BAD82F7A914")) IsmAuto::ILaunchCondition;
struct __declspec(uuid("C9AEE86A-C796-4D2A-B850-6D77B7999F52")) IsmAuto::ILaunchConditions;
struct __declspec(uuid("EA7461F6-61CC-4D43-B02F-40BA3745DD8D")) IsmAuto::ILockPermission;
struct __declspec(uuid("A04C267F-B16E-4476-B925-C5300A6CF821")) IsmAuto::ILockPermissions;
struct __declspec(uuid("F30B81B2-B62A-4ca8-AF05-C23BE3656C18")) IsmAuto::IISLockPermission;
struct __declspec(uuid("FDAC1793-71A7-490a-9283-2C1F94AAE986")) IsmAuto::IISLockPermissions;
struct __declspec(uuid("78FD7E6C-F49D-46ED-9CBD-CB1FBDB58C6E")) IsmAuto::IMedia;
struct __declspec(uuid("DF57DFA6-9CE6-4B01-AB88-B7517DA593F3")) IsmAuto::IMedias;
struct __declspec(uuid("3CDFA53B-1E40-49A9-AB54-EF84612C9A40")) IsmAuto::IMergeModuleCfgValue;
struct __declspec(uuid("6632F233-A853-4ACA-9E31-DF424A1AB86F")) IsmAuto::IMergeModuleCfgValues;
struct __declspec(uuid("4F0E756F-1AE5-4D89-8BFB-10F61797F854")) IsmAuto::IMergeModule;
struct __declspec(uuid("08FDD9F0-F3C4-4490-AB94-E70F82C02827")) IsmAuto::IMergeModule2;
struct __declspec(uuid("55725EC2-5C85-41C4-B6F1-D0C5E2BEE297")) IsmAuto::IMergeModule3;
struct __declspec(uuid("766FACDF-462E-409e-9EAB-EEE963D3852C")) IsmAuto::IMergeModuleProteus;
struct __declspec(uuid("AF4246BE-8470-4689-827A-77D1BBF439F6")) IsmAuto::IMergeModuleEx;
struct __declspec(uuid("AF825DCE-ACB7-405A-8B9F-645BFA369AE8")) IsmAuto::IMergeModules;
struct __declspec(uuid("9C8B5A55-7278-448C-A211-1CDD1A48A3A7")) IsmAuto::IMMAuthoring;
struct __declspec(uuid("48F9CC6D-55D3-4938-BC9F-48B2A7F80B9A")) IsmAuto::IMMAuthoringDependency;
struct __declspec(uuid("4DEEBC00-E0B1-42A1-8A5F-ED9D1BD5684D")) IsmAuto::IMMAuthoringDependencies;
struct __declspec(uuid("BBFD2629-6265-48E5-8CFE-C12A0577A80C")) IsmAuto::IMMAuthoringExclusion;
struct __declspec(uuid("A50722FB-AD4E-4657-8B48-85D844DB9115")) IsmAuto::IMMAuthoringExclusions;
struct __declspec(uuid("CC557EBC-1552-4C38-A792-ABA5BF969C99")) IsmAuto::IMMAuthoringModuleComponent;
struct __declspec(uuid("362452FC-16FE-4CF1-BCB9-828784EF6997")) IsmAuto::IMMAuthoringModuleComponents;
struct __declspec(uuid("2A8E51A4-A0B0-442C-A1C0-B802A54812C3")) IsmAuto::IISObjectProperty;
struct __declspec(uuid("0C790869-307E-4952-9049-97ACC8446859")) IsmAuto::IISObjectProperties;
struct __declspec(uuid("E07804F3-8E39-41DF-ABE8-5A39EC10848D")) IsmAuto::IISObject;
struct __declspec(uuid("8659497C-DF15-4EB9-BB22-0754ADDDFFEF")) IsmAuto::IISObjects;
struct __declspec(uuid("66DBA821-DF24-40AB-AD69-6C0858B9A0FE")) IsmAuto::IMMCustomAction;
struct __declspec(uuid("89D2F34A-15E5-48DF-B46D-B717C7653E67")) IsmAuto::IMMCustomActions;
struct __declspec(uuid("1FE92C96-216B-4B0D-AE94-62333D80F1AA")) IsmAuto::IMMDialog;
struct __declspec(uuid("99D66410-B37C-47FC-8C68-CF209875F5F7")) IsmAuto::IMMDialogs;
struct __declspec(uuid("441E8C3B-1899-47A8-BD7C-3634DA37FEF1")) IsmAuto::IMsiAssemblyName;
struct __declspec(uuid("8D1B8D29-2FA3-4456-9410-10B96E1C9A01")) IsmAuto::IMsiAssemblyNames;
struct __declspec(uuid("EDF417AE-6AF7-48BB-8917-CE8CD7055834")) IsmAuto::IMsiAssembly;
struct __declspec(uuid("E2EC3324-D46E-4458-89F0-31D3F6E64B4F")) IsmAuto::IMultiSelectNeptune;
struct __declspec(uuid("3925EA9B-14E5-48A8-9DE4-9C8699B1B9B1")) IsmAuto::IODBCDataSource;
struct __declspec(uuid("73712D72-AC72-420C-B3BB-B8B26EB7662F")) IsmAuto::IODBCDataSource2;
struct __declspec(uuid("659821AC-3BD5-46FD-ADFE-4923E28E6678")) IsmAuto::IODBCDataSources;
struct __declspec(uuid("A8F79DAD-6A00-48D2-9961-914DF2BAB7C6")) IsmAuto::IODBCDataSourceAttribute;
struct __declspec(uuid("11B3931C-EF17-4E56-9761-6A5A84B2630F")) IsmAuto::IODBCDataSourceAttribute2;
struct __declspec(uuid("780C7505-E177-4398-8D81-3C3A89374173")) IsmAuto::IODBCDataSourceAttributes;
struct __declspec(uuid("7ABE38E9-67A9-401F-904A-4E8B91F19FFA")) IsmAuto::IODBCDriver;
struct __declspec(uuid("7EC4EC1E-D9AC-4094-B2DF-0AC2B18897D6")) IsmAuto::IODBCDriver2;
struct __declspec(uuid("2129BD12-BFE6-486E-9A5A-35ABEE1333E8")) IsmAuto::IODBCDrivers;
struct __declspec(uuid("FD424C5D-B810-49E0-8A9D-6E989F90B59D")) IsmAuto::IODBCAttribute;
struct __declspec(uuid("DE052204-5C99-4699-BC7C-B7E4A54EF74D")) IsmAuto::IODBCAttribute2;
struct __declspec(uuid("311E234E-8E27-466E-BE6D-CBD303862382")) IsmAuto::IODBCAttributes;
struct __declspec(uuid("AFDFA125-F989-44DF-B1A1-7212B25C9B6F")) IsmAuto::IODBCGeneric;
struct __declspec(uuid("972B3571-CF95-4A73-AF20-0DF44C8067FC")) IsmAuto::IODBCGenericAttribute;
struct __declspec(uuid("EA770C34-DCCD-422D-9045-6225BAED9601")) IsmAuto::IODBCGenericAttributes;
struct __declspec(uuid("C872F340-A882-442F-8FE8-E6541A01509E")) IsmAuto::IODBCTranslator;
struct __declspec(uuid("F4E38135-8532-4B70-9014-3B9CEF273D6B")) IsmAuto::IODBCTranslator2;
struct __declspec(uuid("C829BDC3-DCA2-49DE-9747-19D969B98E6E")) IsmAuto::IODBCTranslators;
struct __declspec(uuid("5C10C548-2B35-4EA0-8FF8-14FB01B7B259")) IsmAuto::IPatchExternalFile;
struct __declspec(uuid("236C28B8-7604-4939-B84B-AF6945DC2288")) IsmAuto::IPatchExternalFiles;
struct __declspec(uuid("AD0F330B-1B89-4AF1-AF9D-E99DAAB3DF69")) IsmAuto::IPatchWholeFile;
struct __declspec(uuid("FE56F5A3-50EC-4267-B52A-0ED0FC62466D")) IsmAuto::IPatchWholeFiles;
struct __declspec(uuid("40B8BF0E-6FEC-4C97-BC6B-659D8BA6053A")) IsmAuto::ITargetImage;
struct __declspec(uuid("6054CB1E-FA03-49AF-BB2D-879586F09876")) IsmAuto::ITargetImages;
struct __declspec(uuid("72BC5A54-A43C-4948-BAA1-129661631D76")) IsmAuto::IUpgradedImage;
struct __declspec(uuid("C8D86F58-FFF6-41E9-BFF8-9960DB298310")) IsmAuto::IUpgradedImages;
struct __declspec(uuid("90D2B8F0-4EE0-4841-BE4B-93FA8F239112")) IsmAuto::IPatchConfiguration;
struct __declspec(uuid("60CD3F4B-2CE9-4760-928C-6EEB1DC38439")) IsmAuto::IPatchConfigurationNeptunePDC;
struct __declspec(uuid("60CD3F4C-2CE9-4760-928C-6EEB1DC38439")) IsmAuto::IPatchConfigurationProteus;
struct __declspec(uuid("60CD3F4D-2CE9-4760-928C-6EEB1DC38439")) IsmAuto::IPatchConfigurationProteusSP;
struct __declspec(uuid("60CD3F4E-2CE9-4760-928C-6EEB1DC38439")) IsmAuto::IPatchConfigurationPluto;
struct __declspec(uuid("976AC200-0967-496a-BFE6-D0431A044159")) IsmAuto::IPatchConfigurationIbiza;
struct __declspec(uuid("BA2FCA47-B01D-49D3-8B54-F5D1FE29B0E0")) IsmAuto::IPatchConfigurationJustice;
struct __declspec(uuid("CBBD692B-FFD7-4D77-9F2D-518DFC5B6006")) IsmAuto::IPatchConfigurationMajesty;
struct __declspec(uuid("4F4435E5-8092-4C39-A443-202E9CA9A376")) IsmAuto::IPatchConfigurationQi;
struct __declspec(uuid("D1BE89C1-56A4-4618-8554-E179528CA897")) IsmAuto::IPatchConfigurationRipley;
struct __declspec(uuid("228D6FAC-CDB3-4B97-A632-BB48533E9019")) IsmAuto::IPatchConfigurations;
struct __declspec(uuid("CB522942-1411-489F-A0AC-5320E099DEEB")) IsmAuto::IPathRecommendation;
struct __declspec(uuid("9038321E-4A0C-4ACB-958C-3C1B6D7AC372")) IsmAuto::IPathRecommendations;
struct __declspec(uuid("3DB92FAC-2AA9-4A99-BB5A-61F8714450CE")) IsmAuto::IPathConvertEvent;
struct __declspec(uuid("0BA82B2E-46EA-444C-9197-842D6E2E6089")) IsmAuto::IPathVariableSet;
struct __declspec(uuid("0AB5889A-A920-4774-8BD8-2C0DEDE7F372")) IsmAuto::IPathVariableSets;
struct __declspec(uuid("51199E00-BF3E-4A26-8F11-3B0E816DA39E")) IsmAuto::IPathVariable;
struct __declspec(uuid("DDF039EA-26CA-4EA6-BA3F-759AE3907896")) IsmAuto::IPathVariable2;
struct __declspec(uuid("445DA070-6BDC-4448-B97E-2477AB389FE6")) IsmAuto::IPathVariables;
struct __declspec(uuid("54907E9E-E506-4E80-AA9C-0329803C06C1")) IsmAuto::IProduct;
struct __declspec(uuid("013185A5-B7A9-4E71-9285-7769240E1883")) IsmAuto::IProduct2;
struct __declspec(uuid("434FFF60-0530-491B-9A7B-A62F7764CBF2")) IsmAuto::IProducts;
struct __declspec(uuid("F5819E3D-5612-4AB7-A5C6-72F15546D01F")) IsmAuto::IISStorage;
struct __declspec(uuid("950B09D8-398C-4E4C-8988-7B1C29E53D5E")) IsmAuto::IISStorages;
struct __declspec(uuid("1C5E56A5-F9DD-4ED1-AE73-0E9F04F7654D")) IsmAuto::IISAlias;
struct __declspec(uuid("F5C1AE93-05B9-4C8B-8D51-A4050706ED1E")) IsmAuto::IISAliases;
struct __declspec(uuid("06A9882A-CF3A-46B3-BECD-628C7F353945")) IsmAuto::IISDisk1File;
struct __declspec(uuid("4D7693EE-7856-48B0-9926-6E8D28CC358D")) IsmAuto::IISDisk1Files;
struct __declspec(uuid("3479361C-EC4E-4501-AEC0-F73758DDF9AF")) IsmAuto::IProjectRoot;
struct __declspec(uuid("3BAD3800-5621-42C4-B995-B9F7AC6783B1")) IsmAuto::IProjectRoot2;
struct __declspec(uuid("8D6FC627-96E7-4D4E-882B-15A509442916")) IsmAuto::IProjectRootNeptune;
struct __declspec(uuid("B6747B2D-6BCA-4377-A1DF-AFEA661BBE60")) IsmAuto::IProjectEvents;
struct __declspec(uuid("AE9A3012-E2E6-4B1D-A0F4-619A11E0E9DD")) IsmAuto::IProjectEvents2;
struct __declspec(uuid("6E35D5A4-850D-4F2F-B4F5-C2290B898D91")) IsmAuto::IProjectProgressEvents;
struct __declspec(uuid("84DE63D4-7CCE-4C0D-AD4B-91E68A5A24CD")) IsmAuto::IProject;
struct __declspec(uuid("9C9C6084-6739-4106-858D-A8F569C84182")) IsmAuto::IProject2;
struct __declspec(uuid("9A7D13E1-4186-49FB-B921-68E7FDEB4BD0")) IsmAuto::IProjectNeptune;
struct __declspec(uuid("2D28AB53-D0F6-4998-8B6D-D67431A0ED2A")) IsmAuto::IProjectProteus;
struct __declspec(uuid("E18AF54F-DA53-4d8e-9FB0-95F3E4FEF3B4")) IsmAuto::IProjectIbiza;
struct __declspec(uuid("956fcf2d-7fe1-4750-b83e-1a8708cadd60")) IsmAuto::IProjectIxtapa;
struct __declspec(uuid("DC938885-B11D-4f5b-9603-A5714B4929EF")) IsmAuto::IProjectJustice;
struct __declspec(uuid("EE46FB90-7567-4dd6-BEB6-FE2E5FF629EC")) IsmAuto::IProjectJade;
struct __declspec(uuid("86A5410B-2BDF-41bc-80F9-6A18C5604280")) IsmAuto::IProjectMajesty;
struct __declspec(uuid("54F2D788-4FEB-418a-BEAA-3E3F71F314AD")) IsmAuto::IProjectNeo;
struct __declspec(uuid("045DBE89-1017-41F1-B23B-5529CC8B8D16")) IsmAuto::IProperty;
struct __declspec(uuid("CE62DAEE-B4F0-47a0-B3EF-C001B7B742A8")) IsmAuto::IPropertyJustice;
struct __declspec(uuid("57E9026E-3E39-46E7-9D23-C1F1530E69AD")) IsmAuto::IProperties;
struct __declspec(uuid("A1B33373-841C-4DBC-AC70-F47AAC243F2A")) IsmAuto::IPubCompQualifier;
struct __declspec(uuid("8CDB28FF-3C3D-4B8C-8C0D-8B20243BEFB5")) IsmAuto::IPubCompQualifier2;
struct __declspec(uuid("74572BB3-8E53-45F6-B381-443A8A203A16")) IsmAuto::IPubCompQualifiers;
struct __declspec(uuid("C70DF956-6DF8-44E0-900B-606E6182150F")) IsmAuto::IPubComp;
struct __declspec(uuid("6D1EA750-2830-4A63-9C2F-4602CEBE3C20")) IsmAuto::IPubComps;
struct __declspec(uuid("0F7AC22B-16A0-450A-A23A-B2266E301131")) IsmAuto::IQPRegistryValue;
struct __declspec(uuid("A4C5452C-4254-47D7-9FD0-22934CFA7C40")) IsmAuto::IQPRegistryValues;
struct __declspec(uuid("EF4724E1-C8DA-4166-ADA4-4C1DE3F74EB9")) IsmAuto::IQPRegistryKey;
struct __declspec(uuid("94C87E74-2915-4523-96A1-D7796346A3C6")) IsmAuto::IRegistryKeyIbiza;
struct __declspec(uuid("73FDF5F2-4868-4112-9651-4C5D2049F107")) IsmAuto::IQPRegistryKeys;
struct __declspec(uuid("D6F4A3D3-5C24-4FB6-94BD-C67CFAFB5A8B")) IsmAuto::IQPProperty;
struct __declspec(uuid("18100A2B-FCDE-4155-8A06-31AD61A09CB8")) IsmAuto::IQPProperties;
struct __declspec(uuid("E5115E57-42A2-4ADE-AD93-00451F87ADD7")) IsmAuto::IQPFile;
struct __declspec(uuid("905AF75F-3FD0-4574-BB70-1085A4B7E678")) IsmAuto::IQPFiles;
struct __declspec(uuid("91AA5888-E9B8-42A6-9F19-8D169A871640")) IsmAuto::IQPExcludedPackage;
struct __declspec(uuid("F8C59831-8120-4863-A0A2-C0D09E6CED4C")) IsmAuto::IQPExcludedPackages;
struct __declspec(uuid("365E3D33-6C86-42A7-BA4D-94BB0F009C24")) IsmAuto::IQPRoot;
struct __declspec(uuid("365E3D34-6C86-42A7-BA4D-94BB0F009C24")) IsmAuto::IQPRootProteus;
struct __declspec(uuid("365E3D36-6C86-42A7-BA4D-94BB0F009C24")) IsmAuto::IQPRootProteusSP3;
struct __declspec(uuid("365E3D35-6C86-42A7-BA4D-94BB0F009C24")) IsmAuto::IQPRootPluto;
struct __declspec(uuid("365E3D37-6C86-42A7-BA4D-94BB0F009C24")) IsmAuto::IQPRootJustice;
struct __declspec(uuid("F8A4170D-B5C9-40C0-A831-930B09E3EF93")) IsmAuto::IQPRootMajesty;
struct __declspec(uuid("38308B5C-5B7D-4155-B047-9CBA804B1FE5")) IsmAuto::IQPRootRipley;
struct __declspec(uuid("664F25FD-21F6-4EDF-8B76-3C7CA78C6DE3")) IsmAuto::IRegistryValue;
struct __declspec(uuid("4508C95F-18A9-459D-BE3B-76CDB5E10A9A")) IsmAuto::IRegistryValue2;
struct __declspec(uuid("25E7F21E-DF0D-4327-9BF9-39C7168A75D6")) IsmAuto::IRegistryValueNeptune;
struct __declspec(uuid("7474C192-76B1-4652-9FE2-1D384F6BA141")) IsmAuto::IRegistryValues;
struct __declspec(uuid("EE538B40-9F1A-4EC2-8214-7D1F294E6DA6")) IsmAuto::IRegistryKey;
struct __declspec(uuid("75760525-DD28-4E23-87C9-9336F267440F")) IsmAuto::IRegistryKey2;
struct __declspec(uuid("74A80D90-FC4E-422d-9A70-816411727503")) IsmAuto::IRegistryKeyNeptune;
struct __declspec(uuid("A7C345FF-39F6-4635-ABD6-95054CAF7B55")) IsmAuto::IRegistryKeys;
struct __declspec(uuid("4133B341-3B8E-42B9-838E-48E16DEB7CC2")) IsmAuto::IRegistryEntries;
struct __declspec(uuid("28325CCF-E0F7-4e8a-AD3E-FD9C5EBD7C9D")) IsmAuto::IRegistryEntriesPunk;
struct __declspec(uuid("DA70DDAD-4942-487f-99B0-186FB6579BF1")) IsmAuto::IRegistryEntriesPunkSP;
struct __declspec(uuid("8D85715E-6FAC-47DD-B7E8-2CC76B8D58B4")) IsmAuto::IAppPath;
struct __declspec(uuid("10079B58-11DC-41E4-9692-88ED23678734")) IsmAuto::IAppPaths;
struct __declspec(uuid("2390D0A5-3EBC-4900-9F00-ECBD580614E0")) IsmAuto::ILightRegistryEntry;
struct __declspec(uuid("91A19B09-EC47-4dc3-80AF-74226E5CFB31")) IsmAuto::ILightRegistryEntryJustice;
struct __declspec(uuid("7A7B4DB4-8AD0-4478-B3AF-BB66A0014F2C")) IsmAuto::ILightRegistry;
struct __declspec(uuid("B7DE1F40-F37A-49b3-A77A-9ACBE0B1090B")) IsmAuto::ILightRegistryPunkSP;
struct __declspec(uuid("B2A05148-1E1F-4A43-9DBB-73ACF714D78D")) IsmAuto::IRegistrySetNeptune;
struct __declspec(uuid("5F6F9252-9369-4CFB-B975-234438863C31")) IsmAuto::IRegistrySetsNeptune;
struct __declspec(uuid("AEE5BD67-C66C-4C09-8E39-80F23157C5A8")) IsmAuto::IRelease;
struct __declspec(uuid("F91D23B8-EAD0-46A7-8B03-30D684A32D88")) IsmAuto::IReleases;
struct __declspec(uuid("66B8E81F-8E57-4123-A24B-D4955F9C88F9")) IsmAuto::IRelease2;
struct __declspec(uuid("66B8E820-8E57-4123-A24B-D4955F9C88F9")) IsmAuto::IReleaseNeptune;
struct __declspec(uuid("0FBBF787-27D3-4ca8-8B50-951FFF954086")) IsmAuto::IReleaseProteus;
struct __declspec(uuid("A9055992-D230-48c9-81FB-4AD408FF145B")) IsmAuto::IReleasePluto;
struct __declspec(uuid("2F1BA5EC-FD64-4963-967A-639D1F3CE185")) IsmAuto::IReleaseIxtapa;
struct __declspec(uuid("D29A5DC8-6DCF-42C5-87B9-208438F6EEA3")) IsmAuto::IReleaseIndore;
struct __declspec(uuid("99066988-893F-47f4-A42F-F21AC97AE026")) IsmAuto::IReleaseIronwood;
struct __declspec(uuid("9EB2751D-E867-4255-9A80-8856095A9E64")) IsmAuto::IReleasePublishInfoPluto;
struct __declspec(uuid("C93CBCCD-58CC-4FB1-A066-7938D616A360")) IsmAuto::IPreviousProMediaNeptune;
struct __declspec(uuid("9FA596D2-1717-4AB4-8367-315AA7C76486")) IsmAuto::IPreviousProMediasNeptune;
struct __declspec(uuid("BC2FFB5A-E733-4E95-A3A3-C54A59C9CA50")) IsmAuto::IReleaseReservedSpaceNeptune;
struct __declspec(uuid("DC677749-A6A7-4B27-9B8A-667C751BC1E9")) IsmAuto::IReleaseReservedSpacesNeptune;
struct __declspec(uuid("723E269A-CF47-4856-AE07-596727144D14")) IsmAuto::IReleaseProNeptune;
struct __declspec(uuid("723E269A-CF47-4856-AE07-596727144D14")) IsmAuto::IReleaseProProteus;
struct __declspec(uuid("1574BFB0-8748-4d68-9050-B3AC7E50CEF1")) IsmAuto::IReleaseProPluto;
struct __declspec(uuid("1C31458F-FE6D-4CAE-BAF4-85CC6C9D5064")) IsmAuto::IReleaseProIronwood;
struct __declspec(uuid("C1D72A4E-6D8B-469b-AAB5-BDC99955E12F")) IsmAuto::IReleaseProLoyalty;
struct __declspec(uuid("D99269FB-5EC8-4BA1-92D9-4E38B2374095")) IsmAuto::IRelease3;
struct __declspec(uuid("D6495CB5-C357-48BE-9A96-724E6BEB6D1B")) IsmAuto::IBuildLabel;
struct __declspec(uuid("9A46A34C-4E30-4B01-AEF5-443A8DBB6A06")) IsmAuto::IBuildLabels;
struct __declspec(uuid("44DF3E9F-4A5A-4570-8F7A-FC37E97E1BE3")) IsmAuto::IBuildLabel2;
struct __declspec(uuid("38FCFD83-862D-4151-B891-A57BD47E89C7")) IsmAuto::ILogicalDiskFeature;
struct __declspec(uuid("A4D97165-79FC-4608-9A5F-571EBBBC4870")) IsmAuto::ILogicalDiskFeatures;
struct __declspec(uuid("2E8F5244-8062-4BBA-A616-847792ED570F")) IsmAuto::ILogicalDisk;
struct __declspec(uuid("EAC30682-F34B-4C16-9C33-F8B55B7D68E8")) IsmAuto::ILogicalDisks;
struct __declspec(uuid("4D340FC8-324D-4E7F-B583-6B4CA22B86EB")) IsmAuto::IScriptFile;
struct __declspec(uuid("D3147338-E411-4AA5-9ED0-DC5ACCF77B44")) IsmAuto::IScriptFiles;
struct __declspec(uuid("9AA68CF0-5015-455B-AEA1-A471A09ABAF4")) IsmAuto::ICompilerOption;
struct __declspec(uuid("419433F0-B55C-4112-B85C-5C8B01288FDF")) IsmAuto::ICompilerOption2;
struct __declspec(uuid("7AC844FA-F528-40D4-AE5E-0410523A5F46")) IsmAuto::ICompilerOptionNeptune;
struct __declspec(uuid("1D5A28DD-11CF-4713-8972-23149843A566")) IsmAuto::ICompilerOptionLoyalty;
struct __declspec(uuid("3C8995E8-5D85-4ECE-BEA1-6056F2AA06C1")) IsmAuto::ILinkerOption;
struct __declspec(uuid("170DED61-8CCB-4090-8319-0FD45E1F7795")) IsmAuto::ILinkerOption2;
struct __declspec(uuid("5B2571C2-E6FB-47A5-9A19-1BF6DC5124A6")) IsmAuto::ILinkerOptions;
struct __declspec(uuid("D91E3FE2-D617-4186-B0BD-55D95FEC37C3")) IsmAuto::IScriptingBillboard;
struct __declspec(uuid("88090AC9-038B-46BD-9852-FFEE92F0AA3D")) IsmAuto::IScriptingBillboards;
struct __declspec(uuid("F79B5EC7-5CC7-4390-B312-8ABABF92B4B7")) IsmAuto::ISequence;
struct __declspec(uuid("B29FA8FC-9C2C-464B-B105-209C77F4D275")) IsmAuto::ISequence2;
struct __declspec(uuid("68DFEBF0-1275-47de-B674-F16B7880ECA7")) IsmAuto::ISequenceJustice;
struct __declspec(uuid("7A80DB7C-E834-42F0-BFD2-46804DBCEE5D")) IsmAuto::ISequences;
struct __declspec(uuid("A34E9627-46DA-484C-B9B3-E304E66A05E0")) IsmAuto::ISequenceEvent;
struct __declspec(uuid("D26E8DA2-097E-4EA6-B4C9-B6D46AF52470")) IsmAuto::ISequenceHeader;
struct __declspec(uuid("37EB2A9D-D779-4561-AD0B-B5AD27E4F4F6")) IsmAuto::ISequenceHeader2;
struct __declspec(uuid("0FCF204C-AB4B-4d56-8BE7-AAB4B3B63D5D")) IsmAuto::ISequenceHeaderJustice;
struct __declspec(uuid("94356A78-E1C0-4C1C-9D90-9ABEFFB8EB2F")) IsmAuto::IServiceControl;
struct __declspec(uuid("3E91679E-8414-487A-B89D-2CF9877B10D2")) IsmAuto::IServiceControl2;
struct __declspec(uuid("1B7E55F5-06D1-43BB-AB8E-BD93C71F0A93")) IsmAuto::IServiceControls;
struct __declspec(uuid("9B736D53-F7C6-40B3-A160-39657E1A07B9")) IsmAuto::IServiceControlEvent;
struct __declspec(uuid("4785F3FB-DE0B-41A0-8A63-5B6D35970E17")) IsmAuto::IServiceControlEvent2;
struct __declspec(uuid("F7199ED1-6BD1-4888-9DA4-8B265DB96B56")) IsmAuto::IServiceControlEvents;
struct __declspec(uuid("7A1F46B1-5475-46FB-B763-88E8A0F9D94F")) IsmAuto::IServiceInstall;
struct __declspec(uuid("5028A8AC-D541-4CAE-AEC0-E90BE86E96AE")) IsmAuto::IServiceInstall2;
struct __declspec(uuid("5DA5E1BA-802D-4D06-B735-B74DD04276BC")) IsmAuto::IServiceInstalls;
struct __declspec(uuid("52F5F708-318E-49B9-8097-91BB3C5B9805")) IsmAuto::ISetupType;
struct __declspec(uuid("39F117E4-4031-4C4C-AE88-EB70703B88E8")) IsmAuto::ISetupTypeNeptune;
struct __declspec(uuid("A3938359-6E9F-4BA8-AA9F-DE26370FE96E")) IsmAuto::ISetupTypes;
struct __declspec(uuid("04DD1996-5631-419B-B717-7A139B9C71E3")) IsmAuto::IFolder;
struct __declspec(uuid("39D594DE-EE08-4572-886E-D48EA277C9AE")) IsmAuto::IFolder2;
struct __declspec(uuid("606BAD23-E268-4AF0-9F3B-27C9A144D226")) IsmAuto::IFolderNeptune;
struct __declspec(uuid("C3C94CD1-0C3F-4C78-B0F3-229F2821AA82")) IsmAuto::IFolders;
struct __declspec(uuid("9DFCBE72-F08F-480D-B871-F6DF03B7A88E")) IsmAuto::IShortcut;
struct __declspec(uuid("BBAA1CEF-89A6-4DCD-998A-4245CB4C2258")) IsmAuto::IShortcut2;
struct __declspec(uuid("DC35B0F9-0D20-478A-B759-AACCBB6A9FBE")) IsmAuto::IShortcutNeptune;
struct __declspec(uuid("AF19FAC7-409C-461F-AB21-F3F9414824C4")) IsmAuto::IShortcuts;
struct __declspec(uuid("3393E995-93CE-4A4A-820A-57F399FE1D9B")) IsmAuto::IStringIdSearch;
struct __declspec(uuid("55C9751A-D7DD-4932-89B0-9BB4E66709C3")) IsmAuto::IStringEntry;
struct __declspec(uuid("55A438EC-B463-46E4-9B1E-91476B52284F")) IsmAuto::IStringEntry2;
struct __declspec(uuid("A9BA75F0-9D15-4738-866C-1CC32B94D004")) IsmAuto::IStringEntries;
struct __declspec(uuid("A9BA75F1-9D15-4738-866C-1CC32B94D004")) IsmAuto::IStringEntriesNeptune;
struct __declspec(uuid("80491CD6-6318-4CB2-B143-B822457A3B40")) IsmAuto::ITargetReqs;
struct __declspec(uuid("386B732C-6F8F-42C7-BBD3-7AAB970C5856")) IsmAuto::ITempFile;
struct __declspec(uuid("43706AD6-1341-4369-9B3E-03046E423A3D")) IsmAuto::ITempFiles;
struct __declspec(uuid("8BB5C18D-FDE7-441C-9EA7-B854C0315F9A")) IsmAuto::ISetupFile;
struct __declspec(uuid("0B539B5B-1A00-4A9B-B811-34ACF0BAA37D")) IsmAuto::ISetupFileQi;
struct __declspec(uuid("6366DAB0-9476-4711-BF41-78718C6FB011")) IsmAuto::ISuiteResourceFile;
struct __declspec(uuid("DC1237D5-65A2-4E58-97E0-F737D952AE70")) IsmAuto::ISetupFiles;
struct __declspec(uuid("3FABA2F4-1566-4FE8-87CA-290B190DCD68")) IsmAuto::ISetupFolder;
struct __declspec(uuid("D71693A7-0D70-4FDF-8C88-7303952CE37C")) IsmAuto::ISetupFolders;
struct __declspec(uuid("D0C63FD4-6217-460A-9572-728C74F4E394")) IsmAuto::ITypeLib;
struct __declspec(uuid("845F1A88-72E9-4F8F-8198-82CC46C3A93B")) IsmAuto::ITypeLib2;
struct __declspec(uuid("E68B9119-8636-4EA6-BA4C-AF56B47E05E7")) IsmAuto::ITypeLibs;
struct __declspec(uuid("EBD12E8B-ABB8-4CB5-81EF-7691FC4A0BA8")) IsmAuto::IUITextString;
struct __declspec(uuid("634E9F62-F757-49B8-A9C1-3B7E254CDCA3")) IsmAuto::IUITextStrings;
struct __declspec(uuid("6E5ACE27-B676-4D7D-9849-C1BAAB7C8216")) IsmAuto::ITextStyle;
struct __declspec(uuid("84439A46-E292-4CAB-A41E-D1CC5C8A8F95")) IsmAuto::ITextStyles;
struct __declspec(uuid("A5A1CF23-18EF-4CC5-9247-7D99FBA0031C")) IsmAuto::IUpgradeSettings;
struct __declspec(uuid("F3FC199B-81C9-41BF-888E-285B88E332EC")) IsmAuto::IUpgradeEntry;
struct __declspec(uuid("93AB3351-B12B-4EB3-8ED1-15E95E2023B6")) IsmAuto::IUpgradeEntry2;
struct __declspec(uuid("0192A765-14CB-4016-95C3-4DE9A22D60CC")) IsmAuto::IUpgradeEntries;
struct __declspec(uuid("08F7330A-7E75-4A51-8F82-DF298EA2D6A7")) IsmAuto::IUpgradeMsiItem;
struct __declspec(uuid("C8179FA2-C779-457B-82B9-D0F26B210548")) IsmAuto::IUpgradeMsiItems;
struct __declspec(uuid("DA7A5C3A-D01A-43E1-97BF-665725847373")) IsmAuto::IVisitedView;
struct __declspec(uuid("9D913C12-5FE7-40C6-B551-A94871F948F2")) IsmAuto::IVisitedViews;
struct __declspec(uuid("CE33A15C-DB59-40C1-88FA-665C202F0CF0")) IsmAuto::IVRoot;
struct __declspec(uuid("6365922A-842E-4145-8D83-052DC46EFBDB")) IsmAuto::IVRootProteus;
struct __declspec(uuid("46EA7CFE-E7BF-498f-ACEF-FCF300E56051")) IsmAuto::IVRootIbiza;
struct __declspec(uuid("24E0C453-8ED1-41ED-9270-82D889A36F99")) IsmAuto::IVRoots;
struct __declspec(uuid("F721BC08-BA62-4216-9711-3D22F1310ECC")) IsmAuto::IVRootAppMap;
struct __declspec(uuid("34B88D6B-8E76-4675-BCC7-E3427B1F06D7")) IsmAuto::IVRootAppMaps;
struct __declspec(uuid("31146BCF-BFB6-11d2-B422-00104B261643")) IsmAuto::IAssistantTagNeptune;
struct __declspec(uuid("31146BC0-BFB6-11d2-B422-00104B261643")) IsmAuto::IAssistantTagsNeptune;
struct __declspec(uuid("8B5A3859-5304-4f82-B189-0D5E348C24ED")) IsmAuto::IFileSetDirectoryNeptune;
struct __declspec(uuid("26C6E005-1E77-4167-8BC9-97B120A8CDC2")) IsmAuto::IFileSetDirectoriesNeptune;
struct __declspec(uuid("F54E4B26-47C2-4617-8ED2-1E3993B50167")) IsmAuto::IFileSetNeptune;
struct __declspec(uuid("FD00B9B9-BA1E-4769-9ABE-26D4E89D410F")) IsmAuto::IFileSetsNeptune;
struct __declspec(uuid("DD6330AD-EF56-453b-A0C4-0AA50B9099F2")) IsmAuto::IProObjectCallbackNeptune;
struct __declspec(uuid("D57C2BB8-D057-4d16-A80A-87EF5771590B")) IsmAuto::IProObjectPropertyNeptune;
struct __declspec(uuid("37B58817-C732-4caa-B3F2-4C19DCD3A06C")) IsmAuto::IProObjectPropertiesNeptune;
struct __declspec(uuid("B31E2E51-7EFD-47e6-9EE9-71AC9650F1C4")) IsmAuto::IManifestItemNeptunePDC;
struct __declspec(uuid("B31E2E52-7EFD-47e6-9EE9-71AC9650F1C4")) IsmAuto::IManifestItemsNeptunePDC;
struct __declspec(uuid("B31E2E53-7EFD-47e6-9EE9-71AC9650F1C4")) IsmAuto::IApplicationManifestNeptunePDC;
struct __declspec(uuid("B31E2E54-7EFD-47e6-9EE9-71AC9650F1C4")) IsmAuto::IDeploymentManifestNeptunePDC;
struct __declspec(uuid("CAC1EE3B-197F-4688-8BBA-2AF1920B309D")) IsmAuto::IDeploymentManifestIxtapa;
struct __declspec(uuid("E16C37BE-8EA4-473A-90AD-9D4E5725A68B")) IsmAuto::IApplicationManifestIxtapa;
struct __declspec(uuid("8D6FC628-96E7-4D4E-882B-15A509442916")) IsmAuto::IProjectRootNeptunePDC;
struct __declspec(uuid("F81847E4-CCC9-41d8-A695-30DB5A75A83B")) IsmAuto::IPrerequisiteNeptunePDC;
struct __declspec(uuid("F81847E5-CCC9-41d8-A695-30DB5A75A83B")) IsmAuto::IPrerequisitesNeptunePDC;
struct __declspec(uuid("F5907014-C111-4fb0-9921-C8AE6262C15A")) IsmAuto::IDeviceDriverPackageNeptunePDC;
struct __declspec(uuid("F5907015-C111-4fb0-9921-C8AE6262C15A")) IsmAuto::IDeviceDriverPackageProteus;
struct __declspec(uuid("12C843EF-3A3B-4634-B065-9CBF0AF5C055")) IsmAuto::IDeviceDriverPackagesNeptunePDC;
struct __declspec(uuid("28A49D46-633C-4260-92B2-7BADFD65E6A8")) IsmAuto::IDeviceDriverPackageIbiza;
struct __declspec(uuid("BA90279F-A170-407e-97AE-7C6F79C5D9F4")) IsmAuto::IDeviceDriverPackageIxtapa;
struct __declspec(uuid("4CB70EF2-D7A8-4ee6-BA72-7E74BF460BCE")) IsmAuto::ILightComPlusApplicationNeptuneSP;
struct __declspec(uuid("BF5E0A47-1739-433b-A567-8CFB8E9BA7F0")) IsmAuto::ILightComPlusApplicationEntryNeptuneSP;
struct __declspec(uuid("048EA707-E47B-4103-B5B4-E64A3029CE03")) IsmAuto::ILightComCatalogObjectNeptuneSP;
struct __declspec(uuid("3E281D2B-C874-432f-BB2A-AFD7FDC1EAF0")) IsmAuto::ILightComCatalogObjectEntryNeptuneSP;
struct __declspec(uuid("A8E6F501-9DE2-4188-936C-441902733623")) IsmAuto::ILightComCatalogAttributeNeptuneSP;
struct __declspec(uuid("B07A6139-8D9E-4213-ABBB-1C10831C4D9E")) IsmAuto::ILightComCatalogAttributeEntryNeptuneSP;
struct __declspec(uuid("F02372D7-0244-4ba5-8C98-E5CBDCD5B3DB")) IsmAuto::ILightComCatalogCollectionNeptuneSP;
struct __declspec(uuid("4F75EC22-481B-458c-8953-CDDCDBC94F64")) IsmAuto::ILightComCatalogCollectionEntryNeptuneSP;
struct __declspec(uuid("A819B92F-D8B8-4069-9782-E6348F06DC79")) IsmAuto::IProjectRootNeptuneSP;
struct __declspec(uuid("B3686EFE-81B8-445c-8746-7F820E9037C4")) IsmAuto::ISetupPrerequisiteProteus;
struct __declspec(uuid("65FB16CF-515D-4150-A77D-8E32668CADE5")) IsmAuto::ISetupPrerequisiteIndore;
struct __declspec(uuid("45C6C491-09D2-409F-B391-DBD531941781")) IsmAuto::ISetupPrerequisiteJustice;
struct __declspec(uuid("C039D25F-EAE4-4ac5-83EB-D592970D839D")) IsmAuto::ISetupPrerequisitesProteus;
struct __declspec(uuid("C9CBD5BE-F923-482b-B9D3-232CD5CC975C")) IsmAuto::IProjectRootProteus;
struct __declspec(uuid("7FEDBA19-FF94-40f0-85B1-62334B481A1F")) IsmAuto::IProjectRootPluto;
struct __declspec(uuid("5814E57B-AC12-4a88-BC14-FEFF316C0B82")) IsmAuto::IISComPlusProxyProteus;
struct __declspec(uuid("058E9FB1-58A2-45a9-AD6C-024177435EA7")) IsmAuto::IISComPlusProxiesProteus;
struct __declspec(uuid("4A3734B2-B0F6-4ba8-913F-4C0A5B4C1855")) IsmAuto::IISComPlusApplicationProteus;
struct __declspec(uuid("78953FE3-ED42-47ba-932A-46087436E78B")) IsmAuto::IISCatalogAttributeProteus;
struct __declspec(uuid("588CC6AB-CE37-4b12-BD57-FF94B91ECDA5")) IsmAuto::IComponentProteus;
struct __declspec(uuid("50BA62F0-F041-4a74-A733-1AABEA632503")) IsmAuto::IComponentPluto;
struct __declspec(uuid("35730BB8-8F57-4a24-86C5-71E01A6393CE")) IsmAuto::ISQLScriptFileProteus;
struct __declspec(uuid("EF0AF9BD-C76F-4124-BA50-C90D975EC5BF")) IsmAuto::ISQLScriptFileProteusSP;
struct __declspec(uuid("AF82F9C4-AC14-4d39-9628-386FA6D8B5C4")) IsmAuto::ISQLScriptFilesProteus;
struct __declspec(uuid("2DACC710-FDF4-4557-B312-73CD3FED43D5")) IsmAuto::ISQLConnectionProteus;
struct __declspec(uuid("39DC5001-D6CF-4134-90A0-339C7011DE58")) IsmAuto::ISQLConnectionProteusSP;
struct __declspec(uuid("F22200AB-7767-45e5-94B1-814FAAA9015F")) IsmAuto::ISQLConnectionPluto;
struct __declspec(uuid("55CD8826-7C1F-4c7b-AB35-77F46754C263")) IsmAuto::ISQLConnectionIxtapa;
struct __declspec(uuid("0CA8CBBF-A7E6-4b93-A6B1-52F2591540D1")) IsmAuto::ISQLConnectionJustice;
struct __declspec(uuid("6AB3FAE7-0ADD-4923-9751-0F9A4C9A04EF")) IsmAuto::ISQLConnectionLoyalty;
struct __declspec(uuid("2DACC711-FDF4-4557-B312-73CD3FED43D5")) IsmAuto::ISQLConnectionsProteus;
struct __declspec(uuid("2DACC713-FDF4-4557-B312-73CD3FED43D5")) IsmAuto::ISQLScriptReplacementProteus;
struct __declspec(uuid("2DACC712-FDF4-4557-B312-73CD3FED43D5")) IsmAuto::ISQLScriptReplacementsProteus;
struct __declspec(uuid("2DACC714-FDF4-4557-B312-73CD3FED43D5")) IsmAuto::ISQLScriptImportProteus;
struct __declspec(uuid("849E0945-968C-4038-BF2F-B12F2DB6685B")) IsmAuto::ISQLScriptImportProteusSP;
struct __declspec(uuid("1A10C121-FF24-46e6-AED5-F118C41AEC62")) IsmAuto::ISQLScriptImportIxtapa;
struct __declspec(uuid("A16D2B25-D0D9-4b83-BAD0-1E12DFF6E421")) IsmAuto::ISQLScriptImportsIxtapa;
struct __declspec(uuid("8A17DBAC-8867-4bb2-8003-8C17AA73325B")) IsmAuto::ISQLScriptImportIna;
struct __declspec(uuid("2DACC723-FDF4-4557-B312-73CD3FED43D5")) IsmAuto::ISQLRequirementProteus;
struct __declspec(uuid("46CA1328-643C-421b-8754-6E1237FE7FDB")) IsmAuto::ISQLRequirementPluto;
struct __declspec(uuid("2DACC722-FDF4-4557-B312-73CD3FED43D5")) IsmAuto::ISQLRequirementsProteus;
struct __declspec(uuid("41A26F34-4057-49da-AD66-5507424E522A")) IsmAuto::ISQLScriptErrorProteus;
struct __declspec(uuid("54CEEA74-06D8-48d0-A2FA-DC9256FBE090")) IsmAuto::ISQLScriptErrorsProteus;
struct __declspec(uuid("76884665-ACDA-4c2e-8844-CF7415EF87A2")) IsmAuto::IISComPlusEvents;
struct __declspec(uuid("20F9C1C0-C844-4866-B77B-5C3489A86BC2")) IsmAuto::IWebSiteProteus;
struct __declspec(uuid("C62EEFE5-2D41-47bf-BC36-27A0D986A43F")) IsmAuto::IWebSiteIbiza;
struct __declspec(uuid("84FCA516-7C2B-4cd1-91A1-13A1DCD988B5")) IsmAuto::IWebSiteIronwood;
struct __declspec(uuid("C06432E6-193A-4a6e-A9CA-32F65932D844")) IsmAuto::IWebSiteJustice;
struct __declspec(uuid("54A7AC99-8033-41c2-938E-71932A5661D4")) IsmAuto::IWebSitesProteus;
struct __declspec(uuid("694CCE99-48BA-4462-90AB-872DEE290DBB")) IsmAuto::IPalmAppsProteus;
struct __declspec(uuid("694CCE9A-48BA-4462-90AB-872DEE290DBB")) IsmAuto::IPalmAppProteus;
struct __declspec(uuid("694CCE9C-48BA-4462-90AB-872DEE290DBB")) IsmAuto::IPalmAppFilesProteus;
struct __declspec(uuid("694CCE9D-48BA-4462-90AB-872DEE290DBB")) IsmAuto::IPalmAppFileProteus;
struct __declspec(uuid("DA490341-47EA-431f-B6E6-104F4E79859A")) IsmAuto::IMsiPatchSequenceProteusSP;
struct __declspec(uuid("DA490340-47EA-431f-B6E6-104F4E79859A")) IsmAuto::IMsiPatchSequencesProteusSP;
struct __declspec(uuid("239E4639-1C23-4976-B5C5-DF02363B2BBC")) IsmAuto::IXmlFilePluto;
struct __declspec(uuid("5731A5D6-A094-482d-8708-74DE0774971B")) IsmAuto::IXmlFileIronwood;
struct __declspec(uuid("563F44FB-F8B9-4B62-AE13-ACBCD920D1A1")) IsmAuto::IXmlFileLoyalty;
struct __declspec(uuid("CB79A807-B3EF-4a10-A8FB-E150361FCBF7")) IsmAuto::IXmlFilesPluto;
struct __declspec(uuid("E5B23437-4DE3-472e-9677-7AC42179F8F3")) IsmAuto::IXmlElementPluto;
DEFINE_ISMAUTO_INTERFACE(7562681D-26C6-46d4-A077-7A22616CDC7A, IXmlElementIronwood);
struct __declspec(uuid("9469CBCE-B9AE-4d07-8904-E150E22FAB4C")) IsmAuto::IXmlElementsPluto;
struct __declspec(uuid("E38E52FE-8E87-485d-B362-486E69C76C80")) IsmAuto::IXmlElementAttribPluto;
struct __declspec(uuid("DA107E50-0356-4f47-88A1-E08C1F4553D6")) IsmAuto::IXmlElementAttribsPluto;
struct __declspec(uuid("4F8D9237-82CD-4e22-8879-8F7B7C3886AE")) IsmAuto::IXmlLocatorPluto;
struct __declspec(uuid("63B2F641-4070-4286-B4DF-F62F17BABE45")) IsmAuto::IXmlLocatorsPluto;
struct __declspec(uuid("C0C66416-1922-4907-814B-3C2DF565A75D")) IsmAuto::IXmlXPathExpressionPluto;
struct __declspec(uuid("760CB5E3-63CF-4f7b-AC83-F24EBB236A5C")) IsmAuto::IXmlXPathExpressionsPluto;
struct __declspec(uuid("69A37AE0-BE6C-4000-861A-5E5382F2FF07")) IsmAuto::IXmlNamespaceIronwood;
struct __declspec(uuid("2038D051-CA7E-445c-BAD1-EFF7D9AFBCEF")) IsmAuto::IXmlNamespacesIronwood;
struct __declspec(uuid("09D4B8B7-A187-4951-961D-2EB5D6FAE29F")) IsmAuto::ISQLDatabaseServerPluto;
struct __declspec(uuid("15FB1378-1E21-4432-AC42-193DFE0D24EA")) IsmAuto::ISQLDatabaseServersPluto;
struct __declspec(uuid("40A0E90D-E936-4eef-9BAE-31739344FAD3")) IsmAuto::ISQLDBMetaDataPluto;
struct __declspec(uuid("6D875E0E-F566-41dc-974D-14BA2CEB21C8")) IsmAuto::ISQLDBMetaDataColPluto;
struct __declspec(uuid("08DA6585-5E62-413b-A4B8-26024F4B12B8")) IsmAuto::IDRMFileAttributePluto;
struct __declspec(uuid("EFB7C242-F6CA-4a77-A4A8-F86888CE927D")) IsmAuto::IDRMFileAttributesPluto;
struct __declspec(uuid("7C5428BE-B291-403d-BA9B-1671BFA42A0A")) IsmAuto::IDRMLicenseIbiza;
struct __declspec(uuid("325F88B6-4BCF-4909-A5FA-BA2160D632EF")) IsmAuto::IDRMLicensePluto;
struct __declspec(uuid("9139E43B-49C0-4720-AC69-342F95FE7CAD")) IsmAuto::IDRMLicensesPluto;
struct __declspec(uuid("771DC109-D72D-4609-869F-89480C660B30")) IsmAuto::IDRMFilePluto;
struct __declspec(uuid("C10F874F-7414-4d8b-9D82-B3433639070E")) IsmAuto::IDRMFilesPluto;
struct __declspec(uuid("BA0E5A43-8524-4441-A3FC-AF45173563DD")) IsmAuto::IProjectRootIbiza;
struct __declspec(uuid("DCB6CB42-53D9-4a91-B976-4348DC8FDADB")) IsmAuto::IProductIbiza;
struct __declspec(uuid("E489ECC7-7201-47ec-850B-90E08C692F11")) IsmAuto::ISQLDBMetaDataIbiza;
struct __declspec(uuid("6B31F451-B5DA-452d-A8C7-1D3254EC7915")) IsmAuto::ISQLScriptFileIbiza;
struct __declspec(uuid("963FC6EE-FC8E-49ba-8927-82545AF6B622")) IsmAuto::IComponentIbiza;
struct __declspec(uuid("B54A9729-90AD-475e-9506-0932100086ED")) IsmAuto::IShortcutIbiza;
struct __declspec(uuid("3D4CA646-66EE-46a1-872B-3059FB27992E")) IsmAuto::IIisAppPoolIbiza;
struct __declspec(uuid("36AF267E-F0FA-47e2-AE76-AFB61FCCEB5A")) IsmAuto::IIisAppPools;
struct __declspec(uuid("5E963A09-3C58-4fa6-A8F8-C5DD279B6788")) IsmAuto::IIisWebServiceExtensionIbiza;
struct __declspec(uuid("8D612654-22F7-4cde-877B-C0CAF4E160DF")) IsmAuto::IIisWebServiceExtensionIndore;
struct __declspec(uuid("14C13512-08F5-441d-B4F5-75EEF54D943D")) IsmAuto::IIisWebServiceExtensions;
struct __declspec(uuid("755B7B73-C008-4918-9E2B-E7191850D294")) IsmAuto::IIisItem;
struct __declspec(uuid("F2255DE8-6FE3-4869-A8F5-C05DDEA16BD2")) IsmAuto::IIisItemMajesty;
struct __declspec(uuid("FE25F09F-F741-41b5-AB48-549EDD4FEA2D")) IsmAuto::IIisItems;
struct __declspec(uuid("D3D1648C-C231-4196-A586-7607DFCE121E")) IsmAuto::IIisProperty;
struct __declspec(uuid("FD22E07A-59ED-4b2d-9E70-887409A315B6")) IsmAuto::IIisProperties;
struct __declspec(uuid("35AC7028-B634-4fb4-9DDB-A0897508753D")) IsmAuto::IPathVariableSetIbiza;
struct __declspec(uuid("A8ADD8EF-9286-46fc-9858-3AE3C830E067")) IsmAuto::IPathVariableSetJustice;
struct __declspec(uuid("C94A14E0-9311-4536-A547-BECF666E42EE")) IsmAuto::IDimReferenceLoyalty;
struct __declspec(uuid("7E31A1F7-CF70-4412-A65E-BD86D914C0C1")) IsmAuto::IDimReferenceJustice;
struct __declspec(uuid("BB62CEFD-A784-4ff4-97E1-3A51815ED18D")) IsmAuto::IDimReferenceIxtapa;
struct __declspec(uuid("927FADAE-592A-415c-B2D9-6A630E69770F")) IsmAuto::IDimReferencesIxtapa;
struct __declspec(uuid("6877FBDE-CA42-4568-8E3D-A96A6D83AAEA")) IsmAuto::IDimVariableIxtapa;
struct __declspec(uuid("C9962960-D832-468e-8418-D9DB629747B3")) IsmAuto::IDimVariablesIxtapa;
struct __declspec(uuid("E11BDF8D-A4D5-4d55-8561-4640F04FF9C6")) IsmAuto::IDimDimDependencyIxtapa;
struct __declspec(uuid("79BC1C8B-A0BE-4562-9F3E-6B3EF4987F99")) IsmAuto::IDimDimDependenciesIxtapa;
struct __declspec(uuid("AA24F616-4BB1-4ecf-812E-F35698DD2EFA")) IsmAuto::IFeatureIxtapa;
struct __declspec(uuid("4C86D508-1C59-42ba-923F-62C099DD4AEE")) IsmAuto::IProjectRootIxtapa;
struct __declspec(uuid("37A7B4A8-2C00-4159-A5FA-88EF433B2E1B")) IsmAuto::ISQLScriptFileIxtapa;
struct __declspec(uuid("73269CFF-D12E-4308-891B-D500E4FD2333")) IsmAuto::IVRootIxtapa;
struct __declspec(uuid("49DD66C5-C4B9-4d52-BAC9-E1B3E0772C8E")) IsmAuto::IVRootIndore;
struct __declspec(uuid("9B2F489E-ED96-4cf2-9D90-144F356EDCE1")) IsmAuto::IWebSiteIxtapa;
struct __declspec(uuid("FA82BE0C-372A-4920-9817-684D01F37444")) IsmAuto::IWebSiteIndore;
struct __declspec(uuid("71B47F5C-C8C9-4f23-8B1B-BCFC80C7E0CB")) IsmAuto::IShortcutIxtapa;
struct __declspec(uuid("B45B2285-99FD-4ac6-BE42-E9C4E60FE2E5")) IsmAuto::IReleaseIbizaAtlantis;
struct __declspec(uuid("CBAE32C1-4DAE-4a47-8B5F-27D64C65DD5C")) IsmAuto::IReleaseASRepositoryPropertyIbizaAtlantis;
struct __declspec(uuid("BD2AC4B7-7D9A-43c8-81BB-8D45291B7972")) IsmAuto::IReleaseASRepositoryPropertiesIbizaAtlantis;
struct __declspec(uuid("9B705255-B7C2-444e-BE7F-5B5638C7EA06")) IsmAuto::IListViewRowIndore;
struct __declspec(uuid("B5FE776A-58E6-4622-8EAE-015C5A965C8B")) IsmAuto::ILightComPlusApplicationIndore;
struct __declspec(uuid("E07E41E6-E872-4d24-B0BF-BB1DD88E7DA7")) IsmAuto::ILightComCatalogObjectIndore;
struct __declspec(uuid("9BEA5A19-A90D-47af-91EB-37F4683D5F68")) IsmAuto::ILightComCatalogCollectionIndore;
struct __declspec(uuid("A71FBB8B-A81B-4cf2-9CF4-0C66E9175378")) IsmAuto::IISComPlusApplicationIndore;
struct __declspec(uuid("8685492F-CC80-40f3-930B-BAC325409312")) IsmAuto::ISQLDBMetaDataIndore;
struct __declspec(uuid("A9B9D424-CCB1-43f9-B65C-5C66B2CDA8A1")) IsmAuto::IISCatalogObjectIndore;
struct __declspec(uuid("780E186C-F1BA-4401-8A4C-4FC2BC5A03A8")) IsmAuto::IProjectRootIndore;
struct __declspec(uuid("0B8E509E-9B22-440b-985E-7B4A0E9C3F1F")) IsmAuto::ILightComPlusServerFileIndore;
struct __declspec(uuid("D05F8868-494B-4f53-A0D4-CD3AA3F40148")) IsmAuto::ILightComPlusServerFileEntryIndore;
struct __declspec(uuid("5D4CD2CD-EDE6-41c8-9DCC-726D973BC2EA")) IsmAuto::ILightComPlusProxyFileIndore;
struct __declspec(uuid("FCDC2D0C-96A8-4743-9645-AB9F40810CB2")) IsmAuto::ILightComPlusProxyFileEntryIndore;
struct __declspec(uuid("CDD27CDD-574B-40b4-898B-4CF783BEB597")) IsmAuto::ILightComPlusApplicationDLLIndore;
struct __declspec(uuid("6B36F394-FFAA-44f8-96CC-6381A8DF60FA")) IsmAuto::ILightComPlusApplicationDLLEntryIndore;
struct __declspec(uuid("BBDF10F1-AC64-40b7-A23F-D69E9D78FDCA")) IsmAuto::ILightComCatalogObjectEntryIndore;
struct __declspec(uuid("E8FA5853-9431-4ac9-84F5-0C2B1477CD56")) IsmAuto::IISComPlusApplicationDLLIndore;
struct __declspec(uuid("283A8381-60E0-45a8-B202-EDC603AF8682")) IsmAuto::IISComPlusApplicationDLLsIndore;
struct __declspec(uuid("3C75195E-0B29-4c6a-8C46-168170484002")) IsmAuto::IISComPlusFileIndore;
struct __declspec(uuid("DFED0427-F19B-45c1-A9E3-5502949C52FA")) IsmAuto::IISComPlusFilesIndore;
struct __declspec(uuid("E8C3A424-3F56-4b63-86C1-F5EFFE91909D")) IsmAuto::ILightComPlusServerDepFileIndore;
struct __declspec(uuid("9DEE5643-BF40-4c8b-8136-88E55E8FE0FF")) IsmAuto::ILightComPlusServerDepFileEntryIndore;
struct __declspec(uuid("31716388-6FCB-49cc-A3D6-CCC9594C37DC")) IsmAuto::ILightComPlusProxyDepFileIndore;
struct __declspec(uuid("F356B98A-2AE3-404d-B904-6395918188B2")) IsmAuto::ILightComPlusProxyDepFileEntryIndore;
struct __declspec(uuid("E901B484-917D-40eb-A90C-8D8B3FB6AA3C")) IsmAuto::ILightComPlusApplicationEntryIndore;
struct __declspec(uuid("C98DD974-062A-4399-A587-E6082E97F157")) IsmAuto::IFeatureIndore;
struct __declspec(uuid("E601510D-8A27-44ba-927A-103BA0CFAFD0")) IsmAuto::ILightFileEntryIndore;
struct __declspec(uuid("EEBE52D4-5F46-455f-9C2F-6FE4E7F3399B")) IsmAuto::ILightFileIndore;
struct __declspec(uuid("9C464DA4-95CA-4704-A776-FAE6339F7C53")) IsmAuto::ILightDirectoryEntry;
struct __declspec(uuid("588B26EB-D459-4a7f-BE96-FDD6A1B160B5")) IsmAuto::ILightDirectory;
struct __declspec(uuid("5AEACD23-B434-42bf-AFB1-78A3D5D445B0")) IsmAuto::ILightEntry;
struct __declspec(uuid("2A359550-8B48-44bb-ABEF-E622491A5D8F")) IsmAuto::ICustomActionIndore;
struct __declspec(uuid("5F2D4CAD-2067-4E27-839D-9469D108E673")) IsmAuto::ICustomActionJustice;
struct __declspec(uuid("1C11C89B-FDF2-4639-8E4E-A59F1945F47D")) IsmAuto::ICustomActionRipley;
struct __declspec(uuid("4C359502-78AF-4cd4-8969-A1606F40A05C")) IsmAuto::IBuildLabelIndore;
struct __declspec(uuid("868E2171-A679-4ed5-8339-C0FF9BA4C059")) IsmAuto::IShortcutIndore;
struct __declspec(uuid("BC949CE6-CC70-409d-9DC1-F89909CE798F")) IsmAuto::IShortcutIronwood;
struct __declspec(uuid("2E1B1D8A-E255-4d14-9832-A1DF70E14461")) IsmAuto::IAppSearchIndore;
struct __declspec(uuid("E1A2CE60-9134-4849-B949-DDEC8F0CF39B")) IsmAuto::IDrLocatorIndore;
struct __declspec(uuid("4AEED68F-172B-4f95-B830-8E2F161F4B0F")) IsmAuto::IProjectRootIna;
struct __declspec(uuid("DF18F366-747C-4834-8E1B-248BBA1EB3BA")) IsmAuto::IProjectRootIronwood;
struct __declspec(uuid("3C07EAD4-4BCE-4782-AA24-643E484091F9")) IsmAuto::IProjectRootJustice;
struct __declspec(uuid("DD068037-6D17-4750-A144-6DD47177AF1C")) IsmAuto::IProjectRootLoyalty;
struct __declspec(uuid("A633667B-B4C5-4b65-B6D0-E17EC9579B66")) IsmAuto::IISComPlusApplicationIna;
struct __declspec(uuid("E6E259DB-B04C-4393-BEDB-C8D2E8482E5F")) IsmAuto::IISComPlusProxyIna;
struct __declspec(uuid("7518DA5D-34B8-4642-936C-3C59D435DAD5")) IsmAuto::IISComPlusApplicationQi;
struct __declspec(uuid("6D3C47E4-08BF-4a0c-9409-DD35883B75F4")) IsmAuto::IBusinessObjectIndoreSP1;
struct __declspec(uuid("B6AB10A1-415E-4378-BB53-465E7E15FFFB")) IsmAuto::ISQLDBMetaDataIronwood;
struct __declspec(uuid("3DABCEB5-D13F-4487-A1E3-6ECFDD80A0DE")) IsmAuto::IComponentIronwood;
struct __declspec(uuid("C2E10874-AB8D-4761-B4E8-62DA99BB2CAC")) IsmAuto::IComponentJustice;
struct __declspec(uuid("9EEF0497-3EBC-4b92-9AE3-DFAF899DA011")) IsmAuto::IComponentLoyalty;
struct __declspec(uuid("5F31F09A-631A-4fd1-98D7-D27250436F2E")) IsmAuto::IComponentLoyaltySP1;
struct __declspec(uuid("9AD7422B-23CD-47e0-A84E-B3F1F7D946DD")) IsmAuto::IComponentOpus;
struct __declspec(uuid("0AB8CAD2-2990-4404-B32B-58C712C63FB5")) IsmAuto::IComponentPunk;
struct __declspec(uuid("00EF082D-5787-42C5-AD22-8C63D5E0A4FD")) IsmAuto::IComponentQi;
struct __declspec(uuid("847151AD-3D75-477A-A3E0-4325DD208651")) IsmAuto::IComponentRipley;
struct __declspec(uuid("32D3EA1A-B22F-4962-9292-80B10242B64D")) IsmAuto::IComponentSecret;
struct __declspec(uuid("B80D1847-4A53-4a13-817E-EB872A0E4057")) IsmAuto::IBusinessObjectIronwood;
struct __declspec(uuid("5E1B8B20-DC9D-4f60-9B66-3605797173CA")) IsmAuto::IProductConfigurationInstance;
struct __declspec(uuid("D17F1D1F-A849-4a85-AE5D-5E940D0083AC")) IsmAuto::IProductConfigurationInstances;
struct __declspec(uuid("8C21C3C7-20E5-4935-91BE-91749E9F9C17")) IsmAuto::IBuildLabelJustice;
struct __declspec(uuid("F0384FFF-DFD6-4923-A9B8-143C1CC67CA6")) IsmAuto::IBuildLabelPunk;
struct __declspec(uuid("130A4529-94AA-4e7f-9908-FAB2C0E7C855")) IsmAuto::ISQLScriptFileJustice;
struct __declspec(uuid("7CCDE479-D82B-4591-8400-423C987B2795")) IsmAuto::ISQLScriptFileLoyalty;
struct __declspec(uuid("EC499EEC-E9E3-43b4-9BCD-14A0FA8415A5")) IsmAuto::ISQLScriptFileNeo;
struct __declspec(uuid("3FD84852-AAB3-4cd6-95F7-D51BD994A133")) IsmAuto::ISearchReplace;
struct __declspec(uuid("D017F2D9-1C4B-47E3-9DA0-92221A7C6558")) IsmAuto::ISearchReplaceQi;
struct __declspec(uuid("BEA574DF-F317-4e16-931F-9703C538C716")) IsmAuto::ISearchReplaces;
struct __declspec(uuid("BE94479D-154C-4c62-966F-E61177E0F9A9")) IsmAuto::ISearchReplaceSet;
struct __declspec(uuid("47E2949D-C852-480b-9ECE-9B54A4D1370C")) IsmAuto::ISearchReplaceSets;
struct __declspec(uuid("D6CF4306-42FA-4869-BAD3-4CF576A0CC33")) IsmAuto::IActionText;
struct __declspec(uuid("07C0E747-1871-45f4-BE2A-5E56944B22F5")) IsmAuto::IActionTexts;
struct __declspec(uuid("46C832D5-E97D-4565-8BEB-968FFF42D621")) IsmAuto::IVirtualBuildOptionLoyalty;
struct __declspec(uuid("3C5CE1A3-2B85-484E-BB67-AF0014A229E0")) IsmAuto::IVirtualBuildOptions;
struct __declspec(uuid("8F0B8290-F868-4e38-8554-757BBDCFD51D")) IsmAuto::IMsiServiceConfig;
struct __declspec(uuid("EA927B1C-8B5C-487b-9C69-E8FCD13E0BCE")) IsmAuto::IMsiServiceConfigs;
struct __declspec(uuid("4B48B235-A731-4d6a-BB33-C1DB2DEA8066")) IsmAuto::IMsiServiceConfigFailureAction;
struct __declspec(uuid("750E4420-A40B-4133-A4EC-85D2A3D6E217")) IsmAuto::IMsiServiceConfigFailureActions;
struct __declspec(uuid("874C9BAE-7857-46ae-91A4-F66DDBB6B1C6")) IsmAuto::IServiceControlLoyaltySP1;
struct __declspec(uuid("7F75C1CD-63A0-4888-B33D-8F7BE46236CD")) IsmAuto::IServiceControlPunk;
struct __declspec(uuid("0B9763BD-F349-45bf-9245-D4D78F64C645")) IsmAuto::IServiceInstallLoyaltySP1;
struct __declspec(uuid("D32E55EE-104F-4e3e-807F-8CE6E040DE14")) IsmAuto::IShortcutLoyaltySP1;
struct __declspec(uuid("956CE28C-89CE-4c1a-A906-C1298DD056E6")) IsmAuto::IShortcutPunk;
struct __declspec(uuid("23B9FDDF-F3C1-409b-A9A3-0D22F6DA1638")) IsmAuto::IMsiShortcutProperty;
struct __declspec(uuid("865FABAD-61E0-46bc-B185-9EBD3ED7E917")) IsmAuto::IMsiShortcutProperties;
struct __declspec(uuid("0A26B0D1-0F5D-4b09-BA08-AE0BDBB2D5A8")) IsmAuto::IMsiLockPermissionsEx;
struct __declspec(uuid("F75950F5-1D34-480c-A0EB-9AEB58FC4114")) IsmAuto::IMsiLockPermissionsExs;
struct __declspec(uuid("B6BB3625-1603-469F-95F3-99C53EC23A52"))	IsmAuto::IDimRef;
struct __declspec(uuid("22AA3665-BC42-46D5-8CEF-EB4A6F2833B2"))	IsmAuto::IDimRefs;
struct __declspec(uuid("77E33B3B-A140-4e71-800A-E31F7D05B399")) IsmAuto::IProjectRootJack;
struct __declspec(uuid("193F7141-26FC-401f-9350-A2E3D95C609A")) IsmAuto::IProjectRootMajesty;
struct __declspec(uuid("828CB72D-92B4-4c6a-89E8-28C0CCB3F0AD")) IsmAuto::IProjectRootNeo;
struct __declspec(uuid("D77C6F8E-23F8-47bc-A299-AD7724F07366")) IsmAuto::IProjectRootOpus;
struct __declspec(uuid("A47E412D-9004-4fcd-B641-5483CC25D142")) IsmAuto::ISuitePackage;
struct __declspec(uuid("CA0BC4E9-F058-4703-A0EF-0E0173933C19")) IsmAuto::ISuitePackages;
struct __declspec(uuid("52A414E0-1A17-4d1c-9101-FE5C72654190")) IsmAuto::ISuiteUIAction;
struct __declspec(uuid("F88C1D8A-0A6B-4800-8B7A-31553FD88797")) IsmAuto::ISuiteUIActions;
struct __declspec(uuid("065C6219-1F38-4113-A31E-00BDD4E3769A")) IsmAuto::ISuiteUIControl;
struct __declspec(uuid("55FF9F22-490C-4214-B147-CD8BC06A565A")) IsmAuto::ISuiteUIControls;
struct __declspec(uuid("F1F44BDC-35F1-4294-B5AD-584A671CA036")) IsmAuto::ISuiteUIControlTheme;
struct __declspec(uuid("FD6D7CFB-E1B3-445D-9313-665BBCC53C3A")) IsmAuto::ISuiteUIControlThemes;
struct __declspec(uuid("FB094298-C22E-4bfb-B37C-063F7F3EBD07")) IsmAuto::ISuiteUIFonts;
struct __declspec(uuid("F8980EF4-339C-47dd-A63B-CB012750167E")) IsmAuto::ISuiteUIFont;
struct __declspec(uuid("BBC5507A-7B9C-44a9-9538-35F1D3BADC2F")) IsmAuto::ISuiteUIBrushes;
struct __declspec(uuid("589CFDE8-2B40-4bd2-9C2A-4FA3CD692C26")) IsmAuto::ISuiteUIBrush;
struct __declspec(uuid("D5080419-8DEE-4565-B844-C9EA24296443")) IsmAuto::ISuiteUIGradients;
struct __declspec(uuid("58085E93-DC4C-4c1a-BE60-0A6725C00DB9")) IsmAuto::ISuiteUIGradient;
struct __declspec(uuid("87E213FF-C990-4220-BA8E-D3F1FCB215E5")) IsmAuto::ISuiteUIStyles;
struct __declspec(uuid("28D157D4-929E-4abc-9B41-3E84C9A33CBD")) IsmAuto::ISuiteUIStyle;
struct __declspec(uuid("5A9CD147-091E-4CA0-87CA-1EAD11FD7FB8")) IsmAuto::ISuiteDialog;
struct __declspec(uuid("FD02FFCD-B0D3-4482-B18F-970DCF1A7D81")) IsmAuto::ISuiteDialogs;
struct __declspec(uuid("3067EF98-97F2-4E67-97ED-44B1AAB9FEC3")) IsmAuto::ISuiteSplashPage;
struct __declspec(uuid("8A6B8A55-0C44-4DC2-88C0-7A770C6553B4")) IsmAuto::ISuiteWizardPage;
struct __declspec(uuid("F30BF1EA-773A-47F0-A4B9-6A257943FDED")) IsmAuto::ISuiteWizardPagePunk;
struct __declspec(uuid("B0FE8F1E-8664-45CC-AAE4-C211FE0CC055")) IsmAuto::ISuiteWizardPages;
struct __declspec(uuid("23ED5BF3-7FAF-470C-8A89-C7FCFF355CE3")) IsmAuto::ISuiteWizard;
struct __declspec(uuid("E4F902EC-FBB1-475E-9CBE-23791F30A3DF")) IsmAuto::ISuiteConditionParameter;
struct __declspec(uuid("AFA01196-A3FA-494D-BFE3-5B07D9505115")) IsmAuto::ISuiteConditionParameters;
struct __declspec(uuid("6966633A-1FD2-4358-9D15-82E489EB59FD")) IsmAuto::ISuiteCondition;
struct __declspec(uuid("CE2B1620-F519-43F3-B32E-022467812090")) IsmAuto::ISuiteConditions;
struct __declspec(uuid("4314989A-6F9A-424E-B5E0-27F7D5E58FBE")) IsmAuto::ISuiteAbortCondition;
struct __declspec(uuid("DAFA68A8-D2CD-4BDB-92A4-EE546749796C")) IsmAuto::ISuiteAbortConditions;
struct __declspec(uuid("6C96F0B3-AD9D-40F6-8F7B-1F96C2CAAEAD")) IsmAuto::ISuiteProperty;
struct __declspec(uuid("9D642497-71D1-477a-81F5-8EC97D7785BE")) IsmAuto::IFeatureNeo;
struct __declspec(uuid("0CFBC8CD-112A-4aaa-B645-BCF32AD7AC02")) IsmAuto::IFeatureOpus;
struct __declspec(uuid("3C784A45-0FF2-4803-84A3-D5AC67C542F0")) IsmAuto::IFeatureQi;
struct __declspec(uuid("BA48DB26-7872-456E-999F-069D49E41614")) IsmAuto::IFeatureSecret;
struct __declspec(uuid("432B70D9-D650-4401-ACEC-0E9FA4172EE3"))	IsmAuto::IDimRefCustomAction;
struct __declspec(uuid("A91EE73E-11A6-47C9-B28B-ADB9A3E78874"))	IsmAuto::IDimRefCustomActions;
struct __declspec(uuid("D3B67216-E14B-4A85-82DE-B5F3859B5913"))	IsmAuto::IDimRefDialog;
struct __declspec(uuid("5E89CCF8-B760-42A3-BE35-3D7A3902A1E8"))	IsmAuto::IDimRefDialogs;
struct __declspec(uuid("8B515251-B698-4241-9F22-52456479F22B")) IsmAuto::ISuiteOperation;
struct __declspec(uuid("8E20EBA6-A04A-4b4a-9A69-A9E06CCAF87A")) IsmAuto::ISuiteTransaction;
struct __declspec(uuid("C13D3E61-D96F-448e-8D74-22878ECE184D")) IsmAuto::ISuitePackageBase;
struct __declspec(uuid("5BF2A3DA-F2B4-4334-8B08-D31DAEC32F70")) IsmAuto::ISuiteRelease;
struct __declspec(uuid("3180C20E-82B7-4CB6-9290-9C8E6783496B")) IsmAuto::ISuiteReleaseQi;
struct __declspec(uuid("C0AE15A0-9F8C-4545-B37A-2C9F797134AF")) IsmAuto::ISuiteReleaseRipley;
struct __declspec(uuid("307C4D57-B9EF-4EfA-A3D7-66E388B75DFF")) IsmAuto::ISuiteReleases;
struct __declspec(uuid("A806B190-A98C-4d83-8C21-54F10DBC4D94")) IsmAuto::ISuiteFile;
struct __declspec(uuid("17BB2ECA-09BD-4108-8022-3A7CB85E31DE")) IsmAuto::ISuiteFiles;
struct __declspec(uuid("11314180-63C1-4869-BE97-FA0F4D02EE75")) IsmAuto::ISuiteFolder;
struct __declspec(uuid("C1C46B24-673B-4722-8A53-C8F86E3E3D2A")) IsmAuto::ISuiteFolders;
struct __declspec(uuid("E53CEE12-4611-4f79-8918-DCC4D80175C9")) IsmAuto::ISuiteFileEvent;
struct __declspec(uuid("C39A1F89-F956-4991-8EA3-9822D21775D0")) IsmAuto::ISuiteFeature;
struct __declspec(uuid("B015EEED-F1CE-4E39-9898-DC4D7959D531")) IsmAuto::ISuiteFeatureQi;
struct __declspec(uuid("02B5DDD3-7822-4880-8972-3D561B5F1E33")) IsmAuto::ISuiteFeatures;
struct __declspec(uuid("48FA0379-3349-4244-AF60-C260B485874D")) IsmAuto::IImportPrereqEvents;
struct __declspec(uuid("11D52042-08EF-4f9f-A445-73D7C5C3DF8A")) IsmAuto::INetworkShare;
struct __declspec(uuid("F7B40FD5-D05D-4cd6-A77E-DB40C053E89D")) IsmAuto::INetworkShares;
struct __declspec(uuid("53014108-49BB-42BD-A6F4-6FDA09CE1A3E")) IsmAuto::ISuiteDynamicFileLink;
struct __declspec(uuid("2FCF1C39-4B9A-49dB-84ED-AD76F55B4B16")) IsmAuto::ISuiteDynamicFileLinks;
struct __declspec(uuid("EA0BDC43-BEE2-417F-8AAA-82A565193E41")) IsmAuto::ISuiteDFLFilter;
struct __declspec(uuid("4F79AD60-15C1-4E0f-A36B-4087CDA5D923")) IsmAuto::ISuiteDFLFilters;
struct __declspec(uuid("A022AFFA-3CDB-476c-B9B4-2D0E29B20EB2")) IsmAuto::IScheduledTask;
struct __declspec(uuid("BB26E673-E77B-4d48-A060-FF5EA78427C4")) IsmAuto::IScheduledTasks;
struct __declspec(uuid("F92BE187-ADAA-41cf-AF62-6F4C75266181")) IsmAuto::IISPowerShellWrapper;
struct __declspec(uuid("A524FFC7-E57F-45b4-86B7-DB3A4C0FE28F")) IsmAuto::IISPowerShellWrappers;
struct __declspec(uuid("185F4998-82FA-4244-9CE5-03D4B582F206")) IsmAuto::IProjectOpusSP1;
struct __declspec(uuid("0FCD0577-163B-4B17-90B2-CD6CF54C52E0")) IsmAuto::ISuitePackageOpusSP1;
struct __declspec(uuid("E17B2B2D-20BD-4F52-B3DB-9ED4BC422BC7"))	IsmAuto::ISuiteOperationOpusSP1;
struct __declspec(uuid("A989E76D-6B4D-4A68-A7B4-CA3B2D050AA7")) IsmAuto::ISuiteActionRef;
struct __declspec(uuid("041DA750-6825-4D9C-92CB-0E4D7855DD1D")) IsmAuto::ISuiteActionRefs;
struct __declspec(uuid("EE80E7F1-6440-4D61-B629-13916A1ABF6B")) IsmAuto::ISuiteAction;
struct __declspec(uuid("891BAF62-F3A8-4A63-980C-9143FC5FFCBB")) IsmAuto::ISuiteActionRipley;
struct __declspec(uuid("FC21FC40-1DF4-4D35-8BF7-A3C0C74EA5CF")) IsmAuto::ISuiteActions;
struct __declspec(uuid("2EDB3AD8-CFF5-4fD4-8E0D-9B0AD103E10E")) IsmAuto::IProjectRootPunk;
struct __declspec(uuid("885B9D6D-070A-41EF-8048-6B8B8D28E210")) IsmAuto::IProjectRootPunkSP1;
struct __declspec(uuid("DCFB2008-9108-4CBF-B590-DA3786BB5540")) IsmAuto::IProjectRootQi;
struct __declspec(uuid("759B9C37-D580-4634-AB39-80E4DAEEB4E0")) IsmAuto::ISuitePackagePunk;
struct __declspec(uuid("C4684B0B-2880-4C7E-8BDC-AFE390EA95EB")) IsmAuto::ISuitePackageQi;
struct __declspec(uuid("BC90CEC9-7FB6-48DF-9D65-2E49EB06A94F")) IsmAuto::ISuitePackageRipley;
struct __declspec(uuid("B0471260-C7BF-48B8-8BA6-EA88FFBC336A")) IsmAuto::IRemoveFile;
struct __declspec(uuid("F1552A75-3311-4058-848B-83F862962316")) IsmAuto::IRemoveFiles;
struct __declspec(uuid("75B7C6DF-0F92-439E-B214-EC07FD83292B")) IsmAuto::ISuiteWebDeployParameter;
struct __declspec(uuid("640F70FE-557A-4A03-BF25-0DB6980353C5")) IsmAuto::ISuiteWebDeployParameters;
struct __declspec(uuid("247841E2-306C-4537-A49B-CE8F9AA8B24A")) IsmAuto::IProductRipley;
struct __declspec(uuid("5D532D69-A5CA-4FE6-8970-F894D454D05B")) IsmAuto::IPathVariableSetRipley;
struct __declspec(uuid("82737AB6-2E34-4EE4-809E-08E842C57F71")) IsmAuto::IProjectRootRipley;
struct __declspec(uuid("4C8FC3E5-6B0B-44E7-9852-9AC101F930D1")) IsmAuto::IProjectRootSecret;
struct __declspec(uuid("A6570791-2C9A-455C-A414-43706E809A63")) IsmAuto::IISWSEWrap;
struct __declspec(uuid("F244D1BB-48AD-4552-A64B-F86F5CB49240")) IsmAuto::IISWSEWraps;
struct __declspec(uuid("4A435815-5CC5-4A73-87DB-92E986683A9D")) IsmAuto::IIsVisualElement;
struct __declspec(uuid("28F9AF1F-1785-4175-9DB8-9AACE730D09C")) IsmAuto::IIsVisualElements;

// Below defines are used in client code in cases where you just want the latest code always.
// The idea is that we would change these each release and it would cut down on the number of
// QI calls we have to have in code, since anything using something like:
//		CComPtr<IProjectRootL> m_spProjectRoot
// would have to just be recompiled and then the code can call any new methods as needed
// instead of having to add QI calls
namespace IsmAuto
{
typedef IBusinessObjectIronwood IBusinessObjectL;
typedef IComponentSecret IComponentL;
typedef ICreateFolderIndoreSP1 ICreateFolderL;
typedef IFeatureSecret IFeatureL;
typedef IFileIndoreSP1 IFileL;
typedef IProductIbiza IProductL;
typedef IProjectNeo IProjectL;
typedef IProjectRootSecret IProjectRootL;
typedef IQPRootMajesty IQPRootL;
typedef IShortcutLoyaltySP1 IShortcutL;
typedef IXmlFileLoyalty IXmlFileL;
typedef IXmlElementIronwood IXmlElementL;
typedef IXmlNamespaceIronwood IXmlNamespaceL;
typedef ISQLConnectionLoyalty ISQLConnectionL;
typedef ISQLScriptFileNeo ISQLScriptFileL;
typedef ISequenceHeaderJustice ISequenceHeaderL;
typedef ISuitePackageRipley ISuitePackageL;
typedef ISuiteOperationOpusSP1 ISuiteOperationL;
typedef IBuildLabelPunk IBuildLabelL;
typedef IServiceControlPunk IServiceControlL;
typedef IRegistryEntriesPunkSP IRegistryEntriesL;
typedef ILanguageJack ILanguageL;
typedef IIcon2 IIconL;
typedef ISetupFileQi ISetupFileL;
typedef IPropertyJustice IPropertyL;
typedef IPathVariableSetRipley IPathVariableSetL;
typedef IPathVariable2 IPathVariableL;
typedef IStringEntry2 IStringEntryL;
typedef ISuiteReleaseRipley ISuiteReleaseL;
typedef ISuiteFeatureQi ISuiteFeatureL;
typedef ISuiteActionRipley ISuiteActionL;
typedef ISuiteActionRef ISuiteActionRefL;
typedef ISuiteFile ISuiteFileL;
typedef ISuiteFolder ISuiteFolderL;
typedef ISuiteDynamicFileLink ISuiteDynamicFileLinkL;
typedef ISuiteDFLFilter ISuiteDFLFilterL;
}

#ifdef HRX_H
typedef HRX HRX_BOTH;
#else
#include "hrx_new.h"
typedef hrx HRX_BOTH;
#endif

// Used to simulate VB's "for each" using C++
template <class TCollection, class TItem, class TEnumVariant = IsmAuto::IVBEnumVARIANT,
          typename TCount = long, typename TCountPointer = long>
class enumerator
{
public:
    enumerator(TCollection* pCollection) : m_bLight(false)
    {
        HRX_BOTH hr = pCollection->get_NewEnum(&m_spEnum);
    }
    enumerator(TCollection* pCollection, bool bLight) : m_bLight(bLight)
    {
        HRX_BOTH hr = pCollection->get_NewEnum(&m_spEnum);
    }
    enumerator(int, TCollection* pCollection) : m_bLight(false)
    {
        CComPtr<IUnknown> spUnk;
        HRX_BOTH hr = pCollection->get__NewEnum(&spUnk);
        hr = spUnk.QueryInterface(&m_spEnum);
    }
    bool next(CComPtr<TItem>& spItem)
    {
        spItem.Release();

        CComVariant varItem;
        TCount lFetched;
        HRX_BOTH hr = m_spEnum->Next(1, &varItem, (TCountPointer)&lFetched);
        if (lFetched == 0)
        {
            return false;
        }

        if (V_VT(&varItem) == VT_DISPATCH)
        {
            CComPtr<IDispatch> spDisp = V_DISPATCH(&varItem);
            hr = spDisp.QueryInterface(&spItem);
        }
        else if (V_VT(&varItem) == VT_UNKNOWN)
        {
            CComPtr<IUnknown> spUnknown = V_UNKNOWN(&varItem);
            hr = spUnknown.QueryInterface(&spItem);
        }
        else
        {
            hr = E_FAIL;
        }

		CComPtr<IsmAuto::ILightEntry> spLightEntry;
		if(m_bLight && SUCCEEDED(spItem.QueryInterface(&spLightEntry)))
		{
			IsmAuto::VARIANT_BOOL vbExcludeFromEnum;
			hr = spLightEntry->get_ExcludeFromEnumerator(&vbExcludeFromEnum);

			if(vbExcludeFromEnum)
			{
				return next(spItem);
			}
		}
		return true;
    }
private:
    CComPtr<TEnumVariant> m_spEnum;
	bool m_bLight;
};

// Specialization of enumerator for use with IIsStrings
template<>
class enumerator<IsmAuto::IIsStrings, CComBSTR, IsmAuto::IVBEnumVARIANT,
    long, long>
{
public:
    enumerator(IsmAuto::IIsStrings* pCollection)
    {
        HRX_BOTH hr = pCollection->get_NewEnum(&m_spEnum);
    }

    bool next(CComBSTR& bstrItem)
    {
        CComVariant varItem;
        long lFetched;
        HRX_BOTH hr = m_spEnum->Next(1, &varItem, (long)&lFetched);
        if (lFetched == 0)
        {
            return false;
        }

        if (V_VT(&varItem) == VT_BSTR)
        {
            bstrItem = varItem.bstrVal;
        }
        else
        {
            hr = E_FAIL;
        }
        return true;
    }
private:
    CComPtr<IsmAuto::IVBEnumVARIANT> m_spEnum;
};

// Used by CreateWhereClause below for passing a WHERE clause to a
// collection's get_Item
#ifdef __ATLCOM_H__
class ATL_NO_VTABLE CWhereClause :
    public IsmAuto::IWhereClause,
    public CComObjectRootEx<CComObjectThreadModel>
{
public:
    CWhereClause()
    {
    }
    virtual ~CWhereClause()
    {
    }

    BEGIN_COM_MAP(CWhereClause)
        COM_INTERFACE_ENTRY(IsmAuto::IWhereClause)
    END_COM_MAP()

    STDMETHOD(get_WhereClause)(BSTR* pbstrWhereClause)
    {
        return m_bstrWhereClause.CopyTo(pbstrWhereClause);
    }
    STDMETHOD(put_WhereClause)(BSTR bstrWhereClause)
    {
        m_bstrWhereClause = bstrWhereClause;
        return S_OK;
    }
    CComBSTR m_bstrWhereClause;
};

// Used to pass a WHERE clause to a collection's get_Item
inline CComVariant CreateWhereClause(BSTR bstrWhereClause)
{
    CComObject<CWhereClause>* pWhereClause;
    CComObject<CWhereClause>::CreateInstance(&pWhereClause);
    pWhereClause->AddRef();
    pWhereClause->put_WhereClause(bstrWhereClause);
    CComVariant v;
    V_VT(&v) = VT_UNKNOWN;
    V_UNKNOWN(&v) = pWhereClause;
    return v;
}
#endif // #ifdef __ATLCOM_H__

// Link with IsmAutoGuids.lib
#pragma comment( lib, "IsmAutoGuids" )

#endif // #ifndef ISMAUTOWRAPPER_H
