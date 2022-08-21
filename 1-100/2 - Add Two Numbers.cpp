// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* current = nullptr;

        bool carry = false;

        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int val = val1 + val2 + (carry ? 1 : 0);

            if (val > 9) {
                val -= 10;
                carry = true;
            } else {
                carry = false;
            }
            
            if (!current) {
                result = new ListNode(0);
                current = result;
            } else {
                current->next = new ListNode(0);
                current = current->next;
            }
            
            current->val = val;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return result;
    }
};

int main() {
    ListNode* list1 = new ListNode(9);

    ListNode* list1_2 = new ListNode(9);
    list1->next = list1_2;

    ListNode* list1_3 = new ListNode(9);
    list1_2->next = list1_3;

    ListNode* list1_4 = new ListNode(9);
    list1_3->next = list1_4;

    ListNode* list1_5 = new ListNode(9);
    list1_4->next = list1_5;

    ListNode* list1_6 = new ListNode(9);
    list1_5->next = list1_6;

    ListNode* list1_7 = new ListNode(9);
    list1_6->next = list1_7;

    ListNode* list2 = new ListNode(9);

    ListNode* list2_2 = new ListNode(9);
    list2->next = list2_2;

    ListNode* list2_3 = new ListNode(9);
    list2_2->next = list2_3;

    ListNode* list2_4 = new ListNode(9);
    list2_3->next = list2_4;

    Solution s;
    ListNode* node = s.addTwoNumbers(list1, list2);

    while (node) {
        cout << node->val << "\n";
        node = node->next;
    }

    return 0;
}
