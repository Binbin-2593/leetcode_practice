/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-21 17:02:00
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-21 17:25:13
 * @FilePath: /.leetcode/z剑指offer/30.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        m.push(INT_MAX);
    }

    void push(int x) {
        s.push(x);
        m.push(m.top()<=x?m.top():x);
    }

    void pop() {
        s.pop();
        m.pop();
    }

    int top() {
        return s.top();
    }

    int min() {
        return m.top();
    }
private:
    stack<int> m;
    stack<int> s;
};
