CXX=g++
CXXFLAGS=-std=c++17 -Wall

all:
	g++ src/lru_cache.cpp tests/test_cache.cpp -o cache

run:
	./cache

clean:
	rm -f cache
