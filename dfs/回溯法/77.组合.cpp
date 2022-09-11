/*
 * @Author: your name
 * @Date: 2022-04-07 22:08:41
 * @LastEditTime: 2022-08-07 21:31:31
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE    
 * @FilePath: /.leetcode/深度优先搜索/回溯法/77.组合.cpp
 */
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        //解空间
        vector<vector<int>> ans;
        //构成解空间的中间容器
        vector<int>comb(k,0);
        int count=0;
        backtrack(ans,comb,n,k,count,1);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans,vector<int>&comb,int n,int k,int& count,int pos){
        //只要是状态量都要用引用
        if(count == k){
            ans.push_back(comb);
            return;//return结束的是套着它的那个函数，与外层无关
        }
        for (int i=pos; i<=n; ++i){
            comb[count]=i;
            ++count;

            backtrack(ans,comb,n,k,count,i+1);

            --count;
        }
    }

};
//使用基本套路
class Solution {
    vector<vector<int>>ret;
    vector<int> tmp;
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n,k,1);
        return ret;
    }
    void backtrack(int n,int k,int begin){
        if(tmp.size()==k){
            ret.emplace_back(tmp);
            return;
        }
        for(int i=begin;i<=n;++i){
            tmp.push_back(i);
            backtrack(n,k,i+1);
            tmp.pop_back();
        }
    }
};
// @lc code=end

