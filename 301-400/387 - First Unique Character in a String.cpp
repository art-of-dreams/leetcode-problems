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
#include <set>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, unsigned> map;
        set<unsigned> set;

        for (unsigned i = 0; i < unsigned(s.size()); i++) {
            if (map.find(s[i]) != map.end()) {
                set.erase(map[s[i]]);
            } else {
                map.insert(make_pair(s[i], i));
                set.insert(i);
            }
        }

        return set.empty() ? -1 : (int)*set.begin();
    }
};

int main() {
    Solution s;
    s.firstUniqChar("loveleetcode");
}