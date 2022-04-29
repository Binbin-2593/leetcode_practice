/*
 * @Author: your name
 * @Date: 2022-01-17 19:29:53
 * @LastEditTime: 2022-04-28 13:32:58
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/字符串/3.无重复字符的最长子串.cpp
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
//滑窗:本题所用滑窗是l(l做循环控制)分别基于每个元素创建滑窗（r往前滑（循环），遇到情况停下处理）
class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char> hash;
        int r = -1,m=0;
        for (int l = 0;l<n;++l){
            if(l!=0){
                hash.erase(s[l - 1]);
            }
            while(r+1<n&&!hash.count(s[r+1])){
                hash.insert(s[r + 1]);
                ++r;
            }
            m = max(m, r-l+1);
        }
        return m;
    }
};
// @lc code=end

