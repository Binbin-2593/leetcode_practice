/*
 * @Author: your name
 * @Date: 2022-05-03 20:55:04
 * @LastEditTime: 2022-05-03 21:41:04
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/动态规划/一维/计数/413.等差数列划分.cpp
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
        int n=nums.size();
        if(n<3)
            return 0;

        vector<int> dp(n, 0);//dp[i]表示从nums[0]到nums[i]且以nums[i]为结尾的等差数列子数组的数量
        for (int i = 2; i < n;++i){
            //如果nums[i]能和nums[i-1]nums[i-2]组成等差数列，
            //则以nums[i-1]结尾的等差数列均可以nums[i]结尾，
            //且多了一个新等差数列[nums[i],nums[i-1],nums[i-2]]
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i] = dp[i - 1] + 1;
            }
            //重点搞懂：问题和子问题之间能产生怎样的递推关系
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
// @lc code=end

