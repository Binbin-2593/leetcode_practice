/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-29 23:54:09
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-30 00:08:15
 * @FilePath: /.leetcode/链表/445.两数相加-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        return reverse(add(l1, l2));
    }
    ListNode* reverse(ListNode* head){
        if(!head||!head->next)
            return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next=nullptr;
        return newHead;
    }
    ListNode* add(ListNode*l1,ListNode* l2){
        int x = 0, y = 0, ad = 0;
        ListNode *dummy = new ListNode(0),*prev=dummy;
        while (l1 || l2||ad){
            x = l1 ? l1->val : 0;
            y = l2 ? l2->val : 0;
            int sum = x + y + ad;
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
            ad = sum / 10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        ListNode *ret = dummy->next;
        delete dummy;
        return ret;
    }
};
// @lc code=end

