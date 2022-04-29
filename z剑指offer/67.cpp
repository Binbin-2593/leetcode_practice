/*
 * @Author: your name
 * @Date: 2022-04-29 14:44:48
 * @LastEditTime: 2022-04-29 17:15:50
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/67.cpp
 */
/*
class Solution {
public:
    int strToInt(string str) {
        long long ans = 0;bool flag = false,per=false;
        for (int i = 0;i < str.size(); ++i){
            char c = str[i];
            if (!flag){
                switch(c){
                    case ' ':
                        continue;
                        //break;//switch中使用的break作用与其对应的{}
                        //而switch中的continue做用于其所在的循环的{}
                    case '+':
                        flag=true;
                        continue;
                    case '-':
                        flag=true;
                        per=true;
                        continue;   
                }
                if(!isdigit(c)){
                    break;
                }else{
                    flag = true;
                    //下面char数字转int
                    ans = ans * 10 + (c-'0');
                }
            }else{
                if(!isdigit(c)){
                    break;
                }else{
                    ans = ans * 10 + (c-'0');
                    //关于数字溢出问题，要设置每步都要检测
                    //而不是先让其运行下去最后再检测，这样就爆了
                    if(per){
                        if(-ans<INT_MIN){
                            return INT_MIN;
                        }    
                    }else{
                        if(ans>INT_MAX){
                            return INT_MAX;
                        }
                    }  
                } 
            }
        }
        if(per){
            ans = -ans;
        }
        return ans;
    }
};
*/
//状态机
    //就是处理字符串问题，当前可能遇到几类情况
    //遇到不同类的情况又结合之前的情况有不同的处理方式
class Automaton {
    string state = "start";//初始化状态
    //存储状态及转化关系
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
    bool stop = false;

    void get(char c) {
        //更新状态并做处理
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
        else if(state=="end"){
            stop=true;
        }
    }
};

class Solution {
public:
    int strToInt(string str) {
        //这里可以看出，其实创造类也就是创建一个广义的“函数”
        //这个“函数”接收数据，用其内部的容器装数据、函数处理数据
        //通过一系列处理产生处理的结果（数据），这些结果以此“函数”内部变量、容器的形式装载
        //在一个作用域内，只要这个类对象还在，就能使用其内部的所有
        Automaton automaton;
        for (char c : str){
            //没有反而更快，不用每次都做判
            // if(automaton.stop){
            //     break;
            // }
            automaton.get(c);
        }  
        return automaton.sign * automaton.ans;
    }
};