/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-10 16:06:54
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-10 16:49:50
 * @FilePath: /.leetcode/动态规划/背包问题/474. 一和零.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //理解：
            //这里遍历的每个“物品”是str，重量是[count0，count1]，价值是1
            //一个“物品”切两份，用两个背包同时装
        for (auto &str : strs){
            auto [count0, count1] = count(str);
            for (int i = m;i>=count0;--i){
                for (int j = n; j >= count1;--j){
                    //两个背包（做空间压缩做到了二维）
                    dp[i][j] = max(dp[i][j], 1 + dp[i - count0][j - count1]);
                }
            }
        }
        return dp[m][n];
    }
    pair<int,int> count(string& str){
        int count0=str.size(),count1=0;
        for(auto ch:str){
            if (ch=='1'){
                ++count1;
                --count0;
            }
        }
        return make_pair (count0, count1 );
    }
};
