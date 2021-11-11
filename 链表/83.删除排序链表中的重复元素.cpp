/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         //题设中说的头节点head，指的是指向第一个元素节点的指针
//         //在leetcode里，头节点我们理解为首节点，head为首指针
//         //if(!head) return head;
//         ListNode* curr = head;
//         ListNode *p;
//         while (curr && curr->next)
//         {
//             if(curr->val==curr->next->val){
//                 p=curr->next;
//                 curr->next=p->next;
//                 delete p;
//                 //curr=curr->next; 这里并未确定后面会不会还有重复，不能将当前节点移交不管
//             }
//             else curr=curr->next;
//         }

//         return head;
//     }
// };


// //递归法
// class Solution{
// public:
//     ListNode* deleteDuplicates(ListNode* head){
//         if(!head ||!head->next) return head;//递归的第一步，if写好边界条件
//         head->next = deleteDuplicates(head->next);
//         return head->val == head->next->val ? head->next : head;
// }
// };


// //双指针法
// class Solution{
// public:
//     ListNode* deleteDuplicates(ListNode* head){
//         if(!head || !head->next) return head;

//         ListNode* curr=head;
//         ListNode* next=curr->next;
//         while(next){
//             if(curr->val == next->val){
//                 curr->next=next->next;
//                 next=next->next;
//             }
//             else{curr=curr->next;
//                 next = next->next;
//             }
//         }
//         return head;
        
//     }
//     };


//哑节点法
class Solution{
public:
    ListNode* deleteDuplicates(ListNode*head){
        ListNode *dummy = new ListNode(10000);
        ListNode *curr = dummy;//使用哑节点的好处是不用想上面那些方法那样，考虑边界条件
        ListNode *p;
        dummy->next = head;

        while(curr->next!=nullptr){
            if(curr->val == curr->next->val){
                p=curr->next;
                curr->next=curr->next->next;
                delete p;
            }
            else curr=curr->next;
        }

        //ListNode* retNode = dummy->next;
        //为什么不需要上一句，因为整个函数中head始终都在，83句是使哑节点和给定链表接上
        delete dummy;
        return head;
    }
};
// @lc code=end
