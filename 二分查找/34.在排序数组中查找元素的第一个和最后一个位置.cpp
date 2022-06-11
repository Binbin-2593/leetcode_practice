/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-02-21 18:28:33
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-10 17:40:50
 * @FilePath: /.leetcode/二分查找/34.在排序数组中查找元素的第一个和最后一个位置.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        //产生了一个左闭右开的区间
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target)-1;
        if (lower==nums.size()||nums[lower]>target)
            return {-1, -1};
        return {lower, upper};
    }
    //第一个不小于（>=）target的元素的下标
    int lower_bound(vector<int>&nums,int target){
        int l = 0,r = nums.size(),mid = 0;
        while(l<r){
            mid = (l + r) / 2;
            if(nums[mid]>=target){
                r = mid;//初始化是r=nums.size()
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
    //第一个大于target的元素的下标
    int upper_bound(vector<int>&nums,int target){
        int l = 0,r = nums.size(),mid = 0;
        while(l<r){
            mid = (l + r) / 2;
            if(nums[mid]>target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

