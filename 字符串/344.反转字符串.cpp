/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-21 17:05:02
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-21 20:25:32
 * @FilePath: /.leetcode/字符串/344.反转字符串.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEt
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size(),l=0,r=n-1;
        while(l<r){
            swap(s[l], s[r]);
            ++l;
            --r;
        }
    }
};

// @lc code=end

