/*
 * @Author: your name
 * @Date: 2022-04-24 13:03:58
 * @LastEditTime: 2022-04-24 13:34:22
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/34.cpp
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n)
            return 0;
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target);
        if(lower==n||nums[lower]>target){
            return 0;
        }else{
            return upper - lower;
        }
    }
    //不小于
    int lower_bound(vector<int>&nums, int target){
        int l = 0, r = nums.size(), m;
        while (l<r){
            m = l + (r - l)/2;
            if(nums[m]>=target){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
    //大于
    int upper_bound(vector<int>&nums, int target){
        int l = 0, r = nums.size(), m;
        while (l<r){
            m = l + (r - l)/2;
            if(nums[m]<=target){
                l = m + 1;
            }else{
                r = m;
            }
        }
        return l; 
    }
};
