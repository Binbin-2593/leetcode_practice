/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-07 15:32:04
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-07 16:32:58
 * @FilePath: /.leetcode/581.最短无序连续子数组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
//排序，对照
// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         if(is_sorted(nums.begin(),nums.end())){
//             return 0;
//         }

//         vector<int> tmp(nums.begin(), nums.end());
//         sort(tmp.begin(), tmp.end());
//         int l = 0;
//         while(nums[l]==tmp[l]){
//             ++l;
//         }
//         int r = nums.size()-1;
//         while(nums[r]==tmp[r]){
//             --r;
//         }
//         return r - l + 1;
//     }
// };
//一次遍历
class Solution{
public:
    int findUnsortedSubarray(vector<int>&nums){
        //正向扫一遍，维护最大值，只要出现后面比前面小就更新为乱序数组
        //反向再扫一遍
        int max = INT_MIN, min = INT_MAX, l = -1, r = -1,n=nums.size();
        for (int i = 0;i<n;++i){
            if(nums[i]<max){
                r = i;
            }else{
                max=nums[i];
            }
            if(nums[n-1-i]>min){
                l = n - 1 - i;
            }else{
                min = nums[n - 1 - i];
            }
        }
        return l == -1 ? 0 : r - l + 1;
    }
};
// @lc code=end
