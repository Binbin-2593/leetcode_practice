/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-28 22:01:18
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-28 23:13:15
 * @FilePath: /.leetcode/二分查找/287.寻找重复数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (auto&n:nums) {
                if(n<=mid)
                    ++cnt;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

// @lc code=end

