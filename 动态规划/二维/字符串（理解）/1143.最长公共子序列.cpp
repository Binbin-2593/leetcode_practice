/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-09 18:16:13
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-09 18:33:38
 * @FilePath: /.leetcode/动态规划/子序列问题/1143.最长公共子序列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        //其中 dp[i][j] 表示到第一个字符串位置 i 为止、到第二个字符串位置 j 为止、最长的公共子序列长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m;++i){
            for (int j = 1;j <= n;++j){
                if (text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};