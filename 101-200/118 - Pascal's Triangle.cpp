// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:
// Input: numRows = 1
// Output: [[1]]

// Constraints:
//     1 <= numRows <= 30

#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++) {
            vector<int> v;

            for (int k = 0; k <= i; k++) {
                if (k == 0 || k == i) {
                    v.push_back(1);
                } else {
                    v.push_back(result[i - 1][k - 1] + result[i - 1][k]);
                }
                
            }

            result.push_back(v);
        }

        return result;
    }
};

int main() {
}
