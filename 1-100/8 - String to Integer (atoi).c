// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

// The algorithm for myAtoi(string s) is as follows:
//     - Read in and ignore any leading whitespace.
//     - Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either.
//     This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
//     - Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
//     - Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0.
//     Change the sign as necessary (from step 2).
//     - If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range.
//     Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
//     - Return the integer as the final result.

// Note:
//     Only the space character ' ' is considered a whitespace character.
//     Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

// Example 1:
// Input: s = "42"
// Output: 42
// Explanation: The underlined characters are what is read in, the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "42" ("42" is read in)
//            ^
// The parsed integer is 42.
// Since 42 is in the range [-231, 231 - 1], the final result is 42.

// Example 2:
// Input: s = "   -42"
// Output: -42
// Explanation:
// Step 1: "   -42" (leading whitespace is read and ignored)
//             ^
// Step 2: "   -42" ('-' is read, so the result should be negative)
//              ^
// Step 3: "   -42" ("42" is read in)
//                ^
// The parsed integer is -42.
// Since -42 is in the range [-231, 231 - 1], the final result is -42.

// Example 3:
// Input: s = "4193 with words"
// Output: 4193
// Explanation:
// Step 1: "4193 with words" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
//              ^
// The parsed integer is 4193.
// Since 4193 is in the range [-231, 231 - 1], the final result is 4193.

// Constraints:
//     0 <= s.length <= 200
//     s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char* s) {
    int sign = 1;
    int result = 0;
    int i = 0;
    int size = strlen(s);

    // Discard all spaces from the beginning of the input string.
    while (i < size && s[i] == ' ') {
        i++;
    }

    // sign = +1, if it's positive number, otherwise sign = -1.
    if (i < size && s[i] == '+') {
        i++;
    } else if (i < size && s[i] == '-') {
        sign = - 1;
        i++;
    }

    // Traverse next digits of input and stop if it is not a digit. 
    // End of string is also non-digit character.
    while (i < size && isdigit(s[i])) {
        int digit = s[i] - '0';

        // Check overflow and underflow conditions.
        if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // Append current digit to the result.
        result = 10 * result + digit;
        i++;
    }

    // We have formed a valid number without any overflow/underflow.
    // Return it after multiplying it with its sign.
    return sign * result;
}

int main() {

}