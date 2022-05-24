/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-13 21:25:50
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-13 21:28:56
 * @FilePath: /.leetcode/容器/单调栈/121.买卖股票的最佳时机.cpp
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
        int ans = 0;
        vector<int> St;
        prices.emplace_back(-1); // 哨兵👨‍✈️
        for (int i = 0; i < prices.size(); ++ i){
            while (!St.empty() && St.back() > prices[i]){ // 维护单调栈📈
                ans = std::max(ans, St.back() - St.front()); // 维护最大值
                St.pop_back();
            }
            St.emplace_back(prices[i]);
        }

        return ans;
    }
};
// @lc code=end

