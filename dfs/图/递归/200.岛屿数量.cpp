/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-02 22:40:20
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-02 22:49:34
 * @FilePath: /.leetcode/dfs/递归/200.岛屿数量.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(),ans=0;
        for (int i = 0; i < m;++i){
            for (int j = 0;j<n;++j){
                if (grid[i][j]=='1'){
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>&grid,int i,int j){
        int m = grid.size(), n = grid[0].size();
        grid[i][j] = '0';
        if(i-1>=0&&grid[i-1][j]=='1')
            dfs(grid, i - 1, j);
        if(i+1<m&&grid[i+1][j]=='1')
            dfs(grid, i + 1, j);
        if(j-1>=0&&grid[i][j-1]=='1')
            dfs(grid, i, j - 1);
        if(j+1<n&&grid[i][j+1]=='1')
            dfs(grid, i, j + 1);
    }
};
// @lc code=end

