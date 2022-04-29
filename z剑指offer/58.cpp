/*
 * @Author: your name
 * @Date: 2022-04-28 20:53:32
 * @LastEditTime: 2022-04-28 22:21:37
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/58.cpp
 */
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), l =0 , r =n - 1;
        while(l<=r){
            if(s[l]!=' '&&s[r]!=' '){
                break;
            }
            if(s[l]==' '){
                ++l;
            }
            if(s[r]==' '){
                --r;
            }
        }
        if(l>r)
            return "";
        int i = r, j = r;
        string ans;
        while (i >= l){
            if(s[i]==' '&&i<j){
                ans+=s.substr(i + 1, j-i);
                ans.push_back(' ');
                j = i - 1;
            }
            if(i == l){
                ans+=s.substr(i, j - i + 1);
            }
            --i;
            while(s[j]==' '){
                --j;
            }
        }
        return ans;
    }
};