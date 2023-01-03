// Given an array of intervals where intervals[i] = [starti, endi],
// merge all overlapping intervals, and return an array of the non-overlapping
// intervals that cover all the intervals in the input.

// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// Constraints:
//     1 <= intervals.length <= 104
//     intervals[i].length == 2
//     0 <= starti <= endi <= 104

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (auto current: intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (result.empty() || result.back()[1] < current[0]) {
                result.push_back(current);
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            } else {
                result.back()[1] = max(result.back()[1], current[1]);
            }
        }

        return result;
    }
};

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "{";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "}";
    return out;
}

int main() {
    vector<vector<int>> input = {{1,4},{0,2},{3,5}};
    Solution s;
    cout << s.merge(input) << endl;
}    
