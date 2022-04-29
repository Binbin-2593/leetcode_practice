/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        
        sort(nums.begin(), nums.end());
        int ans ,count=1;
        for (int i = 1; i < nums.size();++i){
            if(nums[i]==nums[i-1])
                continue;
            else if(nums[i]==nums[i-1]+1){
                ++count;
            }else{
                ans = max(ans, count);
                count = 1;
            }
        }
        return max(ans, count);
    }
};
// @lc code=end

