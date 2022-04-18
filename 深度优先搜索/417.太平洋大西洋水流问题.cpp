/*
 * @Author: your name
 * @Date: 2022-04-06 20:42:10
 * @LastEditTime: 2022-04-06 22:03:06
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE//
 * @FilePath: /.leetcode/深度优先搜索/417.太平洋大西洋水流问题.cpp
 */
/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
    //取反：水流向小岛经历的点
public:
    vector<int> d = {-1, 0, 1, 0, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        if(heights.empty()||heights[0].empty())
            return {};
        
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> ans;
        //标记
        vector<vector<bool>> reach_p(m, vector<bool>(n, false)), reach_a(m, vector<bool>(n, false));
        //遍历dfs入口:矩阵外圈接触海面的点
        for(int i=0;i<m;++i){
            dfs(heights, reach_p, i, 0);
            dfs(heights, reach_a, i, n - 1);
        }
        for(int i=0;i<n;++i){
            dfs(heights, reach_p, 0, i);
            dfs(heights, reach_a, m - 1, i);
        }

        for (int i = 0; i < m; ++i){
            for (int j = 0;j<n;++j){
                if(reach_p[i][j]&&reach_a[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
    //dfs
    void dfs(vector<vector<int>>&heights,vector<vector<bool>>& reach,int r,int c){
        if(reach[r][c])
            return;
        
        reach[r][c]=true;
        int x,y;
        for (int i = 0; i < 4;++i){
            x = r + d[i], y = c + d[i + 1];
            if(x>=0&&x<heights.size()&&y>=0&&y<heights[0].size() && heights[x][y]>=heights[r][c]){
                dfs(heights, reach, x, y);
            }
        }
    }
};
// @lc code=end

