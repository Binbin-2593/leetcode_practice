/*
 * @Author: your name
 * @Date: 2022-05-02 17:16:46
 * @LastEditTime: 2022-05-02 17:43:01
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%  
 * @FilePath: /.leetcode/前缀和、积分图/724.寻找数组的中心下标.cpp
 */
/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> sums(n + 1, 0);
//         for (int i = 0; i < n;++i){
//             sums[i+1]=sums[i]+nums[i];
//         }
//         int j = 0;
//         for (; j < n; ++j){
//             if(sums[j]*2+nums[j]==sums[n])
//                 break;    
//         }
//         if(j==n){
//             if(sums[n-1]!=0)
//                 return -1;
//         }
//         return j;
//     }
// };
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size(),cur=0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0;i<n;++i){
            if(cur*2+nums[i]==sum){
                return i;
            }
            cur+=nums[i];
        }
        return -1;
    }
};
// @lc code=end

