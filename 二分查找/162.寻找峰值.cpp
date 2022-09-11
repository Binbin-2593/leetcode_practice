/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-28 21:40:23
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-28 21:49:46
 * @FilePath: /.leetcode/二分查找/162.寻找峰值.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
//两端负无穷，相邻两数又不相等，肯定有峰值，
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while( l < r){
            int mid = ( l + r )/2;
            if(nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};

// @lc code=end

