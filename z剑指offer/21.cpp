/*
 * @Author: your name
 * @Date: 2022-04-25 21:06:13
 * @LastEditTime: 2022-04-25 21:48:33
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/z剑指offer/21.cpp
 */
//双指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0,r=nums.size()-1;
        while (l<r){
            //一定注意取余再取非要加括号
            if(!(nums[l]%2)&&nums[r]%2){
                swap(nums[l], nums[r]);
                ++l;
                --r;
            }else if(nums[l]%2){
                ++l;
                continue;
            }else if(!(nums[r]%2)){
                --r;
                continue;
            }
        }
        return nums;
    }
};
//快慢指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int s = 0,f=0;
        while (f==nums.size()){
            if(nums[f]&1){
                swap(nums[s], nums[f]);
                ++s;//有操作才++slow
            }
            ++f;//每步都++fast
        }
        return nums;
    }
};
