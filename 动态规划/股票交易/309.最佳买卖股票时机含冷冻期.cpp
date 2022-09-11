/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-03 16:28:27
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-06 19:12:44
 * @FilePath: /.leetcode/动态规划/股票交易/309.最佳买卖股票时机含冷冻期.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEif
 */
/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.empty())return 0;

//         int n = prices.size();
//         //int f[n][3];
//         vector<vector<int>> f(n,vector<int>(3));
//         f[0][0] = -prices[0];

//         for (int i = 1; i < n;++i){
//             f[i][0] = max (f[i - 1][0], f[i - 1][2]-prices[i]);//i天结束持有，那之前的状态是：i-1天持有、i-1天不持有但不冷冻
//             f[i][1]=f[i-1][0]+prices[i];//i天不持有且冷冻，i-1天持有并交易
//             f[i][2] = max(f[i-1][1],f[i-1][2]);//i天不持有不冷冻，那：i-1天不持有不冷冻、i-1不持有冷冻
//         }
//         return max(f[n-1][1],f[n-1][2]);
//     }
// };

//压缩状态
//三种状态：持有、不持有冷冻、不持有不冷冻
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //f表示三态对应的Max利润
        int f0 = -prices[0], f1 = 0, f2 = 0;
        for (int i = 1;i<prices.size();++i){
            f0 = max(f0, f2 - prices[i]);
            //f1需要临时值的原因是，由于冷冻机制，下面f2不能由当天冷冻f1得到，由前一天的f1得到
            int nf1 = f0 + prices[i];
            f2= max(f2, f1);
            f1 = nf1;
        }
        return max(f1, f2);
    }
};
// @lc code=end

