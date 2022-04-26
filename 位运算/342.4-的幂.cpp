/*
 * @Author: your name
 * @Date: 2022-04-26 15:41:22
 * @LastEditTime: 2022-04-26 18:16:57
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/位运算/342.4-的幂.cpp
 */
/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
//取模的性质：4^x%3={(3+1)}^x%3={(3%3+1%3)}^x=1^x=1
//n&(n-1)==0——>n是2的次方
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};
// @lc code=end

