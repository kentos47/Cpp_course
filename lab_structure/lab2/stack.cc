#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

#include "stack.h"

// template <typename T>
// void Stack<T>::put_size_max(std::int64_t size_max){
//     if (size_max < 0) {
//         throw std::invalid_argument("Max size must be 0 or higher");
//     }
//     if (size_max > data.getCapacity()){
//         data.increase_Capacity(size_max);
//     }
//     if (size_max < data.getCapacity()){
//         data.decrease_Capacity(size_max);
//     }
// }

template <typename T>
Stack<T>::Stack(std::int64_t maxSize) {
    if (maxSize == 0) {
        throw std::invalid_argument("Max size must be higher than 0");
    }
    this->size_max = maxSize;
}

template <typename T>
void Stack<T>::push(T x){
    if (data.getSize()+1 >= size_max){
        throw std::overflow_error("Stack overflow");
    }
    data.push_back(x);
}

template <typename T>
T Stack<T>::top(){
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return data.back();
}

template <typename T>
T Stack<T>::pop(){
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    T x = data.back();
    data.remove(data.getSize());
    return x;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return data.getSize() == -1;
}

template <typename T>
std::int64_t Stack<T>::size(){
    return data.getSize()+1;
}