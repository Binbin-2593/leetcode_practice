/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-02 23:25:53
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 15:27:55
 * @FilePath: /.leetcode/树/二叉搜索树/96.不同的二叉搜索树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {//j=1、j<=i保证了树的左子树为0和右子树为零
                G[i] += G[j - 1] * G[i - j];//子问题——>dp
            }
        }
        return G[n];
    }
};

// @lc code=end

