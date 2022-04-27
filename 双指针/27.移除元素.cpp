/*
 * @Author: your name
 * @Date: 2022-04-26 20:06:28
 * @LastEditTime: 2022-04-26 20:37:25
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/27.移除元素.cpp
 */
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
//这种在数组中处理“坏值”的问题，用快慢指针（同向）
//快指针每次循环都++，在前面找坏值
//找到坏值再由慢指针处理，这时慢指针才++
    //滑动窗口本质是这种，窗口两边，前面的往前滑，出现情况，后面的才伺机而动

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        for (int r = 0;r<nums.size();++r){
            if(nums[r]!=val){
                nums[l] = nums[r];
                ++l;
            }
        }
        return l;
    }
};
// @lc code=end

