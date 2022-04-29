/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0,area=0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n;++j){
                if (grid[i][j]){
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }

    //辅助函数
    int dfs(vector<vector<int>>&grid,int r,int c){

        //递归进行前必须满足边界条件
        if (r<0||r>=grid.size()||c<0||c>=grid[0].size()||grid[r][c]==0) return 0;
        //必须在递归之前把遍历过的grid[i][j]==1--->grid[i][j]=0
        //来防止一直递归下去（出不来），图遍历及其重要的一个细节
        grid[r][c] = 0;
        return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c - 1) + dfs(grid, r, c + 1);
    }
};

/*
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0,m=grid.size(),n=m?grid[0].size():0;
        for (int i = 0; i < m;++i){
            for (int j = 0;j<n;++j){
                if (grid[i][j]==0) continue;
                int count = 0;
                maxArea = max(maxArea, help(grid, i,j, count));
                
            }
        }
        return maxArea;
    }

    //辅助函数
    //进行左右下中的dfs
    int help(vector<vector<int>>& grid,int i,int j,int &count){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0) return count;
        grid[i][j] = 0;
        help(grid, i,j - 1, count);
        help(grid, i,j + 1, count);
        help(grid, i + 1,j, count);
        help(grid,i-1,j,count);
        ++count;
        

        return count;
    }
};
*/
// @lc code=end

