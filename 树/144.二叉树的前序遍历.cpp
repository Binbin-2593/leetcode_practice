/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-14 16:13:45
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-27 16:33:40
 * @FilePath: /.leetcode/树/144.二叉树的前序遍历.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> out;
        if(root == nullptr) return out;
        stack<TreeNode *> s;
        s.push(root);
        
//使用stack要捋清的是，什么时候push、top、pop
//（一般是初始push一个，然后while，top后pop（成对使用），然后push）
        while(!s.empty()){
            TreeNode *node = s.top();
            s.pop();
            out.push_back(node->val);
//注意这里stack的先进后出
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);

        }
        return out;
    }
};
//默写1
class Solution {
public:
   vector<int> preorderTraversal(TreeNode* root){
       vector<int> ans;
       if(!root)
           return ans;
       stack<TreeNode *> s;
       s.push(root);
       while(!s.empty()){
           TreeNode *node = s.top();
           s.pop();
           ans.push_back(node->val);
           
           if(node->right){
               s.emplace(node->right);
           }
           if(node->left){
               s.emplace(node->left);
           }
       }
       return ans;
   }
};
//非递归
//http://www.javashuo.com/article/p-acckkhic-kv.html
//前序
void PreOrderNonRecursive(TreeNode* root) {
    if (root == NULL)
        return;
    stack<TreeNode*> sta;
    sta.push(root);
    while (!sta.empty()) {
        TreeNode* pNode = sta.top();
        cout << pNode->val << endl;
        sta.pop();
        if (pNode->right != NULL)
            sta.push(pNode->right);
        if (pNode->left != NULL)
            sta.push(pNode->left);
    }
}
//中序
void InOrderNonRecursive(TreeNode* root) {
    if (root == NULL)
        return;
    stack<TreeNode*> sta;
    sta.push(root);
    TreeNode* pNode = root;
    while (!sta.empty()) {
        while (pNode != NULL&&pNode->left != NULL) {
            pNode = pNode->left;
            sta.push(pNode);
        }
        pNode = sta.top();
        cout << pNode->val << endl;
        sta.pop();
        if (pNode->right != NULL) {
            sta.push(pNode->right);
            pNode = pNode->right;
        }else{
            pNode = NULL;
        }    
    }
}
//后序
void PostOrderNonRecursive(TreeNode* root) {
    if (root == NULL)
        return;
    stack<TreeNode*> sta;
    TreeNode* curNode = root;
    TreeNode* preNode = NULL;
    sta.push(root);
    while (!sta.empty()) {
        curNode = sta.top();
        if ((curNode->left == NULL&&curNode->right == NULL) || (preNode != NULL && (preNode == curNode->left || preNode == curNode->right))) {
            cout << curNode->val << endl;
            sta.pop();
            preNode = curNode;
        }else {
            if (curNode->right != NULL)
                sta.push(curNode->right);
            if (curNode->left != NULL)
                sta.push(curNode->left);
        }
    }
}
//递归
//前序
void PreOrder(TreeNode* root){
    if(!root)
        return;
    cout << root->val << endl;
    PreOrder(root->left);
    preOrder(root->right);
}
//中序
void InOrder(TreeNode*root){
    if(!root)return;
    InOrder(root->left);
    cout << root->val << endl;
    InOrder(root->right);
}
//后序
void PostOrder(TreeNode* root){
    if(!root)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << endl;
}
// @lc code=end
