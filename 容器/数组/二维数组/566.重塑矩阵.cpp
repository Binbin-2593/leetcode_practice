/*
 * @Author: your name
 * @Date: 2022-05-01 20:08:07
 * @LastEditTime: 2022-05-01 20:35:47
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/前缀和、积分图/566.重塑矩阵.cpp
 */
/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
//本题展示了两种二维数组顺序遍历的方法
/*
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(),n=mat[0].size(),count=c;
        if(r*c!=m*n)
            return mat;

        vector<vector<int>> ans;
        ans.emplace_back(vector<int>());
        for (int i = 0;i<m;++i){
            for (int j = 0;j<n;++j){
                if(count){
                    ans.back().emplace_back(mat[i][j]);
                    --count;
                }else{
                    count = c;
                    ans.emplace_back(vector<int>());
                    ans.back().emplace_back(mat[i][j]);
                    --count;
                }
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }

        vector<vector<int>> ans(r, vector<int>(c));
        for (int x = 0; x < m * n; ++x) {
            ans[x / c][x % c] = nums[x / n][x % n];
        }
        return ans;
    }
};


// @lc code=end

