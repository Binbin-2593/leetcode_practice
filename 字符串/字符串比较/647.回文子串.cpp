/*
 * @Author: your name
 * @Date: 2022-02-28 19:21:03
 * @LastEditTime: 2022-04-27 15:17:18
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/字符串/字符串比较/647.回文子串.cpp
 */
/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
//判断回文：双指针，两种方式1.双指针两端往中间挤；2.双指针背向往两边走（此种应用场景更多）
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size();++i){
            count += extendSubstrings(s, i, i);
            count += extendSubstrings(s, i, i + 1);
        }
        return count;
    }
    int extendSubstrings(string s,int l,int r){
        int count = 0;
        while(l>=0&&r<s.size()&&s[l]==s[r]){
            --l;
            ++r;++count;
        }
        return count;
    }
};
// @lc code=end

