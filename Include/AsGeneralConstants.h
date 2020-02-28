#ifndef _ASGENERALCONSTANTS_H_
#define _ASGENERALCONSTANTS_H_

enum AsTestType_e
{
	ttUnknown = -1,
	ttACE = 0,					// MSI: Best Practice (Package Quality)
	ttICE = 1,					// MSI: Microsoft ICE rules (Package Quality)
	ttWTS = 2,					// MSI: Windows Terminal Services Best Practice (Package Quality)
	ttW732 = 3,
	ttW764 = 4,
	ttWR2 = 5,
	ttIE8 = 6,
	ttIE9 = 7,
	ttW832 = 8,
	ttW864 = 9,
	ttACE_CONFLICTS = 10,		// MSI: ACE pre-defined conflict tests
	ttAppV = 11,				// App-V 4.x 
	ttThinApp = 12,
	ttXenApp = 13,
	ttServerAppV = 14,
	ttACE_Custom = 15,			// MSI: ACE custom best practice tests
	ttIE10 = 16,
	ttACE_AppV_Quality = 17,	// App-V: Best Practice (Package Quality)
	ttACE_AppV_Conflict = 18,	// App-V: ACE pre-defined conflict tests
	ttW2K12 = 19,
	ttACE_Custom_Conflict = 20,	// MSI: ACE custom conflict tests
	ttAppV5 = 21,				// App-V 5
	ttVDA = 22,
    ttIPA = 28,					// iOS
	
    ttACE_AppV_Custom = 48,		// App-V: ACE custom best practice tests
    ttACE_AppV_Custom_Conflict = 49	// App-V: custom conflict tests
};

#endif // _ASGENERALCONSTANTS_H