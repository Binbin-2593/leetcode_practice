/*
 * @Author: your name
 * @Date: 2022-04-25 13:20:39
 * @LastEditTime: 2022-04-25 13:32:34
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/双指针/167.两数之和-ii-输入有序数组.cpp
 */
/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size()<=1){
            return {};
        }
        int l=0,r=numbers.size()-1,m,sum;
        while (l<r){
            sum = numbers[l] + numbers[r];
            if (sum==target){
                return {l+1, r+1};
            }else if(sum>target){
                --r;
            }else{
                ++l;
            }
        }
        return {};
    }
};
// @lc code=end

