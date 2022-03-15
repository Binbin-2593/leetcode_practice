/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
//思路：如果两个字符串中相同位置的字符与它们第一次出现的位置一样
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //第一次出现的位置都初始化为0
        vector<int> s_first_index(256, 0), t_first_index(156, 0);
        for (int i = 0;i<s.size(); ++i){
            if(s_first_index[s[i]]!=t_first_index[t[i]]) return false;
            //此前出现位置相同，接下来记录此次出现的位置
            s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end

