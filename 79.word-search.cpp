/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
bool findSol(vector<vector<int>> &check, int row, int col, vector<vector<char>> &board, string word, int index, string temp);

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                char c = board[i][j];
                string res = "";
                res += c;
                if (c == word[0])
                {
                    vector<vector<int>> check;
                    for (int i = 0; i < board.size(); ++i)
                    {
                        vector<int> temp;
                        for (int j = 0; j < board[0].size(); ++j)
                        {
                            temp.push_back(0);
                        }
                        check.push_back(temp);
                    }
                    if (findSol(check, i, j, board, word, 1, res))
                        return true;
                }
            }
        }
        return false;
    }
};

bool findSol(vector<vector<int>> &check, int row, int col, vector<vector<char>> &board, string word, int index, string temp)
{
    if (temp == word)
    {
        return true;
    }
    check[row][col] = 1;
    if (row - 1 >= 0)
    {
        if (board[row - 1][col] == word[index] && check[row - 1][col] == 0)
        {
            if (findSol(check, row - 1, col, board, word, index + 1, temp + word[index]))
                return true;
        }
    }
    if (row + 1 < board.size())
    {
        if (board[row + 1][col] == word[index] && check[row + 1][col] == 0)
        {
            if (findSol(check, row + 1, col, board, word, index + 1, temp + word[index]))
                return true;
        }
    }
    if (col + 1 < board[0].size())
    {
        if (board[row][col + 1] == word[index] && check[row][col + 1] == 0)
        {
            if (findSol(check, row, col + 1, board, word, index + 1, temp + word[index]))
                return true;
        }
    }
    if (col - 1 >= 0)
    {
        if (board[row][col - 1] == word[index] && check[row][col - 1] == 0)
        {
            if (findSol(check, row, col - 1, board, word, index + 1, temp + word[index]))
                return true;
        }
    }
    check[row][col] = 0;
    return false;
}

// @lc code=end
