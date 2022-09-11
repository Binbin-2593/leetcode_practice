/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-07 21:48:05
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-07 23:08:57
 * @FilePath: /.leetcode/dfs/回溯法/39.组合总和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEnt
 */
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
// class Solution {
//     vector<vector<int>> ret;
//     vector<int> tmp;
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         backtrack(candidates,target);
//         return ret;
//     }
//     void backtrack(vector<int>&candidates, int target){
//         if(target<0)return;
//         if(target==0){
//             sort(tmp.begin(), tmp.end());
//             if(find(ret.begin(),ret.end(),tmp)==ret.end()){
//                 ret.emplace_back(tmp);
//             }
//             //ret.emplace_back(tmp);
//             return;
//         }
//         for (int i = 0;i<candidates.size();++i){
//             //if(candidates[i]>target) continue;
//             tmp.push_back(candidates[i]);
//             backtrack(candidates, target - candidates[i]);
//             tmp.pop_back();
//         }
//     }
// };
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracting(vector<int>& candidates,int target, int startIndex) {
        if (target==0) {
            res.push_back(path);
            return;
        }
        if (target<0) return;
        //参数startIndex作用是每次只从这之后找,条件➕&& target>0,减少不必要的递归调用
        for (int i = startIndex; i < candidates.size() && target>0; i++) {
            path.push_back(candidates[i]);
            backtracting(candidates, target-candidates[i], i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracting(candidates, target, 0);
        return res;
    }
};


// @lc code=end

