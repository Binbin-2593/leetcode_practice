/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
    vector<string> ret;
    string str = "";
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(0,0,s);
        return ret;
    }
    void backtrack(int level,int index,string&s){
        if (level==4||index==s.size()){
            if (level==4&&index==s.size())
                ret.emplace_back(str.substr(0,str.size()-1));//-1是去掉尾巴的‘.’
            return;
        }

        for (int i = 1; i <= 3;++i){//每段长度可为：1、2、3，出现三个分枝
            if(index+i>s.size()) return;//还没够4块，但是s被用完了
            if(s[index]=='0' && i>1) return;//开头0，选取长度超过1，舍去
            if(i==3 &&s.substr(index,i)>"255") return;//这里使用了字符串的比较,所以要i==3
            str+=s.substr(index,i)+".";
            backtrack(level+1,index+i,s);
            str = str.substr(0,str.size()-i-1);//还原
        }
    }
};
// @lc code=end

