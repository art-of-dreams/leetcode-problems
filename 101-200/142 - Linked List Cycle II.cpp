// Given the head of a linked list, return the node where the cycle begins.
// If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that
// can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's next
// pointer is connected to (0-indexed). It is -1 if there is no cycle.
// Note that pos is not passed as a parameter.

// Do not modify the linked list.

// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// Example 2:
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.

// Example 3:
// Input: head = [1], pos = -1
// Output: no cycle
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode *tortoise = head;
        ListNode *hare = head;

        while (hare) {
            tortoise = tortoise->next;
            hare = hare->next ? hare->next->next : nullptr;

            if (tortoise == hare) {
                break;
            }
        }

        if (!hare) {
            return nullptr;
        }

        ListNode *ptr1 = head;
        ListNode *ptr2 = hare;

        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return ptr1;
    }

    ListNode *detectCycle2(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode *curr = head;
        set<ListNode *> nodes;

        while (curr) {
            if (nodes.find(curr) != nodes.end()) {
                return curr;
            }
            nodes.insert(curr);
            curr = curr->next;
        }

        return nullptr;
    }

    ListNode* getIntersect(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;

        // A fast pointer will either loop around a cycle and meet the slow
        // pointer or reach the `null` at the end of a non-cyclic list.
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                return tortoise;
            }
        }

        return nullptr;
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
    ListNode* cycle = s.detectCycle(list1);

    if (cycle) {
        cout << "cycle with value " << cycle->val << endl;
    } else {
        cout << "no cycle" << endl;
    }
}