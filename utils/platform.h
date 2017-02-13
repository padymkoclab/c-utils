
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

/**
 * Determination platform of an operation system
 * A full supported only the GNU GCC/G++, partial - the Clang/LLVM
 * Based on http://nadeausoftware.com/articles/2012/01/c_c_tip_how_use_compiler_predefined_macros_detect_operating_system
 */
#if defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(_WIN64)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #endif
#elif defined(__hpux)
    #define PLATFORM_NAME "hp-ux" // HP-UX
#elif defined(_AIX)
    #define PLATFORM_NAME "aix" // IBM AIX
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_NAME "osx" // Apple OSX
    #endif
#elif defined(__sun) && defined(__SVR4)
    #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#else
    #define PLATFORM_NAME NULL
#endif

/*
    Determination POSIX version, if is OS is UNIX-style, including BSD, Linux, OSX, and Solaris
 */
#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
    #include <unistd.h>
    #define IS_POSIX_SYSTEM 1
#else
    #define IS_POSIX_SYSTEM 0
#endif


// Returns a name of platform
char *
get_platform_name() {
    return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
}


// Returns a POSIX version of a system, if the system support it, otherwise return 0
long int
get_posix_version() {
    return (IS_POSIX_SYSTEM == 1) ? _POSIX_VERSION : 0;
}


enum platform_bit_t { _unknownArch, _64bitArch, _32bitArch};

enum platform_bit_t
get_architecture(){
    size_t int_size = sizeof(int*);
    if (int_size == 8) return _64bitArch;
    else if (int_size == 4) return _32bitArch;
    else return _unknownArch;
}


#endif // __PLATFORM_H__
