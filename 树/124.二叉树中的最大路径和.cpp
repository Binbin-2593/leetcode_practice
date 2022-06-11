/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-03 16:16:57
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-03 16:29:07
 * @FilePath: /.leetcode/124.二叉树中的最大路径和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxSum=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
    //以node为端点的路径的和
    int dfs(TreeNode*node){
        if(!node)return 0;
        int l = max(dfs(node->left), 0);
        int r = max(dfs(node->right), 0);

        maxSum = max(maxSum, node->val + l + r);
        return node->val + max(l, r);
    }
};
// @lc code=end

