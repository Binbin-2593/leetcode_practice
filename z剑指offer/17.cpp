/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-07-14 22:19:41
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-07-14 22:40:52
 * @FilePath: /.leetcode/z剑指offer/17.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
class Solution {
public:
    vector<int> printNumbers(int n) {
        int count = 0;
        while(n--){
            count *= 10;
            count += 9;
        }
        vector<int> ans;
        int tmp = 1;
        while (count--){
            ans.emplace_back(tmp);
            ++tmp;
        }
        return ans;
    }
};