/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-28 17:35:31
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-28 17:47:32
 * @FilePath: /.leetcode/z剑指offer/64.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution{
public:
    int sumNums(int n){
        n && (n += sumNums(n - 1));//当n==0时，&&的左边为假，就不会执行右边，这就完成了递归的出口
        return n;
    }
};