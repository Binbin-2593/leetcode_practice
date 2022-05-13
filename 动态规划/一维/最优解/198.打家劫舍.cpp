/*
 * @Author: your name
 * @Date: 2022-05-03 16:31:38
 * @LastEditTime: 2022-05-05 18:23:16
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/198.打家劫舍.cpp
 */
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//        int n=nums.size();
//        vector<int> dp(n + 1, 0);
//        dp[0] = 0, dp[1] = nums[0];
//        for (int i = 2; i <= n;++i){
//             //这里nums[i-1]是第i个房间的钱
//            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
//        }
//        return dp[n];
//     }
// };
//空间压缩
    //思想上时dp
    //技法上是双指针
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0;
        for(auto n:nums){
            int tmp = max(curr,prev+n);
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};
// @lc code=end

