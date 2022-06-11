/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-14 18:44:40
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-06-07 21:16:47
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
        //前缀树的每个节点封装了一个size==26的vector和一个bool标志值
        //vector可以看出在此节点之前出现的字符串
        //bool标志值可以看到此节点是不是一个字符串的结束
    
private:
    //节点内容
    vector<Trie*> children;
    bool isEnd;
    /*struct TrieNode{
       bool isEnd; //该结点是否是一个串的结束
       TrieNode* children[26]; //字母映射表
    }
    */

    Trie* searchPrefix(string prefix) {
        Trie* node = this;//指向类对象本身，这里就是指向根节点了
        for (char ch : prefix) {
            ch -= 'a';  //char转int 
            if (node->children[ch] == nullptr) {//children[ch]指向ch的指针
                return nullptr;
            }
            node = node->children[ch];
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
                node->children[ch] = new Trie();
            }
            node = node->children[ch];//链表指针移动
        }
        node->isEnd = true;//字符串最后一个节点指向true（类二叉树叶子节点的next指向nullptr）
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
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

