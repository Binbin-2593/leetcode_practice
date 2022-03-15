/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       //m*n的二维矩阵，则，行：m==matrix.size() 列：n==matrix[i].size()
       int m=matrix.size();
       if(m==0) return false;
       int n=matrix[0].size();
       int i = 0, j = n - 1;
       while(i<m&&j>=0){
           if(matrix[i][j]==target) 
                return true;
           else if(matrix[i][j]>target)
                --j;
            else
                ++i;
                
       }
       return false;
    }
};
// @lc code=end

