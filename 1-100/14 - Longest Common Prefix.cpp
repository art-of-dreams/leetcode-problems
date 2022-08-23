// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".
 

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unsigned size = unsigned(strs.size());

        if (size == 0) {
        	return "";
        }

        unsigned substringEnd = unsigned(strs[0].size());

        for (unsigned i = 1; i < size; i++) {
        	unsigned sameCount = 0;

        	for (unsigned j = 0; j < unsigned(strs[i].size()); j++) {
        		if (strs[0][j] == strs[i][j]) {
        			sameCount += 1;
        		} else {
        			break;
        		}
        	}

        	substringEnd = min(sameCount, substringEnd);

        	if (substringEnd == 0) {
        		return "";
        	}
        }

        return strs[0].substr(0, substringEnd);
    }
};

int main() {
    Solution s;

    vector<string> v1 = {"flower","flow","flight"};
    string res1 = s.longestCommonPrefix(v1);
    cout << "flower, flow, flight -> " << res1 << endl;

    vector<string> v2 = {"dog","racecar","car"};
    string res2 = s.longestCommonPrefix(v2);
    cout << "dog, racecar, car -> " << res2 << endl;
}
