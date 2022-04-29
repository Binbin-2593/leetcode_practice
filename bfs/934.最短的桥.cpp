/*
 * @Author: your name
 * @Date: 2022-04-17 15:21:12
 * @LastEditTime: 2022-04-17 16:15:06
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%j
 * @FilePath: /.leetcode/广度优先搜索/934.最短的桥.cpp
 */
/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
    vector<int> d={-1,0,1,0,-1};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> points;
        //step1:dfs搜出被隔离的点
        bool over =false;
        for(int i=0;i<m;++i){
            if(over)
                    break;
            for (int j = 0;j<n;++j){
                //是0不dfs，我们要找的是2、1之间的0
                if(grid[i][j]==1){
                    dfs(points,grid,m,n,i,j);
                    //某一行搜到所需即停止
                    over=true;
                    break;
                }
            }
        }
        //step2:bfs搜出层数
        int x, y;
        int level = 0;
        while(!points.empty()){
            ++level;
            int n_points=points.size();
            while(n_points--){
                auto[r,c]=points.front();
                points.pop();
                for (int k = 0; k < 4;++k){
                    x = r + d[k], y = c + d[k + 1];
                    if(x>=0&&y>=0&&x<m&&y<n){
                        if(grid[x][y]==2) continue;
                        if(grid[x][y]==1)
                            return level;
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    //dfs
    void dfs(queue<pair<int,int>> &points, vector<vector<int>>&grid,int m,int n,int i,int j){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==2) return;
        //搜到0记录下来即停止。因为2和1之间隔着0（不知道多少层），
        //站在2的角度只向1“蔓延”一层0，这是接下来bfs找出2、1之间多少层0的要求
        if(grid[i][j]==0){
            points.push({i, j});
            return;
        }

        grid[i][j] = 2;
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i +1, j);
        dfs(points, grid, m, n, i, j-1);
        dfs(points, grid, m, n, i, j+1);
    }
};
// @lc code=end

