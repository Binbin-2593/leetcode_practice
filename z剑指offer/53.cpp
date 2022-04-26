/*
 * @Author: your name
 * @Date: 2022-04-24 19:16:20
 * @LastEditTime: 2022-04-24 20:00:18
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/52.cpp
 */
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int l = 0, r = nums.size() - 1, m;
//         while (l <r){
//             m = l + (r - l) / 2;
//             if(nums[m]==m){
//                 l = m + 1;
//             }else{
//                 r = m;
//             }
//         }
//         if(nums[l]==l){
//             return l+1;
//         }else{
//             return l;
//         }
//     }
// };
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0,r=nums.size()-1,m;
        while(l<=r){
            m = l + (r - l) / 2;
            if(nums[m]==m){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return l;
    }
};
