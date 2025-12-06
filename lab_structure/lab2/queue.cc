#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

#include "queue.h"

template <typename T>
Queue<T>::Queue(std::int64_t maxSize)
    : inputStack(maxSize), outputStack(maxSize), size_max(maxSize){
    if (maxSize == 0) {
        throw std::invalid_argument("Max size must be higher than 0");
    }
    // this->size_max = maxSize;
    // inputStack = Stack<T>(maxSize);
    // outputStack = Stack<T>(maxSize);
}

template <typename T>
void Queue<T>::stack_flip(){
    while(!(inputStack.isEmpty())){
        outputStack.push(inputStack.pop());
    }
}

template <typename T>
void Queue<T>::enqueue(T x){
    if ((inputStack.size() >= size_max) && (!(outputStack.isEmpty()))) {
        throw std::overflow_error("Queue overflow");
    }
    if ((inputStack.size() >= size_max) && (outputStack.isEmpty())){
        stack_flip();
        inputStack.push(x);
    }
    inputStack.push(x);
}

template <typename T>
T Queue<T>::dequeue(){
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }

    if (outputStack.isEmpty()) {
        stack_flip();
    }
    return outputStack.pop();
}

template <typename T>
bool Queue<T>::isEmpty(){
    return inputStack.isEmpty() && outputStack.isEmpty();
}

template <typename T>
std::int64_t Queue<T>::size(){
    return inputStack.size() + outputStack.size();
} 