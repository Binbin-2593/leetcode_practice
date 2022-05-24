/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-24 20:59:45
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-24 21:19:15
 * @FilePath: /.leetcode/容器/优先队列/347.前-k-个高频元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Comp{
public:
    bool operator()(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second > p2.second;
    }
};
class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(const auto&num : nums){
            ++hash[num];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> q;

        // for(const auto& p:hash){
        //     q.emplace(p);
        // }

        // vector<int> ans;
        // while(!q.empty()&&ans.size()<k){
        //     ans.emplace_back(q.top().first);
        //     q.pop();
        // }
        //下面写法用时少
        for (const auto &p:hash){
            if(q.size()==k){
                if(q.top().second<p.second){
                    q.pop();
                    q.emplace(p);
                }
            }else{
                q.emplace(p);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.emplace_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

