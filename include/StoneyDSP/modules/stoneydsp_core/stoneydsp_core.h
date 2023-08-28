/***************************************************************************//**
 * @file stoneydsp_core.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 1.0.0-init
 * @date 2023-08-28
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/

#pragma once

#define _STONEYDSP_CORE_H_

#ifndef WINVER
#  define WINVER 0x0A00
#endif

#ifndef _WIN32_WINNT
#  define _WIN32_WINNT 0x0A00
#endif

#ifdef D2D_USE_C_DEFINITIONS
#  undef D2D_USE_C_DEFINITIONS
#endif

#include <windows.h>
#include <d2d1.h>
#pragma comment(lib, "d2d1")

#include <iostream>
#include <string>

#include
