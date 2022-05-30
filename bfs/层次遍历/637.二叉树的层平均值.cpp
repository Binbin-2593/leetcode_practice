/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-11 11:29:14
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-26 17:51:13
 * @FilePath: /.leetcode/bfs/层次遍历/637.二叉树的层平均值.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            double sum = 0;
            for (int i = 0; i < count;++i){
                TreeNode *node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(sum / count);
        }
        return ans;
    }
};
//默写1
class Solution{
public:
    vector<double> averageOfLevels(TreeNode* root){
        vector<double> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qz = q.size();
            double sum = 0;
            for (int i = 0; i<qz;++i){
                TreeNode *node=q.top();
                q.pop();
                sum += node->val;
                if(node->left){
                    q.emplace(node->left);
                }
                if(node->right){
                    q.emplace(node->right);
                }
            }
            ans.push_back(sum / qz);
        }
        return ans;
    }
};
// @lc code=end
