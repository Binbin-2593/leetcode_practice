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
            hash.insert(num);
        int ans = 0;
        while(!hash.empty()){
            int cur = *(hash.begin());
            hash.erase(cur);
            int next = cur + 1,prev=cur-1;

            while(hash.count(next))
                hash.erase(next++);
            while(hash.count(prev))
                hash.erase(prev--);

            ans = max(ans, next - prev - 1);
            if(ans >=nums.size()/2+1) break;
        }
        return ans;
    }
};
// @lc code=end

