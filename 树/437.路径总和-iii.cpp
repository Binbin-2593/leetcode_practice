/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
//递归思想
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        int ret = rootsum(root, targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
    }
    //辅助函数
    //以某节点起向下，和为target的路径
    int rootsum(TreeNode* root,int target){
        if (!root) return 0;
        int ret = 0;
        if (root->val==target)
            ++ret;
        ret+=rootsum(root->left,target-root->val);
        ret += rootsum(root->right, target - root->val);
        return ret;
    }//本题的思路是分两部分，1.答案中包含根节点和不包含根节点 2.答案中不包含根节点

    //处理方法：step1:包含根节点，立足于根节点递归整个树（辅函数）2.在树中把每个节点作为“root”看待，再递归
};
// @lc code=end

