/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-21 17:57:28
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-21 20:37:38
 * @FilePath: /.leetcode/z剑指offer/65位运算实现加法.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
使用加法的本位、进位的思想，考虑二进制相加的本位、进位情况，刚好对应二进制操作‘异或（^）’、‘与（&）’
通过模拟多组全加器进行运算，多个全加器组合，把低位的进位输出，作为高位的进位输入
*/
class Solution {
public:
    int add(int a, int b) {
        while(b != 0) { // 当进位为 0 时跳出，因为二进制运算+0，不再进位
            int c = (unsigned)(a & b) << 1;  // c = 进位，因为leetcode的编译器不能对负数进行左移，左移‘<< 1’是完成进位逻辑（即：进位逻辑：乘以进制数）
            a ^= b; // a = 本位
            b = c; // b = 进位
        }
        return a;
    }
};
// class Solution {
//     public: 
//     int add(int a, int b) {
//         return b ? add(a ^ b, (unsigned)(a & b) << 1) : a;
//     }
// };