/*
 * @Author: your name
 * @Date: 2022-04-25 11:26:53
 * @LastEditTime: 2022-04-25 11:58:06
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/二分查找/74.搜索二维矩阵.cpp
 */
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), l = 0, r = m*n-1,mid;
        while(l<=r){
            mid = l + (r - l) / 2;
            int x = matrix[mid / n][mid % n];
            if(x==target){
                return true;
            }else if(x<target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
            return b < a[0];
        });
        if (row == matrix.begin()) {
            return false;
        }
        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};

// @lc code=end

