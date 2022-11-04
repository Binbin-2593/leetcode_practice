/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-14 18:44:40
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-10-08 14:47:40
 * @FilePath: /.leetcode/树/字典树/208.实现-trie-前缀树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
    //说明：
        //前缀树的每个节点封装了一个size==26的vector（指向子节点的指针数组 ）和一个bool标志值
        //vector可以看出在此节点之前出现的字符串
        //bool标志值可以看到此节点是不是一个字符串的结束
    //注意：把字符理解为“当前节点存在Trie()，且是由前一个节点中vector的ch位置,指向过来的，那就说ch存在”，
    //“字符在路径上，不在节点上，节点上是指向ch的指针”
private:
    //节点内容
    vector<Trie*> children;//指向子节点的指针数组
    bool isEnd;
    //查找前缀
    Trie* searchPrefix(string prefix) {
        Trie* node = this;//指向类对象本身，这里就是指向根节点了
        for (char ch : prefix) {
            ch -= 'a';  //char转int 
            if (node->children[ch] == nullptr) {//children[ch]指向ch的指针
                return nullptr;//子节点不存在。说明字典树中不包含该前缀，返回空指针
            }
            node = node->children[ch];//子节点存在。沿着指针移动到子节点，继续搜索下一个字符。
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();//子节点不存在。创建一个新的子节点，记录在 children数组的对应位置上，
                                //然后沿着指针移动到子节点，继续搜索下一个字符
            }
            node = node->children[ch];//子节点存在,链表指针移动
        }
        node->isEnd = true;//字符串最后一个节点指向true（类二叉树叶子节点的next指向nullptr）
    }

    bool search(string word) {
        // Trie* node = this->searchPrefix(word);
        // return node != nullptr && node->isEnd;
        return this->startsWith(word) && this->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

