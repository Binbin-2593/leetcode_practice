/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-08-03 17:19:15
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-03 19:04:45
 * @FilePath: /.leetcode/前缀和、积分图/238.除自身以外数组的乘积.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int tmp[2][n];
        tmp[0][0] = 1, tmp[1][n - 1] = 1;
        for(int i=1;i<n;++i){
            tmp[0][i]=tmp[0][i-1]*nums[i-1];
            tmp[1][n-1-i]=tmp[1][n-i]*nums[n-i];
        }
        vector<int>ans(n);
        ans[0]=tmp[1][0],ans[n-1]=tmp[0][n-1];
        for(int i=1;i<n-1;++i){
            ans[i]=tmp[0][i]*tmp[1][i];
        }
        return ans;
    }
};
// @lc code=end

