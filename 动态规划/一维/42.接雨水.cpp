/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-11 15:40:21
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-11 15:55:43
 * @FilePath: /.leetcode/双指针/42.接雨水.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEi
 */
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        if(n==0)
            return 0;
        vector<int>leftMax(n),rightMax(n);
        leftMax[0] = h[0];
        for (int i = 1; i < n;++i){
            leftMax[i] = max(leftMax[i - 1], h[i]);
        }
        rightMax[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0;--i){
            rightMax[i] = max(rightMax[i + 1], h[i]);
        }
        int ret = 0;
        for (int i = 0; i < n;++i){
            ret += min(leftMax[i], rightMax[i]) - h[i];
        }
        return ret;
    }
};
// @lc code=end

