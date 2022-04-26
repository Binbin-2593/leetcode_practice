/*
 * @Author: your name
 * @Date: 2022-04-26 15:24:19
 * @LastEditTime: 2022-04-26 15:34:40
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/位运算/136.只出现一次的数字.cpp
 */
/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
//hash
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto i:nums){
            if(hash.count(i)){
                hash.erase(i);
            }else{
                hash.emplace(i);
            }
        }
    return *hash.begin();
    }
};*/
//位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto &n:nums){
            ans ^= n;
        }
        return ans;
    }
};
// @lc code=end

