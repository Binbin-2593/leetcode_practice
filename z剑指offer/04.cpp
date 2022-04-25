/*
 * @Author: your name
 * @Date: 2022-04-21 19:51:13
 * @LastEditTime: 2022-04-21 21:39:05
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/04.cpp
 */
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        for (int i = 0;i<matrix.size();++i){
            if(erfen(matrix[i], target)){
                return true;
            }
        }
        return false;
    }
    bool erfen(vector<int>& v,int target){
        int l=0,r=v.size()-1,m;
        while(l<=r){
            m = l + (r - l) / 2;
            if(v[m]==target){
                return true;
            }else if(v[m]<target){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return false;
    }
};
/*不好实现
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() - 1;
        if(n==0) return false;
        int l = 0, m = matrix[0].size() - 1, r = n > m ? m : n;
        return digui(matrix, 0, n,0,r, target);
    }
    //递归
    bool digui(vector<vector<int>>&matrix,int row1,int row2,int col1,int col2,int target){
        if(row1==row2){
            return erfen(matrix[row1], target);
        }
        if(col1==col2){
            return erfen(matrix[][], target); 
        }
        while(l<=r){
            mid = l + (r - l) / 2;
            if(matrix[mid] == target){
                return true;
            }else if(matrix[mid]>target){
                
            }
        }
    }
    bool erfen(vector<int>& v,int target){
        int l=0,r=v.size()-1,m;
        while(l<=r){
            m = l + (r - l) / 2;
            if(v[m]==target){
                return true;
            }else if(v[m]<target){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return false;
    }
};*/