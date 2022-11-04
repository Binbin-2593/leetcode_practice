/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-24 21:57:34
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-23 13:37:46
 * @FilePath: /.leetcode/718.最长重复子数组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ans = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 1; i <=m; ++i){
            for (int j = 1; j <=n;++j){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

