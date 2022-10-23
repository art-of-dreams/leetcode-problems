// Given a string s and an integer k, reverse the first k characters for
// every 2k characters counting from the start of the string.

// If there are fewer than k characters left, reverse all of them.
// If there are less than 2k but greater than or equal to k characters,
// then reverse the first k characters and leave the other as original.

// Example 1:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"

// Example 2:
// Input: s = "abcd", k = 2
// Output: "bacd"

// Constraints:
//     1 <= s.length <= 10^4
//     s consists of only lowercase English letters.
//     1 <= k <= 10^4

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* reverseStr(char* s, int k) {
    int current = 0;
    int length = strlen(s);

    while (current < length) {
        int start = current;
        int nextLength = current + k;
        int end = (length < nextLength ? length : nextLength) - 1;

        while (start < end) {
            char temp = s[start];
            s[start++] = s[end];
            s[end--] = temp;
        }

        current += 2 * k;
    }

    return s;
}

int main() {
    char s[] = "abcdefg";
    reverseStr(s, 2);
    printf("%s\n", s);
}
