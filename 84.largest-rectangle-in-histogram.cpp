/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int leftLimits[heights.size()];
        int rightLimits[heights.size()];
        stack<int> leftStack;
        stack<int> rightStack;
        //get Left Limits
        for (int i = 0; i < heights.size(); ++i)
        {
            if (leftStack.empty())
            {
                leftLimits[i] = i;
            }
            else
            {
                int curr = i;
                while (!leftStack.empty() && heights[leftStack.top()] >= heights[i])
                {
                    if (heights[leftStack.top()] > heights[i])
                    {
                        curr = leftLimits[leftStack.top()];
                        leftStack.pop();
                    }
                    else if (heights[leftStack.top()] == heights[i])
                    {
                        curr = leftLimits[leftStack.top()];
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                leftLimits[i] = curr;
            }
            if (leftStack.empty())
            {
                leftStack.push(i);
            }
            else if (heights[leftStack.top()] != heights[i])
            {
                leftStack.push(i);
            }
        }
        //get Right Limits
        for (int i = heights.size() - 1; i >= 0; --i)
        {
            if (rightStack.empty())
            {
                rightLimits[i] = i;
            }
            else
            {
                int curr = i;
                while (!rightStack.empty() && heights[rightStack.top()] >= heights[i])
                {
                    if (heights[i] < heights[rightStack.top()])
                    {
                        curr = rightLimits[rightStack.top()];
                        rightStack.pop();
                    }
                    else if (heights[rightStack.top()] == heights[i])
                    {
                        curr = rightLimits[rightStack.top()];
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                rightLimits[i] = curr;
            }
            if (rightStack.empty())
            {
                rightStack.push(i);
            }
            else if (heights[rightStack.top()] != heights[i])
            {
                rightStack.push(i);
            }
        }
        //get All Rectangle Areas
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0; i < heights.size(); ++i)
        {
            int val = heights[i];
            int width = rightLimits[i] - leftLimits[i] + 1;
            int area = width * val;
            pq.push(area);
        }
        //get Maximum Rectangle Area
        if (!pq.empty())
        {
            return pq.top();
        }
        return 0;
    }
};
// @lc code=end
