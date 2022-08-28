// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    ListNode* reverseList2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* result = reverseList2(head->next);
        head->next->next = head;
        head->next = nullptr;

        return result;
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
    ListNode* node = s.reverseList(list1);

    while (node) {
        cout << node->val << endl;
        node = node->next;
    }
}
