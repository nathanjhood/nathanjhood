/***************************************************************************//**
 * @file stoneydsp_core.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-09
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/
#pragma once

#define __STONEYDSP_CORE_H__

#include "version/stoneydsp_version.h"
#include "res/stoneydsp_resource.h"
#include "types/stoneydsp_types.h"

#include "system/stoneydsp_target_platform.h"
#include "native/stoneydsp_native_headers.h"

#ifdef __PLATFORM_IS_WINDOWS
 #undef small
#endif

#include "system/stoneydsp_standard_header.h"
#include "native/stoneydsp_unicode.h"

#include "types/stoneydsp_value.h"
#include "memory/stoneydsp_unique_ptr.h"

#include "maths/stoneydsp_constants.h"
