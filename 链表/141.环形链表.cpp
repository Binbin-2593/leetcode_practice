/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-01-15 17:48:28
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-08 00:46:30
 * @FilePath: /.leetcode/链表/141.环形链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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

//外层循环遍历所有结点；内层一每个结点为基础遍历对比
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode*slow=head,*fast=head;
        do{
            if(!fast->next||!fast->next->next)return false;
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        return true;
    }
};
// @lc code=end

