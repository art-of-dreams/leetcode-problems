// Given a string s, return the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// Constraints:
//     1 <= s.length <= 1000
//     s consist of only digits and English letters.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int expandAroundCerter(char *s, int length, int left, int right) {
    while (left >= 0 && right < length && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

static char* substring(char *string, int position, int length) {
    char* p = malloc(length + 1);
    int c;

    for (c = 0; c < length; c++) {
        *(p + c) = *(string + position);
        string++;
    }

    *(p + c) = '\0';

    return p;
}

char* longestPalindrome(char *s) {
    if (s == NULL) {
        return "";
    }

    int length = strlen(s);

    if (length == 0) {
        return "";
    }

    int start = 0, end = 0;

    for (int i = 0; i < length; i++) {
        int len1 = expandAroundCerter(s, length, i, i);
        int len2 = expandAroundCerter(s, length, i, i + 1);
        int len = len1 > len2 ? len1 : len2;

        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return substring(s, start, end - start + 1);
}

int main() {
    printf("%s\n", longestPalindrome("cbbd"));
}
