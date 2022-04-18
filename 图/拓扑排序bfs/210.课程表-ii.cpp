/*
 * @Author: your name
 * @Date: 2022-03-15 10:34:39
 * @LastEditTime: 2022-04-18 19:57:08
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/图/拓扑排序bfs/210.课程表-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //存图
        vector<vector<int>> graph(numCourses, vector<int>());
        //存入度
        vector<int> indegree(numCourses, 0), ans;
        
        for(const auto&p:prerequisites){
            graph[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }
        //0入度，直接推入
        queue<int>q;
        for (int i = 0; i < numCourses;++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int n=q.front();
            ans.push_back(n);
            q.pop();

            for(auto v:graph[n]){
                --indegree[v];
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        //在bfs处理之后，再次看是否还有节点需要入度
        //因为我们bfs是顺序层次处理的，所以出现相互入度节点肯定无法把入度值减为0
        for (int i = 0;i<numCourses;++i){
            if(indegree[i])
                return {};
        }
        return ans;
    }
};
// @lc code=end

