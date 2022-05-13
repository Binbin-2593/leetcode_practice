/*
 * @Author: your name
 * @Date: 2022-05-02 16:02:04
 * @LastEditTime: 2022-05-02 17:12:43
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/前缀和、积分图/525.连续数组.cpp
 */
/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
//暴力超时
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int n = nums.size(),ans=0;
//         for (int l=0; l < n;++l){
//             int sums = 0;
//             if(nums[l]==0){
//                 sums -= 1;
//             }else{
//                 sums += 1;
//             }

//             int r = l + 1;
//             while(r<n){
//                 if(nums[r]==0){
//                     sums -= 1;
//                 }else{
//                     sums += 1;
//                 }
//                 if(sums==0){
//                     ans = max(ans,r-l+1);
//                 }
//                 ++r;
//             }
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int n = nums.size(),ans=0;
//         vector<int> sums (n + 1, 0);
//         for (int i = 0; i < n;++i){
//             if(nums[i]==0){
//                 sums[i + 1] = sums[i] - 1;
//             }else{
//                 sums[i + 1] = sums[i] + 1;
//             }
//         }
//         unordered_map<int, int> hash;
//         for (int i = 0; i <= n;++i){
//             if(!hash.count(sums[i])){
//                 hash[sums[i]] = i;
//             }else{
//                 ans = max(ans, i - hash[sums[i]]);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(),ans=0,sums=0;
        unordered_map<int, int> hash;
        hash[0] = 0;
        for (int i = 0; i < n; ++i){
            if(nums[i]==0){
                --sums;
            }else{
                ++sums;
            }

            if(!hash.count(sums)){
                hash[sums] = i+1;
            }else{
                ans = max(ans,i+1-hash[sums]);
            }
        }
        return ans;
    }
};
// @lc code=end

