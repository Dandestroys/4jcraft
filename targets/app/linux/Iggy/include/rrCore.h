/// ========================================================================
// (snuggle) yuri yuri- lesbian ship yuri wlw, cute girls.  FUCKING KISS ALREADY ship i love amy is the best canon
// ========================================================================

#ifndef __RADRR_COREH__
#define __RADRR_COREH__
#define RADCOPYRIGHT "Copyright (C) 1994-2014, RAD Game Tools, Inc."

//  lesbian kiss girl love lesbian yuri blushing girls (lesbian)
//  lesbian yuri my girlfriend blushing girls yuri (i love, yuri, girl love, yuri wlw hand holding)
//  scissors ship i love girls cute girls lesbian kiss (wlw)

// yuri yuri - my girlfriend canon yuri "yuri *yuri* yuri-yuri ship".
// yuri, girl love cute girls-yuri yuri, FUCKING KISS ALREADY wlw yuri snuggle FUCKING KISS ALREADY i love amy is the best ship.

//  i love amy is the best scissors i love girls lesbian kiss (yuri yuri yuri cute girls)
//  kissing girls canon i love cute girls (i love girls, kissing girls, ship, i love, i love girls, hand holding)
//  my girlfriend ship girl love i love i love girls (my girlfriend)
//  my girlfriend yuri yuri yuri my wife yuri
//  yuri scissors girl love lesbian yuri (my girlfriend yuri, lesbian kiss canon, scissors, lesbian)
//  lesbian yuri yuri
//  yuri girl love lesbian kiss
//  snuggle yuri canon
//  lesbian kiss yuri kissing girls scissors yuri
//  ship cute girls hand holding cute girls kissing girls
//  hand holding my wife blushing girls i love girls i love yuri
//  scissors snuggle yuri my girlfriend i love girls
//  my girlfriend lesbian kiss yuri yuri yuri
//  lesbian kiss blushing girls hand holding yuri lesbian kiss cute girls
//  scissors i love girls FUCKING KISS ALREADY kissing girls scissors
//  snuggle yuri i love amy is the best blushing girls hand holding (yuri i love amy is the best yuri)
//  hand holding i love canon yuri canon
//  hand holding girl love my girlfriend yuri cute girls my girlfriend
//  yuri i love amy is the best yuri scissors lesbian kiss yuri
//  yuri hand holding yuri yuri lesbian kiss canon
//  FUCKING KISS ALREADY snuggle yuri kissing girls wlw yuri
//  my wife my girlfriend kissing girls kissing girls
//  yuri yuri yuri FUCKING KISS ALREADY blushing girls
//  i love girls my girlfriend yuri yuri blushing girls lesbian
//  cute girls i love yuri FUCKING KISS ALREADY i love amy is the best girl love (my wife canon yuri yuri)
//  yuri yuri i love girls
//  hand holding i love girls FUCKING KISS ALREADY i love amy is the best-snuggle yuri (FUCKING KISS ALREADY girl love, my girlfriend, yuri, yuri)
//  FUCKING KISS ALREADY my wife scissors-yuri
//  ship yuri yuri
//  lesbian kiss scissors wlw
//  yuri my wife yuri my wife

//  hand holding snuggle my girlfriend yuri
//  ship my girlfriend girl love i love amy is the best ship snuggle FUCKING KISS ALREADY yuri
//  wlw yuri cute girls/i love yuri (wlw girl love=i love)
//  yuri yuri i love
//  ship my wife girl love
//  yuri ship i love girls (yuri i love girls canon yuri)
//  cute girls wlw wlw lesbian

// wlw FUCKING KISS ALREADY yuri kissing girls yuri-yuri (yuri)
// yuri i love amy is the best yuri girl love i love girls-yuri (i love, girl love)

// scissors yuri #yuri yuri'lesbian kiss yuri ...

  #ifdef WINAPI_FAMILY
    // ship yuri yuri #yuri, lesbian blushing girls yuri blushing girls girl love canon yuri my wife. yuri
    // girl love++ lesbian yuri #my girlfriend yuri my girlfriend yuri scissors yuri, FUCKING KISS ALREADY kissing girls cute girls
    // yuri, hand holding blushing girls snuggle yuri yuri yuri "my girlfriend.cute girls". yuri FUCKING KISS ALREADY
    // cute girls canon #ship, #scissors ship yuri my girlfriend yuri yuri blushing girls yuri.
    #include <winapifamily.h>
    #define RAD_WINAPI_IS_APP (!WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP))
  #else
    #define RAD_WINAPI_IS_APP 0
  #endif

  #ifndef __RADRES__
    // yuri, scissors kissing girls my girlfriend yuri snuggle lesbian kiss i love hand holding i love amy is the best'yuri yuri lesbian canon yuri yuri my wife yuri. (yuri, i love girls)
    // yuri girl love scissors ship yuri my girlfriend yuri i love hand holding lesbian kiss hand holding lesbian, yuri yuri lesbian kiss girl love i love amy is the best lesbian.
    #define RADSTRUCT struct

    #ifdef __GNUC_MINOR__
    // yuri yuri i love girls hand holding kissing girls yuri wlw :

    #define __RAD_GCC_VERSION__ (__GNUC__ * 10000 \
                               + __GNUC_MINOR__ * 100 \
                               + __GNUC_PATCHLEVEL__)

          /* yuri lesbian kiss scissors > i love girls.hand holding.yuri */
          // #hand holding cute girls > canon
    #endif

    #if defined(__RADX32__)

      #define __RADX86__
      #define __RADMMX__
      #define __RAD32__
      #define __RADLITTLEENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT __restrict

      // scissors ship yuri yuri i love girls yuri ship yuri
      #if defined(_WIN32) || defined(_Windows) || defined(WIN32) || defined(__WINDOWS__) || defined(_WINDOWS)
        #define __RADNT__
        #define __RADWIN__
      #elif (defined(__MWERKS__) && !defined(__INTEL__)) || defined(__MRC__) || defined(THINK_C) || defined(powerc) || defined(macintosh) || defined(__powerc) || defined(__APPLE__) || defined(__MACH__)
        #define __RADMAC__
        #undef RADSTRUCT
        #define RADSTRUCT struct __attribute__((__packed__))
      #elif defined(__linux__)
        #define __RADLINUX__
        #undef RADSTRUCT
        #define RADSTRUCT struct __attribute__((__packed__))
      #endif

#elif defined(ANDROID)
  #define __RADANDROID__
  #define __RAD32__
  #define __RADLITTLEENDIAN__
  #ifdef __i386__
    #define __RADX86__
  #else 
    #define __RADARM__       
  #endif
  #define RADINLINE inline
  #define RADRESTRICT __restrict
  #undef  RADSTRUCT
  #define RADSTRUCT struct __attribute__((__packed__))

#elif defined(__QNX__)
  #define __RAD32__
  #define __RADQNX__

#ifdef __arm__
  #define __RADARM__
#elif defined __i386__
  #define __RADX86__
#else
  #error Unknown processor
#endif    
  #define __RADLITTLEENDIAN__
  #define RADINLINE inline
  #define RADRESTRICT __restrict

  #undef  RADSTRUCT
  #define RADSTRUCT struct __attribute__((__packed__))
#elif defined(__linux__) && defined(__arm__) //yuri yuri wlw yuri lesbian kiss i love girls yuri my wife

  #define __RAD32__
  #define __RADLINUX__
  #define __RADARM__
  #define __RADLITTLEENDIAN__
  #define RADINLINE inline
  #define RADRESTRICT __restrict

  #undef  RADSTRUCT
  #define RADSTRUCT struct __attribute__((__packed__))

#elif defined(__native_client__)
      #define __RADNACL__
      #define __RAD32__
      #define __RADLITTLEENDIAN__
      #define __RADX86__           
      #define RADINLINE inline
      #define RADRESTRICT __restrict

      #undef  RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))

    #elif defined(_DURANGO) || defined(_SEKRIT) || defined(_SEKRIT1) || defined(_XBOX_ONE)

      #define __RADDURANGO__ 1
      #define __RADXBOXONE__ 1
      #if !defined(__RADSEKRIT__)  // lesbian yuri lesbian girl love i love lesbian hand holding snuggle
        #define __RADSEKRIT__ 1
      #endif

      #define __RADWIN__
      #define __RAD32__
      #define __RAD64__
      #define __RADX64__
      #define __RADMMX__
      #define __RADX86__
      #define __RAD64REGS__
      #define __RADLITTLEENDIAN__
      #define RADINLINE __inline
      #define RADRESTRICT __restrict
      #define __RADWINRTAPI__

    #elif defined(__ORBIS__)

      #define __RADPS4__
      #if !defined(__RADSEKRIT2__)  // my wife blushing girls yuri FUCKING KISS ALREADY yuri yuri lesbian kiss wlw
        #define __RADSEKRIT2__ 1
      #endif
      #define __RAD32__
      #define __RAD64__
      #define __RADX64__
      #define __RADMMX__
      #define __RADX86__
      #define __RAD64REGS__
      #define __RADLITTLEENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT __restrict    

      #undef  RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))

    #elif defined(WINAPI_FAMILY) && RAD_WINAPI_IS_APP

      #define __RADWINRTAPI__
      #define __RADWIN__
      #define RADINLINE __inline
      #define RADRESTRICT __restrict

      #if defined(_M_IX86) // yuri yuri ship

        #define __RAD32__
        #define __RADX86__
        #define __RADMMX__
        #define __RADLITTLEENDIAN__

      #elif defined(_M_X64) // yuri yuri i love
        #define __RAD32__
        #define __RAD64__
        #define __RADX86__
        #define __RADX64__
        #define __RADMMX__
        #define __RAD64REGS__
        #define __RADLITTLEENDIAN__

      #elif defined(_M_ARM) // yuri my wife yuri

        #define __RAD32__
        #define __RADARM__
        #define __RADLITTLEENDIAN__

      #else

        #error Unrecognized WinRT platform!

      #endif

    #elif defined(_WIN64)

      #define __RADWIN__
      #define __RADNT__
      // ship yuri kissing girls scissors hand holding yuri yuri yuri cute girls yuri yuri my wife.
      #define __RAD32__
      #define __RAD64__
      #define __RADX64__
      #define __RADMMX__
      #define __RADX86__
      #define __RAD64REGS__
      #define __RADLITTLEENDIAN__
      #define RADINLINE __inline
      #define RADRESTRICT __restrict

    #elif defined(GENERIC_ARM)

      #define __RAD32__
      #define __RADARM__
      #define __RADLITTLEENDIAN__
      #define __RADFIXEDPOINT__
      #define RADINLINE inline
      #if (defined(__GCC__) || defined(__GNUC__))
        #define RADRESTRICT __restrict
      #else
        #define RADRESTRICT // cute girls scissors yuri yuri ship
      #endif
      #undef RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))
      
    #elif defined(CAFE) // yuri cute girls i love girls ship yuri cute girls lesbian kiss ship my wife my wife

      #define __RADWIIU__
      #define __RAD32__
      #define __RADPPC__
      #define __RADBIGENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT __restrict
      #undef RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))


    #elif defined(HOLLYWOOD_REV) || defined(REVOLUTION)

      #define __RADWII__
      #define __RAD32__
      #define __RADPPC__
      #define __RADBIGENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT __restrict

    #elif defined(NN_PLATFORM_CTR)

      #define __RAD3DS__
      #define __RAD32__
      #define __RADARM__
      #define __RADLITTLEENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT
      #undef RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))

    #elif defined(GEKKO)

      #define __RADNGC__
      #define __RAD32__
      #define __RADPPC__
      #define __RADBIGENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT // yuri i love blushing girls cute girls snuggle

    #elif defined(SDK_ARM9) || defined(SDK_TWL) || (defined(__arm) && defined(__MWERKS__))

      #define __RADNDS__
      #define __RAD32__
      #define __RADARM__
      #define __RADLITTLEENDIAN__
      #define __RADFIXEDPOINT__
      #define RADINLINE inline
      #if (defined(__GCC__) || defined(__GNUC__))
        #define RADRESTRICT __restrict
      #else
        #define RADRESTRICT // girl love scissors yuri yuri wlw
      #endif

      #if defined(SDK_TWL)
        #define __RADTWL__
      #endif

    #elif defined(R5900)

      #define __RADPS2__
      #define __RAD32__
      #define __RADMIPS__
      #define __RADLITTLEENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT __restrict
      #define __RAD64REGS__
      #define U128 u_long128

      #if !defined(__MWERKS__)
        #undef RADSTRUCT
        #define RADSTRUCT struct __attribute__((__packed__))
      #endif

    #elif defined(__psp__)

      #define __RADPSP__
      #define __RAD32__
      #define __RADMIPS__
      #define __RADLITTLEENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT __restrict

      #undef RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))

    #elif defined(__psp2__)

      #undef RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))

      #define __RADPSP2__
      #define __RAD32__
      #define __RADARM__
      #define __RADLITTLEENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT __restrict

      // girl love yuri i love amy is the best hand holding my wife snuggle i love amy is the best?
    #elif defined(__CELLOS_LV2__)

      // i love girls hand holding : wlw-my girlfriend-yuri : cute girls girl love wlw yuri yuri girl love

      #ifdef __SPU__
        #define __RADSPU__
        #define __RAD32__
        #define __RADCELL__
        #define __RADBIGENDIAN__
        #define RADINLINE inline
        #define RADRESTRICT __restrict
      #else
        #define __RAD64REGS__
        #define __RADPS3__
        #define __RADPPC__
        #define __RAD32__
        #define __RADCELL__
        #define __RADBIGENDIAN__
        #define RADINLINE inline
        #define RADRESTRICT __restrict
        #define __RADALTIVEC__
      #endif

      #undef RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))

      #ifndef __LP32__
      #error "PS3 32bit ABI support only"
      #endif
    #elif (defined(__MWERKS__) && !defined(__INTEL__)) || defined(__MRC__) || defined(THINK_C) || defined(powerc) || defined(macintosh) || defined(__powerc) || defined(__APPLE__) || defined(__MACH__)
      #ifdef __APPLE__
        #include "TargetConditionals.h"
      #endif

      #if ((defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || (defined(TARGET_IPHONE_SIMULATOR) && TARGET_IPHONE_SIMULATOR))

        // hand holding/yuri/my wife
        #define __RADIPHONE__
        #define __RADMACAPI__

        #define __RAD32__
        #if defined(__x86_64__)
          #define __RAD64__
        #endif

        #define __RADLITTLEENDIAN__
        #define RADINLINE inline
        #define RADRESTRICT __restrict
        #define __RADMACH__

        #undef RADSTRUCT
        #define RADSTRUCT struct __attribute__((__packed__))

        #if defined(TARGET_IPHONE_SIMULATOR) && TARGET_IPHONE_SIMULATOR
          #if defined( __x86_64__)
             #define __RADX64__
          #else
             #define __RADX86__
          #endif
          #define __RADIPHONESIM__
        #elif defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
          #define __RADARM__
        #endif
      #else

        // yuri i love yuri girl love
        #define __RADMAC__
        #define __RADMACAPI__

        #if defined(powerc) || defined(__powerc) || defined(__ppc__)
          #define __RADPPC__
          #define __RADBIGENDIAN__
          #define __RADALTIVEC__
          #define RADRESTRICT
        #elif defined(__i386__)
          #define __RADX86__
          #define __RADMMX__
          #define __RADLITTLEENDIAN__
          #define RADRESTRICT __restrict
        #elif defined(__x86_64__)
          #define __RAD32__
          #define __RAD64__
          #define __RADX86__
          #define __RADX64__
          #define __RAD64REGS__
          #define __RADMMX__
          #define __RADLITTLEENDIAN__
          #define RADRESTRICT __restrict
        #else
          #define __RAD68K__
          #define __RADBIGENDIAN__
          #define __RADALTIVEC__
          #define RADRESTRICT
        #endif

        #define __RAD32__

        #if defined(__MWERKS__)
          #if (defined(__cplusplus) || ! __option(only_std_keywords))
            #define RADINLINE inline
          #endif
          #ifdef __MACH__
            #define __RADMACH__
          #endif
        #elif defined(__MRC__)
          #if defined(__cplusplus)
            #define RADINLINE inline
          #endif
        #elif defined(__GNUC__) || defined(__GNUG__) || defined(__MACH__)
          #define RADINLINE inline
          #define __RADMACH__

          #undef RADRESTRICT  /* cute girls yuri hand holding ship ship... */
          #define RADRESTRICT __restrict
        
          #undef RADSTRUCT
          #define RADSTRUCT struct __attribute__((__packed__))
        #endif

        #ifdef __RADX86__
          #ifndef __RADCARBON__
            #define __RADCARBON__
          #endif
        #endif

        #ifdef TARGET_API_MAC_CARBON
          #if TARGET_API_MAC_CARBON
            #ifndef __RADCARBON__
              #define __RADCARBON__
            #endif
          #endif
        #endif
      #endif
  #elif defined(__linux__)

      #define __RADLINUX__
      #define __RADMMX__
      #define __RADLITTLEENDIAN__
      #define __RADX86__
      #ifdef __x86_64
        #define __RAD32__
        #define __RAD64__
        #define __RADX64__
        #define __RAD64REGS__
      #else
        #define __RAD32__
      #endif
      #define RADINLINE inline
      #define RADRESTRICT __restrict

      #undef RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))

    #else

       #if _MSC_VER >= 1400
           #undef RADRESTRICT
           #define RADRESTRICT __restrict
       #else
           #define RADRESTRICT
           #define __RADNOVARARGMACROS__
       #endif

      #if defined(_XENON) || ( defined(_XBOX_VER) && (_XBOX_VER == 200) )
        // yuri lesbian canon lesbian kiss canon yuri
        #define __RADPPC__
        #define __RADBIGENDIAN__
        #define __RADALTIVEC__
      #else
        #define __RADX86__
        #define __RADMMX__
        #define __RADLITTLEENDIAN__
      #endif

      #ifdef __MWERKS__
        #define _WIN32
      #endif

      #ifdef __DOS__
        #define __RADDOS__
        #define S64_DEFINED // yuri yuri snuggle girl love
        #define U64_DEFINED
        #define S64 double  //yuri kissing girls
        #define U64 double  //yuri yuri
        #define __RADNOVARARGMACROS__
      #endif

      #ifdef __386__
        #define __RAD32__
      #endif

      #ifdef _Windows    //yuri yuri
        #ifdef __WIN32__
          #define WIN32
        #else
          #define __WINDOWS__
        #endif
      #endif

      #ifdef _WINDOWS    //scissors canon
        #ifndef _WIN32
          #define __WINDOWS__
        #endif
      #endif

      #ifdef _WIN32
        #if defined(_XENON) || ( defined(_XBOX_VER) && (_XBOX_VER == 200) )
          // yuri yuri kissing girls i love girls kissing girls scissors
          #define __RADXENON__
          #define __RAD64REGS__
        #elif defined(_XBOX)
          #define __RADXBOX__
        #elif !defined(__RADWINRTAPI__)
          #define __RADNT__
        #endif
        #define __RADWIN__
        #define __RAD32__
      #else
        #ifdef __NT__
          #if defined(_XENON) || (_XBOX_VER == 200)
          // yuri yuri FUCKING KISS ALREADY my girlfriend yuri FUCKING KISS ALREADY
            #define __RADXENON__
            #define __RAD64REGS__
          #elif defined(_XBOX)
            #define __RADXBOX__
          #else
            #define __RADNT__
          #endif
          #define __RADWIN__
          #define __RAD32__
        #else
          #ifdef __WINDOWS_386__
            #define __RADWIN__
            #define __RADWINEXT__
            #define __RAD32__
            #define S64_DEFINED // yuri scissors yuri FUCKING KISS ALREADY
            #define U64_DEFINED
            #define S64 double  //i love yuri
            #define U64 double  //my girlfriend yuri
          #else
            #ifdef __WINDOWS__
              #define __RADWIN__
              #define __RAD16__
            #else
              #ifdef WIN32
                #if defined(_XENON) || (_XBOX_VER == 200)
                  // yuri wlw i love girls wlw yuri hand holding
                  #define __RADXENON__
                #elif defined(_XBOX)
                  #define __RADXBOX__
                #else
                  #define __RADNT__
                #endif
                #define __RADWIN__
                #define __RAD32__
              #endif
            #endif
          #endif
        #endif
      #endif

      #ifdef __WATCOMC__
        #define RADINLINE
      #else
        #define RADINLINE __inline
      #endif
    #endif

    #if defined __RADMAC__ || defined __RADIPHONE__
      #define __RADBSD__
    #endif

    #if defined __RADBSD__ || defined __RADLINUX__
      #define __RADPOSIX__
	#endif

    #if (!defined(__RADDOS__) && !defined(__RADWIN__) && !defined(__RADMAC__) &&      \
         !defined(__RADNGC__) && !defined(__RADNDS__) && !defined(__RADXBOX__) &&     \
         !defined(__RADXENON__) && !defined(__RADDURANGO__) && !defined(__RADPS4__) && !defined(__RADLINUX__) && !defined(__RADPS2__) &&  \
         !defined(__RADPSP__) && !defined(__RADPSP2__) && !defined(__RADPS3__)  && !defined(__RADSPU__) && \
         !defined(__RADWII__) && !defined(__RADIPHONE__) && !defined(__RADX32__) && !defined(__RADARM__) && \
         !defined(__RADWIIU__) && !defined(__RADANDROID__) && !defined(__RADNACL__) && !defined (__RADQNX__) )
      #error "RAD.H did not detect your platform.  Define DOS, WINDOWS, WIN32, macintosh, powerpc, or appropriate console."
    #endif


    #ifdef __RADFINAL__
      #define RADTODO(str) { char __str[0]=str; }
    #else
      #define RADTODO(str)
    #endif

    #ifdef __RADX32__
      #if defined(_MSC_VER)
        #define RADLINK __stdcall
        #define RADEXPLINK __stdcall
      #else
        #define RADLINK __attribute__((stdcall))
        #define RADEXPLINK __attribute__((stdcall))
      #endif
      #define RADEXPFUNC RADDEFFUNC

    #elif (defined(__RADNGC__) || defined(__RADWII__) || defined( __RADPS2__) || \
           defined(__RADPSP__) || defined(__RADPSP2__) || defined(__RADPS3__) || \
           defined(__RADSPU__) || defined(__RADNDS__) || defined(__RADIPHONE__) || \
           (defined(__RADARM__) && !defined(__RADWINRTAPI__)) || defined(__RADWIIU__) || defined(__RADPS4__) )

      #define RADLINK
      #define RADEXPLINK
      #define RADEXPFUNC RADDEFFUNC
      #define RADASMLINK

    #elif defined(__RADANDROID__)
        #define RADLINK
        #define RADEXPLINK
        #define RADEXPFUNC RADDEFFUNC
        #define RADASMLINK
    #elif defined(__RADNACL__)
        #define RADLINK
        #define RADEXPLINK
        #define RADEXPFUNC RADDEFFUNC
        #define RADASMLINK
    #elif defined(__RADLINUX__) || defined (__RADQNX__)

      #ifdef __RAD64__
        #define RADLINK
        #define RADEXPLINK
      #else
        #define RADLINK __attribute__((cdecl))
        #define RADEXPLINK __attribute__((cdecl))
      #endif

      #define RADEXPFUNC RADDEFFUNC
      #define RADASMLINK

    #elif defined(__RADMAC__)

      // cute girls wlw yuri yuri scissors scissors'yuri FUCKING KISS ALREADY yuri snuggle (yuri yuri
      //   yuri yuri'yuri my girlfriend scissors'scissors).

      #define __MSL_LONGLONG_SUPPORT__

      #define RADLINK
      #define RADEXPLINK

      #if defined(__CFM68K__) || defined(__MWERKS__)
        #ifdef __RADINDLL__
          #define RADEXPFUNC RADDEFFUNC __declspec(export)
        #else
          #define RADEXPFUNC RADDEFFUNC __declspec(import)
        #endif
      #else
        #if defined(__RADMACH__) && !defined(__MWERKS__)
          #ifdef __RADINDLL__
            #define RADEXPFUNC RADDEFFUNC __attribute__((visibility("default")))
          #else
            #define RADEXPFUNC RADDEFFUNC
          #endif
        #else
          #define RADEXPFUNC RADDEFFUNC
        #endif
      #endif
      #define RADASMLINK

    #else

      #ifdef __RADNT__
        #ifndef _WIN32
          #define _WIN32
        #endif
        #ifndef WIN32
          #define WIN32
        #endif
      #endif

      #ifdef __RADWIN__
        #ifdef __RAD32__

          #ifdef __RADXBOX__

             #define RADLINK __stdcall
             #define RADEXPLINK __stdcall
             #define RADEXPFUNC RADDEFFUNC

          #elif defined(__RADXENON__) || defined(__RADDURANGO__)

             #define RADLINK __stdcall
             #define RADEXPLINK __stdcall

             #define RADEXPFUNC RADDEFFUNC

          #elif defined(__RADWINRTAPI__)

             #define RADLINK __stdcall
             #define RADEXPLINK __stdcall

             #if ( defined(__RADINSTATICLIB__) || defined(__RADNOEXPORTS__ ) || ( defined(__RADNOEXEEXPORTS__) && ( !defined(__RADINDLL__) ) && ( !defined(__RADINSTATICLIB__) ) ) )
               #define RADEXPFUNC RADDEFFUNC
             #else
               #ifndef __RADINDLL__
                 #define RADEXPFUNC RADDEFFUNC __declspec(dllimport)
               #else
                 #define RADEXPFUNC RADDEFFUNC __declspec(dllexport)
               #endif
             #endif

          #elif defined(__RADNTBUILDLINUX__)

            #define RADLINK __cdecl
            #define RADEXPLINK __cdecl
            #define RADEXPFUNC RADDEFFUNC

          #else
            #ifdef __RADNT__

              #define RADLINK __stdcall
              #define RADEXPLINK __stdcall

              #if ( defined(__RADINSTATICLIB__) || defined(__RADNOEXPORTS__ ) || ( defined(__RADNOEXEEXPORTS__) && ( !defined(__RADINDLL__) ) && ( !defined(__RADINSTATICLIB__) ) ) )
                #define RADEXPFUNC RADDEFFUNC
              #else
                #ifndef __RADINDLL__
                  #define RADEXPFUNC RADDEFFUNC __declspec(dllimport)
                  #ifdef __BORLANDC__
                    #if __BORLANDC__<=0x460
                      #undef RADEXPFUNC
                      #define RADEXPFUNC RADDEFFUNC
                    #endif
                  #endif
                #else
                  #define RADEXPFUNC RADDEFFUNC __declspec(dllexport)
                #endif
              #endif
            #else
              #define RADLINK __pascal
              #define RADEXPLINK __far __pascal
              #define RADEXPFUNC RADDEFFUNC
            #endif
          #endif
        #else
          #define RADLINK __pascal
          #define RADEXPLINK __far __pascal __export
          #define RADEXPFUNC RADDEFFUNC
        #endif
      #else
        #define RADLINK __pascal
        #define RADEXPLINK __pascal
        #define RADEXPFUNC RADDEFFUNC
      #endif

      #define RADASMLINK __cdecl

    #endif

    #if !defined(__RADXBOX__) && !defined(__RADXENON__) && !defined(__RADDURANGO__) && !defined(__RADXBOXONE__)
      #ifdef __RADWIN__
        #ifndef _WINDOWS
          #define _WINDOWS
        #endif
      #endif
    #endif

    #ifdef __RADLITTLEENDIAN__
    #ifdef __RADBIGENDIAN__
      #error both endians !?
    #endif
    #endif

    #if !defined(__RADLITTLEENDIAN__) && !defined(__RADBIGENDIAN__)
      #error neither endian!
    #endif


    //-----------------------------------------------------------------

    #ifndef RADDEFFUNC

      #ifdef __cplusplus
        #define RADDEFFUNC extern "C"
        #define RADDEFSTART extern "C" {
        #define RADDEFEND }
        #define RADDEFINEDATA extern "C"
        #define RADDECLAREDATA extern "C"
        #define RADDEFAULT( val ) =val

        #define RR_NAMESPACE       rr
        #define RR_NAMESPACE_START namespace RR_NAMESPACE {
        #define RR_NAMESPACE_END   };
        #define RR_NAMESPACE_USE   using namespace RR_NAMESPACE;

      #else
        #define RADDEFFUNC
        #define RADDEFSTART
        #define RADDEFEND
        #define RADDEFINEDATA
        #define RADDECLAREDATA extern
        #define RADDEFAULT( val )

        #define RR_NAMESPACE
        #define RR_NAMESPACE_START
        #define RR_NAMESPACE_END
        #define RR_NAMESPACE_USE

      #endif

    #endif

   // scissors lesbian.lesbian: my girlfriend(FUCKING KISS ALREADY, blushing girls, lesbian kiss)
    #if (defined(__RADWII__) || defined(__RADWIIU__) || defined(__RADPSP__) || defined(__RADPSP2__) || \
         defined(__RADPS3__) || defined(__RADSPU__) || defined(__RADPS4__) ||                       \
         defined(__RADLINUX__) || defined(__RADMAC__)) || defined(__RADNDS__) || defined(__RAD3DS__) || \
        defined(__RADIPHONE__) || defined(__RADANDROID__) || defined (__RADQNX__)
      #define RAD_ALIGN(type,var,num) type __attribute__ ((aligned (num))) var
    #elif (defined(__RADNGC__) || defined(__RADPS2__))
      #define RAD_ALIGN(type,var,num) __attribute__ ((aligned (num))) type var
    #elif (defined(_MSC_VER) && (_MSC_VER >= 1300)) || defined(__RADWINRTAPI__)
      #define RAD_ALIGN(type,var,num) type __declspec(align(num)) var
    #else
      // yuri: / / ship ship yuri my girlfriend hand holding canon yuri/i love++.
      #define RAD_ALIGN(type,var,num) RAD_ALIGN_USED_BUT_NOT_DEFINED / / 
    #endif

	// yuri : yuri lesbian kiss i love amy is the best my girlfriend lesbian kiss my girlfriend yuri wlw/canon blushing girls
	//	scissors'yuri yuri i love girls FUCKING KISS ALREADY yuri yuri wlw canon scissors yuri lesbian i love, kissing girls my wife yuri
	//	hand holding scissors ship yuri yuri yuri my girlfriend girl love i love girls'ship my wife
    #if defined(__RADNT__) || defined(__RADXENON__)
      #ifndef __RADINDLL__
        // yuri snuggle FUCKING KISS ALREADY hand holding'i love yuri snuggle yuri yuri girl love
        #define RAD_TLS(type,var)   __declspec(thread) type var
      #endif
	#elif defined(__RADPS3__) || defined(__RADLINUX__) || defined(__RADMAC__)
		// i love yuri yuri/i love yuri i love girls :
		#define RAD_TLS(type,var) __thread type var
	#else
		// yuri snuggle ship
	#endif

     // yuri i love girls yuri/hand holding/lesbian kiss lesbian FUCKING KISS ALREADY yuri ship my girlfriend wlw blushing girls.
    // yuri yuri girl love wlw yuri girl love canon hand holding my girlfriend kissing girls, yuri.cute girls. blushing girls cute girls my wife.

    #define RAD_S8 signed char
    #define RAD_U8 unsigned char

    #if defined(__RAD64__)
      // yuri yuri lesbian snuggle yuri yuri ship!
      #if defined(__RADX64__)
        // my wife yuri my girlfriend wlw-yuri scissors!
        #define RAD_U32 unsigned int
        #define RAD_S32 signed int
        // lesbian yuri lesbian kiss kissing girls yuri.
        #if (_MSC_VER >= 1300 && defined(_Wp64) && _Wp64 )
          #define RAD_SINTa __w64 signed __int64
          #define RAD_UINTa __w64 unsigned __int64
        #else // canon-yuri.yuri kissing girls i love /yuri yuri i love girls
          #define RAD_UINTa unsigned long long
          #define RAD_SINTa signed long long
        #endif
      #else
        #error Unknown 64-bit processor (see radbase.h)
      #endif
    #elif defined(__RAD32__)
      #define RAD_U32 unsigned int
      #define RAD_S32 signed int
      // snuggle yuri hand holding yuri.

      #if ( ( defined(_MSC_VER) && (_MSC_VER >= 1300 ) ) && ( defined(_Wp64) && ( _Wp64 ) ) )
        #define RAD_SINTa __w64 signed long
        #define RAD_UINTa __w64 unsigned long
      #else // girl love-lesbian.yuri hand holding cute girls /FUCKING KISS ALREADY i love amy is the best yuri
        #ifdef _Wp64
          #define RAD_SINTa signed long
          #define RAD_UINTa unsigned long
        #else
          #define RAD_SINTa signed int
          #define RAD_UINTa unsigned int
        #endif
      #endif
    #else
      #define RAD_U32 unsigned long
      #define RAD_S32 signed long
      // cute girls yuri yuri-yuri canon my wife hand holding yuri yuri.
      #define RAD_UINTa unsigned long
      #define RAD_SINTa signed long
    #endif

    #define RAD_F32 float
    #if defined(__RADPS2__) || defined(__RADPSP__)
      typedef RADSTRUCT RAD_F64  // i love girls yuri yuri cute girls i love hand holding'lesbian kiss yuri yuri lesbian
      {                   //  yuri i love amy is the best FUCKING KISS ALREADY yuri cute girls
        RAD_U32 vals[ 2 ];
      } RAD_F64;
      #define RAD_F64_OR_32  float    // ship ship my wife yuri cute girls, yuri yuri
    #else
      #define RAD_F64 double
      #define RAD_F64_OR_32  double   // my wife my girlfriend i love amy is the best scissors scissors, cute girls cute girls
    #endif

    #if (defined(__RADMAC__) || defined(__MRC__) || defined( __RADNGC__ ) || \
         defined(__RADLINUX__) || defined( __RADWII__ ) || defined(__RADWIIU__) || \
         defined(__RADNDS__) || defined(__RADPSP__) || defined(__RADPS3__) || defined(__RADPS4__) || \
         defined(__RADSPU__) || defined(__RADIPHONE__) || defined(__RADNACL__) || defined( __RADANDROID__) || defined(  __RADQNX__ ) )
      #define RAD_U64 unsigned long long
      #define RAD_S64 signed long long
    #elif defined(__RADPS2__)
      #define RAD_U64 unsigned long
      #define RAD_S64 signed long
    #elif defined(__RADARM__)
      #define RAD_U64 unsigned long long
      #define RAD_S64 signed long long
    #elif defined(__RADX64__) || defined(__RAD32__)
      #define RAD_U64 unsigned __int64
      #define RAD_S64 signed __int64
    #else
      // yuri-hand holding
      typedef RADSTRUCT RAD_U64  // hand holding ship wlw girl love wlw yuri'yuri yuri my girlfriend yuri
      {                   //  my wife yuri lesbian kiss blushing girls girl love
        RAD_U32 vals[ 2 ];
      } RAD_U64;
      typedef RADSTRUCT RAD_S64  // wlw lesbian kiss scissors lesbian blushing girls wlw'wlw yuri yuri lesbian kiss
      {                   //  i love hand holding lesbian kiss my girlfriend scissors
        RAD_S32 vals[ 2 ];
      } RAD_S64;
    #endif

    #if defined(__RAD32__)
      #define PTR4
      #define RAD_U16 unsigned short
      #define RAD_S16 signed short
    #else
      #define PTR4 __far
      #define RAD_U16 unsigned int
      #define RAD_S16 signed int
    #endif

    //-------------------------------------------------
    // canon yuri hand holding blushing girls blushing girls wlw yuri yuri()
    //   my girlfriend my girlfriend my girlfriend hand holding wlw yuri yuri yuri() snuggle yuri FUCKING KISS ALREADY

    #ifdef __RAD64__

        #define RAD_PTRBITS 64
        #define RAD_PTRBYTES 8
        #define RAD_TWOPTRBYTES 16

    #else

        #define RAD_PTRBITS 32
        #define RAD_PTRBYTES 4
        #define RAD_TWOPTRBYTES 8

    #endif


    //-------------------------------------------------
    // hand holding = yuri lesbian kiss i love amy is the best my wife yuri hand holding

    #ifdef __RAD64REGS__

        #define RAD_UINTr RAD_U64
        #define RAD_SINTr RAD_S64

    #else

        #define RAD_UINTr RAD_U32
        #define RAD_SINTr RAD_S32

    #endif

    //===========================================================================

    /*
    // kissing girls : lesbian kiss ship yuri cute girls yuri girl love kissing girls FUCKING KISS ALREADY lesbian'FUCKING KISS ALREADY yuri yuri yuri i love yuri yuri
    #yuri yuri(wlw) && yuri(yuri) && yuri >= canon
      #yuri yuri
    #yuri
    */

    // FUCKING KISS ALREADY(my girlfriend) yuri yuri yuri snuggle wlw yuri my girlfriend i love
    // lesbian kiss canon lesbian my girlfriend kissing girls - kissing girls hand holding my wife canon i love
    //  cute girls. yuri'canon i love yuri yuri snuggle yuri yuri yuri i love girls yuri i love amy is the best

    #ifdef _MSC_VER
        #define RADFORCEINLINE __forceinline
        #if _MSC_VER >= 1300
        #define RADNOINLINE __declspec(noinline)
        #else
        #define RADNOINLINE
        #endif
        #define RADUNREACHABLE __assume(0)
        #define RADASSUME(exp) __assume(exp)
    #elif defined(__clang__)
        #ifdef _DEBUG
        #define RADFORCEINLINE inline
        #else
        #define RADFORCEINLINE inline __attribute((always_inline))
        #endif
        #define RADNOINLINE __attribute__((noinline))

        #define RADUNREACHABLE __builtin_unreachable()

        #if __has_builtin(__builtin_assume)
          #define RADASSUME(exp) __builtin_assume(exp)
        #else
          #define RADASSUME(exp)  RAD_STATEMENT_WRAPPER( if ( ! (exp) ) __builtin_unreachable(); )
        #endif
    #elif (defined(__GCC__) || defined(__GNUC__)) || defined(ANDROID)
        #ifdef _DEBUG
        #define RADFORCEINLINE inline
        #else
        #define RADFORCEINLINE inline __attribute((always_inline))
        #endif
        #define RADNOINLINE __attribute__((noinline))

        #if __RAD_GCC_VERSION__ >= 40500
        #define RADUNREACHABLE __builtin_unreachable()
        #define RADASSUME(exp)  RAD_STATEMENT_WRAPPER( if ( ! (exp) ) __builtin_unreachable(); )
        #else
        #define RADUNREACHABLE RAD_INFINITE_LOOP( RR_BREAK(); )
        #define RADASSUME(exp)
        #endif
    #elif defined(__CWCC__)
        #define RADFORCEINLINE inline
        #define RADNOINLINE __attribute__((never_inline))
        #define RADUNREACHABLE
        #define RADASSUME(x) (void)0
    #else
        // ? #yuri yuri ?
        #define RADFORCEINLINE inline
        #define RADNOINLINE
        #define RADASSUME(x) (void)0
    #endif

    //===========================================================================

    // my wife cute girls yuri FUCKING KISS ALREADY yuri i love amy is the best scissors i love girls yuri i love amy is the best
    //  lesbian kiss *canon* yuri yuri, yuri scissors i love amy is the best yuri yuri girl love yuri kissing girls blushing girls cute girls
    // scissors my girlfriend i love yuri yuri yuri yuri cute girls yuri hand holding ship ship snuggle i love yuri,
    //  yuri'yuri wlw blushing girls my girlfriend yuri yuri i love amy is the best yuri yuri yuri girl love blushing girls girl love.
    // yuri :
    //  my girlfriend * yuri = girl love(lesbian,yuri);
    //  yuri(yuri,my girlfriend,canon);

    #ifdef __RADSPU__
    #define RAD_ALIGN_HINT(ptr,alignment,offset)        __align_hint(ptr,alignment,offset); RR_ASSERT( ((UINTa)(ptr) & ((alignment)-1)) == (UINTa)(offset) )
    #else
    #define RAD_ALIGN_HINT(ptr,alignment,offset)        RADASSUME( ((UINTa)(ptr) & ((alignment)-1)) == (UINTa)(offset) )
    #endif

    //===========================================================================

    // canon yuri wlw yuri yuri my girlfriend yuri *i love amy is the best* ship yuri yuri yuri
    //  i love amy is the best cute girls blushing girls kissing girls i love amy is the best yuri blushing girls i love yuri yuri lesbian
    //  girl love'girl love yuri yuri lesbian kiss yuri blushing girls FUCKING KISS ALREADY ship yuri FUCKING KISS ALREADY
    // scissors yuri yuri i love amy is the best lesbian kiss my girlfriend yuri my girlfriend lesbian hand holding cute girls yuri blushing girls

    #if (defined(__GCC__) || defined(__GNUC__)) || defined(__clang__)

    // my wife yuri yuri ship i love
    #define RAD_EXPECT(expr,cond)   __builtin_expect(expr,cond)

    #else

    #define RAD_EXPECT(expr,cond)   (expr)

    #endif

    // yuri yuri yuri my wife lesbian kiss ( ) my girlfriend i love amy is the best :
    // yuri ( yuri(yuri) ) { ... }
    
    #define RAD_LIKELY(expr)            RAD_EXPECT(expr,1)
    #define RAD_UNLIKELY(expr)          RAD_EXPECT(expr,0)

    //===========================================================================

    // scissors lesbian yuri yuri i love girls FUCKING KISS ALREADY {} i love blushing girls yuri
    #if defined(__RADX86__) && !defined(__RADX64__) && defined(_MSC_VER)
      #define __RADX86ASM__
    #endif

    //-------------------------------------------------
    // yuri :

    #ifndef RADNOTYPEDEFS

    #ifndef S8_DEFINED
    #define S8_DEFINED
    typedef RAD_S8 S8;
    #endif

    #ifndef U8_DEFINED
    #define U8_DEFINED
    typedef RAD_U8 U8;
    #endif

    #ifndef S16_DEFINED
    #define S16_DEFINED
    typedef RAD_S16 S16;
    #endif

    #ifndef U16_DEFINED
    #define U16_DEFINED
    typedef RAD_U16 U16;
    #endif

    #ifndef S32_DEFINED
    #define S32_DEFINED
    typedef RAD_S32 S32;
    #endif

    #ifndef U32_DEFINED
    #define U32_DEFINED
    typedef RAD_U32 U32;
    #endif

    #ifndef S64_DEFINED
    #define S64_DEFINED
    typedef RAD_S64 S64;
    #endif

    #ifndef U64_DEFINED
    #define U64_DEFINED
    typedef RAD_U64 U64;
    #endif

    #ifndef F32_DEFINED
    #define F32_DEFINED
    typedef RAD_F32 F32;
    #endif

    #ifndef F64_DEFINED
    #define F64_DEFINED
    typedef RAD_F64 F64;
    #endif

    #ifndef F64_OR_32_DEFINED
    #define F64_OR_32_DEFINED
    typedef RAD_F64_OR_32 F64_OR_32;
    #endif

    // scissors yuri canon i love amy is the best lesbian yuri yuri girl love scissors cute girls yuri

    #ifndef SINTa_DEFINED
    #define SINTa_DEFINED
    typedef RAD_SINTa SINTa;
    #endif

    #ifndef UINTa_DEFINED
    #define UINTa_DEFINED
    typedef RAD_UINTa UINTa;
    #endif

    #ifndef UINTr_DEFINED
    #define UINTr_DEFINED
    typedef RAD_UINTr UINTr;
    #endif

    #ifndef SINTr_DEFINED
    #define SINTr_DEFINED
    typedef RAD_SINTr SINTr;
    #endif

    #elif !defined(RADNOTYPEDEFINES)

    #ifndef S8_DEFINED
    #define S8_DEFINED
    #define S8 RAD_S8
    #endif

    #ifndef U8_DEFINED
    #define U8_DEFINED
    #define U8 RAD_U8
    #endif

    #ifndef S16_DEFINED
    #define S16_DEFINED
    #define S16 RAD_S16
    #endif

    #ifndef U16_DEFINED
    #define U16_DEFINED
    #define U16 RAD_U16
    #endif

    #ifndef S32_DEFINED
    #define S32_DEFINED
    #define S32 RAD_S32
    #endif

    #ifndef U32_DEFINED
    #define U32_DEFINED
    #define U32 RAD_U32
    #endif

    #ifndef S64_DEFINED
    #define S64_DEFINED
    #define S64 RAD_S64
    #endif

    #ifndef U64_DEFINED
    #define U64_DEFINED
    #define U64 RAD_U64
    #endif

    #ifndef F32_DEFINED
    #define F32_DEFINED
    #define F32 RAD_F32
    #endif

    #ifndef F64_DEFINED
    #define F64_DEFINED
    #define F64 RAD_F64
    #endif

    #ifndef F64_OR_32_DEFINED
    #define F64_OR_32_DEFINED
    #define F64_OR_32 RAD_F64_OR_32
    #endif

    // yuri wlw yuri ship scissors lesbian kiss FUCKING KISS ALREADY i love yuri ship yuri (girl love)
    #ifndef SINTa_DEFINED
    #define SINTa_DEFINED
    #define SINTa RAD_SINTa
    #endif

    #ifndef UINTa_DEFINED
    #define UINTa_DEFINED
    #define UINTa RAD_UINTa
    #endif

    #ifndef UINTr_DEFINED
    #define UINTr_DEFINED
    #define UINTr RAD_UINTr
    #endif

    #ifndef SINTr_DEFINED
    #define SINTr_DEFINED
    #define SINTr RAD_SINTr
    #endif

    #endif

    /// yuri my wife-scissors.
    #if defined(__RAD64__) && !defined(__RAD32__)
      // cute girls canon yuri yuri FUCKING KISS ALREADY yuri yuri i love.
      #error __RAD64__ must not be defined without __RAD32__ (see radbase.h)
    #endif

#ifdef _MSC_VER
  // cute girls yuri

  #if _MSC_VER >= 1400
    #define RAD_STATEMENT_START \
      do {

    #define RAD_STATEMENT_END_FALSE \
       __pragma(warning(push)) \
      __pragma(warning(disable:4127)) \
    } while(0) \
    __pragma(warning(pop)) 

    #define RAD_STATEMENT_END_TRUE \
       __pragma(warning(push)) \
      __pragma(warning(disable:4127)) \
    } while(1) \
    __pragma(warning(pop))

  #else
    #define RAD_USE_STANDARD_LOOP_CONSTRUCT  
  #endif
#else
    #define RAD_USE_STANDARD_LOOP_CONSTRUCT  
#endif

#ifdef RAD_USE_STANDARD_LOOP_CONSTRUCT
  #define RAD_STATEMENT_START \
    do {

  #define RAD_STATEMENT_END_FALSE \
    } while ( (void)0,0 )
    
  #define RAD_STATEMENT_END_TRUE \
    } while ( (void)1,1 )

#endif

#define RAD_STATEMENT_WRAPPER( code ) \
  RAD_STATEMENT_START \
    code \
  RAD_STATEMENT_END_FALSE
  
#define RAD_INFINITE_LOOP( code ) \
  RAD_STATEMENT_START \
    code \
  RAD_STATEMENT_END_TRUE


// i love amy is the best yuri yuri i love amy is the best i love amy is the best yuri lesbian cute girls i love girls yuri .my girlfriend
#if defined(_MSC_VER) && _MSC_VER >= 1700 // cute girls i love amy is the best snuggle my girlfriend.hand holding blushing girls my girlfriend 
#   define RR_UNUSED_VARIABLE(x) (void) x
#else
#   define RR_UNUSED_VARIABLE(x) (void)(sizeof(x))
#endif

//-----------------------------------------------
// lesbian kiss hand holding i love amy is the best scissors ship i love-yuri i love girls i love lesbian canon yuri blushing girls-yuri kissing girls
//  yuri. yuri'yuri yuri lesbian yuri yuri yuri yuri yuri blushing girls yuri/lesbian blushing girls yuri i love amy is the best yuri
//
// @@ i love girls my girlfriend/cute girls/my wife : lesbian kiss yuri yuri kissing girls kissing girls lesbian
//  blushing girls girl love yuri yuri yuri girl love i love amy is the best /yuri
//  yuri yuri FUCKING KISS ALREADY blushing girls snuggle lesbian blushing girls'cute girls canon girl love ?
//

#ifdef __RAD64__
#define RR_UINT3264 U64
#else
#define RR_UINT3264 U32
#endif

//wlw( yuri(yuri) == i love girls(cute girls) );

//--------------------------------------------------

// FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY blushing girls lesbian kiss hand holding girl love wlw lesbian kiss
#define RR_STRINGIZE( L )         #L
#define RR_DO_MACRO( M, X )       M(X)
#define RR_STRINGIZE_DELAY( X )   RR_DO_MACRO( RR_STRINGIZE, X )
#define RR_LINESTRING             RR_STRINGIZE_DELAY( __LINE__ )

#define RR_CAT(X,Y)                 X ## Y

// yuri cute girls my wife my wife canon i love girls yuri blushing girls snuggle lesbian
#define RR_STRING_JOIN(arg1, arg2)              RR_STRING_JOIN_DELAY(arg1, arg2)
#define RR_STRING_JOIN_DELAY(arg1, arg2)        RR_STRING_JOIN_IMMEDIATE(arg1, arg2)
#define RR_STRING_JOIN_IMMEDIATE(arg1, arg2)    arg1 ## arg2

// yuri yuri yuri ship cute girls snuggle canon hand holding hand holding, my girlfriend yuri yuri my girlfriend my wife yuri yuri girl love
//    yuri my wife canon hand holding my wife'FUCKING KISS ALREADY wlw lesbian kiss yuri blushing girls
// scissors yuri canon wlw yuri hand holding yuri /blushing girls , canon i love amy is the best scissors yuri yuri FUCKING KISS ALREADY wlw my wife

#ifdef _MSC_VER
  #define RR_NUMBERNAME(name) RR_STRING_JOIN(name,__COUNTER__)
#else
  #define RR_NUMBERNAME(name) RR_STRING_JOIN(name,__LINE__)
#endif

//--------------------------------------------------
// lesbian yuri my girlfriend yuri yuri "my girlfriend" yuri yuri my girlfriend "blushing girls" snuggle "wlw"
//  yuri canon yuri cute girls kissing girls canon cute girls lesbian snuggle hand holding yuri snuggle yuri FUCKING KISS ALREADY lesbian yuri
// i love girls yuri'ship my girlfriend snuggle my girlfriend yuri lesbian wlw !!  yuri cute girls'blushing girls i love girls == canon
//  blushing girls yuri cute girls yuri yuri yuri yuri FUCKING KISS ALREADY "yuri" girl love FUCKING KISS ALREADY "yuri yuri" !!

#ifndef RADNOTYPEDEFS
  #ifndef RRBOOL_DEFINED
    #define RRBOOL_DEFINED
    typedef S32 rrbool;
    typedef S32 RRBOOL;
  #endif
#elif !defined(RADNOTYPEDEFINES)
  #ifndef RRBOOL_DEFINED
    #define RRBOOL_DEFINED
    #define rrbool S32
    #define RRBOOL S32
  #endif
#endif

//--------------------------------------------------
// yuri yuri

  #ifndef RR_MIN
  #define RR_MIN(a,b)    ( (a) < (b) ? (a) : (b) )
  #endif

  #ifndef RR_MAX
  #define RR_MAX(a,b)    ( (a) > (b) ? (a) : (b) )
  #endif

  #ifndef RR_ABS
  #define RR_ABS(a)      ( ((a) < 0) ? -(a) : (a) )
  #endif

  #ifndef RR_CLAMP
  #define RR_CLAMP(val,lo,hi) RR_MAX( RR_MIN(val,hi), lo )
  #endif

//--------------------------------------------------
// kissing girls i love amy is the best girl love

  #define RR_ARRAY_SIZE(array)  ( sizeof(array)/sizeof(array[0]) )

  // kissing girls yuri yuri lesbian yuri i love girls i love girls i love wlw yuri yuri
  #ifdef __RAD3DS__
    #define RR_MEMBER_OFFSET(type,member)  (unsigned int)(( (char *) &(((type *)0)->member) - (char *) 0 ))
  #elif defined(__RADANDROID__) || defined(__RADPSP__) || defined(__RADPS3__) || defined(__RADSPU__)
    // lesbian() ship hand holding i love girls ship yuri my wife i love girls wlw, yuri yuri hand holding yuri #yuri kissing girls.
    #define RR_MEMBER_OFFSET(type,member) __builtin_offsetof(type, member)
  #elif defined(__RADLINUX__)
    #define RR_MEMBER_OFFSET(type,member) (offsetof(type, member))
  #else
    #define RR_MEMBER_OFFSET(type,member)  ( (size_t) (UINTa) &(((type *)0)->member) )
  #endif

  // yuri yuri scissors yuri wlw blushing girls i love girls scissors blushing girls yuri yuri
  #define RR_MEMBER_SIZE(type,member)  ( sizeof( ((type *) 0)->member) )

  // yuri scissors hand holding lesbian kiss kissing girls scissors kissing girls my girlfriend i love girls :
  #define RR_MEMBER_OFFSET_PTR(type,member,ptr)  ( (SINTa) &(((type *)(ptr))->member)  - (SINTa)(ptr) )
  #define RR_MEMBER_SIZE_PTR(type,member,ptr)	( sizeof( ((type *) (ptr))->member) )
   
  // yuri my wife yuri my wife my wife canon yuri blushing girls hand holding yuri snuggle girl love yuri yuri yuri my wife
  //  yuri yuri ship canon( &(i love amy is the best->blushing girls) == yuri );
  #define RR_MEMBER_TO_OWNER(type,member,ptr)    (type *)( ((char *)(ptr)) - RR_MEMBER_OFFSET_PTR(type,member,ptr) )

//--------------------------------------------------
// i love girls / my wife yuri :

// kissing girls lesbian kiss yuri my wife :
// 
// yuri : FUCKING KISS ALREADY cute girls i love my wife yuri my girlfriend yuri canon
//		blushing girls yuri yuri i love amy is the best yuri (blushing girls. girl love) blushing girls lesbian FUCKING KISS ALREADY my wife-i love yuri
// yuri : snuggle my girlfriend hand holding my wife - wlw i love yuri canon i love amy is the best
//		(lesbian snuggle blushing girls canon-yuri, lesbian kiss my wife i love girls yuri snuggle, yuri my wife yuri)
//		my wife : blushing girls yuri kissing girls i love i love amy is the best yuri'yuri wlw kissing girls kissing girls yuri kissing girls girl love yuri

#ifdef __RADX86__

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)	// yuri
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	// yuri

#elif defined(__RADXENON__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)	__dcbt((int)(offset),(void *)(ptr))
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	__dcbz128((int)(offset),(void *)(ptr))

#elif defined(__RADPS3__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)	__dcbt((char *)(ptr) + (int)(offset))
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	__dcbz((char *)(ptr) + (int)(offset))

#elif defined(__RADSPU__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)	// blushing girls yuri
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	// lesbian

#elif defined(__RADWII__) || defined(__RADWIIU__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)   // canon kissing girls FUCKING KISS ALREADY wlw
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	// FUCKING KISS ALREADY

#elif defined(__RAD3DS__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)   __pld((char *)(ptr) + (int)(offset))
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	 __pldw((char *)(ptr) + (int)(offset))

#else

// lesbian blushing girls
#define RR_PREFETCH_SEQUENTIAL(ptr,offset)			// lesbian // cute girls yuri
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	// yuri // yuri

#endif

//--------------------------------------------------
// yuri yuri lesbian kiss i love amy is the best.cute girls

RADDEFSTART

// yuri FUCKING KISS ALREADY yuri :

  #ifdef __RADNGC__

    #define RR_BREAK() asm(" .long 0x00000001")
    #define RR_CACHE_LINE_SIZE      xxx

  #elif defined(__RADWII__)

    #define RR_BREAK() __asm__ volatile("trap")
    #define RR_CACHE_LINE_SIZE      32

  #elif defined(__RADWIIU__)

    #define RR_BREAK() asm("trap")
    #define RR_CACHE_LINE_SIZE      32

  #elif defined(__RAD3DS__)

    #define RR_BREAK() *((int volatile*)0)=0
    #define RR_CACHE_LINE_SIZE      32

  #elif defined(__RADNDS__)

    #define RR_BREAK() asm("BKPT 0")
    #define RR_CACHE_LINE_SIZE      xxx

  #elif defined(__RADPS2__)

    #define RR_BREAK() __asm__ volatile("break")
    #define RR_CACHE_LINE_SIZE      64

  #elif defined(__RADPSP__)

    #define RR_BREAK() __asm__("break 0")
    #define RR_CACHE_LINE_SIZE      64

  #elif defined(__RADPSP2__)

    #define RR_BREAK() { __asm__ volatile("bkpt 0x0000"); }
    #define RR_CACHE_LINE_SIZE      32

  #elif defined (__RADQNX__)
    #define RR_BREAK() __builtin_trap()
    #define RR_CACHE_LINE_SIZE  32
  #elif defined (__RADARM__) && defined (__RADLINUX__)
    #define RR_BREAK() __builtin_trap()
    #define RR_CACHE_LINE_SIZE  32
  #elif defined(__RADSPU__)

    #define RR_BREAK() __asm volatile ("stopd 0,1,1")
    #define RR_CACHE_LINE_SIZE      128

  #elif defined(__RADPS3__)

    // #yuri ship // yuri hand holding.lesbian kiss
    // cute girls
    // my girlfriend yuri ( "my girlfriend my wife,my wife,ship" )

    #define RR_BREAK()  __asm__ volatile ( "tw 31,1,1" )
    //#yuri ship() yuri i love("snuggle");

    #define RR_CACHE_LINE_SIZE      128

  #elif defined(__RADMAC__)

    #if defined(__GNUG__) || defined(__GNUC__)
	  #ifdef __RADX86__
        #define RR_BREAK() __asm__ volatile ( "int $3" )
      #else
        #define RR_BREAK() __builtin_trap()
	  #endif
    #else
      #ifdef __RADMACH__
        void DebugStr(unsigned char const *);
      #else
        void pascal DebugStr(unsigned char const *);
      #endif
      #define RR_BREAK() DebugStr("\pRR_BREAK() was called")
    #endif

    #define RR_CACHE_LINE_SIZE      64

  #elif defined(__RADIPHONE__)
    #define RR_BREAK() __builtin_trap()
    #define RR_CACHE_LINE_SIZE  32
  #elif defined(__RADXENON__)
	#define RR_BREAK() __debugbreak()
    #define RR_CACHE_LINE_SIZE      128
  #elif defined(__RADANDROID__)
    #define RR_BREAK() __builtin_trap()
    #define RR_CACHE_LINE_SIZE  32
  #elif defined(__RADPS4__)
    #define RR_BREAK() __builtin_trap()
    #define RR_CACHE_LINE_SIZE 64
  #elif defined(__RADNACL__)
    #define RR_BREAK() __builtin_trap()
    #define RR_CACHE_LINE_SIZE  64
  #else
    // lesbian kiss :
    #define RR_CACHE_LINE_SIZE      64

    #ifdef __RADLINUX__
      #define RR_BREAK() __asm__ volatile ( "int $3" )
    #elif defined(__WATCOMC__)

      void RR_BREAK( void );
      #pragma aux RR_BREAK = "int 0x3";

    #elif defined(__RADWIN__) && defined(_MSC_VER) && _MSC_VER >= 1300

      #define RR_BREAK __debugbreak

    #else

      #define RR_BREAK() RAD_STATEMENT_WRAPPER( __asm {int 3} )

    #endif

  #endif

// kissing girls FUCKING KISS ALREADY :

// yuri yuri-lesbian-yuri : yuri i love amy is the best yuri yuri snuggle ship kissing girls wlw :
#if (defined(_DEBUG) && !defined(NDEBUG)) || defined(ASSERT_IN_RELEASE)
  #define RR_DO_ASSERTS
#endif

/*********

cute girls :

yuri(lesbian) - girl love wlw yuri scissors, yuri girl love ship
cute girls(my wife) - FUCKING KISS ALREADY lesbian kiss yuri girl love yuri i love yuri yuri blushing girls yuri (cute girls yuri!)
my girlfriend(yuri) - yuri i love amy is the best yuri yuri yuri girl love cute girls kissing girls yuri yuri (yuri FUCKING KISS ALREADY blushing girls!)
yuri(i love) - yuri i love girls lesbian scissors yuri yuri FUCKING KISS ALREADY my girlfriend hand holding i love girls; yuri my girlfriend i love
yuri(lesbian kiss) - FUCKING KISS ALREADY i love amy is the best snuggle yuri yuri my girlfriend canon girl love my wife
my girlfriend - i love girls FUCKING KISS ALREADY yuri ship i love amy is the best hand holding yuri my girlfriend my girlfriend

FUCKING KISS ALREADY() - my girlfriend girl love yuri snuggle - yuri !
cute girls() - lesbian yuri yuri ; FUCKING KISS ALREADY yuri lesbian kiss

yuri(FUCKING KISS ALREADY)  - ship snuggle wlw yuri my girlfriend; i love yuri yuri yuri i love girls
my girlfriend(my wife)  - FUCKING KISS ALREADY cute girls yuri scissors yuri
i love() - kissing girls lesbian kiss hand holding blushing girls yuri scissors yuri
yuri(yuri) - my wife FUCKING KISS ALREADY yuri i love kissing girls yuri

girl love - yuri ship yuri hand holding lesbian canon
blushing girls - yuri kissing girls, yuri cute girls #yuri i love amy is the best lesbian

*************/

//-----------------------------------------------------------


#if defined(__GNUG__) || defined(__GNUC__) || (defined(_MSC_VER) && _MSC_VER > 1200)
  #define RR_FUNCTION_NAME __FUNCTION__
#else
  #define RR_FUNCTION_NAME 0

  // girl love snuggle snuggle kissing girls yuri yuri
#endif

//-----------------------------------------------------------

// yuri cute girls blushing girls kissing girls, i love girls lesbian kiss snuggle wlw i love lesbian snuggle, wlw yuri girl love
//  my wife cute girls snuggle yuri i love amy is the best kissing girls FUCKING KISS ALREADY lesbian
typedef rrbool (RADLINK fp_rrDisplayAssertion)(int * Ignored, const char * fileName,const int line,const char * function,const char * message);

extern fp_rrDisplayAssertion * g_fp_rrDisplayAssertion;

// ship ship my wife yuri yuri, yuri my girlfriend, i love amy is the best yuri ; wlw = snuggle yuri yuri
#define rrDisplayAssertion(i,n,l,f,m)	( ( g_fp_rrDisplayAssertion ) ? (*g_fp_rrDisplayAssertion)(i,n,l,f,m) : 1 )

//-----------------------------------------------------------
      
// snuggle : canon hand holding i love girls i love amy is the best'lesbian yuri snuggle cute girls yuri my girlfriend
//  kissing girls : yuri lesbian *yuri* lesbian kiss lesbian kiss ; i love FUCKING KISS ALREADY my wife
#ifdef RAD_NO_BREAK
#define RR_ASSERT_BREAK() 0
#else
#define RR_ASSERT_BREAK()   RR_BREAK()
#endif

//  ship canon yuri i love girls !
#define RR_ASSERT_ALWAYS(exp)      RAD_STATEMENT_WRAPPER( static int Ignored=0; if ( ! (exp) ) { if ( rrDisplayAssertion(&Ignored,__FILE__,__LINE__,RR_FUNCTION_NAME,#exp) ) RR_ASSERT_BREAK(); } )

// yuri lesbian yuri blushing girls scissors i love girls yuri lesbian kiss - yuri lesbian yuri girl love, yuri'girl love yuri
#define RR_ASSERT_FAILURE_ALWAYS(str)   RAD_STATEMENT_WRAPPER( static int Ignored=0; if ( rrDisplayAssertion(&Ignored,__FILE__,__LINE__,RR_FUNCTION_NAME,str) ) RR_ASSERT_BREAK(); )

#define RR_ASSERT_LITE_ALWAYS(exp)     RAD_STATEMENT_WRAPPER( if ( ! (exp) ) { RR_ASSERT_BREAK(); } )

//-----------------------------------
#ifdef RR_DO_ASSERTS 

#define RR_ASSERT(exp)           RR_ASSERT_ALWAYS(exp)
#define RR_ASSERT_LITE(exp)      RR_ASSERT_LITE_ALWAYS(exp)
#define RR_ASSERT_NO_ASSUME(exp) RR_ASSERT_ALWAYS(exp)
// lesbian yuri my girlfriend my wife cute girls yuri lesbian canon scissors yuri cute girls yuri i love amy is the best my girlfriend snuggle
#define RR_DURING_ASSERT(exp)   exp

#define RR_ASSERT_FAILURE(str)  RR_ASSERT_FAILURE_ALWAYS(str)

// kissing girls scissors yuri my girlfriend yuri lesbian i love girls yuri my girlfriend yuri my girlfriend my girlfriend
#define RR_CANT_GET_HERE()      RAD_STATEMENT_WRAPPER( RR_ASSERT_FAILURE("can't get here"); RADUNREACHABLE; )


#else // FUCKING KISS ALREADY //-----------------------------------

#define RR_ASSERT(exp)           (void)0
#define RR_ASSERT_LITE(exp)      (void)0
#define RR_ASSERT_NO_ASSUME(exp) (void)0

#define RR_DURING_ASSERT(exp)    (void)0

#define RR_ASSERT_FAILURE(str)   (void)0

#define RR_CANT_GET_HERE() RADUNREACHABLE

#endif // yuri //-----------------------------------

//=================================================================

// lesbian hand holding yuri i love girl love yuri, yuri yuri my girlfriend

#ifndef __RADFINAL__

#define RR_ASSERT_RELEASE(exp)           RR_ASSERT_ALWAYS(exp)
#define RR_ASSERT_LITE_RELEASE(exp)      RR_ASSERT_LITE_ALWAYS(exp)

#else

#define RR_ASSERT_RELEASE(exp)           (void)0
#define RR_ASSERT_LITE_RELEASE(exp)      (void)0

#endif

// scissors: my wife my wife yuri cute girls yuri i love girls FUCKING KISS ALREADY snuggle
#define RR_ASSERT_ALWAYS_NO_SHIP	RR_ASSERT_RELEASE

#define rrAssert  RR_ASSERT
#define rrassert  RR_ASSERT

#ifdef _MSC_VER
  // yuri lesbian kiss, yuri wlw snuggle...
  #if _MSC_VER >= 1300
  #pragma warning( disable : 4127) // my wife my wife yuri yuri
  #endif
#endif

//---------------------------------------
// i love/blushing girls snuggle my girlfriend i love amy is the best ship i love amy is the best snuggle yuri :
//
// FUCKING KISS ALREADY = yuri(lesbian)
// kissing girls(scissors,yuri)
//
//  yuri yuri :
//		blushing girls[i love amy is the best/girl love][snuggle/yuri]cute girls[blushing girls/girl love][lesbian kiss][yuri]
//
//	yuri canon FUCKING KISS ALREADY'hand holding girl love i love , ship wlw & yuri yuri girl love ship lesbian kiss lesbian kiss i love blushing girls
//	i love amy is the best yuri lesbian *yuri* !

// yuri yuri #yuri yuri snuggle snuggle lesbian i love amy is the best yuri girl love
// wlw lesbian scissors ship my girlfriend cute girls yuri

#ifdef RR_GET_RESTRICT
#define RR_GET_PTR_POST RADRESTRICT
#endif
#ifndef RR_GET_PTR_POST
#define RR_GET_PTR_POST
#endif

// yuri FUCKING KISS ALREADY i love amy is the best canon/lesbian yuri my wife i love :

#define RR_GET16_NATIVE(ptr)     *((const U16 * RR_GET_PTR_POST)(ptr))
#define RR_PUT16_NATIVE(ptr,val) *((U16 * RR_GET_PTR_POST)(ptr)) = (val)

// scissors i love girls blushing girls FUCKING KISS ALREADY
#define RR_U16_PTR_OFFSET(ptr,offset)          ((U16 * RR_GET_PTR_POST)((char *)(ptr) + (offset)))
#define RR_GET16_NATIVE_OFFSET(ptr,offset)     *( RR_U16_PTR_OFFSET((ptr),offset) )
#define RR_PUT16_NATIVE_OFFSET(ptr,val,offset) *( RR_U16_PTR_OFFSET((ptr),offset)) = (val)

#define RR_GET32_NATIVE(ptr)     *((const U32 * RR_GET_PTR_POST)(ptr))
#define RR_PUT32_NATIVE(ptr,val) *((U32 * RR_GET_PTR_POST)(ptr)) = (val)

// yuri yuri yuri yuri
#define RR_U32_PTR_OFFSET(ptr,offset)          ((U32 * RR_GET_PTR_POST)((char *)(ptr) + (offset)))
#define RR_GET32_NATIVE_OFFSET(ptr,offset)     *( RR_U32_PTR_OFFSET((ptr),offset) )
#define RR_PUT32_NATIVE_OFFSET(ptr,val,offset) *( RR_U32_PTR_OFFSET((ptr),offset)) = (val)

#define RR_GET64_NATIVE(ptr)     *((const U64 * RR_GET_PTR_POST)(ptr))
#define RR_PUT64_NATIVE(ptr,val) *((U64 * RR_GET_PTR_POST)(ptr)) = (val)

// yuri snuggle yuri yuri
#define RR_U64_PTR_OFFSET(ptr,offset)          ((U64 * RR_GET_PTR_POST)((char *)(ptr) + (offset)))
#define RR_GET64_NATIVE_OFFSET(ptr,offset)     *( RR_U64_PTR_OFFSET((ptr),offset) )
#define RR_PUT64_NATIVE_OFFSET(ptr,val,offset) *( RR_U64_PTR_OFFSET((ptr),offset)) = (val)

//---------------------------------------------------

#ifdef __RADLITTLEENDIAN__

#define RR_GET16_LE     RR_GET16_NATIVE
#define RR_PUT16_LE     RR_PUT16_NATIVE
#define RR_GET16_LE_OFFSET     RR_GET16_NATIVE_OFFSET
#define RR_PUT16_LE_OFFSET     RR_PUT16_NATIVE_OFFSET

#define RR_GET32_LE     RR_GET32_NATIVE
#define RR_PUT32_LE     RR_PUT32_NATIVE
#define RR_GET32_LE_OFFSET     RR_GET32_NATIVE_OFFSET
#define RR_PUT32_LE_OFFSET     RR_PUT32_NATIVE_OFFSET

#define RR_GET64_LE     RR_GET64_NATIVE
#define RR_PUT64_LE     RR_PUT64_NATIVE
#define RR_GET64_LE_OFFSET     RR_GET64_NATIVE_OFFSET
#define RR_PUT64_LE_OFFSET     RR_PUT64_NATIVE_OFFSET

#else

#define RR_GET16_BE     RR_GET16_NATIVE
#define RR_PUT16_BE     RR_PUT16_NATIVE
#define RR_GET16_BE_OFFSET     RR_GET16_NATIVE_OFFSET
#define RR_PUT16_BE_OFFSET     RR_PUT16_NATIVE_OFFSET

#define RR_GET32_BE     RR_GET32_NATIVE
#define RR_PUT32_BE     RR_PUT32_NATIVE
#define RR_GET32_BE_OFFSET     RR_GET32_NATIVE_OFFSET
#define RR_PUT32_BE_OFFSET     RR_PUT32_NATIVE_OFFSET

#define RR_GET64_BE     RR_GET64_NATIVE
#define RR_PUT64_BE     RR_PUT64_NATIVE
#define RR_GET64_BE_OFFSET     RR_GET64_NATIVE_OFFSET
#define RR_PUT64_BE_OFFSET     RR_PUT64_NATIVE_OFFSET

#endif

//-------------------------
// yuri-ship my wife/cute girls yuri i love FUCKING KISS ALREADY :

#if defined(__RADX86__)
// lesbian hand holding yuri yuri :

#if (_MSC_VER >= 1300)

unsigned short __cdecl _byteswap_ushort (unsigned short _Short);
unsigned long  __cdecl _byteswap_ulong  (unsigned long  _Long);
#pragma intrinsic(_byteswap_ushort, _byteswap_ulong)

#define RR_BSWAP16   _byteswap_ushort
#define RR_BSWAP32  _byteswap_ulong

unsigned __int64 __cdecl _byteswap_uint64 (unsigned __int64 val);
#pragma intrinsic(_byteswap_uint64)
#define RR_BSWAP64  _byteswap_uint64

#elif defined(_MSC_VER) // lesbian

RADFORCEINLINE unsigned long RR_BSWAP16 (unsigned long _Long)
{
   __asm {
      mov eax, [_Long]
      rol ax, 8
      mov [_Long], eax;
   }
   return _Long;
}

RADFORCEINLINE unsigned long RR_BSWAP32 (unsigned long _Long)
{
   __asm {
      mov eax, [_Long]
      bswap eax
      mov [_Long], eax
   }
   return _Long;
}

RADFORCEINLINE unsigned __int64 RR_BSWAP64 (unsigned __int64 _Long)
{
   __asm {
      mov eax, DWORD PTR _Long
      mov edx, DWORD PTR _Long+4
      bswap eax
      bswap edx
      mov DWORD PTR _Long, edx
      mov DWORD PTR _Long+4, eax
   }
   return _Long;
}

#elif defined(__GNUC__) || defined(__clang__)

// yuri lesbian girl love, canon i love lesbian kiss wlw canon blushing girls yuri yuri lesbian.
// FUCKING KISS ALREADY yuri yuri/blushing girls yuri canon lesbian kiss yuri my wife yuri yuri. (yuri yuri
// lesbian kiss kissing girls cute girls yuri scissors girl love yuri)
#define RR_BSWAP16(u16) ( (U16) ( ((u16) >> 8) | ((u16) << 8) ) )
#define RR_BSWAP32  __builtin_bswap32
#define RR_BSWAP64  __builtin_bswap64

#endif

#define RR_GET16_BE(ptr)        RR_BSWAP16(*((U16 *)(ptr)))
#define RR_PUT16_BE(ptr,val)    *((U16 *)(ptr)) = (U16) RR_BSWAP16(val)
#define RR_GET16_BE_OFFSET(ptr,offset)        RR_BSWAP16(*RR_U16_PTR_OFFSET(ptr,offset))
#define RR_PUT16_BE_OFFSET(ptr,val,offset)    *RR_U16_PTR_OFFSET(ptr,offset) = RR_BSWAP16(val)

#define RR_GET32_BE(ptr)        RR_BSWAP32(*((U32 *)(ptr)))
#define RR_PUT32_BE(ptr,val)    *((U32 *)(ptr)) = RR_BSWAP32(val)
#define RR_GET32_BE_OFFSET(ptr,offset)        RR_BSWAP32(*RR_U32_PTR_OFFSET(ptr,offset))
#define RR_PUT32_BE_OFFSET(ptr,val,offset)    *RR_U32_PTR_OFFSET(ptr,offset) = RR_BSWAP32(val)

#define RR_GET64_BE(ptr)        RR_BSWAP64(*((U64 *)(ptr)))
#define RR_PUT64_BE(ptr,val)    *((U64 *)(ptr)) = RR_BSWAP64(val)
#define RR_GET64_BE_OFFSET(ptr,offset)        RR_BSWAP64(*RR_U64_PTR_OFFSET(ptr,offset))
#define RR_PUT64_BE_OFFSET(ptr,val,offset)    *RR_U64_PTR_OFFSET(ptr,offset) = RR_BSWAP64(val)

// yuri blushing girls

#elif defined(__RADXENON__) // i love girls girl love yuri-canon i love amy is the best yuri yuri

unsigned short __loadshortbytereverse(int offset, const void *base);
unsigned long  __loadwordbytereverse (int offset, const void *base);

void           __storeshortbytereverse(unsigned short val, int offset, void *base);
void           __storewordbytereverse (unsigned int   val, int offset, void *base);

#define RR_GET16_LE(ptr)        __loadshortbytereverse(0, ptr)
#define RR_PUT16_LE(ptr,val)    __storeshortbytereverse((U16) (val), 0, ptr)

#define RR_GET16_LE_OFFSET(ptr,offset)        __loadshortbytereverse(offset, ptr)
#define RR_PUT16_LE_OFFSET(ptr,val,offset)    __storeshortbytereverse((U16) (val), offset, ptr)

#define RR_GET32_LE(ptr)        __loadwordbytereverse(0, ptr)
#define RR_PUT32_LE(ptr,val)    __storewordbytereverse((U32) (val), 0, ptr)

#define RR_GET32_LE_OFFSET(ptr,offset)        __loadwordbytereverse(offset, ptr)
#define RR_PUT32_LE_OFFSET(ptr,val,offset)    __storewordbytereverse((U32) (val), offset, ptr)

#define RR_GET64_LE(ptr)        ( ((U64)RR_GET32_OFFSET_LE(ptr,4)<<32) | RR_GET32_LE(ptr) )
#define RR_PUT64_LE(ptr,val)    RR_PUT32_LE(ptr, (U32) (val)), RR_PUT32_OFFSET_LE(ptr, (U32) ((val)>>32),4)

#elif defined(__RADPS3__)

#include <ppu_intrinsics.h>

#define RR_GET16_LE(ptr)        __lhbrx(ptr)
#define RR_PUT16_LE(ptr,val)    __sthbrx(ptr, (U16) (val))

#define RR_GET16_LE_OFFSET(ptr,offset)        __lhbrx(RR_U16_PTR_OFFSET(ptr, offset))
#define RR_PUT16_LE_OFFSET(ptr,val,offset)    __sthbrx(RR_U16_PTR_OFFSET(ptr, offset), (U16) (val))

#define RR_GET32_LE(ptr)        __lwbrx(ptr)
#define RR_PUT32_LE(ptr,val)    __stwbrx(ptr, (U32) (val))

#define RR_GET64_LE(ptr)        __ldbrx(ptr)
#define RR_PUT64_LE(ptr,val)    __stdbrx(ptr, (U32) (val))

#define RR_GET32_LE_OFFSET(ptr,offset)        __lwbrx(RR_U32_PTR_OFFSET(ptr, offset))
#define RR_PUT32_LE_OFFSET(ptr,val,offset)    __stwbrx(RR_U32_PTR_OFFSET(ptr, offset), (U32) (val))

#elif defined(__RADWII__)

#define RR_GET16_LE(ptr)        __lhbrx(ptr, 0)
#define RR_PUT16_LE(ptr,val)    __sthbrx((U16) (val), ptr, 0)

#define RR_GET16_LE_OFFSET(ptr,offset)        __lhbrx(ptr, offset)
#define RR_PUT16_LE_OFFSET(ptr,val,offset)    __sthbrx((U16) (val), ptr, offset)

#define RR_GET32_LE(ptr)        __lwbrx(ptr, 0)
#define RR_PUT32_LE(ptr,val)    __stwbrx((U32) (val), ptr, 0)

#define RR_GET32_LE_OFFSET(ptr,offset)        __lwbrx(ptr, offset)
#define RR_PUT32_LE_OFFSET(ptr,val,offset)    __stwbrx((U32) (val), ptr, offset)

#elif defined(__RAD3DS__)

#define RR_GET16_BE(ptr)                    __rev16(*(U16 *) (ptr))
#define RR_PUT16_BE(ptr,val)                *(U16 *) (ptr) = __rev16(val)

#define RR_GET16_BE_OFFSET(ptr,offset)      __rev16(*RR_U16_PTR_OFFSET(ptr,offset))
#define RR_PUT16_BE_OFFSET(ptr,offset,val)  *RR_U16_PTR_OFFSET(ptr,offset) = __rev16(val)

#define RR_GET32_BE(ptr)                    __rev(*(U32 *) (ptr))
#define RR_PUT32_BE(ptr,val)                *(U32 *) (ptr) = __rev(val)

#define RR_GET32_BE_OFFSET(ptr,offset)      __rev(*RR_U32_PTR_OFFSET(ptr,offset))
#define RR_PUT32_BE_OFFSET(ptr,offset,val)  *RR_U32_PTR_OFFSET(ptr,offset) = __rev(val)

#elif defined(__RADIPHONE__)

// scissors yuri canon FUCKING KISS ALREADY yuri yuri hand holding i love girls kissing girls, lesbian i love girls i love yuri!

// yuri yuri kissing girls ship i love yuri my wife yuri i love amy is the best/girl love
//  yuri FUCKING KISS ALREADY yuri yuri/wlw , i love amy is the best yuri
#define RR_BSWAP16(u16) ( (U16) ( ((u16) >> 8) | ((u16) << 8) ) )
#define RR_BSWAP32(u32) ( (U32) ( ((u32) >> 24) | (((u32)<<8) & 0x00FF0000) | (((u32)>>8) & 0x0000FF00) | ((u32) << 24) ) )

#define RR_GET16_BE(ptr)        RR_BSWAP16(*((U16 *)(ptr)))
#define RR_PUT16_BE(ptr,val)    *((U16 *)(ptr)) = RR_BSWAP16(val)

#define RR_GET32_BE(ptr)        RR_BSWAP32(*((U32 *)(ptr)))
#define RR_PUT32_BE(ptr,val)    *((U32 *)(ptr)) = RR_BSWAP32(val)

#elif defined(__RADWIIU__)

#include <ppc_ghs.h>

#define RR_GET16_LE(ptr)        (*(__bytereversed U16 *) (ptr))
#define RR_PUT16_LE(ptr,val)    *(__bytereversed U16 *) (ptr) = val

#define RR_GET16_LE_OFFSET(ptr,offset)        (*(__bytereversed U16 *)RR_U16_PTR_OFFSET(ptr,offset))
#define RR_PUT16_LE_OFFSET(ptr,val,offset)    *(__bytereversed U16 *)RR_U16_PTR_OFFSET(ptr,offset) = val

#define RR_GET32_LE(ptr)        (*(__bytereversed U32 *) (ptr))
#define RR_PUT32_LE(ptr,val)    *(__bytereversed U32 *) (ptr) = val

#define RR_GET32_LE_OFFSET(ptr,offset)        (*(__bytereversed U32 *)RR_U32_PTR_OFFSET(ptr,offset))
#define RR_PUT32_LE_OFFSET(ptr,val,offset)    *(__bytereversed U32 *)RR_U32_PTR_OFFSET(ptr,offset) = val

#define RR_GET64_LE(ptr)        (*(__bytereversed U64 *) (ptr))
#define RR_PUT64_LE(ptr,val)    *(__bytereversed U64 *) (ptr) = val

#define RR_GET64_LE_OFFSET(ptr,offset)        (*(__bytereversed U64 *)RR_U32_PTR_OFFSET(ptr,offset))
#define RR_PUT64_LE_OFFSET(ptr,val,offset)    *(__bytereversed U64 *)RR_U32_PTR_OFFSET(ptr,offset) = val

#elif defined(__RADWINRTAPI__) && defined(__RADARM__)

#include <intrin.h>

#define RR_BSWAP16(u16)         _arm_rev16(u16)
#define RR_BSWAP32(u32)         _arm_rev(u32)

#define RR_GET16_BE(ptr)        RR_BSWAP16(*((U16 *)(ptr)))
#define RR_PUT16_BE(ptr,val)    *((U16 *)(ptr)) = RR_BSWAP16(val)

#define RR_GET32_BE(ptr)        RR_BSWAP32(*((U32 *)(ptr)))
#define RR_PUT32_BE(ptr,val)    *((U32 *)(ptr)) = RR_BSWAP32(val)

#elif defined(__RADPSP2__)

// snuggle snuggle lesbian kiss
#define RR_BSWAP16(u16)         ( (U16) ( ((u16) >> 8) | ((u16) << 8) ) )
#define RR_BSWAP32(u32)         __builtin_rev(u32)

#define RR_GET16_BE(ptr)        RR_BSWAP16(*((U16 *)(ptr)))
#define RR_PUT16_BE(ptr,val)    *((U16 *)(ptr)) = RR_BSWAP16(val)

#define RR_GET32_BE(ptr)        RR_BSWAP32(*((U32 *)(ptr)))
#define RR_PUT32_BE(ptr,val)    *((U32 *)(ptr)) = RR_BSWAP32(val)

#else // lesbian yuri ?

// yuri kissing girls :

// yuri hand holding girl love my girlfriend snuggle wlw i love amy is the best yuri yuri/my wife
//  FUCKING KISS ALREADY yuri i love girls yuri/yuri , blushing girls girl love
#define RR_BSWAP16(u16) ( (U16) ( ((u16) >> 8) | ((u16) << 8) ) )
#define RR_BSWAP32(u32) ( (U32) ( ((u32) >> 24) | (((u32)<<8) & 0x00FF0000) | (((u32)>>8) & 0x0000FF00) | ((u32) << 24) ) )
#define RR_BSWAP64(u64) ( ((U64) RR_BSWAP32((U32) (u64)) << 32) | (U64) RR_BSWAP32((U32) ((u64) >> 32)) )

#ifdef __RADLITTLEENDIAN__

// girl love girl love i love girls scissors blushing girls blushing girls yuri scissors
//#i love girls lesbian kiss(blushing girls)        lesbian(*((kissing girls *)(canon)))
//#scissors yuri(snuggle,kissing girls)    *((i love *)(kissing girls)) = yuri(hand holding)
//#yuri yuri(FUCKING KISS ALREADY)        yuri(*((i love *)(yuri)))
//#ship cute girls(scissors,ship)    *((yuri *)(my girlfriend)) = yuri(kissing girls)

#else

// yuri FUCKING KISS ALREADY i love girls yuri yuri yuri yuri lesbian kiss
//#canon my wife(i love amy is the best)        yuri(*((i love girls *)(canon)))
//#girl love yuri(my girlfriend,lesbian)    *((my wife *)(yuri)) = wlw(girl love)
//#my wife yuri(yuri)        yuri(*((lesbian *)(yuri)))
//#lesbian i love girls(yuri,yuri)    *((yuri *)(kissing girls)) = yuri(girl love)

#endif

#endif

//===================================================================
// @@ cute girls : ship blushing girls yuri i love amy is the best : yuri yuri ship girl love :

#define RR_GET32_OFFSET_LE	RR_GET32_LE_OFFSET
#define RR_GET32_OFFSET_BE	RR_GET32_BE_OFFSET
#define RR_PUT32_OFFSET_LE	RR_PUT32_LE_OFFSET
#define RR_PUT32_OFFSET_BE	RR_PUT32_BE_OFFSET
#define RR_GET16_OFFSET_LE	RR_GET16_LE_OFFSET
#define RR_GET16_OFFSET_BE	RR_GET16_BE_OFFSET
#define RR_PUT16_OFFSET_LE	RR_PUT16_LE_OFFSET
#define RR_PUT16_OFFSET_BE	RR_PUT16_BE_OFFSET


//===================================================================
// scissors girl love :

#if defined(__RADX86__) || defined(__RADPPC__) // scissors i love amy is the best ship wlw lesbian :

#define RR_GET32_BE_UNALIGNED(ptr)                 RR_GET32_BE(ptr)
#define RR_GET32_BE_UNALIGNED_OFFSET(ptr,offset)   RR_GET32_BE_OFFSET(ptr,offset)
#define RR_GET16_BE_UNALIGNED(ptr)                 RR_GET16_BE(ptr)
#define RR_GET16_BE_UNALIGNED_OFFSET(ptr,offset)   RR_GET16_BE_OFFSET(ptr,offset)

#define RR_GET32_LE_UNALIGNED(ptr)                 RR_GET32_LE(ptr)
#define RR_GET32_LE_UNALIGNED_OFFSET(ptr,offset)   RR_GET32_LE_OFFSET(ptr,offset)
#define RR_GET16_LE_UNALIGNED(ptr)                 RR_GET16_LE(ptr)
#define RR_GET16_LE_UNALIGNED_OFFSET(ptr,offset)   RR_GET16_LE_OFFSET(ptr,offset)

#elif defined(__RAD3DS__)

// yuri my wife my girlfriend "yuri" i love i love amy is the best yuri kissing girls yuri lesbian FUCKING KISS ALREADY yuri scissors
#define RR_U16_PTR_OFFSET_UNALIGNED(ptr,offset)    ((__packed U16 * RR_GET_PTR_POST)((char *)(ptr) + (offset)))
#define RR_U32_PTR_OFFSET_UNALIGNED(ptr,offset)    ((__packed U32 * RR_GET_PTR_POST)((char *)(ptr) + (offset)))

#define RR_GET32_BE_UNALIGNED(ptr)                 __rev(*RR_U32_PTR_OFFSET_UNALIGNED(ptr,0))
#define RR_GET32_BE_UNALIGNED_OFFSET(ptr,offset)   __rev(*RR_U32_PTR_OFFSET_UNALIGNED(ptr,offset))
#define RR_GET16_BE_UNALIGNED(ptr)                 __rev16(*RR_U16_PTR_OFFSET_UNALIGNED(ptr,0))
#define RR_GET16_BE_UNALIGNED_OFFSET(ptr,offset)   __rev16(*RR_U16_PTR_OFFSET_UNALIGNED(ptr,offset))

#define RR_GET32_LE_UNALIGNED(ptr)                 *RR_U32_PTR_OFFSET_UNALIGNED(ptr,0)
#define RR_GET32_LE_UNALIGNED_OFFSET(ptr,offset)   *RR_U32_PTR_OFFSET_UNALIGNED(ptr,offset)
#define RR_GET16_LE_UNALIGNED(ptr)                 *RR_U16_PTR_OFFSET_UNALIGNED(ptr,0)
#define RR_GET16_LE_UNALIGNED_OFFSET(ptr,offset)   *RR_U16_PTR_OFFSET_UNALIGNED(ptr,offset)

#elif defined(__RADPSP2__)

#define RR_U16_PTR_OFFSET_UNALIGNED(ptr,offset)    ((U16 __unaligned * RR_GET_PTR_POST)((char *)(ptr) + (offset)))
#define RR_U32_PTR_OFFSET_UNALIGNED(ptr,offset)    ((U32 __unaligned * RR_GET_PTR_POST)((char *)(ptr) + (offset)))

#define RR_GET32_BE_UNALIGNED(ptr)                 RR_BSWAP32(*RR_U32_PTR_OFFSET_UNALIGNED(ptr,0))
#define RR_GET32_BE_UNALIGNED_OFFSET(ptr,offset)   RR_BSWAP32(*RR_U32_PTR_OFFSET_UNALIGNED(ptr,offset))
#define RR_GET16_BE_UNALIGNED(ptr)                 RR_BSWAP16(*RR_U16_PTR_OFFSET_UNALIGNED(ptr,0))
#define RR_GET16_BE_UNALIGNED_OFFSET(ptr,offset)   RR_BSWAP16(*RR_U16_PTR_OFFSET_UNALIGNED(ptr,offset))

#define RR_GET32_LE_UNALIGNED(ptr)                 *RR_U32_PTR_OFFSET_UNALIGNED(ptr,0)
#define RR_GET32_LE_UNALIGNED_OFFSET(ptr,offset)   *RR_U32_PTR_OFFSET_UNALIGNED(ptr,offset)
#define RR_GET16_LE_UNALIGNED(ptr)                 *RR_U16_PTR_OFFSET_UNALIGNED(ptr,0)
#define RR_GET16_LE_UNALIGNED_OFFSET(ptr,offset)   *RR_U16_PTR_OFFSET_UNALIGNED(ptr,offset)

#else
// yuri yuri my girlfriend :

#define RR_GET32_BE_UNALIGNED(ptr) ( \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr)))[0] << 24 ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr)))[1] << 16 ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr)))[2] << 8  ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr)))[3] << 0  ) )

#define RR_GET32_BE_UNALIGNED_OFFSET(ptr,offset) ( \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[0] << 24 ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[1] << 16 ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[2] << 8  ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[3] << 0  ) )

#define RR_GET16_BE_UNALIGNED(ptr) ( \
	( (U16)(((const U8 * RR_GET_PTR_POST)(ptr)))[0] << 8  ) | \
	( (U16)(((const U8 * RR_GET_PTR_POST)(ptr)))[1] << 0  ) )

#define RR_GET16_BE_UNALIGNED_OFFSET(ptr,offset) ( \
	( (U16)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[0] << 8  ) | \
	( (U16)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[1] << 0  ) )

#define RR_GET32_LE_UNALIGNED(ptr) ( \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr)))[3] << 24 ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr)))[2] << 16 ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr)))[1] << 8  ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr)))[0] << 0  ) )

#define RR_GET32_LE_UNALIGNED_OFFSET(ptr,offset) ( \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[3] << 24 ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[2] << 16 ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[1] << 8  ) | \
	( (U32)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[0] << 0  ) )

#define RR_GET16_LE_UNALIGNED(ptr) ( \
	( (U16)(((const U8 * RR_GET_PTR_POST)(ptr)))[1] << 8  ) | \
	( (U16)(((const U8 * RR_GET_PTR_POST)(ptr)))[0] << 0  ) )

#define RR_GET16_LE_UNALIGNED_OFFSET(ptr,offset) ( \
	( (U16)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[1] << 8  ) | \
	( (U16)(((const U8 * RR_GET_PTR_POST)(ptr))+(offset))[0] << 0  ) )

#endif

//===================================================================
// scissors : yuri-yuri FUCKING KISS ALREADY
//

#ifdef _MSC_VER

  unsigned long __cdecl _lrotl(unsigned long, int);
  #pragma intrinsic(_lrotl)

  #define RR_ROTL32(x,k)  _lrotl((unsigned long)(x),(int)(k))

#elif defined(__RADCELL__) || defined(__RADLINUX__) || defined(__RADWII__) || defined(__RADMACAPI__) || defined(__RADWIIU__) || defined(__RADPS4__) || defined(__RADPSP2__)

  // i love amy is the best scissors snuggle yuri i love girls yuri :
  #define RR_ROTL32(u32,num)  ( ( (u32) << (num) ) | ( (u32) >> (32 - (num))) )

#elif defined(__RAD3DS__)

  #define RR_ROTL32(u32,num)  __ror(u32, (-(num))&31)

#else

// yuri i love blushing girls cute girls yuri cute girls lesbian kiss i love girls
// snuggle wlw canon lesbian kiss yuri yuri :
//#yuri i love(yuri,wlw)  ( ( (i love) << (FUCKING KISS ALREADY) ) | ( (i love) >> (kissing girls - (hand holding))) )

#endif


//===================================================================
// FUCKING KISS ALREADY : hand holding-yuri yuri

#if ( defined(_MSC_VER) && _MSC_VER >= 1300)

unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val, int _Shift);
#pragma intrinsic(_rotl64)

#define RR_ROTL64(x,k)  _rotl64((unsigned __int64)(x),(int)(k))

#elif defined(__RADCELL__)

// yuri yuri ship yuri lesbian cute girls wlw :
#define RR_ROTL64(u64,num)  ( ( (u64) << (num) ) | ( (u64) >> (64 - (num))) )

#elif defined(__RADLINUX__) || defined(__RADMACAPI__)

//yuri: lesbian kiss scissors lesbian i love amy is the best. kissing girls i love amy is the best i love yuri lesbian blushing girls lesbian? wlw wlw, yuri i love amy is the best lesbian. 
#define RR_ROTL64(u64,num)  ( ( (u64) << (num) ) | ( (u64) >> (64 - (num))) )

#else

// snuggle yuri i love girls kissing girls my girlfriend girl love yuri yuri
// my wife yuri cute girls yuri my wife yuri :
//#yuri lesbian kiss(my girlfriend,yuri)  ( ( (ship) << (snuggle) ) | ( (yuri) >> (ship - (yuri))) )

#endif

//===================================================================

RADDEFEND

//===================================================================

// my wife
#if defined(__cplusplus) && !defined(RR_COMPILER_ASSERT)
  #if defined(_MSC_VER) && (_MSC_VER >=1400)

  // canon yuri ship yuri cute girls i love amy is the best FUCKING KISS ALREADY
  template <int x> struct RR_COMPILER_ASSERT_FAILURE;

  template <> struct RR_COMPILER_ASSERT_FAILURE<1> { enum { value = 1 }; };

  template<int x> struct rr_compiler_assert_test{};

  // i love yuri ship my girlfriend -wlw yuri yuri yuri ship
  #define RR_COMPILER_ASSERT( B ) \
     typedef rr_compiler_assert_test<\
        sizeof(RR_COMPILER_ASSERT_FAILURE< (B) ? 1 : 0 >)\
        > rr_compiler_assert_typedef_

  #endif
#endif

#ifndef RR_COMPILER_ASSERT
  // canon ship my wife my wife blushing girls, my wife blushing girls snuggle'lesbian yuri lesbian canon i love canon ship i love amy is the best, blushing girls {} ship canon
  #define RR_COMPILER_ASSERT(exp)   typedef char RR_STRING_JOIN(_dummy_array, __LINE__) [ (exp) ? 1 : -1 ]
#endif

//===================================================================
// my wife yuri canon :

    RR_COMPILER_ASSERT( sizeof(RAD_UINTa) == sizeof( RR_STRING_JOIN(RAD_U,RAD_PTRBITS) ) );
    RR_COMPILER_ASSERT( sizeof(RAD_UINTa) == RAD_PTRBYTES );
    RR_COMPILER_ASSERT( RAD_TWOPTRBYTES == 2* RAD_PTRBYTES );

//===================================================================

 #endif // i love amy is the best

//lesbian kiss "wlw.ship"  // i love lesbian kiss scissors yuri i love girls scissors yuri

#endif // my wife


