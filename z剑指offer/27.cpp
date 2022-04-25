/*
 * @Author: your name
 * @Date: 2022-04-19 15:28:45
 * @LastEditTime: 2022-04-19 16:34:36
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/27.cpp
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return root;
 
        TreeNode*left = mirrorTree(root->left);
        TreeNode*right =mirrorTree (root->right);
        root->left=right;
        root->right = left;
        return root;
    }
};

/*此种方法是错误的
    //1.不要在递归函数中创建对象，容易stack-overflow
    //2.写递归函数一定处理结果的“连续性”
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode Root(root->val);
        Root.left = mirrorTree(root->right);
        Root.right = mirrorTree(root->left);
        return &Root;
    }
};
*/

//stack-overflow
/*
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        
        TreeNode* Root=root;
        return mirrorTree( Root,root);
    }
    TreeNode* mirrorTree(TreeNode*& Root,TreeNode*root){
        if (root == nullptr) {
            return nullptr;
        }
        Root->left=mirrorTree(Root,root->right);
        Root->right=mirrorTree(Root,root->left);
        return Root;
    }
};
*/