#ifndef DynamicArray_h
#define DynamicArray_h

#include <cstdint>
// size_t == unsigned long long

template <typename T> 
class DynamicArray {
private:
  T* data;
  std::int64_t size = -1; // actual (last occupied)
  std::int64_t capacity; // max

  bool isEmpty() {
    return size == -1;
  }

public:
  DynamicArray(); // default ctor
  DynamicArray(std::int64_t capacity); // parametrized ctor
  DynamicArray(DynamicArray& other);
  ~DynamicArray(); // destructor

  void push_back(T x);
  T add(std::int64_t idx1, std::int64_t idx2);
  T max();
  T min();
  void clear(); // deallocate the data
  void reinitialize(); // restore to default
  void printData();


  //-------------------------------homework 24.11--------------------------------//

  void push_front(T val);
  T front();
  T back();
  void insert(std::int64_t idx, T val);
  void remove(std::int64_t idx);
  void erase_after(std::int64_t idx);
  void increase_Capasity(std::int64_t newCapacity);
  void decrease_Capacity(std::int64_t newCapacity);
  
    std::int64_t getCapacity(){
        return capacity;
    }
  
    std::int64_t getSize(){
        return size;
    }
  //-------------------------------homework 24.11---------------------------------//

};
#include "DynamicArray.cc"
#endif 
