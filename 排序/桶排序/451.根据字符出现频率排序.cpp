/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-24 21:20:55
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-24 21:52:32
 * @FilePath: /.leetcode/排序/桶排序/451.根据字符出现频率排序.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        int max_count = 0;
        for (const auto &c : s){
            max_count=max(max_count,++hash[c]);
        }
        vector<string>buckets(max_count+1);
        for(auto &h:hash){
            buckets[h.second].push_back(h.first);
        }
        string ans;
        for (int i = max_count; i > 0;--i){
            string &bucket=buckets[i];
            for(auto &ch:bucket){
                int count=i;
                while (count--){
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

