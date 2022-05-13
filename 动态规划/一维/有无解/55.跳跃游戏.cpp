/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
//超时
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // step1:状态
        vector<bool> dp(n, false);
        //step2:初始化，边界条件
        dp[0] = true;
        //step3:状态转化
        for (int i = 1;i < n;++i){
            //看i之前的j能不能调到i
            for (int j = 0; j < i;++j){
                if (dp[j]&&j+nums[j]>=i){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

