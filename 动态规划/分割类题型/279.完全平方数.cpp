/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-06 15:18:04
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-06 15:36:22
 * @FilePath: /.leetcode/动态规划/分割类题型/279.完全平方数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n;++i){
            for (int j = 1; j * j <=i;++j){
                dp[i] = min(dp[i],dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

