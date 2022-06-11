/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-15 16:07:13
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-08 15:55:58
 * @FilePath: /.leetcode/dfs/递归/695.岛屿的最大面积.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
// class Solution {
//     vector<int> direction{-1,0,1,0,-1};
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m = grid.size(), n = m ? grid[0].size() : 0,area=0;
//         for (int i = 0; i < m; ++i){
//             for (int j = 0; j < n;++j){
//                 if (grid[i][j]){
//                     area = max(area, dfs(grid, i, j));
//                 }
//             }
//         }
//         return area;
//     }

//     //辅助函数
//     int dfs(vector<vector<int>>& grid, int r,int c){
//         if(!grid[r][c]) return 0;
//         //避免重复计算,
//         grid[r][c] = 0;
//         int local_area = 1, x, y;
//         for (int k = 0;k<4;++k){
//             //这里对点做四周遍历的小技巧
//             x=r+direction[k],y=c+direction[k+1];
//             //这里m、n传不进来
//             if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]==1){
//                 local_area += dfs(grid, x, y);
//             }
//         }
//         return local_area;
//     }
// };
//默写1
class Solution{
    vector<int> d = {-1, 0, 1, 0, -1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int m = grid.size(),n=grid[0].size(),ans=0;
        for (int i = 0;i<m;++i){
            for (int j = 0;j<n;++j){
                if (grid[i][j]){
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>&grid,int r,int c){
        if(!grid[r][c])return 0;
        grid[r][c] = 0;//看过就标记
        int area = 1,x,y;

        for (int k = 0; k < 4; ++k){
            x = r + d[k], y = c + d[k + 1];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]){
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};
// @lc code=end
