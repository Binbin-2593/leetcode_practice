/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-24 23:45:15
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-24 23:45:26
 * @FilePath: /.leetcode/165.比较版本号.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.length(), m = v2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            long x = 0;
            for (; i < n && v1[i] != '.'; ++i) {
                x = x * 10 + v1[i] - '0';
            }
            ++i; // 跳过点号
            long y = 0;
            for (; j < m && v2[j] != '.'; ++j) {
                y = y * 10 + v2[j] - '0';
            }
            ++j; // 跳过点号
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};
// @lc code=end

