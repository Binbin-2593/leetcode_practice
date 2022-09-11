/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-05 16:11:39
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-07 13:32:00
 * @FilePath: /.leetcode/5.最长回文子串.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEin
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<2)return s;

        int maxLen=1,begin=0;
        vector<vector<int>> dp(n,vector<int>(n));

        for(int i=0;i<n;++i){
            dp[i][i]=true;
        }

        for(int L=2;L<=n;++L){
            for(int l=0;l<n;++l){
                int r=l+L-1;
                if(r>=n) break;
                if(s[l]!=s[r]){
                    dp[l][r]=false;
                }else{
                    if(L==2){
                        dp[l][r]=true;
                    }else{
                        dp[l][r]=dp[l+1][r-1];
                    }
                }
                if(dp[l][r]&&L>maxLen){
                    maxLen=L;
                    begin=l;
                }
            }
        }
        return s.substr(begin,maxLen);
    }
};
// @lc code=end

