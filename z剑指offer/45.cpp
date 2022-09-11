/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-28 17:06:17
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-28 17:26:01
 * @FilePath: /.leetcode/z剑指offer/45.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& x, string& y){ return x + y < y + x; });//比较两个字符串数字大小，将两个字符串按两种方式拼接，比较大小；x+y<y+x————>x<y
        for(int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        return res;
    }
};
