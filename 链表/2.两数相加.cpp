/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //同时同步逐结点读取两链表，
        //int n=0;用于临时保存和
        //listnode* l1->data=istnode* l1->data+istnode* l2->data+n
        //遍历过程中，next=NULL，就补data=0的结点，直到两个链表的next都为空
       /* ListNode* p=l1;//遍历指针
        int n=0,sum=0;
        while(p||l2){
            if(!p)
                p=new ListNode();//错
            else if(!l2)
                l2=new ListNode();//错
                //尽量只从条件数据取数据信息使用，不要去修改原条件数据

            sum = p->val + l2->val + n;
            p->val = sum% 10;
            n = sum / 10;
            
            p = p->next;
            l2 = l2->next;
        }
        if(n){
           //p =new ListNode(1);//错，这里p就是个NULL，与链表已脱节
           ListNode * ans = l1;
            while(ans->next)
            {
                ans = ans->next;
            }
            ans->next = new ListNode(1);//这种利用指向最后一个结点的指针，把最后一个结点做“链接”
        }
        return l1;*///思路不错，由于链表末尾插值的错误思路，导致此思路无法实现

    //     ListNode* dummy = new ListNode();
    //     ListNode* r = dummy;
    //     int n(0);
    //     while (l1 || l2){
    //         if(!l1)
    //             l1->val = 0;//错：l1->val不是变量，为空时不能赋值
    //         if(!l2)
    //             l2->val = 0;

    //         r->next = new ListNode((l1->val + l2->val + n) % 10);
    //         n=(l1->val + l2->val + n) / 10;

    //         r=r->next;
    //         if(l1) l1=l1->next;
    
    //         if(l2) l2=l2->next;
            
    //     }
    //     if(n) r->next = new ListNode(1);
    //     return dummy->next;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 || l2) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            int total = x + y + carry;
            curr->next = new ListNode(total % 10);
             // bug 修复：视频中忘了移动 curr 指针了
            curr = curr->next;
            carry = total / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry != 0) curr->next = new ListNode(carry);
        return dummy->next;


    }
};
// @lc code=end

