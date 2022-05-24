/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-17 22:38:09
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-18 18:13:39
 * @FilePath: /.leetcode/链表/426.二叉搜索树与双向链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return NULL;
        dfs(root);
        //首尾连接，成环
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node *pre, *head;
    void dfs(Node* cur){
        //中序遍历套路
        if (cur==nullptr)return;
        dfs(cur->left);
        //创建、延长链表
        if(pre!=nullptr)
            pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;//更新
        dfs(cur->right);
    }
};