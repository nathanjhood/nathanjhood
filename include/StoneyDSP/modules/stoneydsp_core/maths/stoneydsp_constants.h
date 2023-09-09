/**
 * @file stoneydsp_constants.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#define __STONEYDSP_CORE_MATHS_CONSTANTS_H__

namespace StoneyDSP
{
namespace Core
{
namespace Maths
{
template <typename T>
struct Constants
{
    /** A predefined value for Zero. */
    static constexpr T zero = static_cast<T> (0.0L);

    /** A predefined value for One. */
    static constexpr T one = static_cast<T> (1.0L);

    /** A predefined value for Two. */
    static constexpr T two = static_cast<T> (2.0L);

    /** A predefined value for minus One. */
    static constexpr T minusOne = static_cast<T> (-1.0L);

    /** A predefined value for minus Two. */
    static constexpr T minusTwo = static_cast<T> (-2.0L);

    /** A predefined value for one third of one. */
    static constexpr T oneThird = static_cast<T> (1.0L / 3.0L);

    /** A predefined value for two thirds of one. */
    static constexpr T twoThirds = static_cast<T> (2.0L / 3.0L);

    /** A predefined value for pi. */
    static constexpr T pi = static_cast<T> (3.14159265358979323846L);

    /** A predefined value for 2pi. */
    static constexpr T twoPi = static_cast<T> (2.0L * 3.14159265358979323846L);

    /** A predefined value for pi/2. */
    static constexpr T piDivTwo = static_cast<T> (1.57079632679489661923L);

    /** A predefined value for Euler's number (e). */
    static constexpr T euler = static_cast<T> (2.71828182845904523536L);

    /** A predefined value for tau. */
    static constexpr T tau = static_cast<T> (1.0L - (1.0L / 2.71828182845904523536L));

    /** A predefined value for sqrt(2). */
    static constexpr T sqrtTwo = static_cast<T> (1.41421356237309504880L);

    /** A predefined value for 1/sqrt(2). */
    static constexpr T OneDivSqrtTwo = static_cast<T> (0.707106781186547524401L);

    /** A predefined value for 2/sqrt(pi). */
    static constexpr T twoDivSqrtPi = static_cast<T> (1.12837916709551257390L);

    /** A predefined value for 1/pi. */
    static constexpr T oneDivPi = static_cast<T> (0.318309886183790671538L);

    /** A predefined value for 2/pi. */
    static constexpr T twoDivPi = static_cast<T> (0.636619772367581343076L);

    /** A predefined value for log2(e). */
    static constexpr T logTwoE = static_cast<T> (1.44269504088896340736L);

    /** A predefined value for log10(e). */
    static constexpr T logTenE = static_cast<T> (0.434294481903251827651L);

    /** A predefined value for ln(2). */
    static constexpr T linTwo = static_cast<T> (0.693147180559945309417L);

    /** A predefined value for ln(10). */
    static constexpr T linTen = static_cast<T> (2.30258509299404568402L);
};

} // namespace Maths
} // namespace Core
} // namespace StoneyDSP
