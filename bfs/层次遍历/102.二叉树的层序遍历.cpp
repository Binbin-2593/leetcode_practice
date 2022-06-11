/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-02 23:12:09
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-02 23:19:10
 * @FilePath: /.leetcode/bfs/102.二叉树的层序遍历.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qz=q.size();
            vector<int> temp;
            while(qz--){
                TreeNode *node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};
// @lc code=end

