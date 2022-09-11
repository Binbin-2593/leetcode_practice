/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-01 16:24:37
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-19 16:47:55
 * @FilePath: /.leetcode/容器/栈/227.基本计算器-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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

