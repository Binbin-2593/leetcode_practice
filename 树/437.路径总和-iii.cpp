/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-07 12:43:26
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-26 16:27:52
 * @FilePath: /.leetcode/树/437.路径总和-iii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
//默写1
class Solution{
public:
    int pathSum(TreeNode* root,int targetsum){
        if (root==nullptr)
            return 0;
        //前序dfs
        int ret = rootsum(root, targetsum);
        ret += pathSum(root->left, targetsum);
        ret += pathSum(root->right,targetsum);

        return ret;
    }
    int rootsum(TreeNode* root,int target){
        if (root==nullptr)return 0;
        int ret = 0;
        if (root->val == target){
            ++ret;
        }
        ret += rootsum(root->left, target - root->val);
        ret += rootsum(root->right, target - root->val);
        return ret;
    }
};
// @lc code=end
