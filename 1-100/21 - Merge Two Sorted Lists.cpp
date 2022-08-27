// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made
// by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1) {
            current->next = list1;
        } 

        if (list2) {
            current->next = list2;
        }

        return dummy->next;
    }
};

int main() {
	ListNode* list1 = new ListNode(1);

    ListNode* list1_2 = new ListNode(2);
    list1->next = list1_2;

    ListNode* list1_3 = new ListNode(4);
    list1_2->next = list1_3;

    ListNode* list2 = new ListNode(1);

    ListNode* list2_2 = new ListNode(3);
    list2->next = list2_2;

    ListNode* list2_3 = new ListNode(4);
    list2_2->next = list2_3;

    Solution s;
    ListNode* node = s.mergeTwoLists(list1, list2);

    while (node) {
        cout << node->val << endl;
        node = node->next;
    }
}
