#include <iostream>

using namespace std;

#ifdef CPP_COMPILER
    #undef CPP_COMPILER
#endif

#ifdef CPP_COMPILER_VERSION
    #undef CPP_COMPILER_VERSION
#endif


int main()
{
    cout << "This program was compile " << __DATE__ " " << __TIME__ << " in ";

#if defined(__linux__) && !(__ANDROID__)
    cout << "Linux OS";
#endif
#if defined(__ANDROID__)
    cout << "Android OS";
#endif

#if defined(_WIN32) && !(_WIN64)
    cout << "Windows 32 bit";
#endif
#if defined (_WIN64)
    cout << "Windows 64 bit";
#endif

    cout << " by ";

#if defined(__GNUC__) && !(__clang__)
    #define CPP_COMPILER "gcc"
    #define CPP_COMPILER_VERSION __VERSION__
#endif

#if defined(__clang__)
    #define CPP_COMPILER "clang"
    #define CPP_COMPILER_VERSION __VERSION__
#endif

#if defined (_MSC_VER)
    #define CPP_COMPILER "Visual Studio"
    #if _MSC_VER == 800
        #define CPP_COMPILER_VERSION "1"
    #endif
    #if _MSC_VER == 900
        #define CPP_COMPILER_VERSION "3"
    #endif
    #if (_MSC_VER == 1000) || (_MSC_VER == 1020)
        #define CPP_COMPILER_VERSION "4"
    #endif
    #if _MSC_VER == 1100
        #define CPP_COMPILER_VERSION "5"
    #endif
    #if _MSC_VER == 1200
        #define CPP_COMPILER_VERSION "6"
    #endif
    #if (_MSC_VER == 1200) && defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 12008804)
        #define CPP_COMPILER_VERSION "6 SP6"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 13009466)
        #define CPP_COMPILER_VERSION "7"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 13103077)
        #define CPP_COMPILER_VERSION "7.1 (2003)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 140050727)
        #define CPP_COMPILER_VERSION "8 (2005)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 150021022)
        #define CPP_COMPILER_VERSION "9 (2008)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 150030729)
        #define CPP_COMPILER_VERSION "9 SP1"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 160030319)
        #define CPP_COMPILER_VERSION "10 (2010)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 160040219)
        #define CPP_COMPILER_VERSION "10 (2010) SP1"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 170050727)
        #define CPP_COMPILER_VERSION "11 (2012)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 180021005)
        #define CPP_COMPILER_VERSION "12 (2013)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 190023026)
        #define CPP_COMPILER_VERSION "14 (2015)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 190023506)
        #define CPP_COMPILER_VERSION "14 (2015 Update 1)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 190023918)
        #define CPP_COMPILER_VERSION "14 (2015 Update 2)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 190024210)
        #define CPP_COMPILER_VERSION "14 (2015 Update 3)"
    #endif
    #if defined(_MSC_FULL_VER) && (_MSC_FULL_VER == 191025017)
        #define CPP_COMPILER_VERSION "15 (2017 Update 1 & 2)"
    #endif
    #if _MSC_VER == 1911
        #define CPP_COMPILER_VERSION "15 (2017 Update 3 & 4)"
    #endif
    #if _MSC_VER == 1912
        #define CPP_COMPILER_VERSION "15 (2017 Update 5)"
    #endif
#endif

    cout << CPP_COMPILER << " " << CPP_COMPILER_VERSION;
    cout << endl;
    return 0;
}
