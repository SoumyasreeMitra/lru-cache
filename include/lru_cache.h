#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>
#include <list>

class LRUCache {

public:

    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);

private:

    int capacity;

    std::list<std::pair<int,int>> cache_list;

    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> cache_map;

};

#endif
