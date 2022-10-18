// Given a binary array nums, return the maximum length of a contiguous subarray
// with an equal number of 0 and 1.

// Example 1:
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

// Example 2:
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// Constraints:
//     1 <= nums.length <= 10^5
//     nums[i] is either 0 or 1.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unsigned findMaxLength(vector<int>& nums) {
        unsigned maxLength = 0;

        for (unsigned start = 0; start < nums.size(); start++) {
            unsigned zeros = 0;
            unsigned ones = 0;

            for (unsigned end = start; end < nums.size(); end++) {
                if (nums[end] == 0) {
                    zeros++;
                } else {
                    ones++;
                }

                if (zeros == ones) {
                    unsigned currentLength = end - start + 1;

                    if (maxLength < currentLength) {
                        maxLength = currentLength;
                    }
                }
            }
        }

        return maxLength;
    }

    int findMaxLength2(vector<int>& nums) {
        unordered_map<int, int> map; // (count: max_length)
        map.insert(make_pair(0, -1));

        int maxLength = 0, count = 0;

        for (unsigned i = 0; i < nums.size(); i++) {
            count += (nums[i] == 1) ? 1 : -1;
            auto res = map.find(count);

            if (res == map.end()) {
                map.insert(make_pair(count, i));
            } else {
                int currentLength = (int)i - res->second;
                maxLength = maxLength > currentLength ? maxLength : currentLength;
            }
        }

        return maxLength;
    }

    int findMaxLength3(vector<int>& nums) {
        int size = (int)nums.size();
        int n = 2 * size + 1;
        int arr[n];
        fill_n(arr, n, -2);
        arr[size] = -1;
        int max = 0, count = 0;

        for (int i = 0; i < size; i++) {
            count += (nums[i] == 1) ? 1 : -1;

            if (arr[count + size] >= -1) {
                int curr = i - arr[count + size];
                max = max > curr ? max : curr;
            } else {
                arr[count + size] = i;
            }
        }

        return max;
    }
};

int main () {
    vector<int> v1 = {0,1};
    vector<int> v2 = {0,1,0};

    Solution s;
    cout << s.findMaxLength(v1) << endl;
    cout << s.findMaxLength(v2) << endl;
}
