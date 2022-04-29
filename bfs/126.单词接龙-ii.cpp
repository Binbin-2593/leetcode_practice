/*
 * @Author: your name
 * @Date: 2022-04-17 16:16:18
 * @LastEditTime: 2022-04-18 18:33:32
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /.leetcode/广度优先搜索/126.单词接龙-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        //把数据从vector放入hashset中方便后面建图时随机取用
        unordered_set<string> wl;
        for(auto s:wordList){
            wl.insert(s);
        }
        if(!wl.count(endWord))
            return ans;
        
        //下面建图：
            //由于本题是要找出序列（路径），显然是一个图的搜索问题
            //题目没给图，建图关键
                //1.把题目中的每个小单元抽象成点
                //2.根据题意找出点之间有怎样的关系可以建立连接
                //3.确定找出初始点（可能多个）
            //建图方法最好使用bfs的思想一层层地广度建图，建到图中出现所要求的路径时停止（设置标记（found））
            //图的存储用：unordered_map<T,vector<T>>；这个map也是整个构图过程要追求的
        wl.erase(beginWord);wl.erase(endWord);
        //确定起始点
        unordered_set<string> q1{beginWord}, q2{endWord};
        unordered_map<string, vector<string>> next;
        bool reversed=false,found=false;

        //while,一层层广度。。。
        while(!q1.empty()){
            unordered_set<string> q;
            for(const auto& w:q1){
                string s = w;
                for (size_t i= 0; i < s.size();++i){
                    char ch = s[i];
                    //字符串问题中要用到的变换字符的方法
                    for (int j = 0; j < 26;++j){
                        s[i] = j + 'a';
                        if(q2.count(s)){
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if(wl.count(s)){
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s); 
                        }
                    }
                    s[i] = ch;
                }
            }
            if(found)
                break;
            //已在图结构中的数据，要从源数据容器中删除
            for(const auto &w:q){
                wl.erase(w);
            } 
            //选出进行下一轮循环（图的一层）操作的点对象   
                //本题技巧：从节点数少的一方往下层延伸建图
            if(q.size()<=q2.size())
                q1 = q;
            else{
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }
        if(found){
            vector<string> path = {beginWord};
            backtrack(beginWord,endWord,next,path,ans);
        }
        return ans;
    }

    //回溯：因为要得出全部路径
    void backtrack(const string& src, const string&dst,unordered_map<string,vector<string>>&next,vector<string>&path,vector<vector<string>>&ans){
        if(src==dst){
            ans.push_back(path);
            return;
        }
        
        //unordered_map<T,vector<T>>存储的图，再需要找出一个“出发”节点就可以进行全图遍历
        for(const auto &s:next[src]){
            path.push_back(s);
            backtrack(s, dst, next, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end

