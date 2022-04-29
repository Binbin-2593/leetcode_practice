/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
//用vector维护一个栈
class Solution {
public:
    int calculate(string s) {
        vector<int> stack;
        char preSign = '+';
        int num = 0,n=s.size();
        for (int i = 0; i < n;++i){
            if(isdigit(s[i])){
                //char型数字转int
                num = num * 10 + int(s[i] - '0');
            }
            if(!isdigit(s[i])&&s[i]!=' '||i==n-1){
                switch (preSign)
                {
                case  '+':
                    stack.push_back(num);
                    break;
                case '-':
                    stack.push_back(-num);
                    break;
                case '*':
                    stack.back() *= num;
                    break;

                default:
                    stack.back() /= num;
                }
                //preSign面向过程编程中典型的，遇到的先存起来，往后再走一步，然后结合preSign做处理
                preSign=s[i];
                num = 0;
            }
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};
// @lc code=end

