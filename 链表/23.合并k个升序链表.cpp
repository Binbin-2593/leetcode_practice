/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* x=nullptr;
        for (auto &y:lists){
            x = merge(x, y);
        }
        return x;
    }

    ListNode* merge(ListNode *l1,ListNode *l2){
        if(!l1 || l2 && l1->val > l2->val)
            swap(l1, l2);
        if(l1)
            l1->next = merge(l1->next, l2);
        return l1;
    }
};
// @lc code=end

