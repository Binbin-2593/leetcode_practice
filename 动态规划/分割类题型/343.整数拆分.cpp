/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-05 13:37:41
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-05 17:55:38
 * @FilePath: /.leetcode/动态规划/一维/最优解/343.整数拆分.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * [343] 整数拆分
 */

// @lc code=start
//常规dp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        for (int i = 2; i <=n;++i){
            int curMax = 0;
            //i先一分为二，再对其中一个考虑拆or不拆
            //将i先拆分出数j，剩下的那个数看要不要拆
            for (int j = 1; j < i;++j){//不确定拆出的第一个数（j）的大小，那就都让计算机跑一遍Max出来
                curMax =max(curMax,max(j * (i - j), j * dp[i - j])) ;
            }
            dp[i]=curMax;
        }
        return dp[n];
    }
};
// @lc code=end

