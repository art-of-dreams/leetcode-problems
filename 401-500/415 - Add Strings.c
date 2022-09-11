// Given two non-negative integers, num1 and num2 represented as string,
// return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling
// large integers (such as BigInteger). You must also not convert the inputs to integers directly.

// Example 1:
// Input: num1 = "11", num2 = "123"
// Output: "134"

// Example 2:
// Input: num1 = "456", num2 = "77"
// Output: "533"

// Example 3:
// Input: num1 = "0", num2 = "0"
// Output: "0"

// Constraints:
//     1 <= num1.length, num2.length <= 10^4
//     num1 and num2 consist of only digits.
//     num1 and num2 don't have any leading zeros except for the zero itself.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int char_to_int(char c) {
    int num = c - '0';
    return num;
}

static char int_to_char(int i) {
    char c = i + '0';
    return c;
}

static char* reversed_string(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        char c = str[end];
        str[end] = str[start];
        str[start] = c;
        start++;
        end--;
    }

    return str;
}

char* addStrings(char* num1, char* num2) {
    int len = strlen(num1);
    int len2 = strlen(num2);

    if (len < len2) {
        return addStrings(num2, num1);
    }

    int i = len - 1;
    int j = len2 - 1;
    int str_index = 0;

    int carry = 0;
    char *str = malloc(len + 2);

    while (i >= 0) {
        int sum = char_to_int(num1[i]) + carry + (j >= 0 ? char_to_int(num2[j]) : 0);
        char c;

        if (sum > 9) {
            c = int_to_char(sum - 10);
            carry = 1;
        } else {
            c = int_to_char(sum);
            carry = 0;
        }

        str[str_index] = c;

        i--;
        j--;
        str_index++;
    }

    if (carry) {
        char c = int_to_char(carry);
        str[str_index] = c;
        str_index++;
    }

    str[str_index] = '\0';

    return reversed_string(str);
}

int main(int argc, char const *argv[]) {
    printf("%s\n", addStrings("19", "123"));
}
