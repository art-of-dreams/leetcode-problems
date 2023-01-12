// Given an integer array nums, find the subarray
// with the largest sum, and return its sum.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:
// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

// Constraints:
//     1 <= nums.length <= 10^5
//     -10^4 <= nums[i] <= 10^4

// Follow up: If you have figured out the O(n) solution, try coding another solution
// using the divide and conquer approach, which is more subtle.

#include <stdlib.h>
#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
    if (numsSize < 1) {
        return 0;
    }

    int current = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
        int new = current + nums[i];
        current = nums[i] > new ? nums[i] : new;
        result = result > current ? result : current;
    }

    return result;
}

static int findBestSubarray(int left, int right, int* nums, int numsSize) {
    if (left > right) {
        return INT_MIN;
    }

    int mid = left + ((right - left) / 2);
    int curr = 0;
    int bestLeft = 0;
    int bestRight = 0;

    // Iterate from the middle to the beginning.
    for (int i = mid - 1; i >= left; i--) {
        curr += nums[i];
        bestLeft = curr > bestLeft ? curr : bestLeft;
    }

    // Reset curr and iterate from the middle to the end.
    curr = 0;

    for (int i = mid + 1; i <= right; i++) {
        curr += nums[i];
        bestRight = curr > bestRight ? curr : bestRight;
    }

    // The bestCombined uses the middle element and the best
    // possible sum from each half.
    int bestCombined = bestLeft + bestRight + nums[mid];

    // Find the best subarray possible from both halves.
    int recursiveLeft = findBestSubarray(left, mid - 1, nums, numsSize);
    int recursiveRight = findBestSubarray(mid + 1, right, nums, numsSize);

    // The largest of the 3 is the answer for any given input array.
    int bestSide = recursiveRight > recursiveLeft ? recursiveRight : recursiveLeft;
    return bestSide > bestCombined ? bestSide : bestCombined;
}

int maxSubArray2(int* nums, int numsSize) {
    return findBestSubarray(0, numsSize - 1, nums, numsSize);
}

int main() {

}
