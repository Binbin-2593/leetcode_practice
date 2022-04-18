/*
 * @Author: your name
 * @Date: 2022-03-15 10:32:57
 * @LastEditTime: 2022-04-18 19:19:34
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/图/二分图/785.判断二分图.cpp
 */
/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
//注意本题题目给的一种图的存储方式
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        if (!n)
            return true;

        vector<int> color(n, 0);
        queue <int> q;
        for (int i = 0; i < n;++i){
            if(!color[i]){
                q.push(i);
                color[i] = 1;
            }
        //如果确定图中没有“孤儿”，可用下方随便选一点初始化
        //如果不能确定必须向上面for每一个点都要判断是否被搜到，如果没有认为push和初始化
        //q.push(0);color[0]=1;

            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(const int&j:graph[node]){
                    if(color[j]==0){
                        q.push(j);
                        color[j] = color[node] == 2 ? 1 : 2;
                    }else if(color[j]==color[node]){
                        return false;
                    }
                }
            }   
        }
        return true;
    }
};
// @lc code=end

