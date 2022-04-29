/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         quick_sort(nums, 0, nums.size() - 1);
//         return nums[nums.size()-k];
//     }
//     void quick_sort(vector<int>& nums,int l,int r){
//         if(l>=r)
//             return;
//         int first = l, last = r,base=nums[first];
//         while(first <last){
//             while(first<last&&nums[last]>=base){
//                 --last;
//             }
//             nums[first] = nums[last];
//             while(first<last&&nums[first]<=base){
//                 ++first;
//             }
//             nums[last]=nums[first];

//         }
//         nums[first] = base;
//         quick_sort(nums,l,first);
//         quick_sort(nums,first+1,r);
//     }
// };

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k]; 
    }
};
// @lc code=end
