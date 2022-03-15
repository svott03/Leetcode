/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
void subsetsH(vector<vector<int>> &sol, vector<int> temp, vector<int> &nums, int index);
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> sol;
        sol.push_back({});
        subsetsH(sol, {}, nums, 0);
        return sol;
    }
};

void subsetsH(vector<vector<int>> &sol, vector<int> temp, vector<int> &nums, int index)
{
    if (index == nums.size())
    {
        return;
    }
    for (int i = index; i < nums.size(); ++i)
    {
        vector<int> curr = temp;
        curr.push_back(nums[i]);
        sol.push_back(curr);
        subsetsH(sol, curr, nums, i + 1);
    }
}
// @lc code=end
