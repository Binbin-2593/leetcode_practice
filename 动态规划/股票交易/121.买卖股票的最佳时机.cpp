/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-13 21:13:36
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-13 21:23:41
 * @FilePath: /.leetcode/动态规划/股票交易/121.买卖股票的最佳时机.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX, maxprofit = 0;
        for (int p: prices) {
            //由于本题的特殊性，Max只能用后面-前面的min获得，所以可以一次遍历找到
            maxprofit = max(maxprofit, p - minprice);
            //一次遍历不停的min找最小好理解
            minprice = min(p, minprice);
        }
        return maxprofit;
    }
};

// @lc code=end

