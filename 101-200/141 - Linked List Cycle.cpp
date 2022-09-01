// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached
// again by continuously following the next pointer. Internally, pos is used to denote
// the index of the node that tail's next pointer is connected to. Note that pos
// is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

#include<iostream>
#include<set>
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }

        auto slow = head;
        auto fast = head->next;

        while (fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    bool hasCycle2(ListNode* head) {
        if (!head) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (!fast || !fast->next) {
                return false;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }

    bool hasCycle3(ListNode* head) {
        if (!head || !head->next) {
            return false;
        }

        ListNode* curr = head;
        set<ListNode *> nodes;

        while (curr) {
            if (nodes.find(curr) != nodes.end()) {
                return true;
            }
            nodes.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};

int main() {
	ListNode* list1 = new ListNode(3);

    ListNode* list1_2 = new ListNode(2);
    list1->next = list1_2;

    ListNode* list1_3 = new ListNode(0);
    list1_2->next = list1_3;

    ListNode* list1_4 = new ListNode(-4);
    list1_3->next = list1_4;

    ListNode* list1_5 = new ListNode(5);
    list1_4->next = list1_5;

    list1_5->next = list1_2;

    Solution s;
    cout << "[3,2,0,-4] has cycle = " <<  s.hasCycle3(list1) << endl;
}