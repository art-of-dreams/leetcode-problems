// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

// Constraints:
//     3 <= nums.length <= 3000
//     -10^5 <= nums[i] <= 10^5

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
    void twoSum(vector<int>& nums, unsigned index, vector<vector<int>>& result) {
        unsigned low = index + 1;
        unsigned high = nums.size() - 1;

        while (low < high) {
            int sum = nums[low] + nums[high] + nums[index];

            if (sum > 0) {
                high--;
            } else if (sum < 0) {
                low++;
            } else {
                result.push_back({nums[index], nums[low++], nums[high--]});

                // Increment lo while the next value is the same as before to avoid duplicates in the result.
                while (low < high && nums[low] == nums[low - 1]) {
                    low++;
                }
            }
        }
    }

    void twoSum2(vector<int>& nums, unsigned index, vector<vector<int>>& result) {
        unordered_set<int> seen;

        for (unsigned i = index + 1; i < nums.size(); i++) {
            int complement = -nums[index] - nums[i];

            if (seen.count(complement)) {
                result.push_back({nums[index], complement, nums[i]});

                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                    i++;
                }
            }

            seen.insert(nums[i]);
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;

        for (unsigned i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                twoSum(nums, i, result);
            }
        }

        return result;
    }
};

int main() {

}
