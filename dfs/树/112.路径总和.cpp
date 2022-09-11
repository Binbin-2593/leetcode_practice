/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-11 15:39:44
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 16:21:57
 * @FilePath: /.leetcode/dfs/树/112.路径总和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        bool flag = false;
        dfs(root, targetSum, flag);
        return flag;
    }
    void dfs(TreeNode*root,int targetSum,bool &flag){
        if(!root) return;
        if(!root->left&&!root->right){
            if(root->val==targetSum){
                flag=true;
            }
            return;
        }else{//targetSum传引用是错误的，因为经过dfs(left)后的targetSum已经不是targetSum -= root->val了
            targetSum -= root->val;
            dfs(root->left, targetSum, flag);
            dfs(root->right, targetSum, flag);
        }
    }
};
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if(!root)
//             return false;
//         if(!root->left&&!root->right){
//             return root->val==targetSum;
//         }
//         return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
//     }
// };
// @lc code=end

