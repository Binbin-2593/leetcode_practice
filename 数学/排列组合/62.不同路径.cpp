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

