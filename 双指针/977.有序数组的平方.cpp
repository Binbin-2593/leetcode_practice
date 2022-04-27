/*
 * @Author: your name
 * @Date: 2022-04-26 23:08:26
 * @LastEditTime: 2022-04-26 23:28:05
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
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size(), r ;
        vector<int> ans(n,0);
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
                    ans[j]=nums[l]*nums[l];
                    --l;
                }else{
                    ans[j] = nums[r]*nums[r];
                    ++r;
                }
            }else if(l<0){
                ans[j] = nums[r]*nums[r];
                ++r; 
            }else if(r=n){
                ans[j]=nums[l]*nums[l];
                --l; 
            }
        }
        return ans;
    }
};
// @lc code=end

