/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-19 17:27:58
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-21 16:04:36
 * @FilePath: /.leetcode/50.pow-x-n.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
//使用分治思想，奇偶两条线模拟累积过程
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? help(x, N) : 1.0 / help(x, -N);
    }
    double help(double x,long long N){
        double ans = 1.0;
        double x_contribute = x;
        //在对N进行二进制拆分的同时计算结果
        while(N>0){
            if (N%2==1){//N为奇数
                //如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }
    //由于每次递归都会使得指数减少一半，因此递归的层数为O(logn)；
};

class Solution{
public:
    double myPow(double x,int n){
        long long N = n;
        return N >= 0 ? help(x, N) : 1.0 / help(x, -N);
    }
    double help(double x,long long N){
        double ans = 1.0;
        while(N>0){
            if(N%2==1){
                ans *= x;
            }
            x *= x;
            N /= 2;
        }
        return ans;
    }
};

class Solution{
public:
   double myPow(double x,int n){
        long long N = n;
        return N >= 0 ? help(x, N) : 1.0 / help(x, -N);
    }
    double help(double x,long long N){
        if(N==0)
            return 1.0;
        double y = help(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
};
// @lc code=end
