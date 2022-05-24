/*
 * @Author: your name
 * @Date: 2022-02-25 10:42:53
 * @LastEditTime: 2022-05-24 15:40:10
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/堆排序/912.排序数组.cpp
 */
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
            //注意i的上限和下限
            //把begin()处的最值移到end()处
            swap(nums[i], nums[0]);
            --len;//一次只交换一个，然后进行堆调整
            maxHeapadjust(nums, 0, len);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};

//默写1
class Solution {
    //堆调整
    void maxHeapadjust(vector<int>&nums,int i,int len){
        while (i*2+1<=len){
            int l=i*2+1,r=i*2+2,large;
            if(l<=len&&nums[l]>nums[i]){
                large = l;
            }else{
                large = i;
            }
            if(r<=len&&nums[r]>nums[large]){
                large = r;
            }
            if(large!=i){
                swap(nums[i],nums[large]);
                i=large;//更新i继续检查调整
            }else{
                break;//i没问题，跳出调整
            }
        }
    }
    //建堆
    void maxHeapbuild(vector<int>&nums,int len){
        for (int i = len / 2; i >= 0;--i){
            maxHeapadjust(nums, i, len);
        }
    }
    //排序
    void heapSort(vector<int>&nums){
        int len=nums.size()-1;
        maxHeapbuild(nums,len);
        for (int j = len; j >= 1;--j){
            swap(nums[j], nums[0]);
            --len;
            maxHeapadjust(nums,0,len);
        }
    }
pbulic:
    vector<int> sortArray(vector<int>&nums){
        heapSort(nums);
        return nums;
    }
};

// @lc code=end

