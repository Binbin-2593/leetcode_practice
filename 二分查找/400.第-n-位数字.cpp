/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-10 17:29:24
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-10 17:45:27
 * @FilePath: /.leetcode/二分查找/400.第-n-位数字.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
/*
class Solution {
public:
    int findNthDigit(int n) {
        int low = 1, high = 9;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            if (totalDigits(mid) < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int d = low;
        int prevDigits = totalDigits(d - 1);
        int index = n - prevDigits - 1;
        int start = (int) pow(10, d - 1);
        int num = start + index / d;
        int digitIndex = index % d;
        int digit = (num / (int) (pow(10, d - digitIndex - 1))) % 10;
        return digit;
    }

    int totalDigits(int length) {
        int digits = 0;
        int curLength = 1, curCount = 9;
        while (curLength <= length) {
            digits += curLength * curCount;
            curLength++;
            curCount *= 10;
        }
        return digits;
    }
};*/

class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1; // 位数
        long long start = 1; // 对应开始的数字
        long long count = 9; // 记录当前位包含的数字总数

        while (n > count) {
            n -= count;
            ++digit; //位数 + 1
            start *= 10; // 修改起始位置
            count = digit * 9 * start; // 修改包含的数字总数，若起始为100，100~999共有3 * 9 * 100 = 2700 个数字
        }
        --n; // 去掉 0 的影响
        int num = start + n / digit; // 确定位于的数字
        // [n % digit]， n对位数求余就是它在自己的数字的位置
        // 比如 start 为 10， n 为 3，num 为 11，此时对应的就是（3 % 2 = 1），即11的第一个数字1
        int ans = to_string(num)[n % digit] - '0'; 
        return ans;
    }
};


// @lc code=end

