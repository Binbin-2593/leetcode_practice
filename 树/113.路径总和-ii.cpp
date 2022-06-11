/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-30 15:20:47
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-30 16:26:57
 * @FilePath: /.leetcode/树/113.路径总和-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, targetSum, ans,temp);
        return ans;
    }
    void dfs(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int>&path){
        //vector<int> temp;
        // if (!root || root->val > targetSum)
        //     return;
        if (!root)
            return;
        //回溯应该在函数的最后一句
        // if (root->val<targetSum){
        //     temp.push_back(root->val);
        //     helper(root->left, targetSum - root->val, ans,temp);
        //     helper(root->right, targetSum - root->val, ans,temp);
        //     temp.pop_back();
        // }else{
        //     temp.push_back(root->val); 
        //     ans.emplace_back(temp);
        // }

        path.push_back(root->val);
        if(targetSum==root->val&&!root->left&&!root->right){//判断条件后面两个依据题目要求到叶节点
            ans.emplace_back(path);
        }else{
            dfs(root->left, targetSum-root->val, ans, path);
            dfs(root->right, targetSum-root->val, ans, path);
        }
        path.pop_back();
    }
};
// @lc code=end

