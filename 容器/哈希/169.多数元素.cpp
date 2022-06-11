/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-07 23:18:23
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-07 23:25:12
 * @FilePath: /.leetcode/容器/哈希/169.多数元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto&num:nums){
            // hash[num]++;
            if(++hash[num]>nums.size()/2){
                return num;
            }
        }
        return -1;
    }
};
// @lc code=end

