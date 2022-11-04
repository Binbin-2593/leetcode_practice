/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-10-14 18:38:59
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-10-14 18:42:26
 * @FilePath: /.leetcode/72.编辑距离.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start


//对单词A删除一个字符和对单词B插入一个字符是等价的,总结出本质三种操作
    //1.在单词 A中插入一个字符
    //2.在单词 B中插入一个字符
    //3.修改单词 A的一个字符
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        /* 定义dp数组 */
        //dp[i][j]表示下标i-1结尾的w1，j-1结尾的w2,最近编译距离为dp[i][j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        /* dp数组初始化 */
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        /* 遍历 */
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    //当前位置相同，不做操作
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    //三种操作中最小值，这里下标只表示string长度的含义
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

