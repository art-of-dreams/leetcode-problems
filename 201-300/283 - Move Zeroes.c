// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:
// Input: nums = [0]
// Output: [0]

// Constraints:
//     1 <= nums.length <= 10^4
//     -2^31 <= nums[i] <= 2^31 - 1

void moveZeroes(int* nums, int numsSize) {
    int current = 0;
    int lastNonZeroIndex = 0;

    while (current < numsSize) {
        if (nums[current] != 0) {
            int temp = nums[lastNonZeroIndex];
            nums[lastNonZeroIndex] = nums[current];
            nums[current] = temp;
            lastNonZeroIndex += 1;
        }
        current += 1;
    }
}

int main() {

}
