// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Inorder (Left, Root, Right)
// Preorder (Root, Left, Right)
// Postorder (Left, Right, Root)

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,3,2]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [1]
// Output: [1]

// Constraints:
//     The number of nodes in the tree is in the range [0, 100].
//     -100 <= Node.val <= 100

#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static void traverse_node(struct TreeNode* node, int* values, int* size) {
	if (!node) return;
	traverse_node(node->left, values, size);
	values[*size] = node->val;
	*size += 1;
	traverse_node(node->right, values, size);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* values = (int*)malloc(sizeof(int) * 100);
	*returnSize = 0;
	traverse_node(root, values, returnSize);
	return values;
}

int main() {

}
