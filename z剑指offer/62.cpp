/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-21 23:36:23
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-27 18:33:45
 * @FilePath: /.leetcode/z剑指offer/62.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//递归：把问题解析出逻辑上相邻的子问题，找出两着关系
class Solution {
public:
    int lastRemaining(int n, int m) {
        return f(n,m);
    }
    //函数返回最后剩下第..个元素
    int f(int n, int m){
        if(n==1)return 0;

        int x = f(n - 1, m);//最后剩下第x个元素
        return (m + x) % n;//两次之间，位置差了m个
    }
};

//逆过程迭代
class Solution {
public:
    int lastRemaining(int n, int m) {
        int i = 0;//最后剩一个，它的位置为0号位
        //逆推迭代
        for (int j = 2; j <= n;++j){
            i = (i + m) % j;
        }
        return i;
    }
};