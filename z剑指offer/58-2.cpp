/*
 * @Author: your name
 * @Date: 2022-04-29 14:37:11
 * @LastEditTime: 2022-04-29 14:43:33
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/58-2.cpp
 */
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.size() - n + 1) + s.substr(0, n);
    }
};