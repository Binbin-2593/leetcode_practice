/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-11 23:14:15
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-06 19:15:50
 * @FilePath: /.leetcode/动态规划/分割类题型/494.目标和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int n = nums.size(), neg = diff / 2;
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++) {
                if (j >= num) {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-num];//可装i；可不装
                }else{
                    dp[i][j] = dp[i - 1][j];//不能装i，数量不变
                }
            }
        }
        return dp[n][neg];
    }
};

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
//         for (int& num : nums) {
//             sum += num;
//         }
//         int diff = sum - target;
//         if (diff < 0 || diff&1) {
//             return 0;
//         }
//         int neg = diff / 2;
//         vector<int> dp(neg + 1);
//         dp[0] = 1;
//         for (int& num : nums) {
//             for (int j = neg; j >= num; j--) {
//                 dp[j] += dp[j - num];//因为要借用之前确定现在，倒叙遍历
//             }
//         }
//         return dp[neg];
//     }
// };

// class Solution {
//     int count = 0;
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         backtrack(nums,target,0,0);
//         return count;
//     }
//     void backtrack(vector<int>&nums, int target,int level,int sum){
//         if(level==nums.size()){
//             if(sum==target){
//                 ++count;
//             }
//         }else{
//             backtrack(nums, target, level + 1, sum + nums[level]);
//             backtrack(nums, target, level + 1, sum - nums[level]);
//         }
//     }
// };
// @lc code=end

