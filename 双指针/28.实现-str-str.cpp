/*
 * @Author: your name
 * @Date: 2022-03-01 17:17:02
 * @LastEditTime: 2022-04-27 16:02:37
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/字符串/字符串匹配/28.实现-str-str.cpp
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = -1,h_len=haystack.size(),n_len=needle.size();
        if(n_len>h_len) return pos;
        for (int i = 0; i <=h_len-n_len;++i){
            if (haystack[i]==needle[0]){
                int p1 = i+1,p2=1;
                while(p1 < h_len&&p2 < n_len){
                    if(haystack[p1]==needle[p2]){
                        p1++;
                        p2++;
                    }else{
                        break;
                    }
                }
                if(p2==n_len){
                    pos = i;
                    break;
                }
            }
        }
        return pos;
    }
};
// @lc code=end

