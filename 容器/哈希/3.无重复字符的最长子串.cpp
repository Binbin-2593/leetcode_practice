/*
 * @Author: your name
 * @Date: 2022-04-28 14:28:50
 * @LastEditTime: 2022-04-28 15:26:03
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/哈希/3.无重复字符的最长子串.cpp
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
        int l = 1, n = s.length(), ans = 0,len=0;
        unordered_map<char, int> hash;

        for (int r = 0;r<n;++r){
            char c=s[r];
            if(hash[c]&&hash[c]>=l){
                l=hash[c]+1;
                len = r + 1 - l;
            }
            hash[c] = r + 1;
            ++len;
            ans = max(ans, len);
        }
        return ans;
    }
};
// @lc code=end

