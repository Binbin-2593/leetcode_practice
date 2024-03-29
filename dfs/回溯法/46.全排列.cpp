/*
 * @Author: your name
 * @Date: 2022-04-07 16:56:33
 * @LastEditTime: 2022-07-28 13:30:09
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/深度优先搜索/回溯法/46.全排列.cpp
 */
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }

    void backtrack(vector<int>&nums, int level,vector<vector<int>>&ans){
        //走到满足条件的时候，获取结果
        if (level==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        //单层递归搜索逻辑  
        for (int i=level;i<nums.size();++i){
            //step1:记录
            swap(nums[i], nums[level]);
            //step2:递归子节点
            backtrack(nums, level + 1, ans);
            //step3:撤销记录，改回原状态
            //此步是相对于普通dsf多的一步
            swap(nums[i],nums[level]);
        }
    }
};

//按部就班回溯
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    void backtrack(vector<int>&nums,vector<bool>&used){
        if(path.size()==nums.size()){
            ret.emplace_back(path);
            return;
        }
        for (int i = 0;i<nums.size();++i){
            if (used[i])continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used);
            path.pop_back();
            used[i]=false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        ret.clear();
        path.clear();
        vector<bool> used(nums.size(),false);
        backtrack(nums, used);
        return ret;
    }
};


// @lc code=end

