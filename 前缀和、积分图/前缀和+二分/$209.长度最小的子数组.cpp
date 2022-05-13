/*
 * @Author: your name
 * @Date: 2022-05-02 14:15:02
 * @LastEditTime: 2022-05-05 12:55:05
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/前缀和、积分图/209.长度最小的子数组.cpp
 */
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
//对数组片段和的查找，
    //前缀和数组反应出源数组的片段和信息
    //再使用二分来查找
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = n + 1;
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; ++i){
            sums[i+1]=sums[i]+nums[i];
        }
        for (int i = 1; i <= n;++i){
            int tmp = target + sums[i - 1];//target=tmp-sums[i-1]
            auto bound = lower_bound(sums.begin(), sums.end(), tmp);
            //上面两句就是在描述nums一个片段的和，>=target的含义
            //题目要求:>=\<这种范围的可以考虑使用二分查找中的两个函数
            if (bound!=sums.end()){
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
            return ans == n + 1 ? 0 : ans;
    }
};
// @lc code=end

