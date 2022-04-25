/*
 * @Author: your name
 * @Date: 2022-03-03 15:42:07
 * @LastEditTime: 2022-04-19 16:11:32
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/链表/24.两两交换链表中的节点.cpp
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        
        //遍历处理指针
        // ListNode *dummy = new ListNode(0);
        // dummy->next = head;
        // ListNode* prev=head, *cur=prev->next;
        
        // while (cur)
        // {
        //     ListNode *next = cur->next;
        //     cur->next=prev;
        //     prev->next = next;

        //     prev = next;
        //     cur=prev->next;
        // }//引入dummy就应该把dummy节点也画进链表草稿图中演示

        // ListNode *dummy = new ListNode(0);
        // dummy->next = head;
        //不要用上面两句new的方式，需要释放内存
        ListNode dummy (-1, head);
        ListNode *tmp = &dummy;
        //循环条件一定要清楚的演示出来
        while (tmp->next!=nullptr&&tmp->next->next!=nullptr){
            ListNode *n1 = tmp->next, *n2 = tmp->next->next;
            tmp->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            tmp = n1;
        }
        return dummy.next;
    }
};
// @lc code=end

