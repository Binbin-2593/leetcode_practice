/*
 * @Author: your name
 * @Date: 2022-04-26 19:04:07
 * @LastEditTime: 2022-04-26 19:21:22
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/位运算/338.比特位计数.cpp
 */
/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
//一个数不能直接得到他的二进制表示，但是0可以直接知道，
//而又相邻数的二进制有关系，这样就可以起一个"线头"（0）全部解开
//这种特性又符合动态规划
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        for (int i = 1;i<=n;++i){
            dp[i] = i & 1 ? dp[i - 1] + 1 : dp[i >> 1];
        }
        return dp;
    }
};
// @lc code=end

