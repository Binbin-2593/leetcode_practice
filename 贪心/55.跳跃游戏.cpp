/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-18 17:28:22
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-12 16:38:54
 * @FilePath: /.leetcode/贪心/55.跳跃游戏.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),farest=0;
        for (int i = 0; i < n;++i){
            //模拟过程，一次次更新最远
            if(i<=farest){
                farest = max(farest, i + nums[i]);
                if(farest>=n-1)
                    return true;
            }
        }
            return false;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), farest = 0;
        for (int i = 0; i < n;++i){
            if(i<=farest){
                farest = max(farest, nums[i] + i);
                if(farest>=n-1)return true;
            }
        }
        return false;
    }
};
// @lc code=end

