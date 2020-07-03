#pragma once

//////////////////////////////////////////////////////////////////////////
#if _MSC_VER < 1200
#define _VISUALSTUDIO_VERSION "50"
#elif _MSC_VER == 1200
#define _VISUALSTUDIO_VERSION "60"
#elif _MSC_VER == 1300
#define _VISUALSTUDIO_VERSION "70"
#elif _MSC_VER == 1310
#define _VISUALSTUDIO_VERSION "71"
#elif _MSC_VER == 1400
#define _VISUALSTUDIO_VERSION "80"
#elif _MSC_VER == 1500
#define _VISUALSTUDIO_VERSION "90"
#elif _MSC_VER == 1600
#define _VISUALSTUDIO_VERSION "100"
#elif _MSC_VER == 1700
#define _VISUALSTUDIO_VERSION "110"
#elif _MSC_VER == 1916
#define _VISUALSTUDIO_VERSION "141"
#elif _MSC_VER == 1924
#define _VISUALSTUDIO_VERSION "142"
#else
#define _VISUALSTUDIO_VERSION "110"
#endif

#if _MSC_VER < 1700
#define __PRODUCT_VERSION ""
#elif _MSC_VER == 1700
#define __PRODUCT_VERSION "(2012)"
#elif _MSC_VER == 1916 || _MSC_VER == 1900
#define __PRODUCT_VERSION "(2017)"
#elif _MSC_VER == 1924
#define __PRODUCT_VERSION "(2019)"
#endif

//////////////////////////////////////////////////////////////////////////
#if defined(PR_DEBUG)
#define _PROJECT_CONFIGURATION "d"
#else
#define _PROJECT_CONFIGURATION ""
#endif // _DEBUG

#ifdef _WIN64
#define _LIB_PLATFORM "x64"
#else
#define _LIB_PLATFORM ""
#endif

//////////////////////////////////////////////////////////////////////////