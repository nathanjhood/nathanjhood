/***************************************************************************//**
 * @file stoneydsp_compiler_support.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief Contains preprocessor definitions that attempt to detect compiler
 * information.
 *
 * @version 0.1
 * @date 2023-09-09
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/
#pragma once

#define __STONEYDSP_CORE_SYSTEM_COMPILER_SUPPORT_H__

#if defined (__clang__)
#elif defined (__GNUC__)
#elif defined (_MSC_VER)
#else
 #error "Compiler unknown?"
#endif

#if defined(__clang__) && !defined(__ibxml__)

 #define __C_COMPILER_IS_CLANG 1

 #define __C_COMPILER_NAME STRINGIFY(Clang)
 #define __C_COMPILER_VERSION_MAJOR __clang_major__
 #define __C_COMPILER_VERSION_MINOR __clang_minor__
 #define __C_COMPILER_VERSION_PATCH __clang_patchlevel__

 #define __C_COMPILER_VERSION (__clang_major__ * 100 + __clang_minor__)

#elif defined(__GNUC__) && !defined(__clang__) && !defined(__INTEL_COMPILER) && !defined(__NVCOMPILER)

 #define __C_COMPILER_IS_GNU 1

 #define __C_COMPILER_NAME STRINGIFY(GNU)
 #define __C_COMPILER_VERSION_MAJOR __GNUC__
 #define __C_COMPILER_VERSION_MINOR __GNUC_MINOR__
 #define __C_COMPILER_VERSION_PATCH __GNUC_PATCHLEVEL__
 #define __C_COMPILER_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)

#endif

#define __CXX_COMPILER_NAME __C_COMPILER_NAME
#define __CXX_COMPILER_VERSION_MAJOR __C_COMPILER_VERSION_MAJOR
#define __CXX_COMPILER_VERSION_MINOR __C_COMPILER_VERSION_MINOR
#define __CXX_COMPILER_VERSION_PATCH __C_COMPILER_VERSION_PATCH
#define __CXX_COMPILER_VERSION __C_COMPILER_VERSION

#ifdef __ICL
 #define __ICC_VERSION __ICL
#elif defined(__INTEL_COMPILER)
 #define __ICC_VERSION __INTEL_COMPILER
#else
 #define __ICC_VERSION 0
#endif

#ifdef _MSC_VER
 #define __MSC_VERSION _MSC_VER
 #define __MSC_WARNING(...) __pragma(warning(__VA_ARGS__))
#else
 #define __MSC_VERSION 0
 #define __MSC_WARNING(...)
#endif

#if defined(__cplusplus)
 #define __USING_CXX __cplusplus
#elif defined(_MSVC_LANG)
 #define __USING_CXX _MSVC_LANG
#else
 #undef  __USING_CXX
#endif

#ifdef  __USING_CXX
 #define __BEGIN_DECLS  extern "C" {
 #define __END_DECLS    }
#else
 #define __BEGIN_DECLS
 #define __END_DECLS
#endif

#ifdef __has_feature
 #define __HAS_FEATURE(x) __has_feature(x)
#else
 #define __HAS_FEATURE(x) FALSE
#endif

#if defined(__has_include) || __ICC_VERSION >= 1600 || __MSC_VERSION >= 1900
 #define __HAS_INCLUDE(x) __has_include(x)
#else
 #define __HAS_INCLUDE(x) FALSE
#endif

#ifdef __has_attribute
 #define __HAS_ATTRIBUTE(x) __has_attribute(x)
#else
 #define __HAS_ATTRIBUTE(x) FALSE
#endif

#ifdef __has_c_attribute
 #define __HAS_C_ATTRIBUTE(x) __has_c_attribute(x)
#else
 #define __HAS_C_ATTRIBUTE(x) FALSE
#endif

#ifdef __has_cpp_attribute
 #define __HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#else
 #define __HAS_CPP_ATTRIBUTE(x) FALSE
#endif

#ifdef __has_builtin
 #define __HAS_BUILTIN(x) __has_builtin(x)
#else
 #define __HAS_BUILTIN(x) FALSE
#endif

#ifdef __has_extension
 #define __HAS_EXTENSION(x) __has_extension(x)
#else
  #define __HAS_EXTENSION(x) FALSE
#endif
