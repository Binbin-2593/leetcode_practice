/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-02-24 21:01:28
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-09-29 14:35:07
 * @FilePath: /.leetcode/排序/插入排序/insert_sort.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//双指针思想，指针i控制“把握大方向”，依次遍历每个元素，指针j处理具体每个元素的操作
void insert_sort(vector<int>& nums,int n){
    for(int i=0; i<n; ++i){
        for (int j = i; j > 0 && nums[j] < nums[j - 1];--j){//每遍历到一个值，依次与前面比较，出现违反swap
            swap(nums[j], nums[j - 1]);
        }
    }
}

//默写1
void insert_sort(vector<int>&nums,int n){
    for (int i=0;i<n; ++i){
        for (int j = i; j > 0 && nums[j] < nums[j - 1];--j){
            swap(nums[j], nums[j - 1]);
        }
    }
}
void insert_sort(vector<int>&nums,int n){
    for (int i = 0; i < n;++i){
        for (int j = i; j > 0 && nums[j] < nums[j - 1];--j){
            swap(nums[j], nums[j - 1]);
        }
    }
}