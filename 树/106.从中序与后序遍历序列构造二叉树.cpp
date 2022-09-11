/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-11 18:00:51
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 19:54:04
 * @FilePath: /.leetcode/树/106.从中序与后序遍历序列构造二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n==0)
            return nullptr;

        unordered_map<int,int>hash;
        for (int i = 0; i < n;++i){
            hash.emplace(inorder[i], i);
        }
        return helper(hash, postorder,0,n-1,n-1);
    }
    TreeNode* helper(unordered_map<int,int>&hash,vector<int>&postorder, int b, int e, int s){
        if(b>e)return nullptr;
        int pos = hash[postorder[s]],rightlen=e-pos;
        TreeNode *node = new TreeNode(postorder[s]);
        node->left = helper(hash,postorder,b,pos-1,s-rightlen-1);
        node->right = helper(hash, postorder, pos+1, e, s - 1);
        return node;
    }
};
// @lc code=end

