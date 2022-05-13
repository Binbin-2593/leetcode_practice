/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-05 18:00:08
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-05 18:19:02
 * @FilePath: /.leetcode/动态规划/一维/最优解/53.最大子数组和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

//前缀和+双指针
// @lc code=end

