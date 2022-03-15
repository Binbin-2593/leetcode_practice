/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
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
};
// @lc code=end

