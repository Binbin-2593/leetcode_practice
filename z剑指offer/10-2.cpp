/*
 * @Author: Wangfuchen 1600382936@qq.com
 * @Date: 2022-05-05 13:26:25
 * @LastEditors: Wangfuchen 1600382936@qq.com
 * @LastEditTime: 2022-05-05 13:33:20
 * @FilePath: /.leetcode/z剑指offer/10-2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE   
 */
class Solution {
public:
    int numWays(int n) {
        int MOD=1000000007,perv1=1,perv2=1,curr=0;
        for (int i = 0;i<n;++i){
            curr = (perv1 + perv2) % MOD;
            perv1=perv2;
            perv2 = curr;
        }
        return perv1;
    }
};