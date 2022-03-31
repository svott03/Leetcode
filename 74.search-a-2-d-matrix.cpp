/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
int binarySearch(int left, int right, int target, vector<int>& vec, bool& found, bool leftSwap);

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        vector<int> vec;
        for (int i = 0; i < matrix.size(); ++i) {
            vec.push_back(matrix[i][0]);
        }
        int row = binarySearch(0, vec.size() - 1, target, vec, found, false);
        if (found) {
            return true;
        } else {
            //binary search row
            vec.clear();
            for (int i = 0; i < matrix[row].size(); ++i) {
                vec.push_back(matrix[row][i]);
            }
            found = false;
            int col = binarySearch(0, vec.size() - 1, target, vec, found, false);
            return found;
        }
    }
};

int binarySearch(int left, int right, int target, vector<int>& vec, bool& found, bool leftSwap) {
    if (right < left) {
        if (leftSwap) {
            return right;
        }
        return left;
    }
    int mid = left + (right - left)/2;
    if (vec[mid] < target && mid < vec.size() - 1 && vec[mid+1] > target) {
        return mid;
    }
    if (vec[mid] > target && mid > 0 && vec[mid-1] < target) {
        return mid-1;
    }
    if (vec[mid] == target) {
        found = true;
        return mid;
    }
    if (vec[mid] < target) {
        return binarySearch(mid+1, right, target, vec, found, true);
    } else {
        return binarySearch(left, mid-1, target, vec, found, false);
    }
}
// @lc code=end

