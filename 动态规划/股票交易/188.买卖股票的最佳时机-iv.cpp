/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-13 21:44:43
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-06 18:59:00
 * @FilePath: /.leetcode/动态规划/股票交易/188.买卖股票的最佳时机-iv.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //确定可实现的K次
        k = min(k, n / 2);
        vector<int> b(k + 1);//k次所以k+1
        vector<int> s(k + 1);

        b[0] = -prices[0];
        s[0] = 0;
        for (int i = 1; i <= k; ++i) {
            b[i] = s[i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            b[0] = max(b[0], s[0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                b[j] = max(b[j], s[j] - prices[i]);
                s[j] = max(s[j], b[j - 1] + prices[i]);   
            }
        }
        return *max_element(s.begin(), s.end());
    }
};
// @lc code=end

