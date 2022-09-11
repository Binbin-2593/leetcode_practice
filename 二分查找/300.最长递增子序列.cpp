/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-29 00:00:59
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-29 00:04:46
 * @FilePath: /.leetcode/二分查找/300.最长递增子序列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        int ret=0;
        for (int n:nums){
            int i = 0, j = ret;
            while(i<j){
                int m = (i + j) / 2;
                if(dp[m]<n){
                    i = m + 1;
                }else{
                    j = m;
                }
            }
            dp[i] = n;
            if(ret==j)
                ++ret;
        }
        return ret;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        vec.push_back(nums[0]);
        for (int i = 1; i < n;++i){
            if(nums[i]>vec.back()){
                vec.push_back(nums[i]);
            }else{
                auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
                *it=nums[i];
            }
        }
        return vec.size();
    }
};
// @lc code=end

