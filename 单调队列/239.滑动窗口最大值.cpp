/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
//超时
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         auto f = nums.begin(), l = f + k ;
//         while(l<=nums.end()){
//             ans.push_back(*(max_element(f, l)));
//             ++f;
//             ++l;
//         }
//         return ans;
//     }
// };

//用deque来维护一个单调队列(两端都能进出)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0;i<nums.size();++i){
            //超出窗口的踢出
            while(q.size()&&i-k+1>q.front()){
                q.pop_front();
            }
            //维护单调递减队列（需求大值）
            while(q.size()&&nums[i]>nums[q.back()]){
                q.pop_back();
            }

            q.push_back(i);
            //判断窗口滑过的元素数超k个，开始往数组中写入
            if(i-k+1>=0)
                ans.push_back(nums[q.front()]);
        }
            return ans;
    }
};


// @lc code=end

