// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path
// from the root node down to the farthest leaf node.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 3

// Example 2:
// Input: root = [1,null,2]
// Output: 2

// Constraints:
//     The number of nodes in the tree is in the range [0, 10^4].
//     -100 <= Node.val <= 100

#include "stdio.h"
#include "stdlib.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int max(int x, int y) {
    return x > y ? x : y;
}

int maxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return max(left, right) + 1;
}

int main() {

}
