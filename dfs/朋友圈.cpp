/*
 * @Author: your name
 * @Date: 2022-03-16 22:09:44
 * @LastEditTime: 2022-04-06 16:04:59
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/深度优先搜索/朋友圈.cpp
 */
/*
班上有N名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
如果已知A是B的朋友，B是C的朋友，那么我们可以认为A也是C的朋友。所谓的朋友圈，是指所有朋友的集合。
给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:
输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2 
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
*/
class Solution{
public:
    int findCircleNum(vector<vector<int>> &friends){
        //小岛有M*N个节点，这里只有N个节点，所以一层for遍历即可
        int n = friends.size(), count = 0;
        //初始化标记，便于搜索的遍历即标记的要求
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i){
            if(!visited[i]){
                dfs(friends,visited);
                ++count;
            }
            
        }
        return count;
        
    }

    //递归
    void dfs(vector<vector<int>>&friends,vector<bool>&visited,int i){
        //step1:处理当前节点
        //dfs都是要做好记录的
        visited[i]=true;
        //step2:开始递归
        for(int j=0; j<n; ++j){
            if(friends[i][j]==1&&!visited[j])
                dfs(friends, visited, j);
        }
    }
};