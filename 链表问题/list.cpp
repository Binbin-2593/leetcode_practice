/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-13 12:48:31
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-13 13:12:55
 * @FilePath: /.leetcode/链表问题/list.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



//1.反转链表
ListNode* reverse(ListNode* head){
    if(!head||!head->next)return haed;

    ListNode *newHead = reverse(head->next);
    head->next->next = head;
    head->next=nullptr;
    return newHead;
}

pair<ListNode*,ListNode*> reverse2(ListNode* head,ListNode* tail){
    ListNode *prev = tail, *cur = head, *next = nullptr;
    while(prev != tail){
        next = head->next;
        head->next=prev;
        prev = cur;
        cur = next;
    }
    return {tail, head};
}

//2.合并两个有序链表
ListNode* merge(ListNode*l1,ListNode*l2){
    if(!l1){
        return l2;
    }else if(!l2){
        return l1;
    }else if(l1->val<l2->val){
        l1->next = merge(l1->next, l2);
        return l1;
    }else{
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

//3.链表找中点，平分两段
ListNode* midNode(ListNode* head){
    ListNode *slow = head, *fast = head;
    while(fast->next&&fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* l2=slow->next;
slow->next = nullptr;
ListNode *l1 = head;

//4.找到链表倒数第n点
ListNode* retNNode(ListNode* head,int n){
    ListNode *dummy = new ListNode(0, head),*prev=dummy,*fast=head;
    while(n--){
        fast = fast->next;
    }
    while(fast){
        fast = fast->next;
        prev = prev->next;
    }
    return Nnode=prev->next;
}
//5.链表有环
bool cycleList(ListNode *head){
    if(!head)return false;
    ListNode*slow = head,*fast=head;
    do{
        if(!fast->next||!fast->next->next){
            return false;
        }
        slow=slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    return true;
}

