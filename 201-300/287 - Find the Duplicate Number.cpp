// Given an array of integers nums containing n + 1 integers where
// each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2

// Example 2:
// Input: nums = [3,1,3,4,2]
// Output: 3

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int duplicate = -1;

		for (unsigned i = 0; i < nums.size(); i++) {
			unsigned abs_val = (unsigned)abs(nums[i]);

			if (nums[abs_val] < 0) {
				duplicate = (int)abs_val;
				break;
			}

			nums[abs_val] *= -1;
		}

		for (unsigned i = 0; i < unsigned(nums.size()); i++) {
			nums[i] = abs(nums[i]);
		}

		return duplicate;
	}

	int findDuplicate2(vector<int>& nums) {
		unsigned tortoise = (unsigned)nums[0];
		unsigned hare = (unsigned)nums[0];

		do {
			tortoise = (unsigned)nums[tortoise];
			hare = (unsigned)nums[(unsigned)nums[hare]];
		} while (tortoise != hare);

		tortoise = (unsigned)nums[0];

		while (tortoise != hare) {
			tortoise = (unsigned)nums[tortoise];
			hare = (unsigned)nums[hare];
		}

		return int(hare);
	}
};

int main() {
	Solution s;
	vector<int> v1 {1, 3, 4, 2, 2};
	vector<int> v2 {3, 1, 3, 4, 2};
	vector<int> v3 {1, 4, 4, 2, 4};
	cout << s.findDuplicate2(v1) << endl;
	cout << s.findDuplicate2(v2) << endl;
	cout << s.findDuplicate2(v3) << endl;
}