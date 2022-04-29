/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
//使用一个队列
class MyStack {
    queue<int> q;
    //queue<int> q2;

public:
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
        //q2.push(x);
    }

    int pop() {
        int a=q.back();
        for (int i = 1;i <= q.size();++i){
            if(i<q.size())
                q.push(q.front());
            q.pop();
        }
        return a;
    }

    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

