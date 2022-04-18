/*
 * @Author: your name
 * @Date: 2022-04-18 20:06:06
 * @LastEditTime: 2022-04-18 21:59:59
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/442.数组中重复的数据.cpp
 */
/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
/*
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1){
            return {};
        }

        vector<int> ans;
        unordered_map<int,int> hash;
        for(auto i:nums){
            if(hash[i]==1){
                ans.push_back(i);
            }else{
                hash[i] = 1;
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // int n=nums.size();
        // if(n==0||n==1){
        //     return {};
        // }
        
        vector<int> ans;
        // for (int i = 0; i < n;++i){
        //     int x=abs(nums[i])-1;
        //     if(nums[x]>0){
        //         nums[x] = -nums[x];
        //     }
        //     else{
        //         ans.push_back(x+1);
        //     }
        // }
        for (auto& num:nums){
            int x=abs(num)-1;
            if(nums[x]>0){
                nums[x] = -nums[x];
            }
            else{
                ans.push_back(x+1);
            }
        }
        return ans;
    }
};
// @lc code=end
// @lc code=end

