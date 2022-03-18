/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        long newDividend = abs(dividend);
        long newDivisor = abs(divisor);
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long ans = 0;
        while (newDividend >= newDivisor)
        {
            long temp = newDivisor;
            long exp = 1;
            while (temp << 1 <= newDividend)
            {
                temp <<= 1;
                exp <<= 1;
            }
            newDividend -= temp;
            ans += exp;
        }
        return ans * sign;
    }
};
// @lc code=end
