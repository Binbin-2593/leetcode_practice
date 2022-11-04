/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-20 23:20:01
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-25 15:22:00
 * @FilePath: /.leetcode/字符串/8.字符串转换整数-atoi.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        char prev='+';
        long long tmp = 0;
        int i = 0,n=s.size();
        while(i<n){
            //排除一开始就出现字母、‘.’
            if(isalpha(s[i])||s[i] == '.')
                return 0;
            //过滤前导' '
            while (i < n && s[i] == ' ' )
                ++i;
            //遇到符号
            if (i < n && s[i] == '+'){
                //排除符号出现在末尾
                if(i<n-1&&!isdigit(s[i+1])){
                    return 0;
                }else{
                    ++i;
                    prev = '+';
                }
            }
            if(i<n &&s[i]=='-'){
                if(n-1&&!isdigit(s[i+1])){
                    return 0;
                }else{
                    ++i;
                    prev = '-';
                }
            }
            //遍历出数字
            if(i<n&&isdigit(s[i])){
                while(i<n&&isdigit(s[i])){
                    tmp = tmp * 10 + s[i] - '0';
                    //每次数据的增大一级，都与边界对比，此时的tmp还是绝对值
                    tmp= (prev== '-')? min(tmp, -(long long)INT_MIN) : min(tmp, (long long)INT_MAX);
                    ++i;
                }
                //遍历完返回
                return (prev== '-')?-tmp:tmp;
            }
        }
        return 0;
    }
};

class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
