/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int k=nums.size();
//         for (int i = 0; i < k;++i){
//             for (int j = i + 1; j < k;++j){
//                 if(nums[i]+nums[j]==target)
//                     return {i, j};
//             }
//         }
//         return {};
//     }
// };



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};

//这种存在键值对关系的查找问题记得使用unordered_map
//有一种用法思想是：先创建一个空unordered_map，在后面遍历数据时同时使用上它
// @lc code=end


