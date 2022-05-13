/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-07 15:26:13
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-09 17:31:32
 * @FilePath: /.leetcode/动态规划/分割类题型/91.解码方法.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        //1.初始
        int n = s.length();
        // if(n==0)return 0;
        int prev = s[0] - '0';
        if(!prev) return 0;
        if(n==1)
            return 1;

        //2.状态转化
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n;++i){
            int cur = s[i - 1] - '0';
            //状态关系不唯一，分情况讨论
            if((prev==0||prev>2)&&cur==0){
                return 0;
            }
            if(prev==1||prev==2&&cur<7){
                if(cur!=0){
                    dp[i]=dp[i-2]+dp[i-1];//可合可不合
                }else{
                    dp[i] = dp[i - 2];//必须合并，把cur和prev合并为一个单位，做dp[i-1]各情况的小跟班
                }
            }else{//cur不能和prev合并，cur当个小跟班跟着
                dp[i] = dp[i - 1];
            }
           prev = cur;
        }
        return dp[n];
    }
};
// @lc code=end

