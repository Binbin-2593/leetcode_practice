/*
 * @Author: your name
 * @Date: 2022-04-28 19:02:45
 * @LastEditTime: 2022-04-28 19:08:11
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/05.cpp
 */
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(auto&c : s){
            if (c==' '){
                ans.emplace_back('%');
                ans.emplace_back('2');
                ans.emplace_back('0');
            }else{
                ans.emplace_back(c);
            }
        }
        return ans;
    }
};