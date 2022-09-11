/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-31 15:04:27
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-31 16:21:32
 * @FilePath: /.leetcode/动态规划/二维/152.乘积最大子数组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
//超时
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),ret=INT_MIN;
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        for (int i = 0; i < n;++i){
            dp[i][i]=nums[i];
            ret = max(ret, nums[i]);
        }
        for (int L = 2; L <= n;++L){
            for (int l = 0; l < n;++l){
                int r = l + L - 1;
                if(r>=n)
                    break;
                dp[l][r] = dp[l][r - 1] * nums[r];
                ret = max(ret, dp[l][r]);
            }
        }
        return ret;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            //维持一个最小是因为有负数的存在
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};
// @lc code=end

