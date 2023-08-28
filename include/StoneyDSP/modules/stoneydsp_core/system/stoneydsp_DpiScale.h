/**
 * @file stoneydsp_DpiScale.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 1.0.0-init
 * @date 2023-08-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _STONEYDSP_DPISCALE_H_
#define _STONEYDSP_DPISCALE_H_

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

namespace StoneyDSP
{
namespace Core
{
namespace System
{

/**
 * @brief The 'DPIScale' class.
 *
 */
class DPIScale
{
public:
    /**
     * @brief
     *
     * @param hwnd Accepts a handle to a window object.
     */
    static void Initialize(HWND hwnd)
    {
        const float oDpi = 96.0F;
        float dpi = static_cast<float>(GetDpiForWindow(hwnd));
        scale = dpi / oDpi;
    }

    /**
     * @brief
     *
     * @tparam T
     * @param x
     * @param y
     * @return D2D1_POINT_2F
     */
    template <typename T>
    static D2D1_POINT_2F PixelsToDips(T x, T y)
    {
        return D2D1::Point2F(static_cast<float>(x) / scale, static_cast<float>(y) / scale);
    }
private:
    /**
     * @brief
     *
     */
    static float scale;
};

/** float DPIScale::scale = 1.0F; */

} /* namespace System */
} /* namespace Core */
} /* namespace StoneyDSP */

#endif /** _STONEYDSP_DPISCALE_H_ */
