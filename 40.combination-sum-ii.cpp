/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
void dfs(vector<vector<int>> &sol, vector<int> &candidates, int target, int index, vector<int> temp);
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> sol;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(sol, candidates, target, 0, temp);
        return sol;
    }
};
void dfs(vector<vector<int>> &sol, vector<int> &candidates, int target, int index, vector<int> temp)
{
    if (target == 0)
    {
        sol.push_back(temp);
        return;
    }
    int i = index;
    while (i < candidates.size() && target - candidates[i] >= 0)
    {
        if (i == index || candidates[i] != candidates[i - 1])
        {
            temp.push_back(candidates[i]);
            dfs(sol, candidates, target - candidates[i], i + 1, temp);
            temp.pop_back();
        }
        ++i;
    }
}
// @lc code=end
