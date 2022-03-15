/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
//区间左闭右闭写法，分[l,mid-1],[mid+1,r]
// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x==0)
//             return 0;
//         int l=1,r=x,mid,sqrt;
//         while(l<=r){
//             mid = l + (r - l) / 2;//此中写法防止出现r+l的值超过int类型
//             sqrt=x/mid;
//             if(sqrt==mid) return mid;
//             else if(sqrt<mid){
//                 r = mid - 1;
//             }else{
//                 l = mid + 1;
//             }
//         }
//         return r;
//     }
// };
//左闭右开，分[l,mid]和[mid+1,r]
class Solution{
public:
    int mySqrt(int x){
        if(x==0) return x;
        int l=1,r = x,mid,sqrt;
        while(l<=r){
            mid = l + (r - l) / 2;
            sqrt = x / mid;
            if(sqrt==mid)return mid;
            else if(sqrt<mid){
                r = mid;
            }else{
                l = mid +1;
            }
        }
        return l-1;//二分查找一定要关注收敛到最后一个数or两个数的情况
    }
};

// class Solution {
// public:
//     int mySqrt(int x) {
//         int l = 0, r = x, ans = -1;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if ((long long)mid * mid <= x) {
//                 ans = mid;
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }
//         return ans;
//     }
// };


// @lc code=end

