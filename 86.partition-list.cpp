/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
void partitionH(ListNode *&lessFirst, ListNode *head, int x, ListNode *&less, ListNode *&greater, ListNode *&firstGreat);

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lessFirst = NULL;
        ListNode *firstGreat = NULL;
        ListNode *less = NULL;
        ListNode *greater = NULL;
        if (head == NULL)
            return NULL;
        if (head->val < x)
        {
            less = head;
            lessFirst = head;
            partitionH(lessFirst, head->next, x, less, greater, firstGreat);
        }
        else
        {
            greater = head;
            firstGreat = head;
            partitionH(lessFirst, head->next, x, less, greater, firstGreat);
        }
        if (less != NULL)
        {
            less->next = firstGreat;
        }
        if (greater != NULL)
        {
            greater->next = NULL;
        }
        if (lessFirst == NULL)
            return head;
        return lessFirst;
    }
};

void partitionH(ListNode *&lessFirst, ListNode *head, int x, ListNode *&less, ListNode *&greater, ListNode *&firstGreat)
{
    if (head == NULL)
        return;
    if (head->val < x)
    {
        if (less == NULL)
        {
            lessFirst = head;
            less = head;
        }
        else
        {
            less->next = head;
            less = less->next;
        }
    }
    else
    {
        if (greater == NULL)
        {
            greater = head;
            firstGreat = head;
        }
        else
        {
            greater->next = head;
            greater = greater->next;
        }
    }
    partitionH(lessFirst, head->next, x, less, greater, firstGreat);
}
// @lc code=end
