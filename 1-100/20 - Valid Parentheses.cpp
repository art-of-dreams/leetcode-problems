// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (unsigned i = 0; i < unsigned(s.length()); i++) {
            if (is_opening_parenthesis(s[i])) {
                stack.push(s[i]);
            } else {
                if (stack.empty()) {
                    return false;
                }
                if (stack.top() != opening_parenthesis(s[i])) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }

private:
    bool is_opening_parenthesis(char parenthesis) {
        switch (parenthesis) {
            case '(': case '[': case '{':
                return true;
            default:
                return false;
        }
    }

    char opening_parenthesis(char closing_parenthesis) {
        switch (closing_parenthesis) {
            case ')':
                return '(';
            case ']':
                return '[';
            default:
                return '{';
        }
    }
};

int main() {
    Solution s;
    cout << "() - " << s.isValid("()") << endl;
    cout << "()[]{} - " << s.isValid("()[]{}") << endl;
    cout << "(] - " << s.isValid("(]") << endl;
    cout << "] - " << s.isValid("]") << endl;
}
