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

