/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-14 12:58:27
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-06 17:03:48
 * @FilePath: /.leetcode/动态规划/股票交易/122.买卖股票的最佳时机-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n][2];//二维数组存储第i天结束的收益
        dp[0][0] = 0, dp[0][1] = -prices[0];//0表示当天结束手里没股票，1表示有
        for (int i = 1; i < n;++i){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
//压缩空间
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int f0 = 0, f1 = -prices[0];
        for (int i = 1; i < n; ++i){
            f0 = max(f0,f1+prices[i]);
            f1 = max(f1, f0 - prices[i]);
        }
        return f0;
    }
};
//贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};
// @lc code=end

