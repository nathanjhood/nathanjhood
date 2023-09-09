/***************************************************************************//**
 * @file stoneydsp_version.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief Versions with the same major number are ABI stable. API is allowed to
 * evolve between minor releases, but only in a backwards compatible way.
 * Make sure you update the -soname directives in configure.ac
 * whenever you bump STONEYDSP_VERSION_MAJOR or STONEYDSP_VERSION_MINOR (but
 * not STONEYDSP_VERSION_PATCH.)
 * @version 0.1
 * @date 2023-09-09
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/
#pragma once

#define __STONEYDSP_CORE_VERSION_H__

#define STONEYDSP_VERSION_MAJOR 1
#define STONEYDSP_VERSION_MINOR 0
#define STONEYDSP_VERSION_PATCH 0
#define STONEYDSP_VERSION_TWEAK init
#define STONEYDSP_VERSION_IS_RELEASE 1
#define STONEYDSP_VERSION_SUFFIX ""

#define STONEYDSP_VERSION_HEX \
    ((STONEYDSP_VERSION_MAJOR << 16) | \
     (STONEYDSP_VERSION_MINOR <<  8) | \
     (STONEYDSP_VERSION_PATCH))

/**
 * @brief major * 10000 + minor * 100 + patch.
 *
 */
#define STONEYDSP_VERSION ((STONEYDSP_VERSION_MAJOR * 10000) + (STONEYDSP_VERSION_MINOR * 100) + STONEYDSP_VERSION_PATCH)

/**
 * @brief "major.minor.patch-tweak"
 *
 */
#define STONEYDSP_VERSION_STRING \
    STRINGIFY(STONEYDSP_VERSION_MAJOR) STRINGIFY(.) \
    STRINGIFY(STONEYDSP_VERSION_MINOR) STRINGIFY(.) \
    STRINGIFY(STONEYDSP_VERSION_PATCH) STRINGIFY(-) \
    STRINGIFY(STONEYDSP_VERSION_TWEAK)
