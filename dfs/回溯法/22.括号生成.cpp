/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-07 16:51:07
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-07 17:10:28
 * @FilePath: /.leetcode/dfs/回溯法/22.括号生成.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string cur;
        backtrack(ret,cur,0,0,n);
        return ret;
    }
    void backtrack(vector<string>&ret,string&cur,int l,int r,int n){
        if(cur.size()==n*2){
            ret.emplace_back(cur);
            return;
        }
        if(l<n){
            cur.push_back('(');
            backtrack(ret, cur, l + 1, r, n);
            cur.pop_back();
        }
        if(r<l){
            cur.push_back(')');
            backtrack(ret, cur, l, r + 1, n);
            cur.pop_back();
        }
    }
};
// @lc code=end

