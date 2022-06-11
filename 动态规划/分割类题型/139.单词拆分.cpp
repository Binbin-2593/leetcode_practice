/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-07 15:50:34
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 15:18:43
 * @FilePath: /.leetcode/动态规划/分割类题型/139.单词拆分.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
//有bug
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> hash;
//         for(auto&s : wordDict){
//             hash.emplace(s);
//         }
//         int l = 0,n=s.length();
//         bool flag=false;
//         for (int r = 0; r < n;++r){
//             if(hash.count(s.substr(l,r-l+1))){
//                 flag = true;
//                 l = r+1;
//             }else{
//                 flag = false;
//             }
//         }
//         return flag;
//     }
// };

//dp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n + 1, false);
        dp[0]=true;//先保证齿轮组初动力有转的可能
        for (int i = 1; i <= n;++i){
            for (const string &ss : wordDict){
                int l = ss.length();
                if (i >= l && s.substr(i-l,l)==ss){
                    dp[i] = dp[i] || dp[i - l];
                }
            }//问题的结果可能这样有可能那样,用dp
        }
        return dp[n];
    }
};
//moxie1
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n + 1, false);
        dp[0]=true;

        for (int i = 1; i <= n;++i){
            for(auto& w : wordDict){
                int l = w.length();
                if (i >=l &&s.substr(i-l,l)==w){
                    dp[i] = dp[i] || dp[i - l];
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

