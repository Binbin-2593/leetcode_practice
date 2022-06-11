/*
 * @Author: your name
 * @Date: 2022-04-28 14:28:50
 * @LastEditTime: 2022-06-08 13:02:18
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/哈希/3.无重复字符的最长子串.cpp
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
//双指针+哈希
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 1, n = s.length(), ans = 0,len=0;
        unordered_map<char, int> hash;

        for (int r = 0;r<n;++r){
            char c=s[r];
            if(hash[c]&&hash[c]>=l){
                l=hash[c]+1;
                len = r - l + 1;
            }
            hash[c] = r + 1;
            ++len;
            ans = max(ans, len);
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
// @lc code=end

