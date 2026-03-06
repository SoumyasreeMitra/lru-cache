#include "../include/lru_cache.h"

LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
}

int LRUCache::get(int key) {

    if(cache_map.find(key) == cache_map.end())
        return -1;

    auto it = cache_map[key];

    int value = it->second;

    cache_list.erase(it);

    cache_list.push_front({key,value});

    cache_map[key] = cache_list.begin();

    return value;

}

void LRUCache::put(int key, int value) {

    if(cache_map.find(key) != cache_map.end()) {

        cache_list.erase(cache_map[key]);

    }

    else if(cache_list.size() == capacity) {

        auto last = cache_list.back();

        cache_map.erase(last.first);

        cache_list.pop_back();

    }

    cache_list.push_front({key,value});

    cache_map[key] = cache_list.begin();

}
