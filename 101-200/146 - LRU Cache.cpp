// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

//     LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//     int get(int key) Return the value of the key if the key exists, otherwise return -1.
//     void put(int key, int value) Update the value of the key if the key exists.
//     Otherwise, add the key-value pair to the cache. If the number of keys exceeds
//     the capacity from this operation, evict the least recently used key.

// The functions get and put must each run in O(1) average time complexity.

// Example 1:
// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Constraints:
//     1 <= capacity <= 3000
//     0 <= key <= 10^4
//     0 <= value <= 10^5
//     At most 2 * 10^5 calls will be made to get and put.

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) { }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto pair = map.find(key);

        if (pair == map.end()) {
            return -1;
        }

        // move the accessed node to the head;
        move_to_head(pair->second);

        return pair->second->value;
    }
    
    void put(int key, int value) {
        auto pair = map.find(key);

        if (pair == map.end()) {
            Node *new_node = new Node();
            new_node->key = key;
            new_node->value = value;

            map.insert(make_pair(key, new_node));
            add_node(new_node);

            size += 1;

            if (size > capacity) {
                // pop the tail
                Node *tail = pop_tail();
                map.erase(tail->key);
                delete tail;
                size -= 1;
            }
        } else {
            // update the value
            pair->second->value = value;
            move_to_head(pair->second);
        }
    }

private:
    int capacity;
    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;

    // Always add the new node right after head.
    void add_node(Node *node) {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }

    // Unlink an existing node from the linked list.
    void unlink_node(Node *node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    // Move certain node in between to the head.
    void move_to_head(Node *node) {
        unlink_node(node);
        add_node(node);
    }

    // Pop the current tail.
    Node* pop_tail() {
        Node* node = tail->prev;
        unlink_node(node);
        return node;
    }
};

int main() {
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // return -1 (not found)
    cout << lRUCache->get(3) << endl;    // return 3
    cout << lRUCache->get(4) << endl;    // return 4
}
