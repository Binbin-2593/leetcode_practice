/*
 * @Author: your name
 * @Date: 2022-05-03 16:05:20
 * @LastEditTime: 2022-05-03 16:30:37
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/动态规划/一维/计数/70.爬楼梯.cpp
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <=2)
//             return n;
//         //初始化前也要判断边界条件
//         vector<int> dp(n + 1, 1);
//         dp[1] = 1, dp[2] = 2;
        
        
//         for (int i = 3; i <= n; ++i)
//         {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };

//空间压缩版
/*因为 dp[i] 只与 dp[i-1] 和 dp[i-2] 有关，
 *因此 可以只用两个变量来存储 dp[i-1] 和 dp[i-2]
 *使得原来的 O(n) 空间复杂度优化为 O(1) 复杂度。
 */
 class Solution {
public:
    int climbStairs(int n) {
        if (n <=2)
            return n;
        int pre1 = 1, pre2 = 2, cur;
        for (int i = 3;i<=n;++i){
            cur = pre1 + pre2;
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }
};
// @lc code=end

