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
class Comp{
    public:
        bool operator()(ListNode *& l1, ListNode *& l2)
        {
            return l1->val> l2->val;//默认最大堆，如若最小堆，用>号
        }
};
class Solution {
public:
    
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty()) return NULL;

        priority_queue<ListNode *, vector<ListNode *>, Comp> p;
        //自定义数据类型时，才如此传三参
        for(ListNode*& list:lists){
            if(list){
                p.push(list);
            }
        }

        ListNode* dummy=new ListNode(0),*curr=dummy;
        while(!p.empty()){
            curr->next=p.top();
            p.pop();//链表操作中，先把指针存下再删
            curr=curr->next;
            if(curr->next){
                p.push(curr->next);
            }
        }
        return dummy->next;
    }
    
};
// @lc code=end;
