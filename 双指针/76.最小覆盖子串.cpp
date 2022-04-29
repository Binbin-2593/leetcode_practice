/*
 * @Author: your name
 * @Date: 2022-04-25 15:21:55
 * @LastEditTime: 2022-04-28 13:31:53
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/双指针/76.最小覆盖子串.cpp
 */
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
//本题中的滑窗以整个研究序列为对象产生滑窗（初始l=0 ,r做循环控制）
//r往前滑，遇到情况，处理：l变化
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        //字符串查找的问题，由于随机存取，
        //首先hash把参考字符串存一下
        vector<int> chars(128, 0);
        vector<bool>flag(128, false);//计算机属性
        for(auto& c:t){
            //char字符强转int
            flag[c]=true;
            ++chars[c];
        }

        //双指针滑动窗口扫描
        int count = 0,l=0,min_l=0,min_size=s.size()+1;
        for (int r = 0; r < s.size(); ++r){
            if(flag[s[r]]){
                if(--chars[s[r]]>=0){
                    ++count;
                }

                //if目前滑动窗口中已经包含t中所有
                //尝试移动l右移
                while(count==t.size()){
                    if(r-l+1<min_size){
                        //记录
                        min_l = l;//用于最后取子串的起始位置
                        min_size = r - l + 1;//用于最后取子串的大小
                    }
                    //看移动l导致的count情况
                    if(flag[s[l]]&&++chars[s[l]]>0){
                        --count;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};
// @lc code=end

