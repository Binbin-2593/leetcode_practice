/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-07 10:43:57
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-02 21:28:05
 * @FilePath: /.leetcode/树/110.平衡二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;
    }
    int helper(TreeNode* root){
        if (!root){
            return 0;
        }
        int left = helper(root->left), right = helper(root->right);
        if(left == -1||right == -1||abs(left-right)>1) return -1;
        return 1 + max(left, right);
    }
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if(isBalanced(root->left)&&isBalanced(root->right)&&abs(helper(root->left)-helper(root->right))<=1){
            return true;
        }else{
            return false;
        }  
    }
    int helper(TreeNode*root){
        return root? max(helper(root->left),helper(root->right))+1:0;
    }
};

//默写1
class Solution {
public:
    bool isBalanced(TreeNode*root){
        return helper(root) != -1;
    }

    int helper(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left = helper(root->left), right = helper(root->right);
        if(left==-1||right==-1||abs(left-right)>1)
            return -1;
        return 1 + max(left, right);
    }
};
// @lc code=end
