/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-21 17:31:58
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-21 17:50:21
 * @FilePath: /.leetcode/z剑指offer/57_2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ret;
        for (int l = 1, r = 2; l < r;){
            int sum = (l + r) * (r - l + 1) / 2;
            if(sum==target){
                ret.emplace_back(vector<int>{});
                for (int i = l; i <= r;++i){
                    ret.back().emplace_back(i);
                }
                ++l;
            }else if(sum<target){
                ++r;
            }else{
                ++l;
            }
        }
        return ret;
    }
};