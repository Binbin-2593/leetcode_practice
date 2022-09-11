/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-21 16:11:51
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-21 16:49:48
 * @FilePath: /.leetcode/字符串/151.颠倒字符串中的单词.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        int indr = 0;
        for (int start = 0; start < n; ++start){
            if(s[start]!=' '){
                if(indr!=0){
                    s[indr++] = ' ';
                }
                int end = start;
                while(end<n&&s[end]!=' '){
                    s[indr++] = s[end++];
                }
                reverse(s.begin() + indr - (end - start), s.begin() + indr);
                start = end;
            }
        }
        s.erase(s.begin() + indr, s.end());
        return s;
    }
};
// @lc code=end

