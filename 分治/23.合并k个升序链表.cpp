/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
        //1.局部两个合并
        ListNode* mergetwoLists(ListNode*l1,ListNode* l2){
            if(l1 == nullptr)
                return l2;
            else if(l2 == nullptr)
                return l1;
            
            else if(l1->val<=l2->val){
                l1->next=mergetwoLists(l1->next, l2);
                return l1;
            }
            else{
                l2->next = mergetwoLists(l2->next,l1 );
                return l2;
            }
        }

        //2.递归二分、归并，归并时站在上帝视角在处理“对二”的问题
        ListNode* merge(vector<ListNode*> &lists, int l,int r){
            //分治归并，要讨论的区间大小问题,更是低柜结束的条件
            if(l>r) return nullptr;
            if(l==r)
                return lists[l];
            int mid = (l+r)/2;
            return mergetwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
        }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};
// @lc code=end

