/*
 * @Author: your name
 * @Date: 2022-04-13 21:42:27
 * @LastEditTime: 2022-08-07 21:44:20
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/深度优先搜索/回溯法/78.子集.cpp
 */
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> media={};
        backtrack(ans, media, nums,0);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans,vector<int>& media,vector<int>& nums,int pos){
        ans.emplace_back(media);//合格就往里放
        if(pos==nums.size()){
            return;
        }
        
        for(int i=pos; i<nums.size();++i){
            media.emplace_back(nums[i]);
            backtrack(ans, media, nums, i + 1);//注意理解这里pos的形参为i+1
            media.pop_back();
        }
    }

};/*
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};*/

// @lc code=end

