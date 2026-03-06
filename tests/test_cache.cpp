#include "../include/lru_cache.h"
#include <iostream>

int main() {

    LRUCache cache(3);

    cache.put(1,10);
    cache.put(2,20);
    cache.put(3,30);

    std::cout << cache.get(1) << std::endl;

    cache.put(4,40);

    std::cout << cache.get(2) << std::endl;

}

