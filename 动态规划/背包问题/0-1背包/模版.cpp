/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-05-09 18:58:55
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-13 17:46:30
 * @FilePath: /.leetcode/动态规划/背包问题/0-1背包/二维.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//二维
int knapsack(vector<int>weights,vector<int>values,int N,int W){
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));//dp[i][j] 表示前 i 件物品体积不超过 j 的情况下能达到的最大价值
    for (int i = 1; i <= N;++i){
        int w = weights[i - 1], v = values[i - 1];
        for (int j = 1;j<=W;++j){//关于两个for循环，可同遍历二维数组理解
            if(j>=w){ 
            //目前背包容量j，能装下i;
                //1.不装：dp[i - 1][j]。
                //2.装:dp[i - 1][j - w] + v,即容量j的包先装下w，就变成了容量j-w的包，再去装i-1个物
                dp[i][j] = max(dp[i - 1][j] + dp[i - 1][j - w] + v);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][W];
}
//一维压缩
//假设我们目前考虑物品 i = 2，且其体积为 w = 2，价值为 v = 3;
//对于背包容量 j，我们可以得到 dp[2][j] = max(dp[1][j], dp[1][j-2] + 3)。
//这里可以发现我们永远只依赖于上一排 i = 1 的信息，之前算过的其他物品都不需要再使用
    //这个过程中，也是dp的特性，每一级依托于上一级，而每一级又能体现出之前的所有
int knapsack(vector<int>weights,vector<int>values,int N,int W){
    vector<int> dp(W+1,0);
    for (int i = 1; i <= N;++i){
        int w = weights[i - 1],v=values[i-1];
        //每拿出一个物品i，都试一下“所有容量的背包”怎么装,
        //形成这个i对应的vector<int>，i+1的vector<int>就依据i的产生，覆盖
        for (int j = W; j >= w;--j){//逆向遍历：用 上一行物品 i-1 时 dp[j-w] 的值
            dp[j] = max(dp[j], dp[j - w] + v);//这里dp[j]、dp[j-w]都是上一级i-1对应的值
        }
    }
    return dp[W];
}