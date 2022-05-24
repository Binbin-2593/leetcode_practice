/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-17 20:41:33
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-17 21:13:54
 * @FilePath: /.leetcode/链表/203.移除链表元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
//双指针，存储信息防止“丢失”
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         // if(!head)
//         //     return head;
//         ListNode dummy=ListNode(-1,head);
//         ListNode *prev = &dummy,*curr=head;
//         while (curr!=NULL){
//             if(curr->val==val){
//                 prev->next=curr->next;
//             }else{
//                 prev=prev->next;
//             }
//             curr = curr->next;
//         }
//         return dummy.next;
//     }
// };

//链表的特殊性，单指针进行跳跃迭代
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode dummy=ListNode(-1,head);
//         ListNode *temp = &dummy;
//         while(temp->next!=nullptr){
//             if(temp->next->val==val){
//                 temp->next=temp->next->next;
//             }else{
//                 temp = temp->next;
//             }
//         }
//         return dummy.next;
//     }
// };
//递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
// @lc code=end

