/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int limit = INT_MIN;
        if (x > 0)
        {
            limit = INT_MAX;
        }
        int result = 0;

        while (abs(x / 10) > 0)
        {
            int curr = x % 10;
            result *= 10;
            result += curr;
            x /= 10;
        }
        if (abs(limit / 10) < abs(result))
        {
            return 0;
        }
        int carry = x % 10;
        result *= 10;
        if (abs(limit) - abs(carry) < abs(result))
        {
            return 0;
        }
        result += carry;
        return result;
    }
};
// @lc code=end
