/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-18 18:22:38
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 17:59:15
 * @FilePath: /.leetcode/链表/114.二叉树展开为链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
//遍历出所有节点存储，再建立连接关系
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         vector<TreeNode *> l;
//         dfs(root, l);
//         for (int i = 1; i < l.size(); ++i){
//             TreeNode *prev = l.at(i - 1), *curr = l.at(i);//这里用at，因为可以返回引用
//             prev->left=nullptr;
//             prev->right = curr;
//         }
//     }
//     void dfs(TreeNode*root,vector<TreeNode*>&l){
//         if(root!=nullptr){
//             l.emplace_back(root);
//             dfs(root->left,l);
//             dfs(root->right, l);
//         }
//     }

// };
//遍历过程中创建
//与动用指针原地改变一个单链表同理
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left;
                auto predecessor = next;
                //将curr的左侧部分接到其右侧的最左下角
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};
//关于链式数据结构
    //指针赋值等式
        //等号左边有“->”，用中文“接上等号右边的部分”理解
        //等号左边无"->",用“指向等式右边的节点”理解
// @lc code=end

