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
    int num = 0;
    //Substract '0' from entered char to get
    //corresponding digit
    num = c - '0';
    return num;
}


char* addStrings(char* num1, char* num2) {
    int len = strlen(num1);
    int len2 = strlen(num2);

    if (len < len2) {
        return addStrings(num2, num1);
    }

    int i = 0;
    int carry = 0;
    char *str = malloc(len + 2);

    while (i < len2) {
        int sum = num1[i] + num2[i] + (char)carry;
        char c;

        if (sum > 9) {
            c = sum - 10;
            carry = 1;
        } else {
            c = sum;
            carry = 0;
        }

        str[i] = c;

        i++;
    }

    while (i < len) {
        int sum = num1[i] + (char)carry;

        char c;

        if (sum > 9) {
            c = sum - 10;
            carry = 1;
        } else {
            c = sum;
            carry = 0;
        }

        str[i] = c;

        i++;
    }

    if (carry) {
        str[i] = (char)carry;
    }

    return str;
}

int main(int argc, char const *argv[]) {
    printf("%s\n", addStrings("56", "75"));
}
