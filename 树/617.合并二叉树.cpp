/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-02 22:51:54
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-02 23:09:44
 * @FilePath: /.leetcode/树/617.合并二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)return root2;
        if(!root2)return root1;

        root1->val+=root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
        // TreeNode *ans = new TreeNode(root1->val + root2->val);
        // ans->left = mergeTrees(root1->left, root2->left);
        // ans->right = mergeTrees(root1->right,root2->right);
        // return ans;
    }
};
// @lc code=end

