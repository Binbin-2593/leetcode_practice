/*
 * @Author: your name
 * @Date: 2022-04-12 17:39:52
 * @LastEditTime: 2022-04-20 12:16:03
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/深度优先搜索/回溯法/51.n-皇后.cpp
 */
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n==0)
            return ans;

        vector<string> board(n, string(n, '.'));
        //下面三个vector，是一个重要的小细节：计算机和人的差别
        //计算机做了某件事产生的影响变化，如果后面有需要用到这些“影响变化”，就要在做某事的那步把“影响变化”存起来
        //人不用存是因为，人可以站在此刻回看之前产生了什么“影响变化”
        vector<bool> column(n, false), ldiag(2 * n - 1, false), rdiag(2 * n - 1, false);
        backtrack(ans, board, column, ldiag, rdiag, n, 0);
        return ans;
    }

    void backtrack(vector<vector<string>>&ans,vector<string>& board,vector<bool>& column,vector<bool>& ldiag,vector<bool>& rdiag,int n,int row){
        if(row==n){
            ans.emplace_back(board);
            return;
        }

        for(int i=0; i<n; ++i){
            if(column[i]||ldiag[n-row+i-1]||rdiag[row+i+1]){
                continue;
            }

            board[row][i] = 'Q';
            column[i]=ldiag[n-row+i-1]=rdiag[row+i+1]=true;
            backtrack(ans, board, column, ldiag, rdiag, n, row + 1);
            board[row][i] = '.';
            column[i]=ldiag[n-row+i-1]=rdiag[row+i+1]=false; 
        }
    }
};
// @lc code=end

