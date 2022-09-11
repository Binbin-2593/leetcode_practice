/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-30 21:44:40
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-30 21:50:05
 * @FilePath: /.leetcode/997.找到小镇的法官.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1), out(n + 1);
        for(auto&t:trust){
            int x = t[0], y = t[1];
            ++in[y];
            ++out[x];
        }
        for (int i = 1; i <= n;++i){
            if(in[i]==n-1&&out[i]==0)
                return i;
        }
        return -1;
    }
};
// @lc code=end

