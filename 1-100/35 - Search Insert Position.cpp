// Given a sorted array of distinct integers and a target value,
// return the index if the target is found. If not, return the
// index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = int(nums.size()) - 1;

        while (start <= end) {
        	int mid = start + (end - start) / 2;

        	if (nums[unsigned(mid)] == target) {
        		return mid;
        	} else if (nums[unsigned(mid)] > target) {
        		end = mid - 1;
        	} else {
        		start = mid + 1;
        	}
        }

        return start;
    }
};

int main() {
	vector<int> v1 = {1, 3, 5, 6};
	Solution s;
	cout << "target 5: " << s.searchInsert(v1, 5) << endl;
	cout << "target 2: " << s.searchInsert(v1, 2) << endl;
	cout << "target 7: " << s.searchInsert(v1, 7) << endl;
	cout << "target 0: " << s.searchInsert(v1, 0) << endl;
}
