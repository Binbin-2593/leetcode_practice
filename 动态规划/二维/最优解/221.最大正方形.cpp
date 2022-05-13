/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-06 12:52:16
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-06 15:11:37
 * @FilePath: /.leetcode/动态规划/二维/最优解/221.最大正方形.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
//技巧：对于在矩阵内搜索正方形或长方形的题型，
    //一种常见的做法是定义一个二维 dp 数组，
    //其中 dp[i][j] 表示满足题目条件的、以 (i, j) 为右下角的正方形或者长方形的属性。
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(),n=matrix[0].size(),max_side=0;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        //有一些前缀和的意思
        for (int i = 1; i <= m;++i){
            for (int j = 1;j <= n;++j){
                if (matrix[i-1][j-1]=='1'){
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))+1;
                }
                max_side = max(max_side,dp[i][j]);
            }
        }
        return max_side*max_side;
    }
};
// @lc code=end

