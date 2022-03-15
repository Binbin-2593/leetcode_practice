/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         return binary_search(nums.begin(), nums.end(), target);
//     }
// };


//注意观察题目规律，找出特征，去处理
//注意考虑特殊情况
class Solution{
public:
    bool search(vector<int>& nums, int target){
        if(nums.size() == 0)return false;
        int l = 0,r = nums.size()-1,mid;
        while(l<=r){
            mid = l + (r - l) / 2;
            if(nums[mid]==target)
                return true;

            //观察得到：nums[start]>=nums[end]
            if(nums[l]==nums[mid])
                ++l;
            else if (nums[mid] <= nums[r])
            {
                if(nums[mid]<target&&target<=nums[r])
                    l = mid + 1;
                else r=mid - 1;
            }
            else
            {if(nums[mid]>target&&target>=nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};

// @lc code=end

