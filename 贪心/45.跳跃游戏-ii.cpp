/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-11 22:30:58
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-12 16:51:41
 * @FilePath: /.leetcode/贪心/45.跳跃游戏-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, ret = 0,end=0;
        //不访问最后一个元素是因为，在访问它之前maxmaxPos一定已经超过了
        for (int i = 0; i < nums.size()-1;++i){
            if(i<=maxPos){
                maxPos = max(maxPos, i + nums[i]);
                //由于贪心思想，记录每次能产生的最大距离end，当i==end时，记录一次跳跃
                if(i==end){
                    end = maxPos;
                    ++ret;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

