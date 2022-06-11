/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-28 16:09:07
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-30 14:34:01
 * @FilePath: /.leetcode/树/236.二叉树的最近公共祖先.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *ans=nullptr;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
        dfs(root, p, q);
        return ans;
    }
    //本问题场景要求的结果偏向于树更深的位置，所以用后序dfs，其实使用的是回溯过程中“进展”到结果
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q){
        if (root==nullptr)return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if((lson&&rson)||((root==p||root==q)&&(lson||rson))){
            ans = root;
        }
        return lson || rson || (root == p || root == q);
    }
    // void dfs(TreeNode *root, TreeNode*p,TreeNode *q){
    //     if(!root)
    //         return;
    //     if(root==p||root==q){
    //         ans = root;
    //     }
    //     dfs(root->right, p, q);
        
    //     dfs(root->right.p, q);
    // }
};

// class Solution {
// public:
//     TreeNode *lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
//         if (root==nullptr)return nullptr;
//         if(root==p||root==q)
//             return root;
//         TreeNode *left = lowestCommonAncestor(root->left, p, q);
//         TreeNode *right = lowestCommonAncestor(root->right, p, q);
//         if(left==nullptr)return right;
//         if(right==nullptr)return left;
//         if(left&&right)
//             return root;
//         return nullptr;
//     }
// };
// @lc code=end
