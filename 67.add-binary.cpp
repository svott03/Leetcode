/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
string addBinaryH(string &a, string &b);
class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.size() > b.size())
        {
            return addBinaryH(a, b);
        }
        return addBinaryH(b, a);
    }
};

string addBinaryH(string &a, string &b)
{
    int c = 0;
    int j = a.size() - 1;
    for (int i = b.size() - 1; i >= 0; --i)
    {
        int val = int(b[i]) - '0' + int(a[j]) - '0' + c;
        c = val / 2;
        a[j] = val % 2 + '0';
        --j;
    }
    if (c)
    {
        for (int k = j; k >= 0; --k)
        {
            int val = int(a[k]) - '0' + c;
            c = val / 2;
            a[k] = val % 2 + '0';
        }
    }
    if (c)
    {
        a.insert(0, 1, '1');
    }
    return a;
}

// @lc code=end
