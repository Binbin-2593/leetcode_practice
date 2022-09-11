/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-27 21:56:25
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-28 13:32:40
 * @FilePath: /.leetcode/z剑指offer/38.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

//需要考虑s中字符有重复的问题
class Solution {
    vector<string> res;
    string path;
    void backtracking(string s, vector<int>& used) {
        if (path.size() == s.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (used[i] || (i > 0 && !used[i - 1] && s[i] == s[i - 1]))//理解：保证在填每一个空位的时候重复字符只会被填入一次。具体地，我们首先对原字符串排序，保证相同的字符都相邻，在递归函数中，我们限制每次填入的字符一定是这个字符所在重复字符集合中「从左往右第一个未被填入的字符」
                continue;
            path.push_back(s[i]);
            used[i] = 1;
            backtracking(s, used);
            used[i] = 0;
            path.pop_back();
        }
    }
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<int> used(s.size(), 0);
        backtracking(s, used);
        return res;
    }
};


