/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-28 16:39:54
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-28 17:04:26
 * @FilePath: /.leetcode/z剑指offer/56-2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//双指针
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0,n=nums.size()-1;
        while(i<n){
            int j = i + 1;
            if(nums[i]!=nums[j]){
                return nums[i];
            }else{
                i += 3;
            }
        }
        return nums[n];
    }
};
//hash

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (auto &i : nums) ++dict[i];
        for (auto &[k, v] : dict) 
            if (v == 1) return k;
        return 0;
    }
};

