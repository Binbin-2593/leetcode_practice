/*
 * @Author: your name
 * @Date: 2022-03-18 16:34:07
 * @LastEditTime: 2022-05-03 15:11:07
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/数学/排列组合/62.不同路径.cpp
 */
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        //数学排列组合(m-1)+(n-1)中选出(m-1)种
        long long ans = 1;
        for (int x = n, y = 1;y<m; ++x,++y)
            ans = ans * x / y;
            //不能ans*(x/y)
        return ans;
    }
};
// @lc code=end

