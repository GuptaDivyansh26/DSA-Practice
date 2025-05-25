// LRU LFU Cache Class by Bhanu Bhaiya - 20/05/2025

// Cache - Kisi process ki runtime cost ko bachaane ke liye we compromise in space. 

// Main key value pair store krwate h and jismein se main is key and value has no such physical meaning

// LRU- Least Recently Used - last used ki jagah naya daaldo - get() and put()
// get() - 1. If key exists, return value else -1
//         2. Makes an item most frequently used
// put() - 1. Takes key-value. If key exists, update the value.
//         2. else, put it into cache (by or by not removing the LRU data, depending on available capacity of cache)

// Main purpose of cache is to decrease runtime and use space (get() and put() in O(1) avg. time). Therefore, linked list.

// (Class - Blueprint of real world entity. attributes + functions)
// instead of using map or pair, use classes and objects

// Assign dummy nodes head and tail




#include <iostream>

int main()
{
    std::cout<<"Hello World";

    return 0;
}