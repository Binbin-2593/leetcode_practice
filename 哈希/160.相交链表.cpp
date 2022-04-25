/*
 * @Author: your name
 * @Date: 2022-03-03 17:57:13
 * @LastEditTime: 2022-04-20 12:15:14
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/哈希/160.相交链表.cpp
 */
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> sl;
        ListNode *tmp = headA;
        while(tmp){
            sl.emplace(tmp);
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp){
            if(sl.count(tmp))
                return tmp;
            tmp = tmp->next;
        }
        return NULL;
    }//此题中要理解指针本身也是对象，可以直接比较是否相等
};
// @lc code=end

