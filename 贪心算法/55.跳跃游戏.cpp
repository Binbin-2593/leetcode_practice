/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),farest=0;
        for (int i = 0; i < n;++i){
            //模拟过程，一次次更新最远
            if(i<=farest){
                farest = max(farest, i + nums[i]);
                if(farest>=n-1)
                    return true;
            }
        }
            return false;
    }
};
// @lc code=end

