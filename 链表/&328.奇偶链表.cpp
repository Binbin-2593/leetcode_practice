/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-18 19:20:50
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-18 22:17:24
 * @FilePath: /.leetcode/链表/328.奇偶链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD
 */
/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
//  理解错了
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(!head||!head->next)
//             return head;
//         int tmp = (head->val) & 1;
//         ListNode *l = new ListNode(),*curr=head,*lcurr=l;
//         while(curr->next){
//             if((curr->next->val)&1==tmp){
//                 curr = curr->next;
//             }else{
//                 lcurr->next = curr->next;
//                 lcurr=lcurr->next;
//                 curr->next=curr->next->next;
//             }
//         }
//         lcurr->next = nullptr;//注意
//         curr->next = l->next;
//         return head;
//     }
// };
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next)
            return head;
        //int tmp = (head->val) & 1;
        ListNode *l = head->next,*curr=head,*lcurr=l;
        while(lcurr&&lcurr->next){
            curr->next = lcurr->next;
            curr=curr->next;
            lcurr->next=curr->next;
            lcurr=lcurr->next;
        }
        curr->next = l;
        return head;
    }
};
// @lc code=end

