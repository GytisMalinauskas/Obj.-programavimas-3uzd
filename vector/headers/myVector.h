#ifndef myvector_h
#define myvector_h
#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <limits>

template <typename T>
class myVector{
  private:
  
  size_t dydis;
  size_t talpa;
  T* data2;

  public:
  myVector() :  dydis(0), talpa(0), data2(new T[talpa])  {};
  myVector(size_t n) :  dydis(0), talpa(n), data2(new T[talpa]) {};
  myVector(std::initializer_list<T> list) :  dydis(list.size()), talpa(list.size()), data2(new T[talpa]) {};
  myVector(myVector& other) :  dydis(other.dydis), talpa(other.talpa), data2(new T[talpa]) {
    for(size_t i = 0; i < dydis; i++){
      data2[i] = other.data2[i];
  }};
  ~myVector(){delete[] data2;};
  myVector& operator=(const myVector& other){
    if(this != &other){
      delete[] data2;
      dydis = other.dydis;
      talpa = other.talpa;
      data2 = new T[talpa];
      for(size_t i = 0; i < dydis; i++){
        data2[i] = other.data2[i];
    }
    }
    return *this;
  }
  myVector(myVector&& other) : dydis(other.dydis), talpa(other.talpa), data2(other.data2){
    other.data2 = nullptr;
  }
  myVector& operator=(myVector&& other){
    if(this != &other){
      delete[] data2;
      dydis = other.dydis;
      talpa = other.talpa;
      data2 = other.data2;
      other.data2 = nullptr;
    }
    return *this;
  }
  T& at(size_t i){
    if(i >= dydis){
      throw std::out_of_range("Index out of range");
    }
    return data2[i];
  }
  const T& at(size_t i) const{
    if(i >= dydis){
      throw std::out_of_range("Index out of range");
    }
    return data2[i];
  }
  size_t size() const{
      return dydis;
  }
  size_t capacity() const{
        return talpa;
  }
  void push_back(const T& value){
    if(dydis == talpa){
      talpa *= 2;
      T* temp = new T[talpa];
      for(size_t i = 0; i < dydis; i++){
        temp[i] = data2[i];
        }
        delete[] data2;
        data2 = temp;
        }
        data2[dydis++] = value;
  }
  void push_back(T&& value){
    if(dydis == talpa){
      talpa *= 2;
      T* temp = new T[talpa];
      for(size_t i = 0; i < dydis; i++){
        temp[i] = data2[i];
        }
        delete[] data2;
        data2 = temp;
        }
        data2[dydis++] = std::move(value);
  }
  void pop_back(){
    if(dydis > 0){
      dydis--;
      }
  }
  void clear(){
    dydis = 0;
  }
  int max_size() const {
    return std::numeric_limits<size_t>::max() / sizeof(T);
  }
  bool empty() const {
    return dydis == 0;
  }
  void resize(size_t new_size){
      if(new_size > talpa){
        talpa = new_size;
        T* temp = new T[talpa];
        for(size_t i = 0; i < dydis; i++){
          temp[i] = data2[i];
          }
          delete[] data2;
          data2 = temp;
          }
  }
  T& operator[](size_t index){
    return data2[index];
  }
  const T& operator[](size_t index) const {
    return data2[index];
  }
  T& front(){
    return data2[0];
  }
  const T& front() const {
    return data2[0];
  }
  T& back(){
    return data2[dydis - 1];
  }
  const T& back() const{
    return data2[dydis - 1];
  }
  T* data() noexcept {
    return data2;
  }
  const T* data() const noexcept {
  return data2;
  }
  T* end() noexcept{
    return data2+dydis;
  }
  const T* end() const noexcept {
    return data2+dydis;
  }
  T* begin(){
    return data2;
  }
  const T* begin() const {
    return data2;
    }
  void swap(myVector& other){
    std::swap(data2, other.data2);
    std::swap(dydis, other.dydis);
    std::swap(talpa, other.talpa);
  }
 T* erase(T* first, T* second) {
    size_t n = second - first;
    size_t start = first - data2;
    
    for (size_t i = start; i < dydis - n; ++i) {
        data2[i] = std::move(data2[i + n]);
    }
    
    dydis -= n;
    
    return first;
}

void shrink_to_fit() {
    if (dydis < talpa) {
        T* newdata = new T[dydis];
        for (size_t i = 0; i < dydis; i++) {
            newdata[i] = data2[i];
        }
        delete[] data2;
        data2 = newdata;
        talpa = dydis;
    }
}
void assign(T* first, T* last) {
        clear(); // Clear current elements

        size_t count = 0;
        for (T* it = first; it != last; ++it) {
            push_back(*it); // Append each element
            ++count;
        }
    }

  void reserve(unsigned int newtalpa){
    if(newtalpa > talpa){
      T* newdata = new T[newtalpa];
      for(size_t i = 0; i < dydis; i++){
        newdata[i] = data2[i];
        }
        delete[] data2;
        data2 = newdata;
        talpa = newtalpa;
        }
  }
  T* insert(unsigned int index, const T& value){
    if(dydis == talpa){
      reserve(talpa * 2);
      }
      for(size_t i = dydis; i > index; i--){
        data2[i] = data2[i - 1];
        }
        data2[index] = value;
        dydis++;
        return &data2[index];
  }
  T* emplace(unsigned int index, T&& value){
    if(dydis == talpa){
      reserve(talpa * 2);
      }
      for(size_t i = dydis; i > index; i--){
        data2[i] = data2[i - 1];
        }
        data2[index] = std::move(value);
        dydis++;
        return &data2[index];
  }
  T* emplace_back(T&& value){
    if(dydis == talpa){
      reserve(talpa * 2);
      }
      data2[dydis] = std::move(value);
      dydis++;
      return &data2[dydis - 1];
  }
  
      
};
#endif