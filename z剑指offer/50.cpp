/*
 * @Author: your name
 * @Date: 2022-04-28 19:14:06
 * @LastEditTime: 2022-04-28 19:58:02
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/50.cpp
 */
//不适合用双指针
/*
class Solution {
public:
    char firstUniqChar(string s) {
        int n = s.size();
        if (n == 0)
            return ' ';
        unordered_set<char> hash;
        int l = 0;
        for (int r = 1; r < n;++r){
            if (s[r]==s[l]){
                hash.insert(s[l]);
                while(hash.count(s[l])){
                    ++l;
                }
            }
        }
        return s[l];
    }
};*/
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<int, int> frequency;
        for (char ch: s) {
            ++frequency[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (frequency[s[i]] == 1) {
                return s[i];
            }
        }
        return ' ';
    }
};
