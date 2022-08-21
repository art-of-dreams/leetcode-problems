// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include<iostream>
#include<map>
#include<vector>
#include<array>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned currentStartIndex = 0;
        unsigned result = 0;
        unsigned n = unsigned(s.length());
        map<char, unsigned> indicesByChar;

        for (unsigned i = 0; i < n; i++) {
            if (indicesByChar.find(s[i]) != indicesByChar.end()) {
                auto existedIndex = indicesByChar.find(s[i])->second;

                while (currentStartIndex <= existedIndex) {
                    char currentChar = s.at(currentStartIndex);
                    indicesByChar.erase(currentChar);
                    currentStartIndex += 1;
                }

                indicesByChar.insert(pair(s[i], i));
            } else {
                if (indicesByChar.empty()) {
                    currentStartIndex = i;
                }

                indicesByChar.insert(pair(s[i], i));
            }

            if (unsigned(indicesByChar.size()) > result) {
                result = unsigned(indicesByChar.size());
            }
        }

        return int(result);
    }

    int lengthOfLongestSubstring2(const string& s) {
        int best = 0;
        int current = 0;
        array<int, 256> lastOccur{ };
        for (auto c = begin(s); c < end(s); ++c) {
            const int pos = int(distance(begin(s), c) + 1);
            current = min(current + 1, pos - lastOccur[static_cast<uint8_t>(*c)]);
            best = max(best, current);
            lastOccur[unsigned(*c)] = pos;
        }
        return best;
    }
};

int main() {
    Solution s;
    vector<string> inputs = { "abc", "abcabcbb", "bbbbb", "pwwkew", " ", "dvdf" };

    for (unsigned i = 0; i < inputs.size(); i++) {
        cout << inputs[i] << ": " << s.lengthOfLongestSubstring(inputs[i]) << "\n";
    }

    cout << "========\n";

    for (unsigned i = 0; i < inputs.size(); i++) {
        cout << inputs[i] << ": " << s.lengthOfLongestSubstring2(inputs[i]) << "\n";
    }
}
