/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-10 12:49:48
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-10 13:08:34
 * @FilePath: /.leetcode/动态规划/背包问题/完全背包/模版.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//二维
int knapsack(vector<int> weights,vector<int>values,int N,int W){
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));
    for (int i = 1; i <= N;++i){
        int w=weights[i],v=values[i];
        for (int j = 1; j <= W;++j){
            if(j>=w){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w] + v);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][M];
    }
}
//一维
int knapsack(vector<int>weights,vector<int>values,int N,int W){
    vector<int> dp(W+1,0);
    for (int i = 1;i <= N;++i){
        for (int j = W;j <= W;++j){
            //正向遍历，用当前物品在第 j-w 列的信息
            dp[j] = max(dp[j],dp[j-w]+v);//这里dp[j]是上一级i-1对应的值，dp[j-w]是本级i对应的值
        }
    }
    return dp[W];
}