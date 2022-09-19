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

struct ListedListNode {
    int depth;
    struct TreeNode *tree_node;
    struct ListedListNode *next;
    struct ListedListNode *prev;
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

int maxDepth2(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    struct ListedListNode* dummy_node = (struct ListedListNode*)malloc(sizeof(struct ListedListNode));
    dummy_node->depth = 0;
    dummy_node->tree_node = NULL;
    dummy_node->next = NULL;
    dummy_node->prev = NULL;

    struct ListedListNode* tail = (struct ListedListNode*)malloc(sizeof(struct ListedListNode));
    tail->depth = 1;
    tail->tree_node = root;
    tail->next = NULL;
    tail->prev = dummy_node;

    dummy_node->next = tail;

    int res = 0;

    while (dummy_node->next) {
        int current_depth = tail->depth;
        struct TreeNode* current_tree_node = tail->tree_node;
        res = max(res, current_depth);

        struct ListedListNode* prev = tail->prev;
        prev->next = NULL;
        free(tail);
        tail = prev;

        if (current_tree_node->left) {
            struct ListedListNode* node = (struct ListedListNode*)malloc(sizeof(struct ListedListNode));
            node->depth = current_depth + 1;
            node->tree_node = current_tree_node->left;
            node->next = NULL;
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

        if (current_tree_node->right) {
            struct ListedListNode* node = (struct ListedListNode*)malloc(sizeof(struct ListedListNode));
            node->depth = current_depth + 1;
            node->tree_node = current_tree_node->right;
            node->next = NULL;
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    return res;
}

int main() {

}
