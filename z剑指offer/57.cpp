/*
 * @Author: your name
 * @Date: 2022-04-24 13:38:28
 * @LastEditTime: 2022-04-24 18:12:24
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/57.cpp
 */
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         if (nums.size()<=1)
//             return {};
//         unordered_set<int> hash;
//         for (int i;i<nums.size();++i){
//             if(nums[i]<=target){
//                 if(!hash.count(target-nums[i])){
//                     hash.insert(nums[i]);
//                 }else{
//                     return {target - nums[i], nums[i]};
//                 }
//             }else{
//                 break;
//             }
//         }
//         return {};
//     }
// };
//看到顺序排列想到二分，两数之和想到双指针
//二分法+双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size()<=1)
            return {};
        int p1 = 0, n=nums.size(),p2;
        if(target>nums[n-1]){
            p2=n-1;
        }else{
            p2= lower_bound(nums, target);
        }
        while(p1!=p2){
            if(nums[p1]+nums[p2]==target){
                return {nums[p1], nums[p2]};
            }else if(nums[p1]+nums[p2]>target){
                --p2;
            }else{
                ++p1;
            }
        }
        
        return {};
    }
    int lower_bound(vector<int>&nums,int target){
        int l = 0, r = nums.size(), m;
        while(l<r){
            m=l+(r-l)/2;
            if(nums[m]>=target){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};