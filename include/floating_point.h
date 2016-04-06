#ifndef INCLUDE_FLOATING_POINT_H
#define INCLUDE_FLOATING_POINT_H
#include <cstdint>

namespace kairos {
namespace detail {

/**
*   Define Macros to call the pack and unpack of floating point numbers
*/
#define to_uint32(f) (kairos::detail::pack754((f), 32, 8))
#define to_uint64(f) (kairos::detail::pack754((f), 64, 11))
#define from_uint32(i) (kairos::detail::unpack754((i), 32, 8))
#define from_uint64(i) (kairos::detail::unpack754((i), 64, 11))

/**
*   Pack a long double into a uint64_t
*/
uint64_t pack754(long double f, unsigned bits, unsigned expbits) {
    long double fnorm;
    int shift;
    long long sign, exp, significand;
    /** -1 for sign bit */
    unsigned significandbits = bits - expbits - 1;

    if (f == 0.0)
        return 0;

    /** check sign and begin normalization */
    if (f < 0) {
        sign = 1;
        fnorm = -f;
    }
    else {
        sign = 0;
        fnorm = f;
    }

    /** get the normalized form of f and track the exponent */
    shift = 0;

    while(fnorm >= 2.0) {
        fnorm /= 2.0;
        shift++;
    }

    while(fnorm < 1.0) {
        fnorm *= 2.0;
        shift--;
    }

    fnorm = fnorm - 1.0;

    /** calculate the binary form (non-float) of the significand data */
    significand = fnorm * ((1LL << significandbits) + 0.5f);

    /** get the biased exponent */
    exp = shift + ((1 << (expbits-1)) - 1);

    return (sign << (bits-1)) | (exp << (bits-expbits-1)) | significand;
}

/**
*   Unpack a uint64_t into a long double
*/
long double unpack754(uint64_t i, unsigned bits, unsigned expbits) {
    long double result;
    long long shift;
    unsigned bias;
    /** -1 for sign bit */
    unsigned significandbits = bits - expbits - 1;

    if (i == 0)
        return 0.0;

    /** pull the significand */
    result = (i & ((1LL << significandbits)-1));

    /** convert back to float */
    result /= (1LL << significandbits);

    /** add the one back on */
    result += 1.0f;

    /** deal with the exponent */
    bias = (1 << (expbits-1)) - 1;
    shift = ((i >> significandbits) & ((1LL << expbits)-1)) - bias;

    while(shift > 0) {
        result *= 2.0;
        shift--;
    }

    while(shift < 0) {
        result /= 2.0;
        shift++;
    }

    /** sign it */
    result *= (i >> (bits-1))&1 ? -1.0 : 1.0;

    return result;
}

}
}

#endif //KAIROS_FLOATING_POINT_H
