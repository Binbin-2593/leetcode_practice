/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-10 16:55:43
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-13 20:18:48
 * @FilePath: /.leetcode/动态规划/背包问题/完全背包/322. 零钱兑换.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//分割dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1;i<=amount;++i){
            for (auto c:coins){
                if (c<=i){
                    dp[i] = min(dp[i],dp[i-c]+1);
                }
            }
        }
        if (dp[amount]==amount+1)
            return -1;
        return dp[amount];
    }
};


//背包dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto c:coins){
            for (int i = c;i<=amount;++i){
                dp[i] = min(dp[i],dp[i-c]+1);
            }
        }
        if (dp[amount]==amount+1)
            return -1;
        return dp[amount];
    }
};

