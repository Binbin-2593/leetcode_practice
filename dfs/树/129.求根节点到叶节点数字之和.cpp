/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-08 21:47:06
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 15:31:54
 * @FilePath: /.leetcode/dfs/回溯法/129.求根节点到叶节点数字之和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    //递归过程中一层层前缀
    int dfs(TreeNode* root,int prevSum){
        if(!root)
            return 0;
        int sum = prevSum * 10 + root->val;
        if(!root->left&&!root->right){
            return sum;
        }else{
           return dfs(root->left, sum) + dfs(root->right, sum); 
        }    
    }
};
//此问题就是把树的每条路径遍历出来
//遍历的过程中累积数据
// @lc code=end

