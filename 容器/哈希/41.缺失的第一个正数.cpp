/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-16 16:37:54
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-16 16:38:03
 * @FilePath: /.leetcode/41.缺失的第一个正数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start


//原地哈希
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
// @lc code=end

