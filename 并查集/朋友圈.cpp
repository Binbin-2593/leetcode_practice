/*
 * @Author: your name
 * @Date: 2022-04-17 19:51:39
 * @LastEditTime: 2022-04-17 20:03:42
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/并查集/朋友圈.cpp
 */
class UF{
    vector<int> id,size;
    //问题是找有多少个集合时
    int counts;
public:
    UF(int n):id(n),size(n,1){
        counts = n;
        iota(id.begin(), id.end(), 0);
    }
    
    int find(int p){
        while(p!=id[p]){
            //拒绝中间爹，寻根
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    void connect(int p,int q){
        int i = find(p), j = find(q);
        if(i!=j){
            if(size[i]<size[j]){
                id[i]=j;
                size[j] += size[i];
            }else{
                id[j] = i;
                size[i] += size[j];
            }
            counts--;
        }
    }

    bool isConnected(int p,int q){
        return find[p] == find(q);
    }
};

class Solution{
public:
    int findCircleNum(vector<vector<int>> &friends){
        int m=friends.size(),n=friends[0].size();
        UF uf(m);
        for (int i = 0;i<m;++i){
            for (int j;j<n;++j){
                if(friends[i][j]==1){
                    uf.connect(i, j);
                }
            }
        }
        return uf.counts;
    }
};