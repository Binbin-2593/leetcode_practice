/*
 * @Author: your name
 * @Date: 2022-02-28 20:26:54
 * @LastEditTime: 2022-04-27 15:45:41
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/字符串/字符串比较/696.计数二进制子串.cpp
 */
/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
//要观察待研究字符串的规律及要怎么处理问题
class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0, cur = 1, count = 0;
        for (int i = 1; i < s.size();++i){
            if(s[i]==s[i-1]){
                ++cur;
            }else{
                pre = cur;
                cur = 1;
            }
            if(pre>=cur)
                ++count;
        }
        return count;
    }
};
// @lc code=end

