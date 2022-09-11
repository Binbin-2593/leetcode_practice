/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-28 19:51:48
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-29 15:10:27
 * @FilePath: /.leetcode/双指针/287.寻找重复数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
//hash
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_set<int> hash;
//         for(auto &n:nums){
//             if(hash.count(n)){
//                 return n;
//             }
//             else{
//                 hash.insert(n);
//             }
//         }
//         return 0;
//     }
// };
//sort+双指针
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int i = 0;
//         while(i < nums.size()-1){
//             if(nums[i]==nums[i+1]){
//                 return nums[i];
//             }
//             ++i;
//         }
//         return 0;
//     }
// };
//双指针：判断环入口
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while(slow !=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

