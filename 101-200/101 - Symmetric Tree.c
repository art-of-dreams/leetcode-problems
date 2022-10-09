// Given the root of a binary tree, check whether it is a mirror of itself
// (i.e., symmetric around its center).

// Example 1:
// Input: root = [1,2,2,3,4,4,3]
// Output: true

// Example 2:
// Input: root = [1,2,2,null,3,null,3]
// Output: false

// Constraints:
//     The number of nodes in the tree is in the range [1, 1000].
//     -100 <= Node.val <= 100

// Follow up: Could you solve it both recursively and iteratively?

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode* insert_tree_level(int* values, int size, int i) {
    struct TreeNode* root = NULL;

    if (i < size && values[i] != INT_MIN) { // INT_MIN = null
        root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = values[i];
        root->left = root->right = NULL;

        root->left = insert_tree_level(values, size, 2 * i + 1);
        root->right = insert_tree_level(values, size, 2 * i + 2);
    }

    return root;
}

static struct TreeNode* create_tree(int* values, int size) {
    return insert_tree_level(values, size, 0);
}

struct Trunk {
    struct Trunk *prev;
    char* str;
};

static void print_trunk(struct Trunk* trunk) {
    if (trunk) {
        print_trunk(trunk->prev);
        printf("%s", trunk->str);
    }
}
 
static void print_tree_helper(struct TreeNode* root, struct Trunk* prev, int isLeft) {
    if (!root) {
        return;
    }
 
    struct Trunk *trunk = (struct Trunk*)malloc(sizeof(struct Trunk));
    trunk->prev = prev;
    trunk->str = "    ";

    print_tree_helper(root->right, trunk, 1);
  
    if (!prev) {
        trunk->str = "———";
    } else if (isLeft) {
        trunk->str = ".———";
    }
    else {
        trunk->str = "`———";
        prev->str = "    ";
    }
 
    print_trunk(trunk);
    printf(" %d\n", root->val);
 
    if (prev) {
        prev->str = isLeft ? "   |" : "    ";
    }

    trunk->str = "   |";
 
    print_tree_helper(root->left, trunk, 0);
}

static void print_tree(struct TreeNode* root) {
    print_tree_helper(root, NULL, 0);
}

static bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (!left && !right) {
        return true;
    }
    if (!left || !right) {
        return false;
    }
    return left->val == right->val
        && isMirror(left->right, right->left)
        && isMirror(left->left, right->right);
}

bool isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
}

int main() {
    int arr[] = { 1,2,2,3,4,4,3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    struct TreeNode* root = create_tree(arr, n);
    printf("%d\n", isSymmetric(root));
}