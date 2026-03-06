# High Performance LRU Cache in C++

## Overview

This project implements a **high-performance Least Recently Used (LRU) cache** in C++.

The cache supports **O(1) get and put operations** by combining two data structures:

- **Hash Map (`unordered_map`)** for constant-time key lookup
- **Doubly Linked List (`list`)** for tracking usage order

When the cache reaches its capacity, the **least recently used item is automatically evicted**.

This design is widely used in:

- Operating systems (page replacement algorithms)
- database query caches
- distributed caching systems
- web servers and content delivery networks

---

# Key Features

- **O(1) cache operations**
- Efficient eviction policy
- Hash map for constant-time lookups
- Doubly linked list for recency tracking
- Benchmark performing **100K cache operations**
- Memory-efficient design

---

# How LRU Cache Works

The cache stores recently accessed elements at the **front of a doubly linked list**.


Most Recently Used → Least Recently Used

[ Key3 ] <-> [ Key1 ] <-> [ Key5 ]



### Data Structure Relationship


Hash Map
(key → node pointer)
│
▼
Doubly Linked List
(MRU → LRU order)


Steps for operations:

### `get(key)`

1. Look up key in hash map
2. Move the node to the **front of the list**
3. Return the value

### `put(key, value)`

1. If key exists → update value and move to front
2. If capacity reached → remove **least recently used node**
3. Insert new node at the front

---

# Project Structure


lru-cache
│
├── include/
│ └── lru_cache.h # Cache class interface
│
├── src/
│ └── lru_cache.cpp # LRU cache implementation
│
├── tests/
│ └── test_cache.cpp # Cache test and benchmark
│
├── Makefile # Build automation
│
└── README.md


---

# Build Instructions

Compile the project using:


make


---

# Run the Program


make run


---

# Example Output


Get key 1: 10
Get key 2 (should be -1): -1

Running benchmark...
100000 cache operations completed in 4 ms


---

# Benchmark

The test program simulates **100,000 cache operations** to measure performance.

Example benchmark loop:

```cpp
for(int i = 0; i < 100000; i++) {
    cache.put(i, i * 10);
    cache.get(i);
}

This demonstrates the constant-time complexity of the cache operations.

Time Complexity
Operation	Complexity
get(key)	O(1)
put(key,value)	O(1)
Concepts Demonstrated

This project demonstrates important computer science concepts:

Hash tables

Doubly linked lists

Cache eviction policies

Algorithm optimization

Memory-efficient data structures

Performance benchmarking

Applications

LRU caching strategies are widely used in:

operating system memory management

database query caching

distributed caching systems

browser caching

CDN edge caching

Future Improvements

Possible enhancements:

Thread-safe LRU cache using mutex locks

Lock-free cache implementation

Generic template-based cache

Performance profiling with larger workloads

Author

Soumyasree Mitra

GitHub
https://github.com/SoumyasreeMitra

LinkedIn
https://www.linkedin.com/in/soumyasree-mitra/

License

This project is intended for educational purposes.