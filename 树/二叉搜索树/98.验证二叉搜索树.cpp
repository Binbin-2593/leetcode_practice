/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-03 14:10:57
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-03 14:39:43
 * @FilePath: /.leetcode/树/二叉搜索树/98.验证二叉搜索树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if (!root->left&&!root->right)return true;
        long prev = LONG_MIN;
        //long long prev =(long long)INT_MIN - 1;
        bool flag = true;
        dfs(root, prev,flag);
        return flag;
        // return dfs(root, prev);
    }
    void dfs(TreeNode* root,long &prev,bool&flag){
        if(!root)return ;
        dfs(root->left, prev,flag);
        if (prev >=root->val){
            flag= false;
            return;
        }else{
            prev = root->val;
        }
        dfs(root->right, prev,flag);
    }
    // bool dfs(TreeNode*root,long &prev){
    //     if(!root)return true;
    //     bool l=dfs(root->left, prev);
    //     if (prev >=root->val){
    //         return false;
    //     }else{
    //         prev = root->val;
    //     }
    //     bool r=dfs(root->right, prev);
    //     return l&&r;
    // }
};
// @lc code=end

