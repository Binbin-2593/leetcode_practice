/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        if(tickets.empty()) return ans;

        unordered_map<string,multiset<string>> hash;
        for (const auto &x:tickets)
            hash[x[0]].insert(x[1]);

        //跑图过程中的数据存储容器不能用vector(它是线性的关系，没有折回)；使用stack
        // string cur = "JFK";
        // while (!hash[cur].empty()){
        //     ans.push_back(*hash[cur].begin());
        //     hash[cur].erase(hash[cur].begin());
        //     cur = ans.back();
        // }

        stack<string> s;
        s.push("JFK");
        while(!s.empty()){
            string cur = s.top();
            if(hash[cur].empty()){
                ans.push_back(cur);
                s.pop();
            }
            else{
                s.push(*hash[cur].begin());
                hash[cur].erase(hash[cur].begin());
            }

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

