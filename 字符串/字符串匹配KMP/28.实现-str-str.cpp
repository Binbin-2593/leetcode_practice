/*
 * @Author: your name
 * @Date: 2022-04-28 17:26:21
 * @LastEditTime: 2022-05-01 14:28:43
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/字符串/字符串匹配KMP/28.实现-str-str.cpp
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
        int k = -1, h_len = haystack.length(), n_len = needle.length();
        if (n_len == 0) return 0;
        vector<int> next(n_len, -1); //用于存储needle对应下标位的最大相同前后缀，-1表示不存在
        calNext(needle, next); // 计算next数组 
        for (int i = 0; i < h_len; ++i) {
            while (k > -1 && needle[k+1] != haystack[i]) { 
                k = next[k]; //有不匹配，回溯到needle的k位置继续匹配
            }
            if (needle[k+1] == haystack[i]) {
                ++k; 
            }
            if (k == n_len-1) {
                return i - n_len + 1; // 说明k移动到needle的最末端，返回相应的位置
            } 
        }
        return -1;
    }
    // 辅函数 - 计算next数组
    void calNext(const string &needle, vector<int> &next) {
        for (int j = 1, t = -1; j < needle.length(); ++j) { 
            //j对应后缀,t对应前缀
            //t是一个前缀和
            while (t > -1 && needle[t+1] != needle[j]) {
                t = next[t]; // 如果下一位不同，往前回溯 
            }
            if (needle[t+1] == needle[j]) {
                ++t; //如果下一位相同，更新相同的最大前后缀长
            }
            next[j] = t;//处理初始边界 
        }
    }
};
// @lc code=end

