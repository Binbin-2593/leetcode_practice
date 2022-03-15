/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
    vector<vector<int>> intergral;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = m>0?matrix[0].size():0;
        intergral = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0;i<m;++i){
            for (int j = 0;j<n;++j){
                intergral[i + 1][j + 1] = matrix[i][j] + intergral[i][j + 1] + intergral[i + 1][j] - intergral[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return intergral[row2 + 1][col2 + 1] - intergral[row2 + 1][col1] - intergral[row1][col2 + 1] + intergral[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

