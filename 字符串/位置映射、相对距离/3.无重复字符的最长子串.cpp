/*
 * @Author: your name
 * @Date: 2022-04-28 15:27:13
 * @LastEditTime: 2022-04-29 13:39:56
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
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,n=s.length(),ans = 0,len=0;
        //字符串相关问题经典高效位置映射问题的存储
        vector<int> v(128, -1);

        for (int r = 0; r < n;++r){
            if(v[s[r]]>=l){
                l = v[s[r]] + 1;
                len = r - l;
            }
            v[s[r]] = r;
            ++len;
            ans = max(ans, len);
        }
        return ans;
    }
};
// @lc code=end

