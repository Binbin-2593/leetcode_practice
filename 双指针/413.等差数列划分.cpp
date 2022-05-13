/*
 * @Author: your name
 * @Date: 2022-05-03 21:47:48
 * @LastEditTime: 2022-05-03 21:55:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/双指针/413.等差数列划分.cpp
 */
/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),ans=0;
        if(n<3) return 0;

        for (int l = 0; l < n - 2;++l){
            int d = nums[l + 1] - nums[l];
            int r = l + 2;
            while(r<n){
                if(nums[r]-nums[r-1]==d){
                    ++ans;
                }else{
                    break;
                }
                ++r;
            }
        }
        return ans;
    }
};
// @lc code=end

