/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
// 使用STL
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size() + nums2.size();
//         vector<int> nums3(n, 0);
//         merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());
//         return n % 2 == 0 ? (double)(nums3[n / 2] + nums3[n / 2 - 1]) / 2 : nums3[n / 2];
//     }
// };


//双指针，能把空间复杂度降为O（1）
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int count = nums1.size() + nums2.size();
        for (int i = 0; i <= count / 2; ++i)
        {
            int m, n;
            if(nums1[m]>=nums2[n]){
                if(n<nums2.size())++n;
                ++m;
            }

            else{
                if(m<nums1.size())++m;
                ++n;
            }
        }
        return 
    } 
};
// @lc code=end
