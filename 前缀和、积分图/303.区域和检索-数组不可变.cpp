/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
// @lc code=start
class NumArray {
    vector<int> sums;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n+1);
        for (int i = 0; i < n;++i){
            sums[i + 1] = sums[i] + nums[i];
        }
    }
//前缀和表示的是：站在当前节点，得到之前节点累加和，还与本节点数值无关
    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

