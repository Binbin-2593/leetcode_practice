/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-29 16:52:48
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-29 17:07:59
 * @FilePath: /.leetcode/204.计数质数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    //判断一个数是否为质数
    /*
    如果y是x的质数，则x/y也是x的质数，所以只要检测两者中的最小者，即在[2,x^1/2]内检测，时间复杂度O(n^1/2)
    */
    bool isPrime(int x) {
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                return false;
            }
        }
        return true;
    }
    //在[2,n-1]这些数中枚举检测是否是质数
    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i <= n-1; ++i) {
            ans += isPrime(i);
        }
        return ans;
    }
};


// @lc code=end

