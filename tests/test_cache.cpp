#include "../include/lru_cache.h"
#include <iostream>
#include <chrono>

int main() {

    LRUCache cache(3);

    // Basic functionality test
    cache.put(1,10);
    cache.put(2,20);
    cache.put(3,30);

    std::cout << "Get key 1: " << cache.get(1) << std::endl;

    cache.put(4,40);

    std::cout << "Get key 2 (should be -1): " << cache.get(2) << std::endl;

    // Benchmark test
    std::cout << "\nRunning benchmark...\n";

    LRUCache benchmark_cache(1000);

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 100000; i++) {
        benchmark_cache.put(i, i*10);
        benchmark_cache.get(i);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "100000 cache operations completed in "
              << duration.count() << " ms\n";

}