// Given a string columnTitle that represents the column title as appears in an Excel sheet,
// return its corresponding column number.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...

// Example 1:
// Input: columnTitle = "A"
// Output: 1

// Example 2:
// Input: columnTitle = "AB"
// Output: 28

// Example 3:
// Input: columnTitle = "ZY"
// Output: 701

// Constraints:
//     1 <= columnTitle.length <= 7
//     columnTitle consists only of uppercase English letters.
//     columnTitle is in the range ["A", "FXSHRXW"].

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int titleToNumber(char* columnTitle) {
    int res = 0;
    int n = strlen(columnTitle);

    for (int i = 0; columnTitle[i] != '\0'; i++) {
        res *= 26;
        res += columnTitle[i] - 'A' + 1;
    }

    return res;
}

int main() {
    printf("%d\n", titleToNumber("A"));
    printf("%d\n", titleToNumber("AB"));
    printf("%d\n", titleToNumber("ZY"));
}
