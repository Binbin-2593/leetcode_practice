/*
 * @Author: your name
 * @Date: 2022-04-25 14:56:10
 * @LastEditTime: 2022-04-25 15:10:45
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/双指针/142.环形链表-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        // if(head==nullptr||head->next==nullptr)
        //     return NULL;
        ListNode *slow = head, *fast = head;
        //判断是否有环路
        do{
            if(!fast||!fast->next) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        //找入口,fast从头同slow速度再跑到相等
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
// @lc code=end

