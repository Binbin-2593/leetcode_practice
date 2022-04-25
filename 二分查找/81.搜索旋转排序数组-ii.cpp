/*
 * @Author: your name
 * @Date: 2022-02-23 16:26:37
 * @LastEditTime: 2022-04-20 22:27:41
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/二分查找/81.搜索旋转排序数组-ii.cpp
 */
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
                //l = mid + 1;
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

