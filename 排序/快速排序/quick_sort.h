/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-02-24 19:12:35
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-23 18:38:43
 * @FilePath: /.leetcode/排序/快速排序/quick_sort.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution{
public:
    vector<int> sortArry(vector<int>& nums){
        //产生随机种子
        srand((unsigned)time(NULL));
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quick_sort(vector<int>&nums, int l,int r){
        if(l>=r)return;

        //取一个随机位子与首元素交换
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[l]);

        //每层递归函数选出一个base值，通过双指针方法、交换值，
        //完成base的左边小于base，右边大于base
        //这样就完成了一次大致的排序
        //然后分别对左右两块递归
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
//默写1
class Solution{
public:
    void ArraySort(vector<int> &nums){
        //产生随机种子
        srand((unsigned)time(NULL));
        quick_sort(nums,0,nums.size()-1);
    }

    void quick_sort(vector<int>&nums,int l,int r){
        int i = rand() % (r - l + 1) + l;
        swap(nums[l],nums[i]);

        int first = l, last = r, base = nums[first];
        while(first<last){
            while(first<last&&nums[last]>=base){
                --last;
            }
            nums[first] = nums[last];
            while (first < last && nums[first] <= base){
                ++first;
            }
            nums[last] = nums[first];
            
        }
        nums[first]=base;

        quick_sort(nums,l,first);
        quick_sort(nums,first+1,r);
    }
};