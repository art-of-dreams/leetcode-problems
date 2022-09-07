// Design a hit counter which counts the number of hits
// received in the past 5 minutes (i.e., the past 300 seconds).

// Your system should accept a timestamp parameter (in seconds granularity),
// and you may assume that calls are being made to the system in chronological order
// (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.

// Implement the HitCounter class:

// HitCounter() Initializes the object of the hit counter system.

// void hit(int timestamp) Records a hit that happened at timestamp (in seconds).
// Several hits may happen at the same timestamp.

// int getHits(int timestamp) Returns the number of hits in the past 5 minutes
// from timestamp (i.e., the past 300 seconds). 

// Example 1:
// Input
// ["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
// [[], [1], [2], [3], [4], [300], [300], [301]]
// Output
// [null, null, null, null, 3, null, 4, 3]

// Explanation
// HitCounter hitCounter = new HitCounter();
// hitCounter.hit(1);       // hit at timestamp 1.
// hitCounter.hit(2);       // hit at timestamp 2.
// hitCounter.hit(3);       // hit at timestamp 3.
// hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
// hitCounter.hit(300);     // hit at timestamp 300.
// hitCounter.getHits(300); // get hits at timestamp 300, return 4.
// hitCounter.getHits(301); // get hits at timestamp 301, return 3.

// Constraints:
// 1 <= timestamp <= 2 * 10^9
// All the calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing).
// At most 300 calls will be made to hit and getHits.

// Follow up: What if the number of hits per second could be huge? Does your design scale?

#include <iostream>
#include <map>
#include <queue>
using namespace std;

class HitCounter {
public:
    HitCounter() { }
    
    void hit(int timestamp) {
        hitsByTimestamp[timestamp]++;
    }
    
    int getHits(int timestamp) {
        int res = 0;
        int lowerBound = timestamp - 300;

        for (auto iter = hitsByTimestamp.rbegin(); iter != hitsByTimestamp.rend(); ++iter) {
            if (iter->first <= lowerBound) {
                break;
            }
            if (iter->first <= timestamp) {
                res += iter->second;
            }
        }

        return res;
    }

private:
    map<int, int> hitsByTimestamp;
};

class HitCounter2 {
public:
    HitCounter2() { }
    
    void hit(int timestamp) {
        hits.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!hits.empty() && (timestamp - hits.front() >= 300)) {
            hits.pop();
        }
        return int(hits.size());
    }

private:
    queue<int> hits;
};

int main() {
    HitCounter *obj = new HitCounter();
    obj->hit(1);
    obj->hit(2);
    obj->hit(3);
    cout << obj->getHits(4) << endl;
    obj->hit(300);
    cout << obj->getHits(300) << endl;
    cout << obj->getHits(301) << endl;
}