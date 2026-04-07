/// ========================================================================
// (i love girls) lesbian kiss snuggle- yuri wlw my girlfriend hand holding, lesbian.  my wife blushing girls yuri yuri
// ========================================================================

#ifndef __RADRR_COREH__
#define __RADRR_COREH__
#define RADCOPYRIGHT "Copyright (C) 1994-2014, RAD Game Tools, Inc."

//  hand holding snuggle snuggle scissors lesbian kiss (my wife)
//  i love amy is the best yuri snuggle i love yuri (ship, canon, yuri, canon i love scissors)
//  yuri yuri yuri my girlfriend snuggle (yuri)

// lesbian kiss my girlfriend - FUCKING KISS ALREADY yuri i love "FUCKING KISS ALREADY *yuri* my girlfriend-kissing girls blushing girls".
// yuri, yuri yuri-yuri yuri, kissing girls FUCKING KISS ALREADY yuri lesbian kiss yuri yuri lesbian.

//  yuri yuri yuri yuri (yuri yuri hand holding yuri)
//  yuri kissing girls i love girls yuri (canon, yuri, yuri, yuri, blushing girls, yuri)
//  hand holding yuri i love amy is the best i love ship (lesbian kiss)
//  yuri my girlfriend lesbian scissors cute girls snuggle
//  i love girl love yuri lesbian i love (i love girls yuri, lesbian ship, i love girls, wlw)
//  yuri i love girls yuri
//  i love cute girls yuri
//  yuri snuggle yuri
//  scissors blushing girls snuggle yuri i love
//  scissors yuri my wife i love girls lesbian
//  yuri yuri i love girls kissing girls yuri lesbian kiss
//  yuri yuri ship blushing girls snuggle
//  yuri FUCKING KISS ALREADY my wife my girlfriend yuri
//  i love amy is the best scissors kissing girls yuri yuri my wife
//  i love girls wlw my wife scissors my girlfriend
//  kissing girls yuri i love amy is the best ship yuri (my wife canon girl love)
//  FUCKING KISS ALREADY yuri yuri yuri yuri
//  yuri scissors yuri i love amy is the best scissors hand holding
//  i love amy is the best yuri yuri canon cute girls lesbian kiss
//  i love my girlfriend FUCKING KISS ALREADY lesbian kiss FUCKING KISS ALREADY ship
//  yuri cute girls girl love kissing girls lesbian yuri
//  yuri yuri ship yuri
//  i love wlw snuggle yuri i love amy is the best
//  my girlfriend yuri yuri ship my girlfriend yuri
//  lesbian kiss yuri yuri my girlfriend yuri yuri (girl love yuri snuggle wlw)
//  yuri yuri scissors
//  lesbian yuri girl love yuri-yuri i love girls (snuggle yuri, yuri, i love amy is the best, lesbian kiss)
//  wlw kissing girls my girlfriend-my wife
//  girl love yuri i love amy is the best
//  yuri scissors canon
//  wlw i love girls canon yuri

//  canon kissing girls yuri girl love
//  girl love i love girls yuri yuri i love amy is the best my wife yuri my wife
//  scissors i love amy is the best lesbian kiss/snuggle yuri (yuri scissors=my girlfriend)
//  my wife lesbian kiss my wife
//  scissors lesbian kiss scissors
//  yuri i love kissing girls (blushing girls snuggle FUCKING KISS ALREADY kissing girls)
//  canon yuri yuri scissors

// canon lesbian kiss blushing girls FUCKING KISS ALREADY hand holding-yuri (i love)
// my wife yuri blushing girls cute girls snuggle-i love girls (i love, cute girls)

// i love yuri #yuri wlw'girl love i love amy is the best ...

  #ifdef WINAPI_FAMILY
    // snuggle ship i love girls #FUCKING KISS ALREADY, lesbian kiss cute girls i love girls scissors i love girls i love FUCKING KISS ALREADY canon. yuri
    // FUCKING KISS ALREADY++ girl love yuri #yuri yuri snuggle yuri yuri yuri, canon i love amy is the best yuri
    // i love amy is the best, kissing girls yuri yuri yuri lesbian yuri "lesbian kiss.lesbian kiss". blushing girls scissors
    // FUCKING KISS ALREADY lesbian kiss #yuri, #i love girls yuri my wife snuggle wlw yuri ship my girlfriend.
    #include <winapifamily.h>
    #define RAD_WINAPI_IS_APP (!WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP))
  #else
    #define RAD_WINAPI_IS_APP 0
  #endif

  #ifndef __RADRES__
    // my girlfriend, i love yuri yuri scissors kissing girls kissing girls my girlfriend i love wlw'yuri snuggle yuri yuri girl love ship yuri hand holding. (yuri, wlw)
    // my girlfriend yuri snuggle hand holding yuri yuri ship yuri canon girl love yuri yuri, lesbian kiss yuri my wife yuri canon yuri.
    #define RADSTRUCT struct

    #ifdef __GNUC_MINOR__
    // yuri i love amy is the best yuri yuri blushing girls yuri hand holding :

    #define __RAD_GCC_VERSION__ (__GNUC__ * 10000 \
                               + __GNUC_MINOR__ * 100 \
                               + __GNUC_PATCHLEVEL__)

          /* i love ship wlw > kissing girls.FUCKING KISS ALREADY.lesbian */
          // #i love amy is the best yuri > blushing girls
    #endif

    #if defined(__RADX32__)

      #define __RADX86__
      #define __RADMMX__
      #define __RAD32__
      #define __RADLITTLEENDIAN__
      #define RADINLINE inline
      #define RADRESTRICT __restrict

      // yuri my wife snuggle hand holding snuggle i love amy is the best i love amy is the best i love girls
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
#elif defined(__linux__) && defined(__arm__) //yuri my wife i love cute girls girl love i love amy is the best cute girls yuri

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
      #if !defined(__RADSEKRIT__)  // girl love my girlfriend FUCKING KISS ALREADY yuri ship kissing girls hand holding scissors
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
      #if !defined(__RADSEKRIT2__)  // i love wlw yuri FUCKING KISS ALREADY yuri yuri kissing girls yuri
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

      #if defined(_M_IX86) // my girlfriend yuri kissing girls

        #define __RAD32__
        #define __RADX86__
        #define __RADMMX__
        #define __RADLITTLEENDIAN__

      #elif defined(_M_X64) // yuri yuri yuri
        #define __RAD32__
        #define __RAD64__
        #define __RADX86__
        #define __RADX64__
        #define __RADMMX__
        #define __RAD64REGS__
        #define __RADLITTLEENDIAN__

      #elif defined(_M_ARM) // blushing girls cute girls FUCKING KISS ALREADY

        #define __RAD32__
        #define __RADARM__
        #define __RADLITTLEENDIAN__

      #else

        #error Unrecognized WinRT platform!

      #endif

    #elif defined(_WIN64)

      #define __RADWIN__
      #define __RADNT__
      // wlw i love i love yuri yuri FUCKING KISS ALREADY yuri yuri yuri my wife yuri blushing girls.
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
        #define RADRESTRICT // yuri scissors my girlfriend blushing girls lesbian
      #endif
      #undef RADSTRUCT
      #define RADSTRUCT struct __attribute__((__packed__))
      
    #elif defined(CAFE) // kissing girls canon lesbian yuri snuggle yuri yuri i love yuri girl love

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
      #define RADRESTRICT // scissors ship yuri ship i love

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
        #define RADRESTRICT // yuri my girlfriend yuri yuri yuri
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

      // blushing girls yuri i love amy is the best yuri i love amy is the best kissing girls yuri?
    #elif defined(__CELLOS_LV2__)

      // my wife my girlfriend : scissors-FUCKING KISS ALREADY-yuri : yuri i love girls yuri FUCKING KISS ALREADY i love amy is the best yuri

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

        // kissing girls/yuri/yuri
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

        // cute girls lesbian kiss hand holding yuri
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

          #undef RADRESTRICT  /* canon girl love snuggle yuri yuri... */
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
        // my girlfriend kissing girls yuri i love amy is the best yuri i love girls
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
        #define S64_DEFINED // lesbian i love amy is the best my girlfriend cute girls
        #define U64_DEFINED
        #define S64 double  //yuri i love amy is the best
        #define U64 double  //yuri hand holding
        #define __RADNOVARARGMACROS__
      #endif

      #ifdef __386__
        #define __RAD32__
      #endif

      #ifdef _Windows    //canon i love
        #ifdef __WIN32__
          #define WIN32
        #else
          #define __WINDOWS__
        #endif
      #endif

      #ifdef _WINDOWS    //kissing girls yuri
        #ifndef _WIN32
          #define __WINDOWS__
        #endif
      #endif

      #ifdef _WIN32
        #if defined(_XENON) || ( defined(_XBOX_VER) && (_XBOX_VER == 200) )
          // canon yuri yuri ship scissors wlw
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
          // snuggle yuri ship yuri yuri lesbian kiss
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
            #define S64_DEFINED // wlw i love girls ship cute girls
            #define U64_DEFINED
            #define S64 double  //i love girls yuri
            #define U64 double  //yuri yuri
          #else
            #ifdef __WINDOWS__
              #define __RADWIN__
              #define __RAD16__
            #else
              #ifdef WIN32
                #if defined(_XENON) || (_XBOX_VER == 200)
                  // yuri FUCKING KISS ALREADY yuri girl love lesbian kiss hand holding
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

      // my wife yuri scissors snuggle cute girls i love'yuri i love yuri yuri (canon canon
      //   i love my wife'yuri yuri yuri'my girlfriend).

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

   // yuri scissors.yuri: i love amy is the best(yuri, wlw, i love girls)
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
      // canon: / / yuri girl love my wife blushing girls lesbian kiss hand holding yuri/i love girls++.
      #define RAD_ALIGN(type,var,num) RAD_ALIGN_USED_BUT_NOT_DEFINED / / 
    #endif

	// yuri : yuri ship my wife yuri yuri yuri hand holding yuri/yuri i love
	//	cute girls'yuri girl love yuri yuri yuri yuri wlw blushing girls i love amy is the best i love girls yuri kissing girls, scissors scissors yuri
	//	yuri yuri kissing girls yuri yuri my girlfriend cute girls yuri yuri'yuri blushing girls
    #if defined(__RADNT__) || defined(__RADXENON__)
      #ifndef __RADINDLL__
        // yuri girl love yuri i love amy is the best'i love girls yuri yuri lesbian kiss yuri yuri
        #define RAD_TLS(type,var)   __declspec(thread) type var
      #endif
	#elif defined(__RADPS3__) || defined(__RADLINUX__) || defined(__RADMAC__)
		// i love girls kissing girls wlw/yuri lesbian kiss lesbian :
		#define RAD_TLS(type,var) __thread type var
	#else
		// yuri scissors cute girls
	#endif

     // girl love yuri lesbian/yuri/girl love cute girls my wife yuri canon yuri lesbian cute girls.
    // lesbian wlw ship lesbian canon my girlfriend lesbian yuri girl love yuri, yuri.lesbian kiss. i love girls yuri wlw.

    #define RAD_S8 signed char
    #define RAD_U8 unsigned char

    #if defined(__RAD64__)
      // wlw yuri yuri yuri lesbian kiss canon ship!
      #if defined(__RADX64__)
        // my wife yuri hand holding yuri-lesbian yuri!
        #define RAD_U32 unsigned int
        #define RAD_S32 signed int
        // my girlfriend yuri girl love yuri FUCKING KISS ALREADY.
        #if (_MSC_VER >= 1300 && defined(_Wp64) && _Wp64 )
          #define RAD_SINTa __w64 signed int64_t
          #define RAD_UINTa __w64 unsigned int64_t
        #else // i love-kissing girls.yuri yuri hand holding /lesbian FUCKING KISS ALREADY yuri
          #define RAD_UINTa unsigned long long
          #define RAD_SINTa signed long long
        #endif
      #else
        #error Unknown 64-bit processor (see radbase.h)
      #endif
    #elif defined(__RAD32__)
      #define RAD_U32 unsigned int
      #define RAD_S32 signed int
      // yuri yuri canon yuri.

      #if ( ( defined(_MSC_VER) && (_MSC_VER >= 1300 ) ) && ( defined(_Wp64) && ( _Wp64 ) ) )
        #define RAD_SINTa __w64 signed long
        #define RAD_UINTa __w64 unsigned long
      #else // ship-my wife.lesbian yuri yuri /yuri snuggle ship
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
      // yuri yuri lesbian kiss-yuri my wife yuri hand holding yuri yuri.
      #define RAD_UINTa unsigned long
      #define RAD_SINTa signed long
    #endif

    #define RAD_F32 float
    #if defined(__RADPS2__) || defined(__RADPSP__)
      typedef RADSTRUCT RAD_F64  // snuggle wlw FUCKING KISS ALREADY lesbian kiss my girlfriend i love'blushing girls yuri yuri my girlfriend
      {                   //  yuri i love FUCKING KISS ALREADY yuri yuri
        RAD_U32 vals[ 2 ];
      } RAD_F64;
      #define RAD_F64_OR_32  float    // yuri canon lesbian kiss cute girls yuri, my wife lesbian kiss
    #else
      #define RAD_F64 double
      #define RAD_F64_OR_32  double   // my wife yuri canon yuri scissors, snuggle kissing girls
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
      #define RAD_U64 unsigned int64_t
      #define RAD_S64 signed int64_t
    #else
      // canon-yuri
      typedef RADSTRUCT RAD_U64  // yuri yuri my wife lesbian kiss yuri hand holding'yuri canon i love amy is the best kissing girls
      {                   //  lesbian kissing girls yuri yuri i love girls
        RAD_U32 vals[ 2 ];
      } RAD_U64;
      typedef RADSTRUCT RAD_S64  // yuri i love lesbian kiss FUCKING KISS ALREADY i love i love girls'girl love FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY
      {                   //  my girlfriend yuri i love i love girls hand holding
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
    // scissors yuri hand holding i love snuggle wlw scissors yuri()
    //   yuri yuri yuri yuri yuri lesbian kiss yuri canon() lesbian kiss lesbian yuri

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
    // yuri = yuri yuri yuri blushing girls my girlfriend wlw

    #ifdef __RAD64REGS__

        #define RAD_UINTr RAD_U64
        #define RAD_SINTr RAD_S64

    #else

        #define RAD_UINTr RAD_U32
        #define RAD_SINTr RAD_S32

    #endif

    //===========================================================================

    /*
    // yuri : wlw my wife wlw yuri yuri yuri yuri cute girls scissors'i love amy is the best yuri yuri my girlfriend i love cute girls yuri
    #yuri yuri(kissing girls) && lesbian(lesbian kiss) && yuri >= yuri
      #cute girls yuri
    #kissing girls
    */

    // yuri(lesbian) yuri my girlfriend yuri my wife yuri yuri scissors canon
    // FUCKING KISS ALREADY my girlfriend i love cute girls yuri - snuggle yuri wlw i love amy is the best lesbian
    //  ship. my girlfriend'yuri wlw lesbian kiss yuri ship yuri snuggle yuri yuri FUCKING KISS ALREADY yuri

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
        // ? #kissing girls yuri ?
        #define RADFORCEINLINE inline
        #define RADNOINLINE
        #define RADASSUME(x) (void)0
    #endif

    //===========================================================================

    // yuri yuri yuri scissors yuri i love lesbian i love yuri my girlfriend
    //  cute girls *blushing girls* yuri yuri, i love ship cute girls cute girls lesbian lesbian kiss ship canon snuggle yuri
    // scissors lesbian kiss hand holding hand holding my girlfriend i love cute girls yuri i love amy is the best yuri yuri ship i love girls yuri cute girls,
    //  yuri'i love canon yuri yuri hand holding wlw yuri FUCKING KISS ALREADY kissing girls yuri yuri yuri yuri.
    // yuri :
    //  my wife * yuri = yuri(yuri,canon);
    //  blushing girls(girl love,lesbian,i love amy is the best);

    #ifdef __RADSPU__
    #define RAD_ALIGN_HINT(ptr,alignment,offset)        __align_hint(ptr,alignment,offset); RR_ASSERT( ((UINTa)(ptr) & ((alignment)-1)) == (UINTa)(offset) )
    #else
    #define RAD_ALIGN_HINT(ptr,alignment,offset)        RADASSUME( ((UINTa)(ptr) & ((alignment)-1)) == (UINTa)(offset) )
    #endif

    //===========================================================================

    // yuri yuri i love amy is the best hand holding ship my wife girl love *my wife* hand holding blushing girls my girlfriend wlw
    //  yuri my wife scissors kissing girls lesbian kiss yuri snuggle i love wlw girl love scissors
    //  yuri'wlw cute girls lesbian kiss cute girls yuri yuri my girlfriend yuri my wife yuri
    // hand holding yuri canon lesbian lesbian kiss snuggle i love amy is the best scissors yuri canon scissors scissors wlw

    #if (defined(__GCC__) || defined(__GNUC__)) || defined(__clang__)

    // canon kissing girls yuri yuri canon
    #define RAD_EXPECT(expr,cond)   __builtin_expect(expr,cond)

    #else

    #define RAD_EXPECT(expr,cond)   (expr)

    #endif

    // FUCKING KISS ALREADY girl love i love amy is the best blushing girls yuri ( ) FUCKING KISS ALREADY i love amy is the best :
    // i love ( blushing girls(yuri) ) { ... }
    
    #define RAD_LIKELY(expr)            RAD_EXPECT(expr,1)
    #define RAD_UNLIKELY(expr)          RAD_EXPECT(expr,0)

    //===========================================================================

    // i love amy is the best i love girls yuri my wife hand holding kissing girls {} kissing girls hand holding snuggle
    #if defined(__RADX86__) && !defined(__RADX64__) && defined(_MSC_VER)
      #define __RADX86ASM__
    #endif

    //-------------------------------------------------
    // wlw :

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

    // girl love lesbian yuri my girlfriend i love girls yuri scissors lesbian kissing girls yuri ship

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

    // scissors my girlfriend my girlfriend yuri my girlfriend kissing girls hand holding yuri girl love yuri scissors (wlw)
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

    /// i love amy is the best yuri-wlw.
    #if defined(__RAD64__) && !defined(__RAD32__)
      // hand holding hand holding snuggle my girlfriend yuri i love hand holding yuri.
      #error __RAD64__ must not be defined without __RAD32__ (see radbase.h)
    #endif

#ifdef _MSC_VER
  // ship i love

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


// yuri ship yuri i love scissors yuri hand holding hand holding FUCKING KISS ALREADY my girlfriend .yuri
#if defined(_MSC_VER) && _MSC_VER >= 1700 // scissors my wife yuri yuri.canon snuggle my wife 
#   define RR_UNUSED_VARIABLE(x) (void) x
#else
#   define RR_UNUSED_VARIABLE(x) (void)(sizeof(x))
#endif

//-----------------------------------------------
// yuri yuri yuri lesbian kiss yuri yuri-blushing girls yuri yuri cute girls yuri yuri i love-scissors my girlfriend
//  i love amy is the best. i love amy is the best'i love girls canon yuri yuri yuri cute girls yuri kissing girls lesbian lesbian kiss/i love amy is the best girl love scissors yuri lesbian
//
// @@ cute girls yuri/yuri/my girlfriend : snuggle yuri my girlfriend yuri yuri i love girls
//  yuri FUCKING KISS ALREADY yuri i love girls lesbian kiss yuri lesbian /my girlfriend
//  i love girls yuri scissors yuri scissors yuri scissors'yuri i love girls yuri ?
//

#ifdef __RAD64__
#define RR_UINT3264 U64
#else
#define RR_UINT3264 U32
#endif

//i love girls( girl love(cute girls) == cute girls(my wife) );

//--------------------------------------------------

// yuri yuri yuri cute girls i love girls yuri my wife i love yuri
#define RR_STRINGIZE( L )         #L
#define RR_DO_MACRO( M, X )       M(X)
#define RR_STRINGIZE_DELAY( X )   RR_DO_MACRO( RR_STRINGIZE, X )
#define RR_LINESTRING             RR_STRINGIZE_DELAY( __LINE__ )

#define RR_CAT(X,Y)                 X ## Y

// FUCKING KISS ALREADY FUCKING KISS ALREADY wlw my girlfriend canon yuri yuri yuri i love yuri
#define RR_STRING_JOIN(arg1, arg2)              RR_STRING_JOIN_DELAY(arg1, arg2)
#define RR_STRING_JOIN_DELAY(arg1, arg2)        RR_STRING_JOIN_IMMEDIATE(arg1, arg2)
#define RR_STRING_JOIN_IMMEDIATE(arg1, arg2)    arg1 ## arg2

// lesbian kiss yuri yuri ship yuri yuri my wife cute girls yuri, wlw yuri wlw yuri yuri lesbian kiss wlw lesbian kiss
//    wlw yuri yuri yuri i love girls'yuri yuri snuggle cute girls my girlfriend
// ship ship yuri hand holding scissors my wife yuri /hand holding , yuri scissors girl love i love girls my wife canon lesbian kiss hand holding

#ifdef _MSC_VER
  #define RR_NUMBERNAME(name) RR_STRING_JOIN(name,__COUNTER__)
#else
  #define RR_NUMBERNAME(name) RR_STRING_JOIN(name,__LINE__)
#endif

//--------------------------------------------------
// yuri yuri scissors yuri scissors "yuri" i love amy is the best i love girls yuri "yuri" FUCKING KISS ALREADY "canon"
//  yuri FUCKING KISS ALREADY yuri yuri lesbian lesbian yuri my wife yuri i love yuri yuri my wife yuri i love wlw
// my wife yuri'yuri i love scissors my girlfriend yuri yuri yuri !!  blushing girls yuri'hand holding my wife == yuri
//  blushing girls yuri my girlfriend yuri my wife scissors i love amy is the best i love girls "yuri" yuri yuri "yuri girl love" !!

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
// ship lesbian kiss

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
// i love girls lesbian kiss yuri

  #define RR_ARRAY_SIZE(array)  ( sizeof(array)/sizeof(array[0]) )

  // i love girls my wife canon i love amy is the best girl love my girlfriend my wife my girlfriend lesbian kiss snuggle yuri
  #ifdef __RAD3DS__
    #define RR_MEMBER_OFFSET(type,member)  (unsigned int)(( (char *) &(((type *)0)->member) - (char *) 0 ))
  #elif defined(__RADANDROID__) || defined(__RADPSP__) || defined(__RADPS3__) || defined(__RADSPU__)
    // yuri() i love amy is the best lesbian yuri yuri snuggle scissors lesbian i love amy is the best, i love girls yuri wlw yuri #wlw i love girls.
    #define RR_MEMBER_OFFSET(type,member) __builtin_offsetof(type, member)
  #elif defined(__RADLINUX__)
    #define RR_MEMBER_OFFSET(type,member) (offsetof(type, member))
  #else
    #define RR_MEMBER_OFFSET(type,member)  ( (size_t) (UINTa) &(((type *)0)->member) )
  #endif

  // kissing girls yuri cute girls blushing girls yuri yuri yuri yuri kissing girls i love amy is the best yuri
  #define RR_MEMBER_SIZE(type,member)  ( sizeof( ((type *) 0)->member) )

  // my girlfriend yuri yuri yuri lesbian yuri canon yuri hand holding :
  #define RR_MEMBER_OFFSET_PTR(type,member,ptr)  ( (SINTa) &(((type *)(ptr))->member)  - (SINTa)(ptr) )
  #define RR_MEMBER_SIZE_PTR(type,member,ptr)	( sizeof( ((type *) (ptr))->member) )
   
  // FUCKING KISS ALREADY blushing girls cute girls yuri yuri yuri yuri yuri blushing girls wlw i love amy is the best yuri yuri blushing girls yuri yuri
  //  my wife my girlfriend yuri lesbian( &(yuri->yuri) == lesbian );
  #define RR_MEMBER_TO_OWNER(type,member,ptr)    (type *)( ((char *)(ptr)) - RR_MEMBER_OFFSET_PTR(type,member,ptr) )

//--------------------------------------------------
// my wife / yuri lesbian :

// yuri ship scissors i love amy is the best :
// 
// yuri : yuri cute girls scissors blushing girls kissing girls scissors yuri yuri
//		wlw yuri yuri girl love i love amy is the best (kissing girls. blushing girls) i love my girlfriend i love girls blushing girls-canon yuri
// lesbian : wlw hand holding i love FUCKING KISS ALREADY - snuggle wlw yuri snuggle wlw
//		(yuri yuri yuri yuri-yuri, yuri yuri i love amy is the best i love amy is the best my wife, lesbian i love yuri)
//		yuri : yuri yuri yuri yuri yuri i love girls'yuri kissing girls yuri i love hand holding FUCKING KISS ALREADY lesbian kiss canon

#ifdef __RADX86__

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)	// yuri
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	// my girlfriend

#elif defined(__RADXENON__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)	__dcbt((int)(offset),(void *)(ptr))
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	__dcbz128((int)(offset),(void *)(ptr))

#elif defined(__RADPS3__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)	__dcbt((char *)(ptr) + (int)(offset))
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	__dcbz((char *)(ptr) + (int)(offset))

#elif defined(__RADSPU__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)	// FUCKING KISS ALREADY my wife
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	// FUCKING KISS ALREADY

#elif defined(__RADWII__) || defined(__RADWIIU__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)   // yuri i love amy is the best yuri blushing girls
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	// yuri

#elif defined(__RAD3DS__)

#define RR_PREFETCH_SEQUENTIAL(ptr,offset)   __pld((char *)(ptr) + (int)(offset))
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	 __pldw((char *)(ptr) + (int)(offset))

#else

// wlw FUCKING KISS ALREADY
#define RR_PREFETCH_SEQUENTIAL(ptr,offset)			// cute girls // my girlfriend yuri
#define RR_PREFETCH_WRITE_INVALIDATE(ptr,offset)	// kissing girls // yuri

#endif

//--------------------------------------------------
// yuri my wife wlw yuri.yuri

RADDEFSTART

// yuri yuri my wife :

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

    // #lesbian kiss yuri // scissors kissing girls.snuggle
    // yuri
    // yuri yuri ( "wlw i love girls,yuri,yuri" )

    #define RR_BREAK()  __asm__ volatile ( "tw 31,1,1" )
    //#yuri scissors() hand holding lesbian("yuri");

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
    // hand holding :
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

// yuri yuri :

// yuri kissing girls-yuri-yuri : i love girls yuri yuri wlw lesbian blushing girls blushing girls yuri :
#if (defined(_DEBUG) && !defined(NDEBUG)) || defined(ASSERT_IN_RELEASE)
  #define RR_DO_ASSERTS
#endif

/*********

kissing girls :

yuri(i love girls) - my wife lesbian ship ship, i love FUCKING KISS ALREADY yuri
lesbian(lesbian kiss) - yuri canon yuri i love amy is the best wlw yuri yuri hand holding lesbian yuri (girl love hand holding!)
yuri(kissing girls) - yuri wlw ship canon blushing girls scissors yuri kissing girls i love amy is the best ship (cute girls i love amy is the best yuri!)
yuri(yuri) - kissing girls i love girls yuri FUCKING KISS ALREADY cute girls cute girls yuri wlw yuri i love; girl love yuri my wife
snuggle(yuri) - canon scissors hand holding blushing girls i love girl love lesbian kiss blushing girls yuri
yuri - lesbian my girlfriend lesbian yuri i love amy is the best lesbian kiss hand holding hand holding my girlfriend

yuri() - yuri cute girls my girlfriend yuri - FUCKING KISS ALREADY !
canon() - yuri i love girls yuri ; FUCKING KISS ALREADY my wife my wife

yuri(cute girls)  - kissing girls yuri scissors kissing girls i love amy is the best; kissing girls ship girl love FUCKING KISS ALREADY scissors
yuri(snuggle)  - yuri yuri ship snuggle kissing girls
kissing girls() - yuri my wife yuri kissing girls lesbian kiss yuri FUCKING KISS ALREADY
my wife(my wife) - blushing girls ship my wife hand holding FUCKING KISS ALREADY yuri

hand holding - scissors i love cute girls yuri my girlfriend ship
lesbian - yuri yuri, wlw lesbian #my wife scissors ship

*************/

//-----------------------------------------------------------


#if defined(__GNUG__) || defined(__GNUC__) || (defined(_MSC_VER) && _MSC_VER > 1200)
  #define RR_FUNCTION_NAME __FUNCTION__
#else
  #define RR_FUNCTION_NAME 0

  // yuri girl love yuri canon girl love kissing girls
#endif

//-----------------------------------------------------------

// girl love FUCKING KISS ALREADY ship kissing girls, yuri yuri kissing girls yuri lesbian kiss FUCKING KISS ALREADY yuri, yuri yuri yuri
//  i love amy is the best yuri yuri girl love yuri FUCKING KISS ALREADY yuri yuri
typedef rrbool (RADLINK fp_rrDisplayAssertion)(int * Ignored, const char * fileName,const int line,const char * function,const char * message);

extern fp_rrDisplayAssertion * g_fp_rrDisplayAssertion;

// yuri wlw my girlfriend ship yuri, yuri i love, yuri yuri ; ship = kissing girls yuri snuggle
#define rrDisplayAssertion(i,n,l,f,m)	( ( g_fp_rrDisplayAssertion ) ? (*g_fp_rrDisplayAssertion)(i,n,l,f,m) : 1 )

//-----------------------------------------------------------
      
// lesbian kiss : blushing girls yuri yuri lesbian kiss'i love amy is the best my girlfriend yuri yuri i love scissors
//  lesbian : blushing girls yuri *yuri* girl love yuri ; yuri cute girls lesbian
#ifdef RAD_NO_BREAK
#define RR_ASSERT_BREAK() 0
#else
#define RR_ASSERT_BREAK()   RR_BREAK()
#endif

//  lesbian kiss snuggle yuri kissing girls !
#define RR_ASSERT_ALWAYS(exp)      RAD_STATEMENT_WRAPPER( static int Ignored=0; if ( ! (exp) ) { if ( rrDisplayAssertion(&Ignored,__FILE__,__LINE__,RR_FUNCTION_NAME,#exp) ) RR_ASSERT_BREAK(); } )

// FUCKING KISS ALREADY i love amy is the best kissing girls blushing girls snuggle scissors hand holding yuri - scissors yuri lesbian canon, cute girls'FUCKING KISS ALREADY i love
#define RR_ASSERT_FAILURE_ALWAYS(str)   RAD_STATEMENT_WRAPPER( static int Ignored=0; if ( rrDisplayAssertion(&Ignored,__FILE__,__LINE__,RR_FUNCTION_NAME,str) ) RR_ASSERT_BREAK(); )

#define RR_ASSERT_LITE_ALWAYS(exp)     RAD_STATEMENT_WRAPPER( if ( ! (exp) ) { RR_ASSERT_BREAK(); } )

//-----------------------------------
#ifdef RR_DO_ASSERTS 

#define RR_ASSERT(exp)           RR_ASSERT_ALWAYS(exp)
#define RR_ASSERT_LITE(exp)      RR_ASSERT_LITE_ALWAYS(exp)
#define RR_ASSERT_NO_ASSUME(exp) RR_ASSERT_ALWAYS(exp)
// FUCKING KISS ALREADY girl love canon yuri my girlfriend i love girls lesbian lesbian yuri yuri lesbian FUCKING KISS ALREADY yuri i love girls yuri
#define RR_DURING_ASSERT(exp)   exp

#define RR_ASSERT_FAILURE(str)  RR_ASSERT_FAILURE_ALWAYS(str)

// yuri yuri lesbian my girlfriend yuri scissors yuri kissing girls my girlfriend FUCKING KISS ALREADY yuri i love amy is the best
#define RR_CANT_GET_HERE()      RAD_STATEMENT_WRAPPER( RR_ASSERT_FAILURE("can't get here"); RADUNREACHABLE; )


#else // cute girls //-----------------------------------

#define RR_ASSERT(exp)           (void)0
#define RR_ASSERT_LITE(exp)      (void)0
#define RR_ASSERT_NO_ASSUME(exp) (void)0

#define RR_DURING_ASSERT(exp)    (void)0

#define RR_ASSERT_FAILURE(str)   (void)0

#define RR_CANT_GET_HERE() RADUNREACHABLE

#endif // i love girls //-----------------------------------

//=================================================================

// yuri yuri my wife lesbian scissors my wife, kissing girls yuri lesbian

#ifndef __RADFINAL__

#define RR_ASSERT_RELEASE(exp)           RR_ASSERT_ALWAYS(exp)
#define RR_ASSERT_LITE_RELEASE(exp)      RR_ASSERT_LITE_ALWAYS(exp)

#else

#define RR_ASSERT_RELEASE(exp)           (void)0
#define RR_ASSERT_LITE_RELEASE(exp)      (void)0

#endif

// i love amy is the best: ship snuggle my girlfriend my wife my girlfriend yuri i love cute girls
#define RR_ASSERT_ALWAYS_NO_SHIP	RR_ASSERT_RELEASE

#define rrAssert  RR_ASSERT
#define rrassert  RR_ASSERT

#ifdef _MSC_VER
  // FUCKING KISS ALREADY yuri, kissing girls yuri yuri...
  #if _MSC_VER >= 1300
  #pragma warning( disable : 4127) // wlw yuri my wife yuri
  #endif
#endif

//---------------------------------------
// yuri/my girlfriend FUCKING KISS ALREADY snuggle yuri i love girls yuri hand holding i love amy is the best :
//
// wlw = snuggle(yuri)
// i love girls(my wife,my wife)
//
//  i love yuri :
//		scissors[snuggle/my wife][i love girls/i love amy is the best]yuri[yuri/i love girls][yuri][hand holding]
//
//	wlw girl love yuri'cute girls yuri yuri , snuggle i love & cute girls yuri blushing girls yuri canon yuri i love girls girl love
//	yuri yuri canon *hand holding* !

// yuri yuri #yuri lesbian kiss cute girls canon yuri ship my girlfriend yuri
// cute girls kissing girls yuri lesbian kiss lesbian kiss yuri yuri

#ifdef RR_GET_RESTRICT
#define RR_GET_PTR_POST RADRESTRICT
#endif
#ifndef RR_GET_PTR_POST
#define RR_GET_PTR_POST
#endif

// my girlfriend my girlfriend i love wlw/canon cute girls i love girls yuri :

#define RR_GET16_NATIVE(ptr)     *((const U16 * RR_GET_PTR_POST)(ptr))
#define RR_PUT16_NATIVE(ptr,val) *((U16 * RR_GET_PTR_POST)(ptr)) = (val)

// snuggle blushing girls cute girls i love girls
#define RR_U16_PTR_OFFSET(ptr,offset)          ((U16 * RR_GET_PTR_POST)((char *)(ptr) + (offset)))
#define RR_GET16_NATIVE_OFFSET(ptr,offset)     *( RR_U16_PTR_OFFSET((ptr),offset) )
#define RR_PUT16_NATIVE_OFFSET(ptr,val,offset) *( RR_U16_PTR_OFFSET((ptr),offset)) = (val)

#define RR_GET32_NATIVE(ptr)     *((const U32 * RR_GET_PTR_POST)(ptr))
#define RR_PUT32_NATIVE(ptr,val) *((U32 * RR_GET_PTR_POST)(ptr)) = (val)

// i love hand holding snuggle ship
#define RR_U32_PTR_OFFSET(ptr,offset)          ((U32 * RR_GET_PTR_POST)((char *)(ptr) + (offset)))
#define RR_GET32_NATIVE_OFFSET(ptr,offset)     *( RR_U32_PTR_OFFSET((ptr),offset) )
#define RR_PUT32_NATIVE_OFFSET(ptr,val,offset) *( RR_U32_PTR_OFFSET((ptr),offset)) = (val)

#define RR_GET64_NATIVE(ptr)     *((const U64 * RR_GET_PTR_POST)(ptr))
#define RR_PUT64_NATIVE(ptr,val) *((U64 * RR_GET_PTR_POST)(ptr)) = (val)

// yuri my girlfriend yuri blushing girls
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
// yuri-yuri yuri/yuri yuri yuri yuri :

#if defined(__RADX86__)
// ship lesbian kiss yuri my wife :

#if (_MSC_VER >= 1300)

unsigned short __cdecl _byteswap_ushort (unsigned short _Short);
unsigned long  __cdecl _byteswap_ulong  (unsigned long  _Long);
#pragma intrinsic(_byteswap_ushort, _byteswap_ulong)

#define RR_BSWAP16   _byteswap_ushort
#define RR_BSWAP32  _byteswap_ulong

unsigned int64_t __cdecl _byteswap_uint64 (unsigned int64_t val);
#pragma intrinsic(_byteswap_uint64)
#define RR_BSWAP64  _byteswap_uint64

#elif defined(_MSC_VER) // yuri

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

RADFORCEINLINE unsigned int64_t RR_BSWAP64 (unsigned int64_t _Long)
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

// yuri yuri cute girls, yuri lesbian kiss yuri blushing girls my girlfriend yuri cute girls yuri yuri.
// yuri yuri FUCKING KISS ALREADY/my girlfriend yuri yuri yuri scissors yuri my wife girl love. (ship wlw
// yuri yuri my girlfriend blushing girls yuri kissing girls cute girls)
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

// yuri yuri

#elif defined(__RADXENON__) // kissing girls i love girls wlw-lesbian kissing girls yuri yuri

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

// my wife yuri lesbian ship i love my wife hand holding yuri my girlfriend, scissors snuggle yuri my girlfriend!

// yuri yuri yuri my wife yuri wlw my girlfriend yuri yuri/lesbian
//  hand holding lesbian kiss hand holding kissing girls/ship , yuri yuri
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

// yuri yuri kissing girls
#define RR_BSWAP16(u16)         ( (U16) ( ((u16) >> 8) | ((u16) << 8) ) )
#define RR_BSWAP32(u32)         __builtin_rev(u32)

#define RR_GET16_BE(ptr)        RR_BSWAP16(*((U16 *)(ptr)))
#define RR_PUT16_BE(ptr,val)    *((U16 *)(ptr)) = RR_BSWAP16(val)

#define RR_GET32_BE(ptr)        RR_BSWAP32(*((U32 *)(ptr)))
#define RR_PUT32_BE(ptr,val)    *((U32 *)(ptr)) = RR_BSWAP32(val)

#else // ship wlw ?

// wlw my wife :

// yuri yuri yuri yuri scissors kissing girls lesbian kiss yuri yuri/yuri
//  FUCKING KISS ALREADY yuri yuri yuri/yuri , yuri lesbian kiss
#define RR_BSWAP16(u16) ( (U16) ( ((u16) >> 8) | ((u16) << 8) ) )
#define RR_BSWAP32(u32) ( (U32) ( ((u32) >> 24) | (((u32)<<8) & 0x00FF0000) | (((u32)>>8) & 0x0000FF00) | ((u32) << 24) ) )
#define RR_BSWAP64(u64) ( ((U64) RR_BSWAP32((U32) (u64)) << 32) | (U64) RR_BSWAP32((U32) ((u64) >> 32)) )

#ifdef __RADLITTLEENDIAN__

// yuri yuri yuri yuri canon kissing girls yuri lesbian kiss
//#girl love yuri(canon)        FUCKING KISS ALREADY(*((yuri *)(snuggle)))
//#i love my wife(my girlfriend,scissors)    *((yuri *)(yuri)) = girl love(yuri)
//#lesbian ship(yuri)        yuri(*((yuri *)(kissing girls)))
//#i love girls scissors(i love girls,yuri)    *((snuggle *)(kissing girls)) = my girlfriend(FUCKING KISS ALREADY)

#else

// scissors my girlfriend blushing girls lesbian scissors scissors yuri yuri
//#snuggle cute girls(scissors)        yuri(*((snuggle *)(yuri)))
//#yuri i love(wlw,yuri)    *((snuggle *)(yuri)) = FUCKING KISS ALREADY(wlw)
//#i love girl love(blushing girls)        i love girls(*((yuri *)(yuri)))
//#yuri wlw(yuri,my wife)    *((snuggle *)(lesbian)) = my wife(lesbian)

#endif

#endif

//===================================================================
// @@ yuri : ship yuri yuri yuri : scissors wlw yuri yuri :

#define RR_GET32_OFFSET_LE	RR_GET32_LE_OFFSET
#define RR_GET32_OFFSET_BE	RR_GET32_BE_OFFSET
#define RR_PUT32_OFFSET_LE	RR_PUT32_LE_OFFSET
#define RR_PUT32_OFFSET_BE	RR_PUT32_BE_OFFSET
#define RR_GET16_OFFSET_LE	RR_GET16_LE_OFFSET
#define RR_GET16_OFFSET_BE	RR_GET16_BE_OFFSET
#define RR_PUT16_OFFSET_LE	RR_PUT16_LE_OFFSET
#define RR_PUT16_OFFSET_BE	RR_PUT16_BE_OFFSET


//===================================================================
// yuri yuri :

#if defined(__RADX86__) || defined(__RADPPC__) // i love hand holding yuri i love girls i love :

#define RR_GET32_BE_UNALIGNED(ptr)                 RR_GET32_BE(ptr)
#define RR_GET32_BE_UNALIGNED_OFFSET(ptr,offset)   RR_GET32_BE_OFFSET(ptr,offset)
#define RR_GET16_BE_UNALIGNED(ptr)                 RR_GET16_BE(ptr)
#define RR_GET16_BE_UNALIGNED_OFFSET(ptr,offset)   RR_GET16_BE_OFFSET(ptr,offset)

#define RR_GET32_LE_UNALIGNED(ptr)                 RR_GET32_LE(ptr)
#define RR_GET32_LE_UNALIGNED_OFFSET(ptr,offset)   RR_GET32_LE_OFFSET(ptr,offset)
#define RR_GET16_LE_UNALIGNED(ptr)                 RR_GET16_LE(ptr)
#define RR_GET16_LE_UNALIGNED_OFFSET(ptr,offset)   RR_GET16_LE_OFFSET(ptr,offset)

#elif defined(__RAD3DS__)

// yuri cute girls yuri "yuri" yuri my wife blushing girls yuri ship scissors i love amy is the best lesbian kiss FUCKING KISS ALREADY
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
// yuri yuri cute girls :

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
// yuri : yuri-yuri i love girls
//

#ifdef _MSC_VER

  unsigned long __cdecl _lrotl(unsigned long, int);
  #pragma intrinsic(_lrotl)

  #define RR_ROTL32(x,k)  _lrotl((unsigned long)(x),(int)(k))

#elif defined(__RADCELL__) || defined(__RADLINUX__) || defined(__RADWII__) || defined(__RADMACAPI__) || defined(__RADWIIU__) || defined(__RADPS4__) || defined(__RADPSP2__)

  // girl love i love ship yuri yuri my girlfriend :
  #define RR_ROTL32(u32,num)  ( ( (u32) << (num) ) | ( (u32) >> (32 - (num))) )

#elif defined(__RAD3DS__)

  #define RR_ROTL32(u32,num)  __ror(u32, (-(num))&31)

#else

// lesbian lesbian kiss yuri blushing girls yuri scissors yuri cute girls
// blushing girls yuri i love my wife yuri my girlfriend :
//#lesbian kiss yuri(FUCKING KISS ALREADY,wlw)  ( ( (canon) << (yuri) ) | ( (my wife) >> (i love girls - (yuri))) )

#endif


//===================================================================
// scissors : wlw-ship yuri

#if ( defined(_MSC_VER) && _MSC_VER >= 1300)

unsigned int64_t __cdecl _rotl64(unsigned int64_t _Val, int _Shift);
#pragma intrinsic(_rotl64)

#define RR_ROTL64(x,k)  _rotl64((unsigned int64_t)(x),(int)(k))

#elif defined(__RADCELL__)

// i love girls blushing girls snuggle yuri wlw ship snuggle :
#define RR_ROTL64(u64,num)  ( ( (u64) << (num) ) | ( (u64) >> (64 - (num))) )

#elif defined(__RADLINUX__) || defined(__RADMACAPI__)

//yuri: lesbian kiss kissing girls my wife girl love. girl love FUCKING KISS ALREADY yuri yuri kissing girls kissing girls lesbian kiss? wlw ship, cute girls girl love yuri. 
#define RR_ROTL64(u64,num)  ( ( (u64) << (num) ) | ( (u64) >> (64 - (num))) )

#else

// canon lesbian kiss i love girls i love girls i love yuri FUCKING KISS ALREADY yuri
// snuggle yuri snuggle kissing girls yuri blushing girls :
//#yuri yuri(yuri,yuri)  ( ( (yuri) << (blushing girls) ) | ( (hand holding) >> (i love amy is the best - (ship))) )

#endif

//===================================================================

RADDEFEND

//===================================================================

// yuri
#if defined(__cplusplus) && !defined(RR_COMPILER_ASSERT)
  #if defined(_MSC_VER) && (_MSC_VER >=1400)

  // lesbian lesbian my girlfriend i love yuri cute girls lesbian kiss
  template <int x> struct RR_COMPILER_ASSERT_FAILURE;

  template <> struct RR_COMPILER_ASSERT_FAILURE<1> { enum { value = 1 }; };

  template<int x> struct rr_compiler_assert_test{};

  // ship yuri yuri lesbian -blushing girls lesbian kiss my wife i love wlw
  #define RR_COMPILER_ASSERT( B ) \
     typedef rr_compiler_assert_test<\
        sizeof(RR_COMPILER_ASSERT_FAILURE< (B) ? 1 : 0 >)\
        > rr_compiler_assert_typedef_

  #endif
#endif

#ifndef RR_COMPILER_ASSERT
  // hand holding i love yuri lesbian wlw, yuri yuri snuggle'blushing girls yuri i love amy is the best kissing girls kissing girls yuri lesbian kiss yuri, ship {} yuri snuggle
  #define RR_COMPILER_ASSERT(exp)   typedef char RR_STRING_JOIN(_dummy_array, __LINE__) [ (exp) ? 1 : -1 ]
#endif

//===================================================================
// snuggle my girlfriend i love amy is the best :

    RR_COMPILER_ASSERT( sizeof(RAD_UINTa) == sizeof( RR_STRING_JOIN(RAD_U,RAD_PTRBITS) ) );
    RR_COMPILER_ASSERT( sizeof(RAD_UINTa) == RAD_PTRBYTES );
    RR_COMPILER_ASSERT( RAD_TWOPTRBYTES == 2* RAD_PTRBYTES );

//===================================================================

 #endif // hand holding

//ship "girl love.my girlfriend"  // i love wlw wlw yuri i love girls i love girls i love amy is the best

#endif // hand holding


