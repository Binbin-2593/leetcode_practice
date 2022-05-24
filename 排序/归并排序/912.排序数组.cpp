/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n,0);
        merge_sort(nums, 0, n - 1, temp);
        return nums;
    }

    void merge_sort(vector<int>& nums,int l,int r,vector<int>&temp){
            if(l>=r)
                return;

            //分半
            int mid = l + (r - l) / 2;
            merge_sort(nums, l, mid, temp);
            merge_sort(nums, mid + 1, r, temp);


            //合并,归并时站在上帝视角在处理“对二”的问题
            int i = l, j = mid + 1, cur=0;
            //1.两子列都有元素
            while(i<=mid&&j<=r){
                if(nums[i]<=nums[j])
                    temp[cur++] = nums[i++];
                else temp[cur++]=nums[j++];
            }
            //2.左子列有元素，右无
            while(i<=mid){ 
                temp[cur++]=nums[i++];}
            //3.右子列有元素，左无
            while(j<=r){
                temp[cur++] = nums[j++];}

            for (int i = 0; i < r - l + 1; ++i) {
                nums[i + l] = temp[i];
            }
    }
};

//默写1
class Solution {
public:
    vector<int> sortArray(vector<int>&nums){
        int n = nums.size();
        vector<int> temp(n,0);
        merge_sort(nums, 0,n-1,temp);
    }
    void merge_sort(vector<int>&nums,int l,int r,vector<int>& temp){
        if(l>=r){
            return;
        }

        int mid = l + (r - l) / 2;
        merge_sort(nums,l,mid,temp);
        merge_sort(nums, mid + 1, r, temp);

        int i=l,j=mid+1,curr=0;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j]){
                temp[curr++]=nums[i++];
            }else{
                temp[curr++] = nums[j++];
            }
        }

        while(i<=mid){
            temp[curr++] = nums[i++];
        }
        while(j<=r){
            temp[curr++] = nums[j++];
        }

        for (int i = 0; i < r - l + 1;++i){
            nums[l + i] = temp[i];
        }
    }
};

// @lc code=end

