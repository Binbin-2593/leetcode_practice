/*
 * @Author: your name
 * @Date: 2022-04-26 15:12:23
 * @LastEditTime: 2022-04-26 15:14:49
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/位运算/461.汉明距离.cpp
 */
/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y,ans=0;
        while(diff){
            ans += diff & 1;
            diff >>= 1;
        }
        return ans;
    }
};
// @lc code=end

