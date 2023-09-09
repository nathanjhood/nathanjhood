/***************************************************************************//**
 * @file stoneydsp_unicode.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 *
 * @version 0.1
 * @date 2023-09-09
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/
#pragma once

#define __STONEYDSP_CORE_NATIVE_UNICODE_H__

// _NEED_UNICODE defined based on UNICODE flag
#if !defined(_NEED_UNICODE)


 #if defined(UNICODE)
  #define _NEED_UNICODE 1
  #define __NAME_AW(func) func##W
  #define __NAME_AW_EXT(func,ext) func##W##ext
  #define __NAME_UAW(func) func##_W
  #define __NAME_UAW_EXT(func,ext) func##_W_##ext
  #define __STRING_AW(str) L##str	// same as TEXT() from winnt.h
  #define __PROCNAMEEXT_AW "W"
 #else
  #define _NEED_UNICODE 2
  #define __NAME_AW(func) func##A
  #define __NAME_AW_EXT(func,ext) func##A##ext
  #define __NAME_UAW(func) func##_A
  #define __NAME_UAW_EXT(func,ext) func##_A_##ext
  #define __STRING_AW(str) str	// same as TEXT() from winnt.h
  #define __PROCNAMEEXT_AW "A"
 #endif

 #define __TYPEDEF_AW(type)	typedef __NAME_AW(type) type;
 #define __TYPEDEF_UAW(type) typedef __NAME_UAW(type) type;

#endif // !defined(_NEED_UNICODE)
