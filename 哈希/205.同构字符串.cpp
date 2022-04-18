/*
 * @Author: your name
 * @Date: 2022-02-28 20:57:53
 * @LastEditTime: 2022-04-05 18:38:26
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/哈希/205.同构字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
//两个研究对象之间有映射关系
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        int len = s.size();
        for (int i = 0; i < len;++i){
            //x,y作为媒介使两个字符串中的元素对应起来
            char x = s[i], y = t[i];
            if(s2t.count(x)&&s2t[x]!=y||(t2s.count(y)&&t2s[y]!=x))
                return false;
            s2t[x] = y;
            t2s[y] = x;

        }
        return true;
    }
};

//两个map少不了
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map<char, char> s2t;
//         if(s.size()!=t.size()) return false;

//         for (int i = 0;i < s.size();++i){
//             if(s2t[s[i]]=='\0'){
//                 s2t[s[i]]=t[i];
//             }else if(s2t[s[i]]!=t[i]){
//                 return false;
//             }
//             if(s2t[t[i]]=='\0'){
//                 s2t[t[i]]=s[i];
//             }else if(s2t[t[i]]!=s[i]){
//                 return false;
//             }
//         }
        
//         return true;
//     }
// };


// @lc code=end

