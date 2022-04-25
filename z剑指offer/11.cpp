/*
 * @Author: your name
 * @Date: 2022-04-21 21:42:19
 * @LastEditTime: 2022-04-21 21:49:00
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/11.cpp
 */
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size() - 1, m;
        while(l<=r){
            m = l + (r - l) / 2;
            if(numbers[m]>=numbers[l]){
                l = m + 1;
            }else if(numbers[m]<numbers[r]){
                r = m - 1;
            }else{
                --r;
            }
        }
        return numbers[l];
    }
};