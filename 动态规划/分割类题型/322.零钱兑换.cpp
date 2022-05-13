/*
 * @Author: your name
 * @Date: 2022-03-18 14:39:06
 * @LastEditTime: 2022-05-03 15:04:15
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/动态规划/322.零钱兑换.cpp
 */
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //step1:确定状态，
            //用dp数组存放状态,把问题、子问题的目标数值抽象为状态
            //把问题、子问题的情况抽象成下标
            //这样就映射了
            
            //设置一个不可能拼出的方法数做最大值
            //dp数组的元素数要是amount+1，这样数组最后一个下标是amount（最终所求问题状态），因为初始下标为0
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

