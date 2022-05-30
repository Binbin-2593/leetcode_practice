/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-11 09:59:06
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-27 17:30:37
 * @FilePath: /.leetcode/树/1110.删点成林.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       vector<TreeNode*> forest;
       //方便查找，将给的vector中的“坏值”，存到hash_set中
       unordered_set<int> dict(to_delete.begin(), to_delete.end());
       //后续dfs因为root是后面处理，所以根据递归函数实际情况在主函数中要对输入树的root单独处理
       root = helper(root,dict,forest);
       if(root)
           forest.push_back(root);
       return forest;
    }
    //树问题中递归函数的返回值往往跟最终函数的返回值不一样
    //因为递归函数的返回值往往要在函数内部使用
    TreeNode* helper(TreeNode* root,unordered_set<int>&dict,vector<TreeNode*>& forest){
        if(!root)
            return root;

        root->left = helper(root->left, dict, forest);
        root->right = helper(root->right, dict, forest);

        if(dict.count(root->val)){
            //这里有一点很重要的细节，由于是后续遍历，所以在处理根节点之前，
            //左右子树的根节点已经被此递归算法“洗礼”过了，已经不是之前”单纯“节点了
            //所以才有下面这些
            //用前中后dfs时注意
            if(root->left)
                forest.push_back(root->left);
            if(root->right)
                forest.push_back(root->right);
            root=nullptr;
        }

        return root;
    }
};
//默写1
class Solution {
   vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
       vector<TreeNode*> ans;
       unordered_set<int> hash(to_delete.begin(),to_delete.end());

       root=help(root, ans, hash);
       if(!root){
           ans.emplace_back(root);
       }
       return ans;
   }
   TreeNode* help(TreeNode* root, vector<TreeNode* >&ans,unordered_set<int>&hash){
       if(root==nullptr)
           return root;
       root->left = help(root->left, ans, hash);
       root->right = help(root->right, ans, hash);
       if(hash.count(root->val)){
           if (root->left){
               ans.emplace_back(root->left);
           }
           if(root->right){
               ans.emplace_back(root->right);
           }
           root = NULL;
       }
       return root;
   }
};
// @lc code=end
