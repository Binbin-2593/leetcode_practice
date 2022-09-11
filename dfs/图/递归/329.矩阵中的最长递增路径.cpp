/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-11 21:05:28
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 22:42:28
 * @FilePath: /.leetcode/dfs/329.矩阵中的最长递增路径.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
    vector<int> d = {-1,0,1,0,-1};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        if(m==0||n==0)
            return 0;
        int ans = 0;
        vector<vector<int>> memo(m, vector<int>(n));
        for (int i = 0; i < m; ++i){
            for (int j = 0;j<n;++j){
                ans = max(ans, dfs(matrix, memo, i, j));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>&matrix,vector<vector<int>>&memo,int r,int c){
        if(memo[r][c]!=0){
            return memo[r][c];
        }
        ++memo[r][c];
        int x, y;
        for (int i = 0; i < 4; ++i){
            x = r + d[i], y = c + d[i + 1];
            if(x>=0&&x<matrix.size()&&y>=0&&y<matrix[0].size()&&matrix[x][y]>matrix[r][c]){
                memo[r][c] = max(memo[r][c],dfs(matrix,memo,x,y)+1);
            }
        }
        return memo[r][c];
    }
};
// @lc code=end

