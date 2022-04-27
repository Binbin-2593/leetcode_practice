/*
 * @Author: your name
 * @Date: 2022-03-03 18:34:11
 * @LastEditTime: 2022-04-26 21:13:16
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/双指针/234.回文链表.cpp
 */
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
//一定画图演示
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        //用快慢指针分段
        ListNode *slow = head, *fast = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //反转后半段
        slow->next = reverseList(slow->next);
        //下面比对两个链表相等不
        slow=slow->next;
        while (slow)
        {
            if(head->val!=slow->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
        
    }
    ListNode* reverseList(ListNode* head){
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        //用快慢指针分段
        ListNode *slow = head, *fast = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //反转后半段
        slow->next = reverseList(slow->next);
        //下面比对两个链表相等不
        slow=slow->next;
        while (slow)
        {
            if(head->val!=slow->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
        
    }
    ListNode* reverseList(ListNode* head){
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
};

// @lc code=end

