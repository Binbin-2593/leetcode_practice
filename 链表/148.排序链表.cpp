/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-18 19:12:51
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-24 17:00:35
 * @FilePath: /.leetcode/链表/148.排序链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
//插入排序超时
/*
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        //处理临界条件：哑jiedian
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        //排序迭代初始化
        ListNode *lastSorted = head, *curr = head->next;
        while(curr != nullptr){
            if(lastSorted->val<=curr->val){
                lastSorted=lastSorted->next;
            }else{//当前值需要往前排：拎出来与前面一个个的比较（插入排序思想）
                ListNode *prev = dummy;
                while(prev->next->val<=curr->val){
                    prev = prev->next;//滑动指针找到curr->val要插入的位置
                }
                //删除节点操作
                lastSorted->next = curr->next;
                //插入节点
                curr->next = prev->next;
                prev->next = curr;
            }
            curr=lastSorted->next;//当前对象始终是lastSorted->next
        }
        return dummy->next;
    }
};*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head, nullptr);
    }
    //分
    ListNode*mergesort(ListNode* head,ListNode* tail){
        if(head==nullptr){
            return head;
        }
        if(head->next==tail){
            head->next=nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while(fast!=tail){
            slow = slow->next;
            fast = fast->next;
            if(fast!=tail){
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge(mergesort(head, mid), mergesort(mid, tail));
    }
    //合
    ListNode* merge(ListNode*head1,ListNode*head2){
        ListNode *dummy = new ListNode(0),*temp=dummy,*temp1=head1,*temp2=head2;
        while(temp1!=nullptr&&temp2!=nullptr){
            if (temp1->val<=temp2->val){
                temp->next=temp1;
                temp1 = temp1->next;
            }else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1!=nullptr){
            temp->next=temp1;
        }else if(temp2!=nullptr){
            temp->next = temp2;
        }
        return dummy->next;
    }
};


// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if (head == NULL || head->next == NULL)
//             return head;
        
//         ListNode* slow = head;
//         ListNode* fast = head->next;
        
//         while (fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         //divide the list into two parts 
//         fast = slow->next;
//         slow->next = NULL;
        
//         return merge(sortList(head), sortList(fast));
//     }
    
//     ListNode* merge(ListNode* l1, ListNode* l2)
//     {
//         ListNode dump(0);
//         ListNode* cur = &dump;
        
//         while (l1 != NULL && l2 != NULL){
//             if (l1->val < l2->val){
//                 cur->next = l1;
//                 l1 = l1->next;
//             }else{
//                 cur->next = l2;
//                 l2 = l2->next;
//             }   
//             cur = cur->next;
//         }
        
//         if (l1 != NULL)
//             cur->next = l1;
//         else
//             cur->next = l2;
            
//         return dump.next;
//     }
// };

// @lc code=end

