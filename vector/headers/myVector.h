#ifndef myVector_h
#define myVector_h
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm> // For std::partition

template<typename T>
class Vector {
private:
    T* data;        // Pointer to the underlying array
    size_t size_;   // Number of elements currently in the Vector
    size_t capacity_; // Capacity of the Vector (size of allocated memory)

public:
    // Constructor
    Vector() : data(nullptr), size_(0), capacity_(0) {}
    // Constructor with inializer list
    Vector(std::initializer_list<T> list) : data(nullptr), size_(0), capacity_(0) {
        for (const auto& element : list) {
            push_back(element);
            }
            }

    // Destructor
    ~Vector() { delete[] data; }

    // Copy constructor
    Vector(const Vector& other) : data(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    // Move constructor
    Vector(Vector&& other) noexcept : data(other.data), size_(other.size_), capacity_(other.capacity_) {
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    // Copy assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.capacity_];
            size_ = other.size_;
            capacity_ = other.capacity_;
            for (size_t i = 0; i < size_; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Move assignment operator
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    // push_back
    void push_back(const T& value) {
        if (size_ == capacity_) {
            // Need to allocate more memory
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            T* new_data = new T[new_capacity];

            // Move the existing elements to the new array
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = std::move(data[i]);
            }

            // Clean up the old array
            delete[] data;
            data = new_data;
            capacity_ = new_capacity;
        }

        // Add the new element
        data[size_] = value;
        ++size_;
    }

    // pop_back
    void pop_back() {
        if (size_ > 0) {
            --size_;
        } else {
            throw std::out_of_range("Vector::pop_back: vector is empty");
        }
    }

    // size
    size_t size() const {
        return size_;
    }
    // capacity
    size_t capacity() const {
        return capacity_;
        }
    //shrink_to_fit
    void shrink_to_fit() {
        if (size_ < capacity_) {
            T* new_data = new T[size_];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = std::move(data[i]);
                }
                delete[] data;
                data = new_data;
                capacity_ = size_;
                }
    }

    // empty
    bool empty() const {
        return size_ == 0;
    }

    // begin
    T* begin() {
        return data;
    }

    const T* begin() const {
        return data;
    }

    // end
    T* end() {
        return data + size_;
    }

    const T* end() const {
        return data + size_;
    }
    //erase for v.erase(1);
    void erase(size_t pos) {
        if (pos >= size_) {
            throw std::out_of_range("Index out of range");
            }
            for (size_t i = pos; i < size_ - 1; ++i) {
                data[i] = std::move(data[i + 1]);
            }
            --size_;
            shrink_to_fit();
            }

    // erase
    T* erase(T* pos) {
        if (pos < data || pos >= data + size_) {
            throw std::out_of_range("Vector::erase: position out of range");
        }

        for (T* p = pos; p < data + size_ - 1; ++p) {
            *p = std::move(*(p + 1));
        }

        --size_;
        return pos;
    }

    T* erase(T* first, T* last) {
        if (first < data || first >= data + size_ || last < data || last > data + size_ || first > last) {
            throw std::out_of_range("Vector::erase: range out of range");
        }

        T* new_end = std::move(last, data + size_, first);
        size_ -= (last - first);
        return new_end;
    }

    // clear
    void clear() {
        size_ = 0;
    }

    // insert
    T* insert(T* pos, const T& value) {
        if (pos < data || pos > data + size_) {
            throw std::out_of_range("Vector::insert: position out of range");
        }

        size_t index = pos - data;
        if (size_ == capacity_) {
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < index; ++i) {
                new_data[i] = std::move(data[i]);
            }
            new_data[index] = value;
            for (size_t i = index; i < size_; ++i) {
                new_data[i + 1] = std::move(data[i]);
            }
            delete[] data;
            data = new_data;
            capacity_ = new_capacity;
        } else {
            for (size_t i = size_; i > index; --i) {
                data[i] = std::move(data[i - 1]);
            }
            data[index] = value;
        }
        ++size_;
        return data + index;
    }
    // insert 
    T* insert(T* pos, T&& value ){
        if (pos < data || pos > data + size_) {
            throw std::out_of_range("Vector::insert: position out of range");
            }
            size_t index = pos - data;
            if (size_ == capacity_) {
                size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
                T* new_data = new T[new_capacity];
                for (size_t i = 0; i < index; ++i) {
                    new_data[i] = std::move(data[i]);
                    }
                    new_data[index] = std::move(value);
                    for (size_t i = index; i < size_; ++i) {
                        new_data[i + 1] = std::move(data[i]);
                        }
                        delete[] data;
                        data = new_data;
                        capacity_ = new_capacity;
                        } else {
                            for (size_t i = size_; i > index; --i) {
                                data[i] = std::move(data[i - 1]);
                                }
                                data[index] = std::move(value);
                                }
                                ++size_;
                                return data + index;
                                }
        
                                            

    // reserve
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity_) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = std::move(data[i]);
            }
            delete[] data;
            data = new_data;
            capacity_ = new_capacity;
        }
    }

    // resize
    void resize(size_t new_size, const T& value = T()) {
        if (new_size > capacity_) {
            reserve(new_size);
        }
        for (size_t i = size_; i < new_size; ++i) {
            data[i] = value;
        }
        size_ = new_size;
    }

    // at
    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Vector::at: index out of range");
        }
        return data[index];
    }

    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Vector::at: index out of range");
        }
        return data[index];
    }

    // front
    T& front() {
        if (empty()) {
            throw std::out_of_range("Vector::front: vector is empty");
        }
        return data[0];
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Vector::front: vector is empty");
        }
        return data[0];
    }

    // back
    T& back() {
        if (empty()) {
            throw std::out_of_range("Vector::back: vector is empty");
        }
        return data[size_ - 1];
    }

    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Vector::back: vector is empty");
        }
        return data[size_ - 1];
    }

    // data
    T* data2() {
        return data;
    }

    const T* data2() const {
        return data;
    }

    // assign
    void assign(T* first, T* last) {
        size_t new_size = last - first;
        if (new_size > capacity_) {
            delete[] data;
            capacity_ = new_size;
            data = new T[capacity_];
        }
        for (size_t i = 0; i < new_size; ++i) {
            data[i] = *(first + i);
        }
        size_ = new_size;
    }
    //assign for v.assign(10, 5);
    void assign(size_t count, const T& value) {
        if (count > capacity_) {
            delete[] data;
            capacity_ = count;
            data = new T[capacity_];
            }
            for (size_t i = 0; i < count; ++i) {
                data[i] = value;
                }
                size_ = count;
                }


    // operator[]
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }
    //emplace
template <class... Args>
    void emplace_back(Args&&... args) {
        if (size_ == capacity_) {
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = std::move(data[i]);
            }
            delete[] data;
            data = new_data;
            capacity_ = new_capacity;
        }
        data[size_++] = T(std::forward<Args>(args)...);
    }

    //emplace
    template <typename... Args>
    void emplace(size_t index, Args&&... args) {
        if (index > size_) {
            throw std::out_of_range("Index out of range");
            }
            if (size_ == capacity_) {
                capacity_ *= 2;
                T* new_data = new T[capacity_];
                for (size_t i = 0; i < index; ++i) {
                    new_data[i] = std::move(data[i]);
                    }
                    for (size_t i = size_; i > index; --i) {
                        new_data[i] = std::move(data[i - 1]);
                        }
                        delete[] data;
                        data = new_data;
                        }
                        data[index] = T(std::forward<Args>(args)...);
                        size_++;
    }
    //swap
    void swap(Vector& other) {
        std::swap(data, other.data);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        }
};
#endif