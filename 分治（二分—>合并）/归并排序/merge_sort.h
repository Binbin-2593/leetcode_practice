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


            //合并
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

            //4.将temp中的元素复制到nums的l-r段
            for (int i = 0; i < r - l + 1; ++i) {
                nums[i + l] = temp[i];
            }
    }
};