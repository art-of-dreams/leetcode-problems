// Given the head of a singly linked list and two integers left and right where left <= right,
// reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [5], left = 1, right = 1
// Output: [5]

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (left > 1) {
            prev = curr;
            curr = curr->next;
            left -= 1;
            right -= 1;
        }

        ListNode *reversedHeadPrev = prev;
        ListNode *reversedTail = curr;
        ListNode *next;

        while (right > 0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            right -= 1;
        }

        if (reversedHeadPrev) {
            reversedHeadPrev->next = prev;
        } else {
            head = prev;
        }

        if (reversedTail) {
            reversedTail->next = curr;
        }

        return head;
    }

    ListNode* reverseBetween2(ListNode* head, int left, int right) {
        leftNode = head;
        stop = false;
        reverseRecursively(head, left, right);
        return head;
    }

private:
    ListNode* leftNode;
    bool stop = false;

    void reverseRecursively(ListNode* rightNode, int left, int right) {
        if (right == 1) {
            return;
        }

        rightNode = rightNode->next;

        if (left > 1) {
            leftNode = leftNode->next;
        }

        reverseRecursively(rightNode, left - 1, right - 1);

        if (leftNode == rightNode || leftNode == rightNode->next) {
            stop = true;
        }

        if (!stop) {
            int val = rightNode->val;
            rightNode->val = leftNode->val;
            leftNode->val = val;
            leftNode = leftNode->next;
        }
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
    ListNode* node = s.reverseBetween(list1, 2, 4);
    node->print();
}