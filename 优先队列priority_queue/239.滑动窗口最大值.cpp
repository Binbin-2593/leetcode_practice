/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start


//最值问题第一步先想优先队列行不行
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        //同时使用到数组元素的多个属性，使用pair类型
        priority_queue<pair<int, int>> q;
        for (int i = 0;i<k;++i){
            //向这几个容器适配器里构造添加元素，只有emplace
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first};

        for (int i = k;i<n;++i){
            q.emplace(nums[i], i);
            //把离得远的不是框中的最大值踢出
            while(q.top().second<=i-k){
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
// @lc code=end

