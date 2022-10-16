// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
// To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

// Example 2:
// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].

// Example 3:
// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

// Constraints:
//     nums1.length == m + n
//     nums2.length == n
//     0 <= m, n <= 200
//     1 <= m + n <= 200
//     -10^9 <= nums1[i], nums2[j] <= 10^9

// Follow up: Can you come up with an algorithm that runs in O(m + n) time?

#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = 0, j = 0;
    
    int arr[200] = {};
    
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            arr[i + j] = nums1[i];
            i++;
        } else {
            arr[i + j] = nums2[j];
            j++;
        }
    }
    
    while (i < m) {
        arr[i + j] = nums1[i];
        i++;
    }
    
    while (j < n) {
        arr[i + j] = nums2[j];
        j++;
    }
    
    memcpy(nums1, arr, nums1Size * sizeof(*nums1));
}

void merge2(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i1 = m - 1, i2 = n - 1, i = m + n - 1;

    while (i1 >= 0) {
        if (nums1[i1] > nums2[i2]) {
            nums1[i] = nums1[i1];
            i1--;
        } else {
            nums1[i] = nums2[i2];
            i2--;
        }
        i--;
    }

    while (i2 >= 0) {
        nums1[i] = nums2[i2];
        i2--;
        i--;
    }

    // Proof (optional)

    // You might be a bit skeptical of this claim. Does it really work in every case?
    // Is it safe to be making such a bold claim?

    // This way, it is guaranteed that once we start overwriting the first m values in nums1,
    // we will have already written each into its new position. In this way, we can eliminate the additional space.

    // Great question! So, why does this work? To prove it, we need to ensure that i never overwrites a value in nums1
    // that i1 hasn't yet read from nums1.

    // Words of Advice: Terrified of proofs? Many software engineers are. Good proofs are simply a series of logical
    // assertions, each building on the next. In this way, we can go from "obvious" statements, all the way to the one
    // we want to prove. I recommend reading each statement one-by-one, ensuring that you understand each before moving onto the next.

    // 1. We know that upon initialization, i is n steps ahead of i1 (in other words, i1 + n = i).

    // 2. We also know that during each of the i iterations this algorithm performs, i is always decremented by 1, and either i1 or i2 is
    // decremented by 1.

    // 3. We can deduce that when i1 decremented, the gap between i and i1 stays the same, so there can't be an "overtake" in that case.

    // 4. We can also deduce that when i2 is decremented though, the gap between i and i1 shrinks by 1 as i moves, but not i1.

    // 5. And from that, we can deduce that the maximum number of times that i2 can be decremented is n. In other words, the gap
    // between i and i1 can shrink by 1, at most n times.

    // 6. In conclusion, it's impossible for an overtake to occur, as they started n apart. And when i = i1, the gap has to have
    // shrunk n times. This means that all of nums2 have been merged in, and so there is nothing more to do.
}

int main() {

}
