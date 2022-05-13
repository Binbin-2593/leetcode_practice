/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-06 11:15:23
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-06 11:37:50
 * @FilePath: /.leetcode/bfs/542.01-矩阵.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
    vector<int> d = {-1, 0, 1, 0, -1};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0)),visited(m,vector<int>(n,0));
        queue<pair<int, int>> q;
        //初始化入队
        for (int i = 0; i < m;++i){
            for (int j = 0; j < n;++j){
                if(mat[i][j]==0){
                    q.emplace(i, j);
                    visited[i][j] = 1;
                }
            }
       
        }
        //bfs
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for (int k = 0; k < 4;++k){
                int x = i+d[k], y =j+ d[k + 1];
                if(x>=0&&x<m&&y>=0&&y<n&&!visited[x][y]){
                    ans[x][y] = ans[i][j] + 1;
                    q.emplace(x,y);
                    visited[x][y] = 1;
                }
            }
        }
        return ans;
    }    
};
// @lc code=end

