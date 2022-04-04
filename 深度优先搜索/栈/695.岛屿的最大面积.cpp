/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
/*栈溢出
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
        help(grid, i,j - 1, count);
        help(grid, i,j + 1, count);
        help(grid, i + 1,j, count);
        help(grid,i-1,j,count);
        ++count;
        grid[i][j] = 0;

        return count;
    }
};*/



//用栈
//算法没问题，不过会heap溢出
class Solution {
    vector<int> direction{-1, 0, 1, 0, - 1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=m?grid[0].size():0,local_area,area=0,x,y;
        for (int i = 0; i < m;++i){
            for (int j=0;j<n;++j){
                if (grid[i][j]){
                    local_area=1;
                    grid[i][j] = 0;

                    stack<pair<int,int>> island;
                    island.push({i, j});
                    while(!island.empty()){
                        //对pair变量的取用方式
                        auto [r,c]=island.top();
                        island.pop();

                        for (int k = 0; k < 4;++k){
                            x = r + direction[k], y = c + direction[k + 1];
                            if (x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==1){
                                grid[x][y] = 0;
                                ++local_area;
                                island.push({x, y});
                            }
                        }
                    }
                    //cout<<"---1----2-----3-----4----"<<endl;
                    area = max(area, local_area);
                }
            }

            
        }
        return area;
    }

   
};

/*
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                int cur = 0;
                stack<int> stacki;
                stack<int> stackj;
                stacki.push(i);
                stackj.push(j);
                while (!stacki.empty()) {
                    int cur_i = stacki.top(), cur_j = stackj.top();
                    stacki.pop();
                    stackj.pop();
                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
                        continue;
                    }
                    ++cur;
                    grid[cur_i][cur_j] = 0;
                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        stacki.push(next_i);
                        stackj.push(next_j);
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
*/

// @lc code=end

