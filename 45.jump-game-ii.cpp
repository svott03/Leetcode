/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int currEnd = 0;
        int currFarthest = 0;
        int jumps = 0;
        for (int i = 0; i < nums.size()-1; ++i)
        {
            currFarthest = std::max(currFarthest, i + nums[i]);
            if (i == currEnd)
            {
                currEnd = currFarthest;
                ++jumps;
            }
        }
        return jumps;
    }
};
// @lc code=end
