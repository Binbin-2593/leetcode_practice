/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-23 23:59:47
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-24 00:08:58
 * @FilePath: /.leetcode/树/102.二叉树的层序遍历.cpp
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
//BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ret;
        queue<TreeNode * > q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            ret.push_back({});
            while (sz--){
                TreeNode*root=q.front();
                q.pop();
                ret.back().push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return ret;
    }
};
//DFS
class Solution {
    vector<vector<int>> ret;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
    void dfs(TreeNode* root,int level){
        if(!root)
            return;
        if(ret.size()==level){
            ret.push_back({});
        }
        ret[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};
// @lc code=end

