/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
void dfs(vector<int> &candidates, vector<vector<int>> &sol, vector<int> temp, int target, int index);
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> sol;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, sol, {}, target, 0);
        return sol;
    }
};
void dfs(vector<int> &candidates, vector<vector<int>> &sol, vector<int> temp, int target, int index)
{
    if (index == candidates.size())
    {
        return;
    }
    for (int i = index; i < candidates.size(); ++i)
    {
        int val = candidates[i];
        int tempTar = target - val;
        temp.push_back(val);
        if (tempTar == 0)
        {
            sol.push_back(temp);
            return;
        }
        if (tempTar < 0)
        {
            return;
        }
        dfs(candidates, sol, temp, tempTar, i);
        temp.pop_back();
    }
}
// @lc code=end
