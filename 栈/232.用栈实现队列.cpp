/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */



// @lc code=start
class MyQueue {
    stack<int> sin, sout;

public:
    MyQueue() {

    }
    
    void push(int x) {
        sin.push(x);
    }
    
    int pop() {
        int b=peek();
        sout.pop();
        return b;
    }
    
    int peek() {
        //这里非常重要，这个stack的元素转移要分批次的，必须保证sout空才能转移，这样才满足功能
        if(sout.empty())
            while(sin.size()){
                sout.push(sin.top());
                sin.pop();
            }
       return sout.top();
    }
    
    bool empty() {
        return sin.empty()&&sout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

