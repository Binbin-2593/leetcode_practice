/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> sl;
        ListNode *tmp = headA;
        while(tmp){
            sl.insert(tmp);
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp){
            if(sl.count(tmp))
                return tmp;
            tmp = tmp->next;
        }
        return NULL;
    }//此题中要理解指针本身也是对象，可以直接比较是否相等
};
// @lc code=end

