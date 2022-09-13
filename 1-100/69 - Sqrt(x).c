// Given a non-negative integer x, compute and return the square root of x.

// Since the return type is an integer, the decimal digits are truncated,
// and only the integer part of the result is returned.

// Note: You are not allowed to use any built-in exponent function or operator,
// such as pow(x, 0.5) or x ** 0.5.

// Example 1:
// Input: x = 4
// Output: 2

// Example 2:
// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

// Constraints:
// 0 <= x <= 2^31 - 1

#include "stdio.h"
#include "math.h"

int mySqrt(int x) {
    if (x < 4) {
        return x <= 0 ? 0 : 1;
    }

    int start = 0;
    int end = x / 2;
    int sqr = 0;

    while (start <= end) {
        long mid = start + (end - start) / 2;
        long res = mid * mid;

        if (res == x) {
            return mid;
        } else if (res < x) {
            sqr = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return sqr;
}

int mySqrt2(int x) {
    if (x < 2)
        return x;

    double x0 = x;
    double x1 = (x0 + x / x0) / 2.0;

    while (fabs(x0 - x1) >= 1) {
        x0 = x1;
        x1 = (x0 + x / x0) / 2.0;
    }

    return (int)x1;
}

int main() {
    printf("%d\n", mySqrt2(4));
    printf("%d\n", mySqrt2(8));
    printf("%d\n", mySqrt2(10));
}
