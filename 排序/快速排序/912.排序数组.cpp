/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

@lc code=start

class Solution{
public:
    vector<int> sortArray(vector<int>& nums){
        srand((unsigned)time(NULL));//产生随机种子
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quick_sort(vector<int>&nums, int l,int r){
        if(l>=r)return;

        //取一个随机位子与首元素交换
        int i=rand()%(r-l+1)+l;
        swap(nums[i], nums[l]);

        int first = l, last = r, base = nums[first];
        while(first<last){
            while(first<last&&nums[last]>=base){
                --last;
            }
            nums[first] = nums[last];
            while(first<last&&nums[first]<=base){
                ++first;
            }
            nums[last]=nums[first];
        }
        nums[first] = base;

        quick_sort(nums,l,first);
        quick_sort(nums, first + 1, r);
    }
};
// @lc code=end

