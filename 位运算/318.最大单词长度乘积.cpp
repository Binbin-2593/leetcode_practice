/*
 * @Author: your name
 * @Date: 2022-04-26 18:18:29
 * @LastEditTime: 2022-04-26 19:05:04
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/位运算/318.最大单词长度乘积.cpp
 */
/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        //既要看每个元素的内容又要看每个元素的长度：map
        unordered_map<int, int> hash;//没需要元素有序就用hash版的省时间
        int ans = 0;
        for(const string& w:words){
            int mask = 0,size=w.size();
            //位运算产生字符串字母组合种类对应的int数值
            for(const char& c:w){
                mask |= 1 << (c - 'a');
            }
            
            hash[mask] = max(hash[mask], size);//max因为有重复

            for (const auto &[h_mask, h_len]:hash){
                if(!(mask&h_mask)){
                    ans = max(ans, size * h_len);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

