/*
 * @Author: your name
 * @Date: 2022-04-21 13:18:08
 * @LastEditTime: 2022-04-21 22:40:42
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/二分查找/154.寻找旋转排序数组中的最小值-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int l=0,r=nums.size()-1,mid,m=nums[0];
//         while(l<=r){
//             mid = l + (r - l) / 2;
//             if(nums[l]==nums[mid]){
//                 ++l; 
//             }
//             else if(nums[mid]<=nums[r]){
//                 r = mid - 1;
//             }else{
//                 l = mid + 1;
//             }
//             if(m>nums[mid]) m=nums[mid];
//         }
//         return m;
//     }
// };

//更优：观察nums离散函数形状，找规律，
//重点依据最终结果落在的区域做区间取舍
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m;
            } else {
                r--;
            }
        }
        return nums[l];
    }
};
/*
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            整个分支代码块（分类讨论）要用一个判断依据点
            if (nums[m] >=nums[l]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m;
            } else {
                r--;
            }
        }
        return nums[l];
    }
};*/
// @lc code=end

