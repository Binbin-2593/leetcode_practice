/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-18 19:17:23
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-24 15:02:43
 * @FilePath: /.leetcode/链表/147.对链表进行插入排序.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
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
};
// @lc code=end

