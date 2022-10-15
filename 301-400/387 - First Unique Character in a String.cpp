// Given a string s, find the first non-repeating character in it and return its index.
// If it does not exist, return -1.

// Example 1:
// Input: s = "leetcode"
// Output: 0

// Example 2:
// Input: s = "loveleetcode"
// Output: 2

// Example 3:
// Input: s = "aabb"
// Output: -1

// Constraints:
//     1 <= s.length <= 105
//     s consists of only lowercase English letters.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(0);

        int m[128]= {};

        for (auto x: s) {
            m[x]++;
        }

        for(unsigned i = 0; i < s.size(); i++)
            if(m[s[i]] == 1)
                return int(i);

        return -1;
    }
};

int main() {
    Solution s;
    s.firstUniqChar("loveleetcode");
}