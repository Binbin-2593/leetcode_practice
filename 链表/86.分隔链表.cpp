/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-18 19:19:50
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-18 22:41:08
 * @FilePath: /.leetcode/链表/86.分隔链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        //unordered_set<ListNode *> hash;
        ListNode *l1 = new ListNode(),*l2=new ListNode(),*curr=head,*l1c=l1,*l2c=l2;
        while(curr){
            if(curr->val<x){
                l1c->next = curr;
                l1c = l1c->next;
            }else{
                l2c->next = curr;
                l2c = l2c->next; 
            }
            curr=curr->next;
        }
        l2c->next=nullptr;
        l1c->next = l2->next;
        return l1->next;
    }
};
// @lc code=end

