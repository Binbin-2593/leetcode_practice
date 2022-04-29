/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

//本问题有两个需要的数据关系:1.数据有匹配关系2.数据的匹配规则还要满足：先获取后匹配，后获取先匹配
// class Solution {
// public:
//     bool isValid(string s) {
//         if(s.size()%2!=0) return false;
        
//         //unordered_map用来存储和呈现键值对关系
//         unordered_map<char,char> pairs={
//             {')','('},
//             {'}','{'},
//             {']','['}
//         };

//         //使用栈用来实现上述第二个数据关系
//         stack<char> cstk;
//         for (auto &c:s){
//             if(pairs.count(c)){
//                 if(cstk.empty()||cstk.top()!=pairs[c])
//                     return false;
//                 cstk.pop();
//             }
//             else cstk.push(c);//使用选择语句一定注意else是不是可以省
//         }
//         return cstk.empty();
//     }
// };


//使用switch完成多种情况的匹配处理问题

class Solution {
public:
    bool isValid(string s){
        stack<char> cstk;
        for(auto &c:s){

            //一个现实问题如果需要分多类讨论的话，想起switch试试
            switch(c){
                case '(':
                case '[':
                case '{': cstk.push(c); break;
                case ')':if(cstk.empty()||cstk.top()!='(') return false; else cstk.pop(); break;
                case ']':if(cstk.empty()||cstk.top()!='[') return false; else cstk.pop(); break;
                case '}':if(cstk.empty()||cstk.top()!='{') return false; else cstk.pop(); break;
                default:;
            }
        }
        return cstk.empty();
    }
};
// @lc code=end
