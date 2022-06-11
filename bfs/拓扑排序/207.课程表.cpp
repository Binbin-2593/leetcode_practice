/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-03 16:32:37
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-03 18:46:32
 * @FilePath: /.leetcode/bfs/拓扑排序/207.课程表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 */
/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //存图：入度关系
        vector<vector<int>> grid(numCourses, vector<int>());
        //存节点对应的入度数
        vector<int> in(numCourses);

        for(const auto&p:prerequisites){
            //节点数值充当下标
            grid[p[1]].push_back(p[0]);
            ++in[p[0]];
        }

        //初始入度为0的节点为突破口
        queue<int> q;
        for (int i = 0;i<numCourses;++i){
            if(in[i]==0){
                q.push(i);
            }
        }
        //调整节点入度数，==0时入队
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto v:grid[temp]){
                --in[v];
                if(in[v]==0){
                    q.push(v);
                }
            }  
        }        
        //检查，是否存在节点入度没降为0的
        for(auto& j:in){
            if(j)
                return false;
        }

        return true;
    }
};
// @lc code=end

