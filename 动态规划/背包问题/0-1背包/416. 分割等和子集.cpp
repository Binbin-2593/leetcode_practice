/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-10 14:37:47
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-10 15:59:04
 * @FilePath: /.leetcode/动态规划/背包问题/416. 分割等和子集.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2)return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n;++i){
            dp[i][0]=true;
        }
        for (int i = 1;i <= n;++i){
            int temp = nums[i - 1];
            for (int j = 1; j <= target; ++j){
                if(j>=temp){
                    dp[i][j] = dp[i-1][j] || dp[i - 1][j - temp];//由于这里是一个可能性问题
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};
//有bug
// bool canPartition(vector<int> &nums) {
// int sum = accumulate(nums.begin(), nums.end(), 0);
// if (sum % 2) return false;
// int target = sum / 2, n = nums.size();
// vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false)); 
// for (int i = 0; i <= n; ++i) {
//     dp[i][0] = true;
// }
// for (int i = 1; i <= n; ++i) {
//     for (int j = nums[i-1]; j <= target; ++j) {
//         dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]; 
//     }
// }
// return dp[n][target];
// }
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2)return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0]=true;
        for (int i = 1;i <= n;++i){
            int temp = nums[i - 1];
            for (int j = target; j >=temp;--j){
                dp[j] = dp[j] || dp[j - temp];//由于这里是一个可能性问题
            }
        }
        return dp[target];
    }
};

