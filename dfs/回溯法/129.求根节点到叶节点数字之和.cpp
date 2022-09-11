/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-17 16:47:33
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-17 16:48:02
 * @FilePath: /.leetcode/dfs/回溯法/129.求根节点到叶节点数字之和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sum=0,tmp=0;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return sum;
    }
    void dfs(TreeNode*root){
        if(!root)return;
        if(!root->left&&!root->right){
            sum+=tmp*10+root->val;
            return;
        }
        tmp=tmp*10+root->val;
        dfs(root->left);
        dfs(root->right);
        tmp/=10;
    }
};
// @lc code=end

