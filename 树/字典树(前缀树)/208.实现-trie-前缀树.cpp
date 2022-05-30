/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-03-14 18:44:40
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-05-27 18:00:14
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
            ch -= 'a';
            if (node->children[ch] == nullptr) {
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
        node->isEnd = true;//最后一个节点字符串结尾标识为true
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

