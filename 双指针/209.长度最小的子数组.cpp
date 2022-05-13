/*
 * @Author: your name
 * @Date: 2022-05-01 22:07:44
 * @LastEditTime: 2022-05-02 14:12:15
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/前缀和、积分图/209.长度最小的子数组.cpp
 */
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = n+1,sum=0,l=0,r=0;
        while(r<n){
            sum += nums[r];
            while(sum>=target){
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                ++l; 
            }
            ++r;
        }
        return ans==n+1?0:ans;
    }
};
// @lc code=end

