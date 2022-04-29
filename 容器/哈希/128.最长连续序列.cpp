/*
 * @Author: your name
 * @Date: 2022-02-27 16:55:02
 * @LastEditTime: 2022-04-20 12:13:55
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/哈希/128.最长连续序列.cpp
 */
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(const auto& num : nums)
            hash.emplace(num);
        int ans = 0;
        while(!hash.empty()){
            int cur = *(hash.begin());
            hash.erase(cur);
            //求长度，双指针反向滑动
            int next = cur + 1,prev=cur-1;
        
            while(hash.count(next))
                hash.erase(next++);
            while(hash.count(prev))
                hash.erase(prev--);
            //找出最值通用做法，每次迭代出现一个值——>找出当前最值
            ans = max(ans, next - prev - 1);
            if(ans >=nums.size()/2+1) break;
        }
        return ans;
    }
};
// @lc code=end

