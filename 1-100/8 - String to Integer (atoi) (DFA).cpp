#include <iostream>
#include <string>
using namespace std;

// Algorithm

//     Initialize three variables:
//         currentState (to represent current state) as q0
//         result (to store result till now) as 0
//         sign (to represent the sign of the final result) as 1
//     For each character of the input string, if the current state is not qd:
//         If the current state is q0:
//             Stay in the same state if whitespaces occur.
//             If a sign occurs, change the sign variable to -1 if it's a negative sign and change the state to q1.
//             If a digit occurs, append the current digit to the resulting number (clamp result if needed) and change the state to q2.
//             If anything else occurs, then stop building the number and transition to state qd.
//         If the current state is q1:
//             If a digit occurs, append the current digit to the resulting number (clamp result if needed) and change the state to q2.
//             If anything else occurs, stop building the result number and transition to state qd.
//         If the current state is q2:
//             If a digit occurs, append the current digit to the resulting number (clamp result if needed) and stay in the current state.
//             Anything else after a digit character will not be valid; hence, stop building the number and transition to state qd.
//     Return the final result with the respective sign, result * sign.

enum State { q0, q1, q2, qd };

class StateMachine {
	// Store current state value.
	State currentState;

	// Store result formed and it's sign.
	int result, sign;

	// Transition to state q1.
	void toStateQ1(char& c) {
		sign = (c == '-') ? -1 : 1;
		currentState = q1;
	}

	// Transition to state q2.
	void toStateQ2(int digit) {
		currentState = q2;
		appendDigit(digit);
	}

	// Transition to dead state qd.
	void toStateQd() {
		currentState = qd;
	}

	// Append digit to result, if out of range return clamped value.
	void appendDigit(int& digit) {
		if ((result > INT_MAX / 10) ||
			(result == INT_MAX / 10 && digit > INT_MAX % 10)) {
			if (sign == 1) {
				// If sign is 1, clamp result to INT_MAX.
				result = INT_MAX;
			} else {
				// If sign is -1, clamp result to INT_MIN.
				result = INT_MIN;
				sign = 1;
			}

			// When the 32-bit int range is exceeded, a dead state is reached.
			toStateQd();
		} else {
			// Append current digit to the result.
			result = result * 10 + digit;
		}
	}

public:
	StateMachine() {
		currentState = q0;
		result = 0;
		sign = 1;
	}

	// Change state based on current input character.
	void transition(char& c) {
		switch (currentState) {
		case q0:
			// Beginning state of the string (or some whitespaces are skipped).
			if (c ==' ') {
				// Current character is a whitespaces.
                // We stay in same state. 
                return;
			} else if (c == '+' || c == '-') {
				// Current character is a sign.
				toStateQ1(c);
			} else if (isdigit(c)) {
				toStateQ2(c - '0');
			} else {
				// Current character is not a space/sign/digit.
                // Reached a dead state.
                toStateQd();
			}
			break;
		case q1: case q2:
			// Previous character was a sign or digit.
			if (isdigit(c)) {
				// Current character is a digit.
				toStateQ2(c - '0');
			} else {
				// Current character is not a digit.
                // Reached a dead state.
                toStateQd();
			}
			break;
		case qd:
			break;
		}
	}

	// Return the final result formed with it's sign.
	int getInteger() {
		return sign * result;
	}

	// Get current state.
	State getState() {
		return currentState;
	}
};

class Solution {
public:
    int myAtoi(string s) {
        StateMachine machine;

        for (unsigned i = 0; i < s.size() && machine.getState() != qd; i++) {
        	machine.transition(s[i]);
        }

        return machine.getInteger();
    }
};

int main() {

}