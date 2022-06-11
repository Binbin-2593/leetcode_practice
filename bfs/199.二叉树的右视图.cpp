/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-08 20:44:33
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-08 21:05:19
 * @FilePath: /.leetcode/dfs/树/199.二叉树的右视图.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int qz = q.size();
            while(qz--){
                TreeNode *node = q.front();
                q.pop();
                if(qz==0){
                    ans.push_back(node->val);
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

