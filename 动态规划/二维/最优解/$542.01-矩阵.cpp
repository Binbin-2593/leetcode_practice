/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-06 10:05:59
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-06 11:39:01
 * @FilePath: /.leetcode/动态规划/二维/最优解/542.01-矩阵.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
//二维数组需要四个方向搜索时，只要从左上到右下dp一次，再右下到左上dp一次
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> ans(m,vector(n,INT_MAX-1));
        //左上到右下dp一次
        for (int i = 0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                }else{
                    if(j>0){
                        ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
                    }
                    if(i>0){
                        ans[i][j] = min(ans[i][j], ans[i - 1][j]+1);
                    }
                }
            }
        }
        //右下到左上dp一次
        for (int i = m - 1; i >= 0;--i){
            for (int j = n - 1; j >= 0;--j){
                if (mat[i][j]!=0){
                    if(j<n-1){
                        ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
                    }
                    if(i<m-1){
                        ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

