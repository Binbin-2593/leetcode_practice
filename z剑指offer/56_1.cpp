/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-28 15:27:19
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-28 16:23:51
 * @FilePath: /.leetcode/z剑指offer/56_1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

/*思想*/
    //1.一组数中，除了一个单独数，其他都成对出现，直接异或这组数得单独数
    //2.从二进制的角度将数字分两组，这里就是把一个数组看成了一个“图形”
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
    int tmp=0;
    for(auto i:nums)
    {
        tmp^=i;//计算两个只出现一次的数字的异或结果
    }

    int target=1;
    while((target&tmp)==0)//记得&运算加括号，因为优先级小于==
    {
        target=target<<1;//找出tmp二进制中哪一位为1，标记为分组位，以此分组
    }

    int a=0,b=0;
    for(int num:nums)
    {
        if((num&target)==0)
        {
            a^=num;//分组位为0的分为一组，进行异或求得一个出现一次的数字
        }
        else
        {
            b^=num;//分组位为1的分为一组，进行异或求得另外一个出现一次的数字
        }
    }
    
    return vector<int>{a,b};
    }
};
