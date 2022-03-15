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
// @lc code=end

