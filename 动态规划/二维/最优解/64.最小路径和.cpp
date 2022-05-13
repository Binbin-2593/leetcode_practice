/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-05 21:23:25
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-06 10:04:12
 * @FilePath: /.leetcode/动态规划/二维/最优解/64.最小路径和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i){
            for (int j = 0;j<n;++j){
                if(i==0&&j==0){
                    dp[i][j] = grid[i][j];
                }else if(i==0){
                    dp[i][j] = dp[i][j - 1] + grid[i][j];//只有从左侧到达
                }else if(j==0){
                    dp[i][j] = dp[i - 1][j] + grid[i][j];//只有从上面达到
                }else{
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};*/
//最优：有初始条件、边界条件的思想
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i=1;i<m;++i){
            dp[i][0] = dp[i - 1][0] + grid[i][0];   
        }
        for (int j=1;j<n;++j){
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i){
            for (int j = 1;j<n;++j){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
//原地dp
/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; i++) grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; j++) grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};*/
// @lc code=end

