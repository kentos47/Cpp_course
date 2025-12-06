#include "DynamicArray.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>
DynamicArray<T>::DynamicArray() {
  this->capacity = 8;
  this->data = new T[this->capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(std::int64_t capacity) {
  if (capacity < 1) {
    throw std::invalid_argument("Capacity < 1"); // https://en.cppreference.com/w/cpp/error/exception.html
  }
  this->capacity = capacity;
  this->data = new T[this->capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray& other) {
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new T[this->capacity]; // (*this).data

  for (int i = 0; i <= size; ++i) {
    this->data[i] = other.data[i];
  }
}


template <typename T>
DynamicArray<T>::~DynamicArray() {
  if (this->data) {
    delete[] this->data;
  }
}

template <typename T>
void DynamicArray<T>::push_back(T x) {
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  //data[++size] = x;
  data[size + 1] = x;
  size++;
}

template <typename T>
T DynamicArray<T>::add(std::int64_t idx1, std::int64_t idx2) {
  if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0) {
    throw std::invalid_argument("idx1 or idx2 out of range");
  }
  return data[idx1] + data[idx2];
}

template <typename T>
T DynamicArray<T>::max() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMax = -1e+38; // -1 * 10^38
  // float currentMax = std::numeric_limits<float>::lowest();
  for (int i = 0; i <= size; ++i) {
    if (data[i] >= currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;
}

template <typename T>
T DynamicArray<T>::min() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMin = 1e+38; // -1 * 10^38
  // float currentMin = std::numeric_limits<float>::max();
  for (int i = 0; i <= size; ++i) {
    if (data[i] <= currentMin) {
      currentMin = data[i];
    }
  }
  return currentMin;
}

template <typename T>
void DynamicArray<T>::clear() {
  if (this->data) {
    delete[] this->data;
    this->data = nullptr;
  }
  size = -1;
  capacity = 8;
}

template <typename T>
void DynamicArray<T>::reinitialize() {
  clear();
  data = new float[capacity](); // init with zeros
}

template <typename T>
void DynamicArray<T>::printData() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i <= size; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

// template <typename T>
// T DynamicArray<T>::operator[](std::int64_t idx) {
//   if (isEmpty() || idx < 0 || idx > size) {
//     throw std::invalid_argument("Out of range");
//   }
//   return data[size - idx]; // Arabic operator[]
//   // return data[idx];     // European operator[]
// }

// template <typename T>
// T DynamicArray<T>::operator()() {
//   if (isEmpty()) {
//     return 0;
//   }
//   float sum = 0;
//   for (int i = 0; i <= size; ++i) {
//     sum += data[i];
//   }
//   return sum;
// }

  //-------------------------------homework 24.11------------------------------//

template <typename T>
void DynamicArray<T>::push_front(T val) {
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; i++) {
      tempArray[i+1] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
    data[0] = val;
    size++;
  }
  if (size + 1 < capacity) {
    std::int64_t cur = data[0];
    data[0] = val;
    size++; 
    for (int i = 1; i <= size; i++){
      std::int64_t tmp = data [i];
      data[i] = cur;
      cur = tmp;
    }
  }
}


template <typename T>
T DynamicArray<T>::front() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  return data[0];
}

template <typename T>
T DynamicArray<T>::back() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  return data[size];
}


template <typename T>
void DynamicArray<T>::insert(std::int64_t idx, T val) {
  if (idx < 0 || idx > size) {
    throw std::invalid_argument("Index out of range");
  }
  
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < idx; i++) {
      tempArray[i] = data[i];
    }
    tempArray[idx] = val;

    for (int i = idx+1; i <= size; i++) {
      tempArray[i + 1] = data[i];
    }

    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }

  else {
    std::int64_t cur = data[idx];
    data[idx] = val;
    size++; 
    for (int i = idx+1; i <= size; i++){
      std::int64_t tmp = data [i];
      data[i] = cur;
      cur = tmp;
    }
  }
}

template <typename T>
void DynamicArray<T>::remove(std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Out of range");
  }

  for (int i = idx; i < size; i++) {
    data[i] = data[i + 1];
  }
  size--;
}

template <typename T>
void DynamicArray<T>::erase_after(std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Out of range");
  }
  for (int i = idx+1; i <= size; i++){
    data[i] = 0;
  }
  size = idx;
}


template <typename T>
void DynamicArray<T>::increase_Capasity(std::int64_t newCapacity){
  if (newCapacity < capacity){
    throw std::invalid_argument("incorrect input");
  }
  T* tempArray = new T[newCapacity];
  for (int i = 0; i <= size; i++){
    tempArray[i] = data[i];
  }
  delete[] data;
  data = tempArray;
  capacity = newCapacity;
}


template <typename T>
void DynamicArray<T>::decrease_Capacity(std::int64_t newCapacity){
  if (newCapacity > capacity){
    throw std::invalid_argument("incorrect input");
  }

  if (size < newCapacity < capacity) {
    T* tempArray = new T[newCapacity];
    for (int i = 0; i <= size; i++){
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }

  if (newCapacity < size) {
    size = newCapacity;
    
    T* tempArray = new T[newCapacity];
    for (int i = 0; i <= size; i++){
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
}

  //-------------------------------homework 24.11----------------------------------//