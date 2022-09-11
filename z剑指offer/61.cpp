/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-21 20:41:41
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-21 21:01:18
 * @FilePath: /.leetcode/z剑指offer/61.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero = 0;
        for (int i = 0; i < 4; ++i){
            if(nums[i]==0){
                ++zero;
            }else if(nums[i]==nums[i+1]){
                return false;
            }
        }
        //理解：用排队，两人间缝隙大小来理解
        return nums[4] - nums[zero] < 5;//最大牌-最小牌<5,能顺子
    }
};