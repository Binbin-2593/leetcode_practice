class Solution{
public:
    int findCircleNum(vector<vector<int>> &friends){
        int n=friends.size(),count=0;
        //是否被遍历到，初始化
        vector<bool> visited(n, false);
        queue<int> q;
        for (int i = 0;i<n; ++i){
            if(!visited[i]){
                q.push(i);
                while(!q.empty()){
                    //遍历到就标识
                    visited[q.front()]=true;
                    q.pop();
                    for (int j = 0;j<n; ++j){
                        //所有有联系的入队
                        if(friends[i][j]==1&&!visited[j])
                            q.push(j);
                    }
                }
            }
            ++count;
        }
        return count;

    }

    
};