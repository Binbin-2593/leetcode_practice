/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-14 22:46:22
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-14 23:57:27
 * @FilePath: /.leetcode/z剑指offer/29.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        if (m==0)
            return {};
        vector<int> ans;
        
        for (int c = 0; m > 0 && n > 0; m -= 2, n -= 2,++c){
            pair<int, int> index = {c, c};
            ans.emplace_back(matrix[index.first][index.second]);
            int tmp=n-1;
            while(tmp>0){
                ++index.second;
                ans.emplace_back(matrix[index.first][index.second]);
                --tmp;
            }
            tmp = m - 1;
            while (tmp>0){
                ++index.first;
                ans.emplace_back(matrix[index.first][index.second]); 
                --tmp;
            }
            tmp = n - 1;
            while (tmp>0){
                --index.second;
                ans.emplace_back(matrix[index.first][index.second]);
                --tmp;
            }
            tmp = m - 2;
            while(tmp>0){
                --index.first;
                ans.emplace_back(matrix[index.first][index.second]);
                --tmp;
            }
        }
        return ans;
    }
};