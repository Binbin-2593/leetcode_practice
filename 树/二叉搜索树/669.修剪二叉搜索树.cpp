/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-14 18:23:45
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-27 16:07:36
 * @FilePath: /.leetcode/树/二叉搜索树/669.修剪二叉搜索树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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

//解答二叉树问题，结合其大小结构特点
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;

        if(root->val>high)
            return trimBST(root->left, low, high);
        if(root->val<low)
            return trimBST(root->right, low, high);

        root->left = trimBST(root->left, low, high);
        root->right=trimBST(root->right,low, high);

        return root;
    }

};
//默写1
class Solution{
public:
    TreeNode* trimBST(TreeNode* root,int low,int high){
        if(!root)
            return root;
        if(root->val>high){
            return trimBST(root->left,low,high);
        }
        if(root->val<low){
            return trimBST(root->right,low,high);
        }
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
// @lc code=end
