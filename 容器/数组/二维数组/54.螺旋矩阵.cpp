/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-19 16:38:09
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-21 15:16:41
 * @FilePath: /.leetcode/容器/数组/二维数组/54.螺旋矩阵.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
//一层一层的顺时针跑
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(m==0||n==0)
            return {};

        vector<int> ans;
        int left = 0, right = n - 1, top = 0,bottom=m-1;
        while(left<=right&&top<=bottom){
            for (int c = left; c <= right;++c){
                ans.push_back(matrix[top][c]);
            }
            for (int r = top + 1;r<=bottom;++r){
                ans.push_back(matrix[r][right]);
            }
            if(left<right&&top<bottom){
                for(int c=right-1;c>left;--c){
                    ans.push_back(matrix[bottom][c]);
                }
                for (int r = bottom; r > top;--r){
                    ans.push_back(matrix[r][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return ans;
    }
};
// @lc code=end

