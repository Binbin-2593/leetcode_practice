/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count=0,cur_max=0;
        for (int i = 0;i<arr.size();++i){
            cur_max = max(arr[i], cur_max);
            if (cur_max==i) ++count;
        }
        return count;
    }
};
// @lc code=end

