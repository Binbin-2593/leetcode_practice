/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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


//本来是一个有序序列，交换其中两个数，有两种交换可能
//1.相邻两个交换、2.非相邻两个交换
//再遍历一遍可分别出现一次乱序or两次乱序
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *mistake1=nullptr,*mistake2=nullptr,*prev=nullptr;
        inorder(root, mistake1, mistake2, prev);

        if(mistake1 && mistake2){
            int temp = mistake1->val;
            mistake1->val=mistake2->val;
            mistake2->val = temp;
        }
    }
    //辅助函数：将乱序处遍历出来
    void inorder(TreeNode*root,TreeNode*& mistake1,TreeNode*& mistake2,TreeNode*& prev){
        if(!root) return;
        if(root->left)
            inorder(root->left,mistake1,mistake2,prev);
    //遍历使用树的遍历，函数处理区使用双指针思想
        if(prev&&prev->val>root->val){
            if(!mistake1){
                mistake1 = prev;
                mistake2 = root;
            }
            else{
                mistake2 = root;
            }
        }
        prev = root;

        if(root->right)
            inorder(root->right, mistake1, mistake2, prev);

    }
};
// @lc code=end

