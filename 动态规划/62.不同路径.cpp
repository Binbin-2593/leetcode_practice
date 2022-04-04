/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        //step1：确定状态
        vector<vector<int>> dp(m, vector<int>(n));
        //step2:初始化和边界条件
        for (int i = 0;i<m;++i)
            dp[i][0] = 1;
        for (int j = 0;j<n;++j)
            dp[0][j] = 1;

        //计算顺序、状态转移
        for (int i = 1;i<m;++i){
            for (int j = 1;j<n;++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        //return 要求的最终状态
        return dp[m-1][n-1];
    }
};
// @lc code=end

