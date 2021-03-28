#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator > key_node;
    int cp;

public:
    LRUCache(int capacity) {
        cp = capacity;
    }
    
    int get(int key) {
        if (key_node.find(key) == key_node.end()) return -1;
        pair<int,int> key_val = *(key_node[key]);
        cache.erase(key_node[key]);
        cache.push_front(key_val);
        key_node[key] = cache.begin();
        return key_val.second;
    }
    
    void put(int key, int value) {
        // 存在
        if (key_node.count(key) > 0) {
            cache.erase(key_node[key]);
            cache.push_front(pair<int,int>(key, value));
            key_node[key] = cache.begin();
        }
        // 不存在
        else {
            // 满了，先删除最后一个和映射
            if (cp == cache.size()) {
                key_node.erase(cache.back().first);
                cache.pop_back();
            }
            // 添加
            cache.push_front(pair<int,int>(key, value));
            key_node[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */