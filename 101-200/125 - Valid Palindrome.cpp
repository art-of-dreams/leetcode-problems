// A phrase is a palindrome if, after converting all uppercase letters into
// lowercase letters and removing all non-alphanumeric characters, it reads
// the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome1(string s) {
        unsigned length = unsigned(s.length());

        if (length < 2) {
            return true;
        }

    	vector<int> filtered;

        for (unsigned i = 0; i < length; i++) {
            if (isalpha(s[i])) {
                filtered.push_back(tolower(s[i]));
            } else if (isdigit(s[i])) {
                filtered.push_back(s[i]);
            }
        }

        unsigned filteredLength = unsigned(filtered.size());

        if (filteredLength < 2) {
            return true;
        }

        vector<int> reversed(filteredLength, 0);

        for (unsigned i = 0; i < filteredLength; i++) {
            reversed[i] = filtered[filteredLength - i - 1];
        }

        return filtered == reversed;
    }

    bool isPalindrome2(string s) {
        for (int i = 0, j = int(s.size()) - 1; i < j; i++, j--) {
            while (i < j && !isalnum(s[unsigned(i)])) {
                i++;
            }
            while (i < j && !isalnum(s[unsigned(j)])) {
                j--;
            }
            if (tolower(s[unsigned(i)]) != tolower(s[unsigned(j)])) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << "A man, a plan, a canal: Panama -> " << s.isPalindrome2("A man, a plan, a canal: Panama") << endl;
    cout << "race a car -> " << s.isPalindrome2("race a car") << endl;
    cout << " -> " << s.isPalindrome2(" ") << endl;
    cout << "a. -> " << s.isPalindrome2("a.") << endl;
}
