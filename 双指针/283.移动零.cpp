/*
 * @Author: your name
 * @Date: 2022-04-26 21:19:56
 * @LastEditTime: 2022-04-26 22:04:36
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/双指针/283.移动零.cpp
 */
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int l = 0;
//         for (int r = 0;r<nums.size();++r){
//             if(nums[r]){
//                 swap(nums[l], nums[r]);
//                 // l = r;
//             }
//             if (nums[l]){
//                 ++l;
//             }
//         }
//     }
// };
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0;
        for(int right=0;right < n;++right) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};

// @lc code=end

