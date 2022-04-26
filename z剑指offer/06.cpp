/*
 * @Author: your name
 * @Date: 2022-04-25 20:46:32
 * @LastEditTime: 2022-04-25 21:00:26
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/06.cpp
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//1.双指针
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        while (head){
            ans.emplace_back(head->val);
            head = head->next;
        }
        int l=0,r=ans.size()-1;
        while(l<r){
            swap(ans[l], ans[r]);
            ++l;
            --r;
        }
        return ans;
    }
};
//2.用栈
//3.递归
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
       if(!head){
           return {};
       }
       vector<int> ans = reversePrint(head->next);
       ans.emplace_back(head->val);
       return ans;
    }
};


