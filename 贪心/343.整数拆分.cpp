/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-05 17:55:49
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-05 17:57:14
 * @FilePath: /.leetcode/贪心/343.整数拆分.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if(n < 4){
            return n - 1;
        }else if(n == 4){
            return n;
        }
        int res = 1;
        while(n > 4){
            res *= 3;
            n -= 3;
        }
        // 最终剩下来的肯定是2,3,4
        return res * n;
    }
};
// @lc code=end

