/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
void letterCombinationsH(string digits, string current, vector<string> &sol);

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> sol;
        letterCombinationsH(digits, "", sol);
        return sol;
    }
};

void letterCombinationsH(string digits, string current, vector<string> &sol)
{
    if (digits.size() == 0)
    {
        if (current.size() > 0) 
        {
            sol.push_back(current);
        }
        return;
    }
    char c = digits[0];
    digits.erase(0, 1);
    int index = c + 47 + (c - '2') * 2;
    int amount = 3;
    if (c == '7' || c == '9')
        amount = 4;
    if (c == '8' || c == '9')
        index++;
    for (int i = index; i < index + amount; ++i)
    {
        letterCombinationsH(digits, current + char(i), sol);
    }
}
// @lc code=end
