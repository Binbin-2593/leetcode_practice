/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-05 12:59:02
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-05 13:24:07
 * @FilePath: /.leetcode/z剑指offer/10.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        //dp一定要考虑状态小的边界条件
        vector<int> f(n+1,0);
        f[1] = 1;
        int MOD = 1000000007;
        for (int i = 2; i <= n;++i){
            f[i] = (f[i - 1] + f[i - 2])%MOD;
        }

        return f[n];
    }
};

class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;

        int MOD = 1000000007,perv1=0,perv2=1,curr=0;
        for (int i=2;i<=n;++i){
            curr = (perv1+perv2) % MOD;
            perv1=perv2;
            perv2 = curr;
        }
   
        return curr;
    }
};