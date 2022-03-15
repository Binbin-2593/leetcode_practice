/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
    //1.堆调整
    void maxHeapadjust(vector<int>& nums, int i, int len) {
        //i是要研究的非叶子结点，len是数组的最后一个下标（size()-1）
        //while是看父节点拉下来的小数是否能当下一层的父节点
        while (i*2 + 1 <= len) {
            int lson = i*2 + 1;
            int rson = i*2 + 2;
            int large;
            if (lson <= len && nums[lson] > nums[i]) {
                large = lson;
            } else {
                large = i;
            }
            if (rson <= len && nums[rson] > nums[large]) {
                large = rson;
            }
            if (large != i) {
                swap(nums[i], nums[large]);
                i = large;
            } else {
                break;//不做交换，直接退出以i这个父节点入口的调整
            }
        }
    }

    //2.建堆
    void buildMaxHeap(vector<int>& nums, int len) {
        for (int i = len / 2; i >= 0; --i) {
            //注意i的初始值
            maxHeapadjust(nums, i, len);
        }
    }
    //3.堆排序
    void heapSort(vector<int>& nums) {
        int len = (int)nums.size() - 1;
        buildMaxHeap(nums, len);
        for (int i = len; i >= 1; --i) {
            //注意i的下限
            swap(nums[i], nums[0]);
            --len;
            maxHeapadjust(nums, 0, len);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};


// @lc code=end

