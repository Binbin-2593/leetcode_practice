/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-09-29 20:28:14
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-29 20:45:37
 * @FilePath: /.leetcode/容器/栈/32.最长有效括号.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        stack<int> stk;
        stk.push(-1);//充当边界条件
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {//每个‘（’直接入栈
                stk.push(i);
            } else {//遇到‘）’
                stk.pop();//直接pop栈顶
                if (stk.empty()) {//如果空，说明这个‘）’匹配了初始化的边界条件，不能算，入栈
                    stk.push(i);
                } else {
                    //栈不空，表明从之前某个节点，到目前都是有效的
                    //i-stk.top(),是一段有效的括号段
                    ret = max(ret, i - stk.top());
                }
            }
        }
        return ret;
    }
};
// @lc code=end

