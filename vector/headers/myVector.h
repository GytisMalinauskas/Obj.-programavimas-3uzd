/**
 * @file myVector.h
 * @brief Header file for the custom vector implementation.
 */

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm> // For std::partition

/**
 * @class Vector
 * @brief A simple vector class.
 * 
 * @tparam T Type of the elements stored in the vector.
 */
template<typename T>
class Vector {
private:
    T* data;        /**< Pointer to the underlying array */
    size_t size_;   /**< Number of elements currently in the Vector */
    size_t capacity_; /**< Capacity of the Vector (size of allocated memory) */

public:
    /**
     * @brief Default constructor.
     */
    Vector() : data(nullptr), size_(0), capacity_(0) {}

    /**
     * @brief Constructor with initializer list.
     * 
     * @param list Initializer list to initialize the vector.
     */
    Vector(std::initializer_list<T> list) : data(nullptr), size_(0), capacity_(0) {
        for (const auto& element : list) {
            push_back(element);
        }
    }

    /**
     * @brief Destructor.
     */
    ~Vector() { delete[] data; }

    /**
     * @brief Copy constructor.
     * 
     * @param other Vector to copy from.
     */
    Vector(const Vector& other) : data(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    /**
     * @brief Move constructor.
     * 
     * @param other Vector to move from.
     */
    Vector(Vector&& other) noexcept : data(other.data), size_(other.size_), capacity_(other.capacity_) {
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    /**
     * @brief Copy assignment operator.
     * 
     * @param other Vector to copy from.
     * @return Reference to this vector.
     */
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

    /**
     * @brief Move assignment operator.
     * 
     * @param other Vector to move from.
     * @return Reference to this vector.
     */
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

    /**
     * @brief Adds an element to the end of the vector.
     * 
     * @param value The value to add.
     */
    void push_back(const T& value) {
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

        data[size_] = value;
        ++size_;
    }

    /**
     * @brief Removes the last element of the vector.
     */
    void pop_back() {
        if (size_ > 0) {
            --size_;
        } else {
            throw std::out_of_range("Vector::pop_back: vector is empty");
        }
    }

    /**
     * @brief Returns the number of elements in the vector.
     * 
     * @return Number of elements in the vector.
     */
    size_t size() const {
        return size_;
    }

    /**
     * @brief Returns the capacity of the vector.
     * 
     * @return Capacity of the vector.
     */
    size_t capacity() const {
        return capacity_;
    }

    /**
     * @brief Reduces the capacity to fit the size.
     */
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

    /**
     * @brief Checks if the vector is empty.
     * 
     * @return true if the vector is empty, false otherwise.
     */
    bool empty() const {
        return size_ == 0;
    }

    /**
     * @brief Returns an iterator to the beginning.
     * 
     * @return Iterator to the beginning.
     */
    T* begin() {
        return data;
    }

    const T* begin() const {
        return data;
    }

    /**
     * @brief Returns an iterator to the end.
     * 
     * @return Iterator to the end.
     */
    T* end() {
        return data + size_;
    }

    const T* end() const {
        return data + size_;
    }

    /**
     * @brief Erases an element at a specific position.
     * 
     * @param pos Position of the element to erase.
     */
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

    /**
     * @brief Erases an element at a specific position.
     * 
     * @param pos Iterator to the position of the element to erase.
     * @return Iterator to the next element.
     */
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

    /**
     * @brief Erases elements in a range.
     * 
     * @param first Iterator to the first element to erase.
     * @param last Iterator to the last element to erase.
     * @return Iterator to the next element.
     */
    T* erase(T* first, T* last) {
        if (first < data || first >= data + size_ || last < data || last > data + size_ || first > last) {
            throw std::out_of_range("Vector::erase: range out of range");
        }

        T* new_end = std::move(last, data + size_, first);
        size_ -= (last - first);
        return new_end;
    }

    /**
     * @brief Clears all elements from the vector.
     */
    void clear() {
        size_ = 0;
    }

    /**
     * @brief Inserts an element at a specific position.
     * 
     * @param pos Iterator to the position.
     * @param value The value to insert.
     * @return Iterator to the inserted element.
     */
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

    /**
     * @brief Inserts an element at a specific position.
     * 
     * @param pos Iterator to the position.
     * @param value The value to insert.
     * @return Iterator to the inserted element.
     */
    T* insert(T* pos, T&& value) {
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

    /**
     * @brief Reserves memory for the vector.
     * 
     * @param new_capacity The new capacity to reserve.
     */
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

    /**
     * @brief Resizes the vector.
     * 
     * @param new_size The new size of the vector.
     * @param value The value to initialize new elements with.
     */
    void resize(size_t new_size, const T& value = T()) {
        if (new_size > capacity_) {
            reserve(new_size);
        }
        for (size_t i = size_; i < new_size; ++i) {
            data[i] = value;
        }
        size_ = new_size;
    }

    /**
     * @brief Accesses an element at a specific index with bounds checking.
     * 
     * @param index The index of the element.
     * @return Reference to the element at the specified index.
     */
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

    /**
     * @brief Accesses the first element.
     * 
     * @return Reference to the first element.
     */
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

    /**
     * @brief Accesses the last element.
     * 
     * @return Reference to the last element.
     */
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

    /**
     * @brief Returns a pointer to the underlying array.
     * 
     * @return Pointer to the underlying array.
     */
    T* data2() {
        return data;
    }

    const T* data2() const {
        return data;
    }

    /**
     * @brief Assigns new content to the vector.
     * 
     * @param first Iterator to the first element.
     * @param last Iterator to the last element.
     */
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

    /**
     * @brief Assigns new content to the vector.
     * 
     * @param count Number of elements to assign.
     * @param value Value to assign to the elements.
     */
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

    /**
     * @brief Accesses an element at a specific index.
     * 
     * @param index The index of the element.
     * @return Reference to the element at the specified index.
     */
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    /**
     * @brief Constructs and adds an element to the end of the vector.
     * 
     * @tparam Args Types of the arguments.
     * @param args Arguments to forward to the constructor.
     */
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

    /**
     * @brief Constructs and inserts an element at a specific position.
     * 
     * @tparam Args Types of the arguments.
     * @param index The position to insert the element at.
     * @param args Arguments to forward to the constructor.
     */
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

    /**
     * @brief Swaps the contents of this vector with another.
     * 
     * @param other The other vector to swap with.
     */
    void swap(Vector& other) {
        std::swap(data, other.data);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }
};

#endif // MYVECTOR_H