// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. 
// You will not be given access to the first node of head.

// All the values of the linked list are unique, and it is guaranteed
// that the given node node is not the last node in the linked list.

// Delete the given node. Note that by deleting the node,
// we do not mean removing it from memory. We mean:

//     The value of the given node should not exist in the linked list.
//     The number of nodes in the linked list should decrease by one.
//     All the values before node should be in the same order.
//     All the values after node should be in the same order.

// Custom testing:

//     For the input, you should provide the entire linked list head and
//     the node to be given node. node should not be the last node of the
//     list and should be an actual node in the list.
//     We will build the linked list and pass the node to your function.
//     The output will be the entire list after calling your function.

// Example 1:
// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5,
// the linked list should become 4 -> 1 -> 9 after calling your function.

// Example 2:
// Input: head = [4,5,1,9], node = 1
// Output: [4,5,9]
// Explanation: You are given the third node with value 1,
// the linked list should become 4 -> 5 -> 9 after calling your function.

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void print() {
        cout << val << " ";

        if (next) {
            next->print();
        } else {
            cout << endl;
        }
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;

        while (curr->next) {
            curr->val = curr->next->val;
            prev = curr;
            curr = curr->next;
        }

        if (prev) {
            prev->next = nullptr;
        }
    }

    void deleteNode2(ListNode* node) {
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
    }
};

int main() {
    ListNode* list1 = new ListNode(1);

    ListNode* list1_2 = new ListNode(2);
    list1->next = list1_2;

    ListNode* list1_3 = new ListNode(3);
    list1_2->next = list1_3;

    ListNode* list1_4 = new ListNode(4);
    list1_3->next = list1_4;

    ListNode* list1_5 = new ListNode(5);
    list1_4->next = list1_5;

    Solution s;
    s.deleteNode2(list1_3);
    list1->print();
}
