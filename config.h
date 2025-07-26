/*
 * Configuration
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Default memory device file */
#if defined(__BEOS__) || defined(__HAIKU__)
#define DEFAULT_MEM_DEV "/dev/misc/mem"
#else
#ifdef __sun
#define DEFAULT_MEM_DEV "/dev/xsvc"
#elif defined _WIN32
#define DEFAULT_MEM_DEV "Win32" /* Invalid value */
#else
#define DEFAULT_MEM_DEV "/dev/mem"
#endif
#endif

/* Use mmap or not */
#if !defined(__BEOS__) && !defined(_WIN32)
#define USE_MMAP
#endif

/* Use memory alignment workaround or not */
#if defined(__ia64__) || defined(__arm__)
#define ALIGNMENT_WORKAROUND
#endif

/* Avoid unaligned memcpy on /dev/mem */
#ifdef __aarch64__
#define USE_SLOW_MEMCPY
#endif

#ifdef _MSC_VER
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif

#endif
