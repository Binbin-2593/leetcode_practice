/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-28 15:05:51
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-28 15:10:08
 * @FilePath: /.leetcode/树/判断子树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B)return false;
        vector<TreeNode*> rootA;
        inorder(A,rootA,B);
        bool flag=false;
        if(rootA.size()==0) return false;
        for(auto&t:rootA){
            flag=isSameTree(t,B);
            if(flag)return flag;
        }
        return flag;

    }
    bool isSameTree(TreeNode*p,TreeNode*q){
        if(!p&&q)return false;
        if(!q)return true;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    void inorder(TreeNode*root,vector<TreeNode*>&v,TreeNode*&B){
        if(!root)return ;
        inorder(root->left,v,B);
        if(root->val==B->val){
            v.push_back(root);
        }
        inorder(root->right,v,B);
    }
    
};
//法2
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
     // 特判：树 A 为空 或 树 B 为空 时，直接返回 false
     if (A == nullptr || B == nullptr) return false;
    /* 
    1. 判断 B 是 A 的子树，recur(A, B);
    2. 判断 B 是 A 的左子树，isSubisSubStructure(A->left, B);
    3. 判断 B 是 A 的右子树，isSubisSubStructure(A->right, B);
    */
    return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool recur(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true;
        if (A == nullptr || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};
