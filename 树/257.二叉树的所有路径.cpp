/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-30 10:49:59
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-30 10:54:35
 * @FilePath: /.leetcode/257.二叉树的所有路径.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%Ai
 */
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root)
            return ans;
        if(!root->left&&!root->right){
            ans.emplace_back(to_string(root->val));
            return ans;
        }
        vector<string> ansL = binaryTreePaths(root->left);
        vector<string> ansR = binaryTreePaths(root->right);
        for(auto &s : ansL){
            ans.emplace_back(to_string(root->val) + "->" + s);
        }
        for(auto &s : ansR){
            ans.emplace_back(to_string(root->val) + "->" + s);
        }
        return ans;
    }
};
// @lc code=end

