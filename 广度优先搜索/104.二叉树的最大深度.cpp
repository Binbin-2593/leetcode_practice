/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
//思想来自于树的层序遍历，
//不同在这里每次pop出上一层的所有节点，push进下一层的所有节点，
//这样就突出了层数
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz >0){//内循环实现把每层节点都遍历一遍
                TreeNode *node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right) 
                    q.push(node->right);
                sz -= 1;
            }
            ans += 1;
        }
        return ans;
    }
};
// @lc code=end

