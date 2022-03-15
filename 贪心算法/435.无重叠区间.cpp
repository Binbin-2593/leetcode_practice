/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        //形参传引用和传指针，达到直接访问的目的，避免了创造临时变量，提高了运行效率，尽量传指针、引用
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int> &b)
             { return a[1] < b[1]; });

        int n=intervals.size(),total=0,prev=intervals[0][1];
        for (int i = 1;i < n;++i){
            if (intervals[i][0]<prev) ++total;
            else prev = intervals[i][1];
        }
        //二维数组的另一种看待方式
        // for(vector<int> i: intervals) {
		// 	if(prev[1]>i[0]) {
		// 		total++;                
		// 	}else prev=i;           
		// }
        return total;
    }
};

// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         if (intervals.empty()) {
//             return 0;
//         }
        
//         sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
//             return u[1] < v[1];
//         });

//         int n = intervals.size();
//         int right = intervals[0][1];
//         int ans = 1;
//         for (int i = 1; i < n; ++i) {
//             if (intervals[i][0] >= right) {
//                 ++ans;
//                 right = intervals[i][1];
//             }
//         }
//         return n - ans;
//     }
// };


// @lc code=end

