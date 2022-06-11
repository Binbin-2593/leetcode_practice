/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-30 14:00:26
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-30 14:23:52
 * @FilePath: /.leetcode/树/235.二叉搜索树的最近公共祖先.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
//递归
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if(!root)return NULL;
//        if(root==p||root==q)
//            return root;
//        TreeNode *left = lowestCommonAncestor(root->left, p, q);
//        TreeNode *right = lowestCommonAncestor(root->right, p, q);
//        if(!left)return right;
//        if(!right)return left;
//        if(right&&left)
//            return root;
//         return nullptr;
//     }
// };
//根据二叉搜索树的性质 迭代遍历
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       while(1){
        //    if(root->val<p->val&&root->val>q->val||root->val>p->val&&root->val<q->val||root==p||root==q){
            //   &&优先级高于||
        //        return root;
        //    }else if(root->val<q->val&&root->val<p->val){
        //        root=root->right;
        //    }else if(root->val>q->val&&root->val>p->val){
        //        root=root->left;
        //    }
        if(root->val<q->val&&root->val<p->val){
            root=root->right; 
        }else if(root->val>q->val&&root->val>p->val){
            root=root->left;
        }else{
            return root;
        }
       }
    }
};
// @lc code=end

