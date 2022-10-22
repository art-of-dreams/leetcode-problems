// Given an array nums containing n distinct numbers in the range [0, n],
// return the only number in the range that is missing from the array.

// Example 1:
// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
// 2 is the missing number in the range since it does not appear in nums.

// Example 2:
// Input: nums = [0,1]
// Output: 2
// Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2].
// 2 is the missing number in the range since it does not appear in nums.

// Example 3:
// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9].
// 8 is the missing number in the range since it does not appear in nums.
 

// Constraints:
//     n == nums.length
//     1 <= n <= 104
//     0 <= nums[i] <= n
//     All the numbers of nums are unique.

// Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

#include <stdlib.h>
#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int countsSize = numsSize + 1;
    int* counts = calloc(countsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]] = 1;
    }

    for (int i = 0; i < countsSize; i++) {
        if (counts[i] == 0) {
            free(counts);
            return i;
        }
    }

    free(counts);
    return -1;
}

// Using XOR
int missingNumber2(int* nums, int numsSize) {
    int result = numsSize;

    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i] ^ i;
    }

    return result;
}

// Gauss' Formula
int missingNumber3(int* nums, int numsSize) {
    int totalSum = numsSize * (numsSize + 1) / 2;
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return totalSum - sum;
}

int main() {
    int arr1[] = {3,0,1};
    printf("%d\n", missingNumber3(arr1, sizeof(arr1) / sizeof(arr1[0])));

    int arr2[] = {0,1};
    printf("%d\n", missingNumber3(arr2, sizeof(arr2) / sizeof(arr2[0])));

    int arr3[] = {9,6,4,2,3,5,7,0,1};
    printf("%d\n", missingNumber3(arr3, sizeof(arr3) / sizeof(arr3[0])));
}