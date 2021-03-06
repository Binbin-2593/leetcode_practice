/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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

//方法一：迭代
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         //哑节点用于处理边界条件
//         //一下两句是解决链表问题的套路，创建一个哑节点，其实是头节点的作用
//         //然后把哑节点的地址赋值给prev，做头指针
//         ListNode dummy =ListNode(-1);
//         ListNode *prev=&dummy;
//         while (l1 != nullptr&&l2!=nullptr){
//             if (l1->val<l2->val){
//                 prev->next = l1;
//                 l1=l1->next;
//             }
//             else{
//                 prev->next = l2;
//                 l2=l2->next; 
//             }
//             prev = prev->next;
//         }
//         prev->next = l1 == nullptr ? l2 : l1;
//         return dummy.next;//最后返回哑节点的next，为最终链表的头指针
//     }
// };



//方法二：递归

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//  下面两行是递归停止的条件
//         if(l1==nullptr) return l2;
//         else if(l2==nullptr) return l1;

//         else if(l1->val<l2->val){
//             l1->next = mergeTwoLists(l1->next,l2);
//             return l1;
//         }
//         else{l2->next = mergeTwoLists(l2->next,l1);
//             return l2;}
//     }
// };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || l2 && l1->val > l2->val)
            swap(l1, l2);
        if(l1)
            l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};
// @lc code=end

