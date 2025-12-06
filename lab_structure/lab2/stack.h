#ifndef STACK_H
#define STACK_H

#include <cstdint>
#include "DynamicArray.h"


template <typename T>
class Stack {
private:
DynamicArray<T> data;
std::int64_t size_max;

public:
Stack(std::int64_t maxSize);
// void put_size_max(std::int64_t size_max);
void push(T x);
T top();
T pop();
bool isEmpty();
std::int64_t size();
};
#include "stack.cc"
#endif