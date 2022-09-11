/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-06 19:01:31
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-06 19:04:49
 * @FilePath: /.leetcode/动态规划/股票交易/714.买卖股票的最佳时机含手续费.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int f0 = 0, f1 = -prices[0];//不持有、持有
        for (int i = 1; i < n; ++i) {
            f0 = max(f0, f1 + prices[i] - fee);
            f1 = max(f1, f0 - prices[i]);
        }
        return f0;
    }
};

// @lc code=end

