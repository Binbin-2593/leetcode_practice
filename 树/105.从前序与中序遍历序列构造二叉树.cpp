/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-11 12:10:22
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-27 17:26:01
 * @FilePath: /.leetcode/树/105.从前序与中序遍历序列构造二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
//整个思路建立在，树是由递归生成的
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if(preorder.empty()) return nullptr;
//         //用hashmap，因为要根据值随机索引对应的下标值
//         unordered_map<int, int> inorderhash;
//         for (int i = 0;i<preorder.size();++i){
//             inorderhash[inorder[i]]=i;
//         }
//         return findRoot(preorder, inorderhash, 0, preorder.size() - 1, 0);
//     }

//     //辅助函数
//     TreeNode* findRoot(vector<int>& preorder,unordered_map<int,int>&inorderhash,int s0,int e0,int s1){
//         if(s0>e0)
//            return nullptr;
//         int mid = preorder[s1],index=inorderhash[mid],leftLen=index-s0;
//         TreeNode *node = new TreeNode(mid);
//         node->left = findRoot(preorder,inorderhash,s0,index-1,s1+1);
//         node->right = findRoot(preorder,inorderhash,index+1,e0,s1+1+leftLen);
//         return node;
//     }
// };

//默写1
class Solution {
public:
    TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder){
        int n = preorder.size();
        if (n==0)
            return NULL;

        unordered_map<int, int> hash;
        for (int i = 0;i<n;++i){
            //hash[inorder[i]]=i;
            hash.emplace(inorder[i], i);
        }
        return findRoot(preorder, hash, 0,n-1 , 0);
    }
    TreeNode* findRoot(vector<int> & preorder, unordered_map<int, int> & hash, int b, int e, int s){
        if(b>e)return nullptr;
        int index = hash[preorder[s]],leftLen=index-b;
        TreeNode *root = new TreeNode(preorder[s]);
        root->left = findRoot(preorder, hash, b, index - 1, s + 1);
        root->right = findRoot(preorder, hash, index + 1, e, s + leftLen + 1);
        return root;
    }
};
// @lc code=end
