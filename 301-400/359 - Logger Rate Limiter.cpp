// Design a logger system that receives a stream of messages along with their timestamps.
// Each unique message should only be printed at most every 10 seconds (i.e. a message
// printed at timestamp t will prevent other identical messages from being printed
// until timestamp t + 10).

// All messages will come in chronological order. Several messages may arrive at the same timestamp.

// Implement the Logger class:

// Logger()
// Initializes the logger object.

// bool shouldPrintMessage(int timestamp, string message)
// Returns true if the message should be printed in the given timestamp, otherwise returns false.

// Example 1:
// Input
// ["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
// [[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
// Output
// [null, true, true, false, false, false, true]

// Explanation
// Logger logger = new Logger();
// logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
// logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
// logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
// logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
// logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
// logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21

// Constraints:
// 0 <= timestamp <= 109
// Every timestamp will be passed in non-decreasing order (chronological order).
// 1 <= message.length <= 30
// At most 104 calls will be made to shouldPrintMessage.

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Logger {
public:
    Logger() { }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamps_by_message.count(message)) {
            if (timestamp >= timestamps_by_message[message] + 10) {
                timestamps_by_message[message] = timestamp;
                return true;
            } else {
                return false;
            }
        } else {
            timestamps_by_message[message] = timestamp;
            return true;
        }
    }

private:
    unordered_map<string, int> timestamps_by_message;
};

struct Message {
    string text;
    int timestamp;
};

struct ListItem {
    Message *message;
    ListItem *next;
    ListItem() : message(nullptr), next(nullptr) { }
    ListItem(Message *message) : message(message), next(nullptr) {}
};

class Logger2 {
public:
    Logger2() { }
    
    bool shouldPrintMessage(int timestamp, string message) {
        ListItem *curr = queue;

        // Remove staled messages
        while (curr && timestamp >= curr->message->timestamp + 10) {
            messages.erase(curr->message->text);
            ListItem *next = curr->next;
            delete curr->message;
            delete curr;
            curr = next;
        }

        if (messages.count(message)) {
            queue = curr;
            return false;
        }

        messages.insert(message);

        ListItem *newHead = curr;

        // Move to the last node
        while (curr && curr->next) {
            curr = curr->next;
        }

        Message* m = new Message();
        m->text = message;
        m->timestamp = timestamp;
        ListItem* node = new ListItem(m);

        if (newHead) {
            curr->next = node;
            queue = newHead;
        } else {
            queue = node;
        }

        return true;
    }

private:
    ListItem *queue = nullptr;
    unordered_set<string> messages;
};

int main() {
    Logger2* obj = new Logger2();
    cout << "1 foo = " << obj->shouldPrintMessage(1, "foo") << endl;
    cout << "2 bar = " << obj->shouldPrintMessage(2, "bar") << endl;
    cout << "3 foo = " << obj->shouldPrintMessage(3, "foo") << endl;
    cout << "8 bar = " << obj->shouldPrintMessage(8, "bar") << endl;
    cout << "10 foo = " << obj->shouldPrintMessage(10, "foo") << endl;
    cout << "11 foo = " << obj->shouldPrintMessage(11, "foo") << endl;
    delete obj;
}
