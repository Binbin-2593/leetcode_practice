/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-29 23:44:46
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-29 23:50:29
 * @FilePath: /.leetcode/字符串/125.验证回文串.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {//isalnum判断是数字OR字母
                sgood += tolower(ch);//tolower转换成小写、toupper转换成大写
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right) {
           if (sgood[left] != sgood[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

// @lc code=end

