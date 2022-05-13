/*
 * @Author: your name
 * @Date: 2022-05-01 20:45:59
 * @LastEditTime: 2022-05-01 21:58:20
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/66前缀和.cpp
 */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n=a.size();
        if(n==0)
            return {};

        vector<int> l(n),r(n),ans;
        l[0]=1;
        r[n-1] = 1;
        //由于本题要使用到前缀和及后缀和
        //又由于vector的首下标不能为-1
        //所以有别于一般前缀和处理方法，分别舍弃了第一个、最后一个元素
        for (int i = 1; i < n; ++i){
            l[i]=l[i-1]*a[i-1];
        }
        for (int k = n-2;k>=0;--k){
            r[k]=r[k+1]*a[k+1];
        }
        for (int j = 0; j < n; ++j){
            ans.emplace_back(l[j] * r[j]);
        }
        return ans;
    }
};