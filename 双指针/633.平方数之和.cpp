/*
 * @Author: your name
 * @Date: 2022-04-25 16:14:21
 * @LastEditTime: 2022-04-25 16:38:14
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/双指针/633.平方数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        //1.需要开方直接用
        //2.关于数字的题目注意int溢出的问题
        long s = 0, t = (int)sqrt(c);
        while(s<=t){
            long tmp=s*s+t*t;
            if (tmp==c){
                return true;
            }else if(tmp<c){
                ++s;
            }else{
                --t;
            }
        }
        return false;
    }
    // int Sqrt(int c){
    //     if(c==0)
    //         return c;
    //     int l = 1, r = c, m,sqrt;
    //     while(l<=r){
    //         m = l + (r - l) / 2;
    //         sqrt=c/m;
    //         if(sqrt==m){
    //             return m;
    //         }else if(sqrt<m){
    //             r = m - 1;
    //         }else{
    //             l = m + 1;
    //         }
    //     }
    //     return l;
    // }
};
// @lc code=end

