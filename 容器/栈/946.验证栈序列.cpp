/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-27 21:42:03
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-27 21:50:26
 * @FilePath: /.leetcode/容器/栈/946.验证栈序列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
//模拟+辅助栈
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int index = 0;
        for (int i = 0;i<pushed.size();++i){
            s.push(pushed[i]);
            while(!s.empty()&&s.top()==popped[index]){
                s.pop();
                ++index;
            }
        }
        return s.empty();
    }
};
// @lc code=end

