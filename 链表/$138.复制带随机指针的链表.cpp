/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-17 21:45:16
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-13 14:47:31
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

public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return nullptr;
        if(!hash.count(head)){
            Node* newhead=new Node(head->val);
            hash[head] = newhead;
            newhead->next = copyRandomList(head->next);
            newhead->random = copyRandomList(head->random);
        }
        return hash[head];
    }
};
// @lc code=end

