/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-25 15:54:53
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-25 17:20:14
 * @FilePath: /.leetcode/字符串/97.交错字符串.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
//一般过程模拟法，无法解决一个“节点”处，出现两种可能的问题
/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1==""||s2==""||s3==""){
            if(s1==""&&s2==""&&s3=="")
                return true;
            else if(s3=="")
                return false;
            else if(s1==""||s2==""){
                if(s1==""&&s2==s3)
                    return true;
                else if(s2==""&&s1==s3)
                    return true;
            }
        }

        int p1 = 0, p2 = 0, p3 = 0;
        while(p3<s3.size()){
            while(p3<s3.size()&&p1<s1.size()&&s1[p1]==s3[p3]){
                ++p1;
                ++p3;
            }
            while(p3<s3.size()&&p2<s2.size()&&s2[p2]==s3[p3]){
                ++p2;
                ++p3;
            }
            if(s3[p3]!=s1[p1])
                break;
        }
        return p1 == s1.size() && p2 == s2.size() && p3 == s3.size();
    }
};*/

//dp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if(n+m!=t)
            return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m && s1[i - 1] == s3[i - 1];++i)
            dp[i][0] = true;
        for (int i = 1; i <= n && s2[i - 1] == s3[i - 1];++i)
            dp[0][i] = true;

        for (int i = 1; i <= m;++i){
            for (int j = 1; j <= n;++j){
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

