#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>
#include <iostream>

#include "iterator.h"


template <class T, std::size_t N>
class Array {
public:
    Array();
    Array(const Array<T, N>&);
    Array(Array<T, N>&&);
    Array(std::initializer_list<T>&);
    ~Array();

public:
    Array<T, N>& front();  //access the first element
    Array<T, N>& back();  //access the last element
    RandomAccessIterator<T> begin();  //returns an iterator to the beginning
    RandomAccessIterator<T> end();  //return an iterator to the end
    bool empty();
    std::size_t size();
    void fill(const T&);  //fill the container with specified value
    T& at(Array<T, N>);  //error-i jamanak std::out_of_range
    T* data();  //direct access to underlying array
    ReverseRandomAccessIterator<T> rbegin();
    ReverseRandomAccessIterator<T> rend();

    Array<T, N>& operator=(Array<T, N>&);  //copy operator assignment
    Array<T, N>& operator=(Array<T, N>&&);  //move operator assignment
    friend std::ostream operator<<(std::ostream& out, Array<T, N>&);
    T& operator[](int);
    Array<T, N>& operator+(const Array<T, N>&);
    Array<T, N>& operator+=(const Array<T, N>&);
    bool operator<(const Array<T, N>&);
    bool operator<=(const Array<T, N>&);
    bool operator>(const Array<T, N>&);
    bool operator>=(const Array<T, N>&);
    bool operator==(const Array<T, N>&);
    bool operator!=(const Array<T, N>&);

private:
    T& sum();

private:
    T m_data[N];
    std::size_t m_size;
};

#include "array.hpp"

#endif  // ARRAY_H