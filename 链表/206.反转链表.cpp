/*
 * @Author: your name
 * @Date: 2022-01-17 16:43:28
 * @LastEditTime: 2022-08-07 23:49:11
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/链表/206.反转链表.cpp
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
//方法一(笨)：遍历->保存->生成

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //迭代
        // if(head==nullptr||head->next==nullptr) return head;

        // ListNode *cur = head,*prev=nullptr;
        // while(cur){
        //     ListNode *next = cur->next;//断开处一定提前保存
        //     cur->next=prev;
        //     prev=cur;
        //     cur=next;
           
        // }
        // return prev;

        //递归
        //1.对问题进行同逻辑分解出次级问题，用“要...只要...”来思考
        //2.找出递归层级终止条件
        //3.算法中除了递归调用那句，解决问题的句子是描述解决最低层级问题的语句
        if(head==nullptr||head->next==nullptr) return head;//进入算法，第一步就要判断
        ListNode *newhead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newhead;
        //代码次序：递归终止条件判断->递归调用->解决最低层级问题的代码->return
    }
};
// @lc code=end

