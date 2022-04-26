/*
 * @Author: your name
 * @Date: 2022-04-26 15:15:59
 * @LastEditTime: 2022-04-26 15:22:24
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/位运算/190.颠倒二进制位.cpp
 */
/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
//正向遍历反向输出
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end

