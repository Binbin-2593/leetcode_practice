/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-07 23:34:18
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-08 12:34:45
 * @FilePath: /.leetcode/动态规划/分割类题型/264.丑数-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            //2、3、5是产生后面丑数的基础，当前状态一定由之前的某个状态*（2、3、5）其中之一获得
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);//由于是依次罗列，所以每次选紧接着的最小
            if (dp[i] == num2) {
                //p2指向的状态*2已经是当前的状态了，就不再是之后一个更大的状态，所以把基准值变大
                p2++;
            }
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
        }
        return dp[n];
    }
};

// @lc code=end

