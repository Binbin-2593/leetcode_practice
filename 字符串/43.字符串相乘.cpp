/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-24 23:48:50
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-25 15:52:57
 * @FilePath: /.leetcode/字符串/43.字符串相乘.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        string ret;
        int m=num1.size(),n=num2.size();
        vector<int> v(m+n,0);
        for(int i=m-1;i>=0;--i){
            int n1=num1[i]-'0';
            for(int j=n-1;j>=0;--j){
                int n2=num2[j]-'0',tmp=n1*n2;
                //每次迭代着眼于局部乘积结果的十位
                tmp+=v[i+j+1];
                v[i+j+1]=tmp%10;
                v[i+j]+=tmp/10;
            }
        }
        for(auto&n:v){
            if(ret.empty()&&n==0)continue;
            ret+=n+'0';
        }
        return ret.empty()?"0":ret;
    }
};
// @lc code=end

