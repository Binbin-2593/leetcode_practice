/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> ans;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         auto it=unique(nums.begin(),nums.end());
//         //nums.erase(it, nums.end());

//         for (int i = 0; i < n; ++i)
//         {
//             if (nums[i] != i + 1){
//                 ans.push_back(i+1);
//                 nums.insert(nums.begin()+i, i + 1);
//                 //超时了，vector算法中不能大量使用insert
//                 //++n;
//              }
//         }
//         return ans;
//     }
// };



//思路：要查找的是vector中元素，利用hash思想，
//将这些元素映射出自己vector中的下标pos，vector就可取原本vector
//那么缺的元素本该的pos位置就被别的重复占用了，
//那么将重复占用的位置标注出来（标注方法：取反）即可

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        //由于本题的特殊性：数组中的数字和数组下标有某种联系
        //可想到发现hash函数，解决问题
        for(auto &num:nums){
            int pos = abs(num) - 1;
            if(nums[pos]>0)
                nums[pos] = -nums[pos];
        }//由n个属于1～n的整数的特殊性

        for (int i = 0;i<nums.size();++i){
            if(nums[i]>0)
                ans.push_back(i + 1);
        }
        return ans;
        
    }
};
// @lc code=end

