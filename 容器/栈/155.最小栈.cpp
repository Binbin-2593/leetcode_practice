/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    //要完成一个特殊性能要求的栈，我们可以封装几个基本栈，通过算法来实现
    stack<int> data_stack;
    stack<int> min_stack;

public:
    MinStack() {
        //data_stack=new stack ;
        //min_stack =new stack;
    }

    void push(int val) {
        if(min_stack.empty()||val<=min_stack.top())
            min_stack.push(val);
        data_stack.push(val);
    }

    void pop() {
        //先pop()min_stack，因为其中的值受data_stack影响
        if(min_stack.top()==data_stack.top())
            min_stack.pop();
        data_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

