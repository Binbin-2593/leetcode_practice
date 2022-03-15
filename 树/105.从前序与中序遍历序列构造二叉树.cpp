/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        //用hashmap，因为要根据值随机索引对应的下标值
        unordered_map<int, int> inorderhash;
        for (int i = 0;i<preorder.size();++i){
            inorderhash[inorder[i]]=i;
        }
        return findRoot(preorder, inorderhash, 0, preorder.size() - 1, 0);
    }

    //辅助函数
    TreeNode* findRoot(vector<int>& preorder,unordered_map<int,int>&inorderhash,int s0,int e0,int s1){
        if(s0>e0)
           return nullptr;
        int mid = preorder[s1],index=inorderhash[mid],leftLen=index-s0-1;
        TreeNode *node = new TreeNode(mid);
        node->left = findRoot(preorder,inorderhash,s0,index-1,s1+1);
        node->right = findRoot(preorder,inorderhash,index+1,e0,s1+2+leftLen);
        return node;
    }
};
// @lc code=end

