#ifndef QUEUE_H
#define QUEUE_H

#include <cstdint>
#include "stack.h"

template <typename T>
class Queue{
private:
Stack<T> inputStack;
Stack<T> outputStack;
std::int64_t size_max;

void stack_flip();


public:
Queue(std::int64_t maxSize);

void enqueue(T x);
T dequeue();
bool isEmpty();
std::int64_t size();
};
#include "queue.cc"

#endif