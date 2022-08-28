// Given the head of a singly linked list, return true
// if it is a palindrome or false otherwise.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false

#include<iostream>
#include<vector>
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
    // O(n) time
    // O(n) space
    bool isPalindrome(ListNode* head) {
    	if (!head) {
    		return true;
    	}

        vector<int> v;

        while (head) {
        	v.push_back(head->val);
        	head = head->next;
        }

        unsigned start = 0;
        unsigned end = unsigned(v.size()) - 1;

        while (start < end) {
        	if (v[start] != v[end]) {
        		return false;
        	}
        	start += 1;
        	end -= 1;
        }

        return true;
    }

    // O(n) time
    // O(n) space
    bool isPalindrome2(ListNode* head) {
    	frontPointer = head;
    	return checkForPalindromeRecursively(head);
    }

    // O(n) time
    // O(1) space
    bool isPalindrome3(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfStart = reversedList(firstHalfEnd->next);

        ListNode* curr1 = head;
        ListNode* curr2 = secondHalfStart;
        bool res = true;

        // Check for palindrome
        while (curr2) {
            if (curr1->val != curr2->val) {
                res = false;
                break;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        // Restore initial list
        firstHalfEnd->next = reversedList(secondHalfStart);

        return res;
    }

private:
    ListNode* frontPointer;

    bool checkForPalindromeRecursively(ListNode* node) {
    	if (node) {
    		if (!checkForPalindromeRecursively(node->next)) {
    			return false;
    		}
    		if (node->val != frontPointer->val) {
    			return false;
    		}
    		frontPointer = frontPointer->next;
    	}
    	return true;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reversedList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
	ListNode* list1 = new ListNode(1);

    ListNode* list1_2 = new ListNode(2);
    list1->next = list1_2;

    ListNode* list1_3 = new ListNode(3);
    list1_2->next = list1_3;

    ListNode* list1_4 = new ListNode(2);
    list1_3->next = list1_4;

    ListNode* list1_5 = new ListNode(1);
    list1_4->next = list1_5;

    Solution s;
    cout << s.isPalindrome3(list1) << endl;
}
