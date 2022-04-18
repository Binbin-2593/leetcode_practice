/*
 * @Author: your name
 * @Date: 2022-04-08 16:06:58
 * @LastEditTime: 2022-04-13 20:16:26
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/深度优先搜索/回溯法/79.单词搜索.cpp
 */
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
/*
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int m = board.size(), n = board[0].size();

        //本题是通过暴力回溯枚举看看能不能出现某种情况，套路：bool find = false——>dfs看有没有改变find
        bool find = false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0;i < m;++i){
            for (int j = 0;j<n;++j){
                backtrack(board,word,visited,i,j,0,find);
            }
        }
        return find;
    }

    void backtrack(vector<vector<char>>&board,string &word,vector<vector<bool>> &visited,int i,int j,int pos,bool &find){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) return ;
        if(visited[i][j]||board[i][j]!=word[pos]||find) return ;
        if(pos==word.size()-1) {
            find = true;
            return ;
        }

        visited[i][j]=true;
        backtrack(board, word, visited, i + 1, j, pos + 1,find);
        backtrack(board, word, visited, i -1, j, pos + 1,find);
        backtrack(board, word, visited, i , j+1, pos + 1,find);
        backtrack(board, word, visited, i , j-1, pos + 1,find);
        visited[i][j]=false;
    }
};*/
class Solution {
    vector<int> d{-1, 0, 1, 0, -1};
public:
    bool exist(vector<vector<char>>& board,string word){
        if(board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0;i<m;++i){
            for (int j = 0;j<n;++j){
                backtrack(board,word,visited,find,i,j,0);
            }
        }
        return find;
    }

    void backtrack(vector<vector<char>>& board,string &word,vector<vector<bool>>& visited,bool& find,int i,int j,int pos){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||visited[i][j]||find||board[i][j]!=word[pos])
            return;
        if(pos==word.size()-1){
            find=true;
            return;
        }

        visited[i][j]=true;
        for (int k = 0; k < 4;++k){
            int x = i + d[k], y = j + d[k + 1];
            backtrack(board, word, visited, find, x, y, pos + 1);
        }
        visited[i][j]=false;
    }
};
// @lc code=end

