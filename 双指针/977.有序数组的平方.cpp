/*
 * @Author: your name
 * @Date: 2022-04-26 23:08:26
 * @LastEditTime: 2022-04-27 12:44:57
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/双指针/977.有序数组的平方.cpp
 */
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size(), r ;
        vector<int> ans;
        for (int i = 0; i < n;++i){
            if(nums[i]>=0){
                r = i;
                break;
            }
        }
        int l = r-1;
        for (int j = 0; j < n;++j){
            if(l>=0&&r<n){
                if(nums[l]*nums[l]<nums[r]*nums[r]){
                    ans.emplace_back(nums[l]*nums[l]);
                    --l;
                }else{
                    ans.emplace_back(nums[r]*nums[r]);
                    ++r;
                }
            }else if(l<0){
                ans.emplace_back(nums[r]*nums[r]);
                ++r; 
            }else if(r=n){
                ans.emplace_back(nums[l]*nums[l]);
                --l; 
            }
        }
        return ans;
    }
};*/

class Solution{
public:
    vector<int> sortedSquares(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);

        int i = 0, j = n - 1, pos = n - 1;
        while(i<=j){
            if(nums[i]*nums[i]>nums[j]*nums[j]){
                ans[pos--]=nums[i]*nums[i];
                ++i;
            }else{
                ans[pos--]=nums[j]*nums[j];
                --j;
            }
        }
        return ans;
    }
};
// @lc code=end
