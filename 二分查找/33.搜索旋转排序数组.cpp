/*
 * @Author: your name
 * @Date: 2022-04-21 14:39:47
 * @LastEditTime: 2022-04-21 16:00:13
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/二分查找/33.搜索旋转排序数组.cpp
 */
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int l=0,r=nums.size()-1,m;
        while(l<=r){
            m = l + (r - l) / 2;
            
            if(target==nums[m]){
                return m;
            //错误分段形式
            }else if(target>=nums[l]){
                if(nums[m]>target){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }else if(target<=nums[r]){
                if(nums[m]>target){
                    r = m-1;
                }else{
                    l=m + 1;
                }
            }
        }
        return -1;
    }
};*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int l=0,r=nums.size()-1,m;
        while(l<=r){
            m = l + (r - l) / 2;
            if(nums[m]==target){
                return m;
            }
            //要用nums[m]值的关系分段
            else if(nums[m]<=nums[r]){
                if(target>nums[m]&&target<=nums[r]){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }else{
                if(target<nums[m]&&target>=nums[l]){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

