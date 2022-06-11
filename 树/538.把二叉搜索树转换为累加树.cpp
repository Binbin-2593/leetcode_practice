/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-03 13:30:39
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-03 14:08:02
 * @FilePath: /.leetcode/树/538.把二叉搜索树转换为累加树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
//树+dfs+前缀和
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root)return nullptr;
        int curr = 0;
        dfs(root, curr);
        return root;
    }
    void dfs(TreeNode* root,int &curr){
        if(!root)
            return;
        dfs(root->right, curr);
        root->val += curr;
        curr = root->val;
        dfs(root->left, curr);
    }
};
// @lc code=end

