// Given an integer array nums, return true if any value appears at least
// twice in the array, and return false if every element is distinct.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: true

// Example 2:
// Input: nums = [1,2,3,4]
// Output: false

// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

// Constraints:
//     1 <= nums.length <= 10^5
//     -10^9 <= nums[i] <= 10^9

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (unsigned i = 0; i < (unsigned)nums.size(); i++) {
            if (set.find(nums[i]) != set.end()) {
                return true;
            }
            set.insert(nums[i]);
        }

        return false;
    }
};

int main() {
    vector<int> v1 = {1,2,3,1};
    vector<int> v2 = {1,2,3,4};
    vector<int> v3 = {1,1,1,3,3,4,3,2,4,2};

    Solution s;
    cout << s.containsDuplicate(v1) << endl;
    cout << s.containsDuplicate(v2) << endl;
    cout << s.containsDuplicate(v3) << endl;
}
