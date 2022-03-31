/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
void fillEdges(int n, int row, int col, int& curr, vector<vector<int>>& matrix);

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                temp.push_back(0);
            }
            matrix.push_back(temp);
        }
        int curr = 1;
        int time = 0;
        for (int i = n; i > 0; i -= 2) {
            fillEdges(i, time, time, curr, matrix);
            time++;
        }
        return matrix;
    }
};

void fillEdges(int n, int row, int col, int& curr, vector<vector<int>>& matrix) {
    //top row
    for (int i = 0; i < n; ++i) {
        matrix[row][col + i] = curr;
        ++curr;
    }
    //right col
    for (int i = 1; i < n; ++i) {
        matrix[row + i][col + n - 1] = curr;
        ++curr;
    }
    //bot row
    for (int i = 1; i < n; ++i) {
        matrix[row + n - 1][col + n - i - 1] = curr;
        ++curr;
    }
    //left col
    for (int i = 1; i < n-1; ++i) {
        matrix[row+n-i - 1][col] = curr;
        ++curr;
    }
}
// @lc code=end

