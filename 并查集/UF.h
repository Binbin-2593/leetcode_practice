/*
 * @Author: your name
 * @Date: 2022-04-17 16:52:43
 * @LastEditTime: 2022-04-17 20:07:19
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/并查集/UF.h
 */

/*
并查集一般可以解决一下问题 :

1.查找元素属于哪个集合
    沿着数组表示树形关系以上一直找到根(即：树中中元素为负数的位置)
2.查看两个元素是否属于同一个集合
    沿着数组表示的树形关系往上一直找到树的根，如果根相同表明在同一个集合，否则不在
3.将两个集合归并成一个集合
    (1)将两个集合中的元素合并
    (2)将一个集合名称改成另一个集合的名称
4.集合的个数
    遍历数组，数组中元素为负数的个数即为集合的个数。
*/
# pragma once
#include<vector>

using namespace std;

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
        return find[p] == find(q);
    }
};

