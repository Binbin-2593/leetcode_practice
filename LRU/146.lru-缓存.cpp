/*
 * @Author: Binbin-2593 1600382936@qq.com
 * @Date: 2022-06-07 18:21:06
 * @LastEditors: Binbin-2593 1600382936@qq.com
 * @LastEditTime: 2022-08-09 19:38:00
 * @FilePath: /.leetcode/LRU/146.lru-缓存.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
    //本场景需要O(1)的知道元素所在位置，及元素键值所对应的实值
    unordered_map<int, list<pair<int, int>>::iterator> hash;//建立数值及其在链表中位置的映射
    list<pair<int, int>> cache;//数据用链表存储
    int size;

public:
    LRUCache(int capacity):size(capacity) {}
    
    int get(int key) {
        auto it=hash.find(key);
        if (it==hash.end())
            return -1;
        cache.splice(cache.begin(),cache,it->second);//把key在list中的位置变到begin()处
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if(it!=hash.end()){//已存在
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);//最近访问放链首
        }else{//不存在
            cache.emplace(cache.begin(), make_pair(key, value));//链首插入
            hash[key] = cache.begin();
            if(cache.size()>size){
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

