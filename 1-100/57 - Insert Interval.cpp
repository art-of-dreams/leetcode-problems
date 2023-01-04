// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi]
// represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.
// You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals
// still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

// Constraints:
//     0 <= intervals.length <= 10^4
//     intervals[i].length == 2
//     0 <= starti <= endi <= 10^5
//     intervals is sorted by starti in ascending order.
//     newInterval.length == 2
//     0 <= start <= end <= 10^5

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Returns true if the intervals a and b have a common element.
    bool doesIntervalsOverlap(vector<int>& a, vector<int>& b) {
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }

    // Return the interval having all the elements of intervals a and b.
    vector<int> mergedInterval(vector<int>& a, vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    // Insert the interval newInterval, into the list interval keeping the sorting order intact.
    void insertIntervalUsingLinearSearch(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool isInserted = false;

        for (unsigned i = 0; i < intervals.size(); i++) {
            if (newInterval[0] < intervals[i][0]) {
                // Found the position, insert the interval and break from the loop.
                intervals.insert(intervals.begin() + i, newInterval);
                isInserted = true;
                break;
            }
        }

        // If there is no interval with a greater value of start value,
        // then the interval must be inserted at the end of the list.
        if (!isInserted) {
            intervals.push_back(newInterval);
        }
    }

    void insertIntervalUsingUpperBound(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();

        if (index != intervals.size()) {
            intervals.insert(intervals.begin() + index, newInterval);
        } else {
            intervals.push_back(newInterval);
        }
    }

    void insertIntervalUsingBinarySearch(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = firstSuitableIndexToInsert(
            intervals,
            newInterval,
            0,
            intervals.size() - 1,
            intervals.size()
        );

        if (index != intervals.size()) {
            intervals.insert(intervals.begin() + index, newInterval);
        } else {
            intervals.push_back(newInterval);
        }
    }

    int firstSuitableIndexToInsert(vector<vector<int>>& intervals, vector<int>& newInterval, int lowerBound, int upperBound, int currentResult) {
        if (lowerBound > upperBound) {
            return currentResult;
        }

        int mid = lowerBound + (upperBound - lowerBound) / 2;

        if (newInterval[0] < intervals[mid][0]) {
            return firstSuitableIndexToInsert(
                intervals,
                newInterval,
                lowerBound,
                mid - 1,
                mid
            );
        } else {
            return firstSuitableIndexToInsert(
                intervals,
                newInterval,
                mid + 1,
                upperBound,
                currentResult
            );
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Insert the interval first before merge processing.
        insertIntervalUsingBinarySearch(intervals, newInterval);

        vector<vector<int>> result;

        for (unsigned i = 0; i < intervals.size(); i++) {
            vector<int> current = {intervals[i][0], intervals[i][1]};

            // Merge until the list gets exhausted or no overlap is found.
            while (i < intervals.size() && doesIntervalsOverlap(current, intervals[i])) {
                current = mergedInterval(current, intervals[i]);
                i++;
            }

            // Decrement to ensure we don't skip the interval due to outer for-loop incrementing.
            i--;
            result.push_back(current);
        }

        return result;
    }
};

int main() {

}
