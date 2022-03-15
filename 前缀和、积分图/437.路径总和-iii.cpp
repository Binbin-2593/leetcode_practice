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
class Solution {
public:
    unordered_map<long long, int> hashmap;
    int pathSum(TreeNode *root, int targetSum){
        //键值表示前缀和的数值，实值表示次前缀和值的个数
        hashmap[0] = 1;
        return dfs(root, 0, targetSum);
    }
    int dfs(TreeNode*root,long long curr,int targetSum){
        if(!root)return 0;
        int ret = 0;
        curr += root->val;
        if(hashmap.count(curr-targetSum))
            ret = hashmap[curr - targetSum];//某个键值对应的实值不一定为一

        hashmap[curr]++;
        //下面是在本函数总调用的两个函数，函数（1）、函数（2）是分别的两个作用域，
        //其中进行的各种操作不会影响到外界，外界只能看到它的return结果
        //所以不如在此之前curr==5，下面调用的两个函数传入的都是5
        ret += dfs(root->left, curr, targetSum);//(1)
        ret += dfs(root->right, curr, targetSum);//(2)
        hashmap[curr]--;//此句可由递归到最深处时的现实情况得出（dfs要回溯，结合前缀和注意这点）
        //所以用递归解决问题，不仅要找出终止条件，还要把最深处也是最开始执行的递归函数脑子里跑一遍

        return ret;
    }
};
// @lc code=end

