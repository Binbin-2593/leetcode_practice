/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tmp;
        for(int i = 0;i < nums.size();++i){
            if(tmp.find(target-nums[i])!=tmp.end()){
                return {tmp[target - nums[i]],i};
            }else tmp[nums[i]]=i;
        }
        return {};
    }
};
// @lc code=end

