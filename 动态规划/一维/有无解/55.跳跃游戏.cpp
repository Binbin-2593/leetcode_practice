/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-18 18:50:17
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-30 17:08:01
 * @FilePath: /.leetcode/动态规划/一维/有无解/55.跳跃游戏.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
//超时
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // step1:状态
        vector<bool> dp(n, false);
        //step2:初始化，边界条件
        dp[0] = true;
        //step3:状态转化
        for (int i = 1;i < n;++i){
            //看i之前的j能不能调到i
            for (int j = 0; j < i;++j){
                if (dp[j]&&j+nums[j]>=i){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};

class Solution {
public:
    bool canJump(vector<int>&nums){
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        int perv = 0;
        for (int i = 0; i < n; ++i){
            for (int k = perv+1; k <= nums[i] + i&&k<n;++k){
                if(dp[i]){
                    dp[k] = true;
                }else{
                    break;
                }
            }
            perv = nums[i] + i;
        }
        return dp[n - 1];
    }
};
// @lc code=end
