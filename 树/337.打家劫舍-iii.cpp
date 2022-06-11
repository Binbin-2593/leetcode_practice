/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-03 14:40:43
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-03 16:06:25
 * @FilePath: /.leetcode/树/337.打家劫舍-iii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
//理解错误，题目要求父子不能同时，这里使用的是相邻层不能同时
/*
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(root->val);

        queue<TreeNode *> q;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
            
        while(!q.empty()){
            int qz = q.size(),counts=0;
            while(qz--){
                TreeNode *temp=q.front();
                q.pop();
                counts+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            dp.push_back(max(dp.back(), dp[dp.size() - 2] + counts));
        }
        return dp.back();
    }
};*/
class Solution {
    unordered_map<TreeNode *, int> Y, N;

public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(Y[root], N[root]);
    }
    void dfs(TreeNode* node){
        if(!node)
            return;
        dfs(node->left);
        dfs(node->right);
        Y[node] = node->val + N[node->left] + N[node->right];
        N[node] = max(Y[node->left], N[node->left]) + max(Y[node->right],N[node->right]);
    }
};
// @lc code=end

