/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-09 10:35:54
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-09 21:21:47
 * @FilePath: /.leetcode/动态规划/子序列问题/300.最长递增子序列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
//双指针,情况出现多种可能情况，双指针不可行
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size(),ans=0;
//         if(n==1)
//             return 1;
//         for (int l = 0; l < n - 1; ++l)
//         {
//             int r = l + 1,prev=nums[l],count=1;
//             while (r<n){
//                 if(nums[r]>prev){
//                     prev=nums[r];
//                     ++count; 
//                 } 
//                 ++r;
//                 // else
//                 // {
//                 //     break;
//                 // }
//             }
//             ans = max(ans, count);
//         }
//         return ans;
//     }
// };
//dp
    //对子序列某一性质的研究
    //随着单位研究对象数量级的增大过程中记录这一性质
    //在这个递进的过程中后者依据前者得到，前者是后者产生的积累
class Solution{
public:
    int lengthOfLIS(vector<int>&nums){
        int ans = 0, n = nums.size();
        vector<int> dp(n,1);
        //dp[i]表示以i结尾的子序列的性质（这里最长子序列长度）
        for (int i = 0; i < n;++i){
            for (int j = 0; j < i;++j){//此层for:i之前可能的状态
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans; 
    }
};
//dp+二分
class Solution{
public:
    int lengthOfLIS(vector<int>&nums){
        int ans = 0, n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1;i<n;++i){
            if(dp.back()<nums[i]){
                dp.push_back(nums[i]);
            }else{
                auto iter = lower_bound(dp.begin(), dp.end(), nums[i]);
                //将nums[i]填在它合适的位置，这样增大了递增子序列更长的可能性
                *iter=nums[i];
                //注意这里的序列不一定是最长子序列，长度一定是最长子序列的长度
            }
        }
        return dp.size();
    }//需要查找有关（a<x<b）中x的信息可以二分
};
// @lc code=end
