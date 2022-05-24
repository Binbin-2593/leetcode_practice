/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-24 17:25:43
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-24 21:45:26
 * @FilePath: /.leetcode/排序/桶排序/347.前-k-个高频元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int max_count = 0;
        for (const auto num : nums){
            max_count = max(max_count, ++hash[num]);
        }

        vector<vector<int>> buckets(max_count + 1);//用二维因为同频率的不只一个元素
        //vector的元素做桶，下标表示次数，桶内装此次数对应的元素值
        for(const auto& h:hash){
            buckets[h.second].push_back(h.first);
        }

        vector<int> ans;
        for (int i = max_count;i>=0&&ans.size()<k; --i){
            for(const auto& j:buckets[i]){
                ans.push_back(j);
                if(ans.size()==k){
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

