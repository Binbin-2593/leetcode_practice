/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-07 23:13:23
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-07 23:15:36
 * @FilePath: /.leetcode/z剑指offer/03.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto& n:nums){
            if(hash.count(n)){
                return n;
            }else{
                hash.emplace(n);
            }
        }
        return 0;
    }
};