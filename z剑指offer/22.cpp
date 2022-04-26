/*
 * @Author: your name
 * @Date: 2022-04-25 21:57:12
 * @LastEditTime: 2022-04-25 22:01:07
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/22.cpp
 */
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* l=head,h=l;
        while(h&&k--){
            h = h->next;
        }
        while(h){
            l=l->next;
            h = h->next;
        }
        return l;
    }
};