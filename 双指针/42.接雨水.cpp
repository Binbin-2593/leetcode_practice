/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& h) {
        int ret = 0, l = 0, r = h.size() - 1, lMax = 0, rMax = 0;
        while(l<r){
            lMax = max(lMax, h[l]);
            rMax = max(rMax, h[r]);
            //由于Max向着扫描方向维持着单调性，所以走到某个位置直接可以通过比较确定当前雨水量
            if(h[l]<h[r]){
                ret += lMax - h[l];
                ++l;
            }else{
                ret += rMax - h[r];
                --r;
            }
        }
        return ret;
    }
};
// @lc code=end

