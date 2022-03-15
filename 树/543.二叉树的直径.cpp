/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        //树的最长直径-->只要子树的最长直径（递归）
        int maxd = 0;
        help(root,maxd);
        return maxd;
    }
    int help(TreeNode* root ,int& diameter){
        //左子树最大长路径+右子树的最长路径
        if (root==nullptr)
            return 0;
        int l = help(root->left, diameter), r = help(root->right, diameter);
        diameter = max(l + r, diameter);//如果想在递归函数中一层层连续贯穿返回>一个变量，就要为函数加入引用形参
        //return的是左右子树最长路径
        return max(l, r) + 1;//递归本身可以通过return一直一层层连续贯穿返回一个变量
    }//本体思路
};
// @lc code=end

