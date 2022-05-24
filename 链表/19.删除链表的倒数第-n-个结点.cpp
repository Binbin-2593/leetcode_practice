/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-17 22:56:45
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-18 17:26:48
 * @FilePath: /.leetcode/链表/19.删除链表的倒数第-n-个结点.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
//双指针：快慢指针
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *slow = head, *fast = head;
//         while(n--){
//             fast=fast->next;
//         }
//         if(fast==nullptr){//n=sz的情况
//             return head->next;
//         }
//         while(fast->next!=nullptr){
//             slow = slow->next;
//             fast=fast->next;
//         }
//         slow->next = slow->next->next;
//         return head;
//     }
// };
//哑节点处理边界
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(-1, head),*slow=dummy,*fast=head;
        while(n--){
            fast=fast->next;
        }
        while(fast){
            fast = fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        ListNode*ans=dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end

