/*
 * @Author: your name
 * @Date: 2022-02-27 21:06:06
 * @LastEditTime: 2022-04-27 14:27:00
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/字符串/字符串比较/242.有效的字母异位词.cpp
 */
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> counts(26, 0);
        for (int i = 0;i<s.size();++i){
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }
        for(const int & i : counts){
            if(i){
                return false;
            }
        }
        return true;
    }
};*/
class Solution {
public:
    bool isAnagram(string s,string t){
        if(s.size()!=t.size()) return false;
        unordered_map<int, int> hash;
        for (auto & c : s){
            ++hash[c - 'a'];
        }
        for(auto & h:t){
            if(!hash[h-'a']){
                return false;
            }else{
                --hash[h-'a'];
            }
        }
        return true;
    }
};
// @lc code=end
