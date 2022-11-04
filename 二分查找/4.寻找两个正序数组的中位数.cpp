/*
 * @Author: your name
 * @Date: 2022-02-23 19:30:44
 * @LastEditTime: 2022-09-11 17:02:54
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/二分查找/4.寻找两个正序数组的中位数.cpp
 */
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
// 使用STL
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size() + nums2.size();
//         vector<int> nums3(n, 0);
//         merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());
//         return n % 2 == 0 ? (double)(nums3[n / 2] + nums3[n / 2 - 1]) / 2 : nums3[n / 2];
//     }
// };


//超时：双指针，能把空间复杂度降为O（1）
/*
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size(),m=nums2.size(),s=n+m;
        int p1 = 0, p2 = 0,pos;
        if(s%2==0){
            pos = s / 2 - 1;
        }else{
            pos = s / 2;
        }
        while (p1+p2<=pos){
            if(p1==n-1){
                p2 = pos - (p1+1);
                break;    
            }else if (p2 == m - 1){
                p1 = pos - (p2+1);
                break;
            }else{
                if(nums1[p1]<=nums2[p2]){
                    ++p1;
                }else{
                    ++p2;
                }
            }
        }
        if(s%2==0){
            int sum=0;
            if(nums1[p1]<=nums2[p2]){
                sum += nums2[p2];   
            }else{
                sum += nums1[p1];
            }
            if(p1==n-1){
               sum += nums2[p2 + 1]; 
            }
            if(p2 == m - 1){
               sum += nums1[p1 + 1]; 
            }
            if(nums1[p1+1]<=nums2[p2+1]){
                sum += nums1[p1 + 1];
            }else{
                sum += nums2[p2 + 1];
            }
            return double(sum / 2);
        }else{
            if(nums1[p1]<=nums2[p2]){
                return double(nums2[p2]);
            }else{
                return double(nums1[p1]);
            }
        }
        return (double)0;
    }
};*/
/*
//二分法
class Solution {
public:
//寻找两个有序数组中的第 k 小的数
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */
/*
        int m = nums1.size();
        int n = nums2.size();
        int i1 = 0, i2 = 0;

        while (true) {
            // 边界情况
            if (i1 == m) {
                return nums2[i2 + k - 1];
            }
            if (i2 == n) {
                return nums1[i1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[i1], nums2[i2]);
            }

            // 正常情况
            int newI1 = min(i1 + k / 2 - 1, m - 1);
            int newI2 = min(i2 + k / 2 - 1, n - 1);
            int n1 = nums1[newI1];
            int n2 = nums2[newI2];
            //舍弃、更新k值、更新起点
            if (n1 <= n2) {
                k -= (newI1 - i1) + 1;
                i1 = newI1 + 1;
            }
            else {
                k -= (newI2 - i2) + 1;
                i2 = newI2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {//奇
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {//偶
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
*/

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //保证数组1一定最短
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = m + n - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
	}
};
// @lc code=end
