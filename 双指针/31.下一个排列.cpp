/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-20 22:26:31
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-20 23:09:31
 * @FilePath: /.leetcode/31.下一个排列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int r = n - 2;
        while(r>=0&&nums[r]>=nums[r+1]){
            --r;
        }
        if(r>=0){
            int l=n-1;
            while(l>=0&&nums[r]>=nums[l]){
                --l;
            }
            swap(nums[l], nums[r]);
        }
        reverse(nums.begin()+r+1, nums.end());
    }
};
// @lc code=end

