/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-14 16:50:19
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-27 17:00:27
 * @FilePath: /.leetcode/树/二叉搜索树/99.恢复二叉搜索树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
// class Solution {
// public:
//     void recoverTree(TreeNode* root) {
//         TreeNode *mistake1=nullptr,*mistake2=nullptr,*prev=nullptr;
//         inorder(root, mistake1, mistake2, prev);

//         if(mistake1 && mistake2){
//             // int temp = mistake1->val;
//             // mistake1->val=mistake2->val;
//             // mistake2->val = temp;
//             swap(mistake1->val, mistake2->val);
//         }
//     }
//     //辅助函数：将乱序处遍历出来
//     void inorder(TreeNode*root,TreeNode*& mistake1,TreeNode*& mistake2,TreeNode*& prev){
//         if(!root) return;
//         if(root->left)
//             inorder(root->left,mistake1,mistake2,prev);
//     //遍历使用树的遍历，函数处理区使用双指针思想
//         if(prev&&prev->val>root->val){
//             if(!mistake1){
//                 mistake1 = prev;
//                 mistake2 = root;
//             }
//             else{
//                 mistake2 = root;
//             }
//         }
//         prev = root;

//         if(root->right)
//             inorder(root->right, mistake1, mistake2, prev);

//     }
// };
//默写1
class Solution{
public:
    void recoverTree(TreeNode*root){
        TreeNode *mistake1=nullptr, *mistake2=nullptr, *prev=nullptr;

        inorder(root, mistake1,mistake2,prev);

        if(mistake1&&mistake2){
            swap(mistake1->val,mistake2->val);
        }
    }
    void inorder(TreeNode*root,TreeNode*&mistake1,TreeNode*&mistake2,TreeNode*&prev){
        if(!root)return;

        inorder(root->left, mistake1, mistake2, prev);

        if(prev&&prev->val>root->val){
            if(!mistake1){
                mistake1=prev;
                mistake2=root;
            }else{
                mistake2 = root;
            }
        }
        prev = root;
        
        inorder(root->right, mistake1, mistake2, prev);
    }
};
// @lc code=end
