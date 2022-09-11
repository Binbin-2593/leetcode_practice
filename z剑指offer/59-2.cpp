/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-28 19:02:16
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-28 19:41:53
 * @FilePath: /.leetcode/z剑指offer/59-2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class MaxQueue {
public:
    MaxQueue() {}
    
    int max_value() {
        if(q.empty()){
            return -1;
        }else{
            return d.front();
        }
    }
    
    void push_back(int value) {
        //由于队列的先进先出，当a进入队列，前面有比它小的元素，对最大值没有影响，可以直接删了
        //删了也是提高效率，之后进来的元素，避免了一些无必要的比较
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty()){
            return -1;
        }
        int v=q.front();
        if (v == d.front()) {
            d.pop_front();
        }
        q.pop();
        return v;
    }
private:
    queue<int> q;
    deque<int> d;
};