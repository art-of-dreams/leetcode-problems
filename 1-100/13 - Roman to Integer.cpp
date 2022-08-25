// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// For example, 2 is written as II in Roman numeral, just two ones added together.
// 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right.
// However, the numeral for four is not IIII. Instead, the number four is written as IV.
// Because the one is before the five we subtract it making four. The same principle applies
// to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.

// Given a roman numeral, convert it to an integer.

// Example 1:
// Input: s = "III"
// Output: 3
// Explanation: III = 3.

// Example 2:
// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.

// Example 3:
// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

#include<iostream>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int size = int(s.length());
        int result = getNumber(s[unsigned(size - 1)]);
        int index = size - 2;

        while (index >= 0) {
            int current = getNumber(s[unsigned(index)]);

            if (current >= getNumber(s[unsigned(index) + 1])) {
                result += current;
            } else {
                result -= current;
            }

            index -= 1;
        }

        return result;
    }

private:
    int getNumber(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << "III = " << s.romanToInt("III") << endl;
    cout << "LVIII = " << s.romanToInt("LVIII") << endl;
    cout << "MCMXCIV = " << s.romanToInt("MCMXCIV") << endl;
    cout << "DCXXI = " << s.romanToInt("DCXXI") << endl;
    cout << "MCMXCIV = " << s.romanToInt("MCMXCIV") << endl;

}
