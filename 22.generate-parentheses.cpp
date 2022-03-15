/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
void generateParenthesisH(int n, vector<string> &sol, string s, int open);

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> sol;
        generateParenthesisH(n, sol, "", 0);
        return sol;
    }
};

void generateParenthesisH(int n, vector<string> &sol, string s, int open)
{
    if (n == 0 && open == 0)
    {
        sol.push_back(s);
        return;
    }
    if (open > 0)
    {
        generateParenthesisH(n, sol, s + ')', open - 1);
    }
    if (n > 0)
    {
        generateParenthesisH(n - 1, sol, s + '(', open + 1);
    }
}
// @lc code=end
