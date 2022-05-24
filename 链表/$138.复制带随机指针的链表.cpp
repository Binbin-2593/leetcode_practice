/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-17 21:45:16
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-18 17:54:57
 * @FilePath: /.leetcode/链表/138.复制带随机指针的链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//回溯 + 哈希表
class Solution {
    unordered_map<Node *, Node *> hash;
    //键值：旧值；实值：新值
    //其实本题用hash的原因是：根据本题描述情况某个“元素”在当前时刻被访问到，之后某个时刻还要被访问到（回溯）
    //这就体现了hash的功能1.记录2.随机访问
    //本题也引出了回溯的含义：访问过的，在未来的某个时刻还要”回头“再次访问
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        
        if(!hash.count(head)){
            // Node temp (head->val);
            // Node* newhead = &temp;
            //注意上面这种不可用的原因是，temp都在自己的函数栈中，对外不可见
            Node* newhead = new Node(head->val);
            hash[head]=newhead;
            newhead->next = copyRandomList(head->next);
            newhead->random = copyRandomList(head->random);
            //delete newhead;//不能删
        }
        return hash[head];
    }
};
// @lc code=end

