/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-13 18:12:10
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-13 20:19:44
 * @FilePath: /.leetcode/动态规划/分割类题型/518.零钱兑换-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
//分割dp,有重复
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<int> dp(amount + 1, 0);
//         dp[0] = 1;
//         for (int i = 1; i <= amount; ++i){
//             for(auto c:coins){
//                 if(i>=c){
//                     dp[i]+=dp[i-c];
//                 }
//             }
//         }
//         return dp[amount];
//     }
// };

//背包dp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int& c : coins) {
            for (int i = c; i <= amount; i++) {
                dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
};

// @lc code=end

