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
        dfs(root, ans,0);
        return ans;
    }
    void dfs(TreeNode *root, vector<int> &ans,int depth){
        if(!root)return;
        if(depth==ans.size()){//这就实现了一层只取一个
            ans.push_back(root->val); 
        }
        ++depth;
        dfs(root->right,ans, depth);
        dfs(root->left,ans ,depth);
    }
};
// @lc code=end

