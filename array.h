#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>
#include <iostream>

template <class T, std::size_t N>
class Array {
public:
    class RandomAccessIterator {
    public:
        typedef T									value_type;
        typedef T&                                  reference;
        typedef const T&                            const_reference;
        typedef T*                                  pointer;
        typedef const T*                            const_pointer;
        typedef std::ptrdiff_t						difference_type;
        typedef std::random_access_iterator_tag		iterator_category;

    public:
        RandomAccessIterator(value_type*);
        reference operator[](RandomAccessIterator);
        pointer operator->();
        reference operator*();
        RandomAccessIterator& operator++();
        RandomAccessIterator& operator++(int);
        RandomAccessIterator& operator--();
        RandomAccessIterator& operator--(int);
        RandomAccessIterator operator-(RandomAccessIterator) const;
        RandomAccessIterator operator+(RandomAccessIterator) const;
        RandomAccessIterator& operator+=(RandomAccessIterator);
        RandomAccessIterator& operator-=(RandomAccessIterator);
        bool operator==(const RandomAccessIterator&) const;
        bool operator!=(const RandomAccessIterator&) const;

    private:
        T* m_ptr;
    };

    class ReverseRandomAccessIterator {
    public:
        typedef T									value_type;
        typedef T&                                  reference;
        typedef const T&                            const_reference;
        typedef T*                                  pointer;
        typedef const T*                            const_pointer;
        typedef std::ptrdiff_t						difference_type;
        typedef std::random_access_iterator_tag		iterator_category;

    public:
        ReverseRandomAccessIterator(value_type*);
        reference operator[](ReverseRandomAccessIterator);
        pointer operator->();
        reference operator*();
        ReverseRandomAccessIterator& operator++();
        ReverseRandomAccessIterator& operator++(int);
        ReverseRandomAccessIterator& operator--();
        ReverseRandomAccessIterator& operator--(int);
        ReverseRandomAccessIterator operator-(ReverseRandomAccessIterator) const;
        ReverseRandomAccessIterator operator+(ReverseRandomAccessIterator) const;
        ReverseRandomAccessIterator& operator+=(ReverseRandomAccessIterator);
        ReverseRandomAccessIterator& operator-=(ReverseRandomAccessIterator);
        bool operator==(const ReverseRandomAccessIterator&) const;
        bool operator!=(const ReverseRandomAccessIterator&) const;

    private:
        T* m_ptr;
    };

public:
    Array();
    Array(const Array<T, N>&);  //copy ctor
    Array(Array<T, N>&&);  //move ctor
    Array(const std::initializer_list<T>&);
    ~Array();

public:
    T& front() const;  //access the first element
    T& back() const;  //access the last element
    RandomAccessIterator begin() const;  //returns an iterator to the beginning
    RandomAccessIterator end() const;  //return an iterator to the end
    ReverseRandomAccessIterator rbegin() const;
    ReverseRandomAccessIterator rend() const;
    T& at(std::size_t) const;  //returns reference at specified position
    T* data() const;  //direct access to underlying array
    bool empty() const;
    std::size_t size() const;
    void fill(const T&);  //fill the container with specified value

    Array<T, N>& operator=(const Array<T, N>&);  //copy operator assignment
    Array<T, N>& operator=(Array<T, N>&&);  //move operator assignment
    Array<T, N>& operator+(const Array<T, N>&);
    Array<T, N>& operator+=(const Array<T, N>&);
    friend std::ostream operator<<(std::ostream& out, const Array<T, N>&);
    T& operator[](int) const;
    bool operator<(const Array<T, N>&);
    bool operator<=(const Array<T, N>&);
    bool operator>(const Array<T, N>&);
    bool operator>=(const Array<T, N>&);
    bool operator==(const Array<T, N>&);
    bool operator!=(const Array<T, N>&);

private:
    T sum() const;

private:
	T* m_data;
    std::size_t m_size;
};

#include "array.hpp"

#endif  // ARRAY_H