/*
 * @Author: your name
 * @Date: 2022-03-08 11:45:14
 * @LastEditTime: 2022-05-01 20:04:15
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/前缀和、积分图/560.和为-k-的子数组.cpp
 */
/*
 * @lc app=leetcode.cn id560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;//其中存放的是：pair<前缀和，此值数量>
        mp[0] = 1;//前缀和问题的临界值初始化
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.count(pre - k)) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};
// @lc code=end

