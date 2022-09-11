/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-14 21:55:45
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-14 22:16:06
 * @FilePath: /.leetcode/z剑指offer/09.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class CQueue {
public:
    CQueue() {}
    
    void appendTail(int value) {
       in.push(value);
    }
    
    int deleteHead() {
        if(out.empty()){
            if(in.empty()){
                return -1;
            }else{
                InToOut()
            }
        }
        int val=out.top();
        out.pop();
        return val;
    }

private:
    stack<int> in,out;//一个负责入，一个负责出
    void InToOut(){
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
};