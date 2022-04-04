/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //step1:确定状态，用dp数组存放状态
        //设置一个不可能拼出的方法数做最大值
        //dp数组的元素数要是amount+1，因为初始下标为0
        int max = amount + 1;
        vector<int> dp(amount + 1, max);

        //step2:初始条件
        //初始条件指，此件事“零行为”的情况，如：走迷宫，初始值为没走时的情况
        dp[0] = 0;

        //step5:计算顺序：用for循环体现
        for (int i = 1;i<=amount;++i){
            for (int j = 0; j < coins.size();++j){
                //step3:边界条件
                if(coins[j]<=i){
                    //step4:状态转移方程
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    //次状态：dp[i - coins[j]]
                }
            }
        }
        if(dp[amount]>amount)
            return -1;
        return dp[amount];
    }
};
// @lc code=end

