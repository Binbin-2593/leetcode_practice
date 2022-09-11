/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-20 00:26:39
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-20 15:25:04
 * @FilePath: /.leetcode/排序/冒泡排序/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

/*
从左到右，相邻元素进行比较。每次比较一轮，就会找到序列中最大的一个或最小的一个。这个数就会从序列的最右边冒出来
*/
void maopao(vector<int>nums,int n){
    for (int i=0; i<n-1; i++) {
        //每次冒一个最值，放在最值的位置不用管了，接着冒剩下的
        for(int j=0;j<n-i-1;j++){
            if (nums[j]>nums[j+1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void maopao(vector<int>&nums){
    for (int i = 0; i < nums.size()-1;++i){
        for (int j = 0;j<nums.size()-1-i;++j){
            if(nums[j]>nums[j+1]){
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}