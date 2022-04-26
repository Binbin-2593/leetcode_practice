/*
 * @Author: your name
 * @Date: 2022-04-25 16:40:31
 * @LastEditTime: 2022-04-25 17:15:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/双指针/680.验证回文字符串-ⅱ.cpp
 */
/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]==s[r]){
                --r;
                ++l;
            }else{
                /*
                if(flag){
                    --r; //也有可能++l,是一个或的关系
                    flag = 0;
                }else{
                    return false;
                }*/
                return (check(l, r - 1, s) || check(l + 1, r, s));
            }
        }
        return true;
    }
    bool check(int left,int right,string&s){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end

