/*
 * @Author: your name
 * @Date: 2022-04-17 19:33:25
 * @LastEditTime: 2022-04-17 19:50:34
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/并查集/684.冗余连接.cpp
 */
/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class UF{
    vector<int> id,size;
public:
    UF(int n):id(n),size(n,1){
        iota(id.begin(),id.end(),0);
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
        }
    }

    bool isConnected(int p,int q){
        return find(p) == find(q);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //也就是说，我们做了一个有某些功能特性的类（数据结构）
        //把源数据（edges）按照其（UF）特性存入其中
        //这样数据直接就有了某些关系结构（数据结构）
        //然后利用这些关系结构解决问题
        int n=edges.size();
        UF uf(n + 1);//这里数组长度参数注意

        for(auto e:edges){
            int u = e[0], v = e[1];
            if(uf.isConnected(u,v))
                return e;
            uf.connect(u, v);
        }
        return vector<int>{};
    }
};
// @lc code=end

