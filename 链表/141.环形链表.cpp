/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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

//外层循环遍历所有结点；内层一每个结点为基础遍历对比
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // int pos(0);
        // vector<ListNode *> lnp;//由于链表不支持随机访问的特殊性，如需后续速记访问，将结点保存
        // lnp.push_back(head);
        // if(!head||(head&&!head->next)) {
        //     pos = -1;
        // return false;
        // }

        // ListNode *curr = head->next;
        // while (curr)
        // {
        //     for(auto &i:lnp){
        //         //if(i->val==curr->val&&i->next==curr->next)
        //         if(i==curr)//注意指针本身也是变量，指向变量“没动”的话指针就是等的
        //             return true;
        //     }
        //     lnp.push_back(curr);
        //     curr= curr->next;
        //     ++pos;
        // }
        // pos = -1;
        // return false;

        //快慢指针
        // int pos(0); 
        // if(!head||head&&!head->next){
        //     pos = -1;
        //     return false;
        // }
        // //快慢指针可同步去head或者起步就一前一后，要看“短”链表的特殊情况
        // ListNode *slow=head;
        // ListNode *fast = head->next;
        // while(slow!=fast){
        //     if(!fast||!fast->next)return false;//因为后面要进行fast->next,所以要判断!fast,fast->next->next同理
        //     slow=slow->next;
        //     fast=fast->next->next;
        
        //     //++pos;
        // }
        // return true;

        if(head==nullptr)//用head==nullptr，相对于!head要省空间
            return false;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast->next){//存在判断，循环语句也有判断选择的含义
            slow = slow->next;		    // 慢指针每次走一步
            fast = fast->next->next;	// 快指针每次走两步
            if(slow == fast)
                return true;
        }
        return false;

    }
};
// @lc code=end

