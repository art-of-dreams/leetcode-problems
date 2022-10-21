// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:
//     1 <= s.length, t.length <= 5 * 104
//     s and t consist of lowercase English letters.

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int lenght = strlen(s);

    if (lenght != strlen(t)) {
        return false;
    }

    int array[26] = {0};

    for (int i = 0; i < lenght; i++) {
        array[s[i] - 97]++;
        array[t[i] - 97]--;
    }

    for (int i = 0; i < 26; i++) {
        if (array[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    printf("%d\n", isAnagram("anagram", "nagaram"));
    printf("%d\n", isAnagram("rat", "car"));
}
