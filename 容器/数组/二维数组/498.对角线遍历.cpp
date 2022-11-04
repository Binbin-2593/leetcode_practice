/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-10-15 16:16:54
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-10-15 16:31:48
 * @FilePath: /.leetcode/容器/数组/二维数组/498.对角线遍历.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(),n=mat[0].size();
        vector<int> res;
        for (int i = 0; i < m + n - 1; i++) {//m+n-1条对角线
        //对角线序号的奇偶对应不同遍历顺序
            if (i % 2) {
                //注意遍历起始位置坐标，与m,n的关系（结合图形）
                    //当 i<m时，则此时对角线遍历的起点位置为 (0,i)；
                    //当 i≥n 时，则此时对角线遍历的起点位置为 (i−n+1,n−1)；
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                while (x < m && y >= 0) {
                    res.emplace_back(mat[x][y]);
                    x++;
                    y--;
                }
            } else {
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                while (x >= 0 && y < n) {
                    res.emplace_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

