/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-28 15:40:49
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-28 15:56:27
 * @FilePath: /.leetcode/树/二叉搜索树/O33.二叉搜索树的后序遍历.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size() - 1);
    }
    //假设是
    bool helper(vector<int>&postorder,int l,int r){
        if(l>=r)return true;
        int p = l;
        while(postorder[p]<postorder[r])
            ++p;
        int m = p;
        while(postorder[p]>postorder[r]){//前提没有值相等
            ++p;
        }
        return p == r && helper(postorder, l, m - 1) && helper(postorder, m, r - 1);
    }
};