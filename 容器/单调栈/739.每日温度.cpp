/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> index;

        for (int i = 0; i < n;++i){
            while(!index.empty()){
                int pre_index = index.top();
                if(temperatures[i]<=temperatures[pre_index])
                    break;
                index.pop();
                ans[pre_index] = i - pre_index;
            }
            index.push(i);
        }
        return ans;
    }
};
// @lc code=end

