/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-01 21:58:55
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-01 22:09:04
 * @FilePath: /.leetcode/dfs/回溯法/494.目标和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
    int count = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums,target,0,0);
        return count;
    }
    void backtrack(vector<int>&nums, int target,int level,int sum){
        if(level==nums.size()){
            if(sum==target){
                ++count;
            }
        }else{
            backtrack(nums, target, level + 1, sum + nums[level]);
            backtrack(nums, target, level + 1, sum - nums[level]);
        }
    }
};
// @lc code=end

