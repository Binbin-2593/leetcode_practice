/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-11 16:16:06
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-11 17:18:03
 * @FilePath: /.leetcode/dfs/394.字符串解码.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        src = s;
        p = 0;
        return getString();
    }
    int getDigits(){
        int ret = 0;
        while(p<src.size()&&isdigit(src[p])){
            ret = ret * 10 + src[p++] - '0';
        }
        return ret;
    }
    string getString(){
        if(p==src.size()||src[p]==']'){
            return "";
        }
        char cur = src[p];
        int count = 1;
        string ret;

        if(isdigit(cur)){
            //1.得次数
            count = getDigits();
            //2.过滤'['
            ++p;
            //3.递归
            string str = getString();
            //4.过滤']'
            ++p;
            //5.倍数增加
            while(count--){
                ret += str;
            }
        }else if(isalpha(cur)){
            ret = string(1, src[p++]);
        }
        return ret+getString();//还要+getString()，是因为如"3[a]2[bc]"
    }

private:
    //算法需要多个函数共用些参数，
    //或者这些参数要伴随着整个递归的生命周期使用、改变
    string src;
    size_t p;
};
// @lc code=end

