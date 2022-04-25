/*
 * @Author: your name
 * @Date: 2022-04-19 11:49:54
 * @LastEditTime: 2022-04-19 15:13:46
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/13.cpp
 */
class Solution{
    vector<int> d{0,1,0};
public:
    int movingCount(int m,int n,int k){
        int count = 0;int x,y;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0,0});
        visited[0][0]=true;
        while(!q.empty()){
            auto [r,c]=q.front();
            //错误操作时间点
            // visited[r][c]=true;
            // ++count;
            q.pop();

            for (int l = 0; l < 2;++l){
                x = r + d[l], y = c + d[l + 1];
                if(x>=0&&y>=0&&x<m&&y<n&&!visited[x][y]){
                    if(get(x)+get(y)<=k){
                        q.push({x, y});
                        //在节点入队时就要及时visited=true，防止从另一条路到达此节点再被入队一次
                        visited[x][y]=true;
                        ++count; 
                    }
                }
            }
        }
        return count;
    }
    //一个整数各位数字和的算法
    int get(int x) {
        int res=0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
};