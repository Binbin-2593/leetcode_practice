/*
 * @Author: your name
 * @Date: 2022-04-25 17:18:46
 * @LastEditTime: 2022-04-25 20:20:45
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/524.通过删除字母匹配到字典里最长单词.cpp
 */
/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
// class Solution {
// public:
//     string findLongestWord(string s, vector<string>& dictionary) {
//         string ans = "";
//         int len=s.size();
//         for(auto &str:dictionary){
//             int i = 0, j = 0,slen=str.size();
//             while(i<slen&&j<len){
//                 if(str[i]==s[j]){
//                     ++i;
//                     ++j;
//                 }else{
//                     ++j;
//                 }
//             }
//             if(i==slen){
//                 if(slen>ans.size()||slen==ans.size()&&str.compare(ans)<0){
//                     ans = str;
//                 }
//             }
//         }
//         return ans;
//     }
// };
//先排序再比对
class comp{
public:
    bool operator()(string &s1,string &s2){
        int l1=s1.size(),l2=s2.size();
        if(l1<l2||(l1==l2&&s1.compare(s2)>0)){
            return true;
        }else{
            return false;
        }
        //关于sort的comp大小逻辑问题
            //把vector降序就用<返回true（反着的感觉）
    }

};

class Solution{
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), comp());
        string ans = "";
        int len=s.size();
        for(auto &str:dictionary){
            int i = 0, j = 0,slen=str.size();
            while(i<slen&&j<len){
                if(str[i]==s[j]){
                    ++i;
                    ++j;
                }else{
                    ++j;
                }
            }
            if(i==slen){
                ans = str;
            }
        }
        return ans;
    }
};

// @lc code=end

