/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-07 19:22:19
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-07 19:22:45
 * @FilePath: /.leetcode/动态规划/一维/最优解/213.打家劫舍-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);
        else
            return max(help(nums, 0, n - 2), help(nums, 1, n - 1));
    }
    //常规偷
    int help(vector<int>&nums,int start,int end){
        int p1 = 0, p2 = 0, cur = 0;
        for (int i = start; i <= end;++i){
            cur = max(p2, p1 + nums[i]);
            p1 = p2;
            p2 = cur;
        }
        return cur;
    }
};
// @lc code=en