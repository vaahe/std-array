#pragma once

#include <iterator>

template <class T>
class RandomAccessIterator {
public:
	typedef T									value_type;
	typedef T&									reference;
	typedef const T&							const_reference;
	typedef T*									pointer;
	typedef const T*							const_pointer;
	typedef std::ptrdiff_t						difference_type;
	typedef std::random_access_iterator_tag		iterator_category;

public:
	RandomAccessIterator(value_type*);
	reference operator[](difference_type);
	pointer operator->();
	reference operator*();
	RandomAccessIterator& operator++();
	RandomAccessIterator& operator++(int);
	RandomAccessIterator& operator--();
	RandomAccessIterator& operator--(int);
	RandomAccessIterator operator-(difference_type) const;
	RandomAccessIterator operator+(difference_type) const;
	RandomAccessIterator& operator+=(difference_type);
	RandomAccessIterator& operator-=(difference_type);
	bool operator==(const RandomAccessIterator&) const;
	bool operator!=(const RandomAccessIterator&) const;

private:
	T* m_ptr;
};

template <class T>
RandomAccessIterator<T>::RandomAccessIterator(value_type* ptr) : m_ptr(ptr) {}

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator++() {
	++m_ptr;
	return *this;
}

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator++(int) {
	RandomAccessIterator<T> tmp = *this;
	++(*this);
	return tmp;
}

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator--() {
	--m_ptr;
	return *this;
}

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator--(int) {
	RandomAccessIterator<T> tmp = *this;
	--(*this);
	return tmp;
}

template <class T>
typename RandomAccessIterator<T>::reference RandomAccessIterator<T>::operator*() {
	return *m_ptr;
}

template <class T>
typename RandomAccessIterator<T>::pointer RandomAccessIterator<T>::operator->() {
	return m_ptr;
}

template <class T>
T& RandomAccessIterator<T>::operator[](difference_type index) {
	return *(m_ptr + index);
}

template <class T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator+(difference_type other) const {
	return RandomAccessIterator(m_ptr + other);
}

template <class T>
RandomAccessIterator<T> RandomAccessIterator<T>::operator-(difference_type other) const {
	return RandomAccessIterator(m_ptr - other);
}

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator+=(difference_type ptr) {
	m_ptr += ptr;
	return *this;
}

template <class T>
RandomAccessIterator<T>& RandomAccessIterator<T>::operator-=(difference_type ptr) {
	m_ptr -= ptr;
	return *this;
}

template <class T>
bool RandomAccessIterator<T>::operator==(const RandomAccessIterator<T>& other) const {
	return m_ptr == other.m_ptr;
}

template <class T>
bool RandomAccessIterator<T>::operator!=(const RandomAccessIterator<T>& other) const {
	return m_ptr != other.m_ptr;
}


/**Reverse Random Access Iterator**/


template <class T>
class ReverseRandomAccessIterator {
public:
	typedef T									value_type;
	typedef T&									reference;
	typedef const T&							const_reference;
	typedef T*									pointer;
	typedef const T*							const_pointer;
	typedef std::ptrdiff_t						difference_type;
	typedef std::random_access_iterator_tag		iterator_category;

public:
	ReverseRandomAccessIterator(value_type*);
	reference operator[](int);
	pointer operator->();
	reference operator*();
	ReverseRandomAccessIterator& operator++();
	ReverseRandomAccessIterator& operator++(int);
	ReverseRandomAccessIterator& operator--();
	ReverseRandomAccessIterator& operator--(int);
	ReverseRandomAccessIterator& operator-(difference_type) const;
	ReverseRandomAccessIterator& operator+(difference_type) const;
	ReverseRandomAccessIterator& operator-=(difference_type);
	ReverseRandomAccessIterator& operator+=(difference_type);
	bool operator==(const ReverseRandomAccessIterator&) const;
	bool operator!=(const ReverseRandomAccessIterator&) const;

private:
	T* m_ptr;
};

template <class T>
ReverseRandomAccessIterator<T>::ReverseRandomAccessIterator(value_type* ptr) : m_ptr(ptr) {}

template <class T>
typename ReverseRandomAccessIterator<T>::reference ReverseRandomAccessIterator<T>::operator[](int index) {
	return *(m_ptr - index);
}

template <class T>
typename ReverseRandomAccessIterator<T>::pointer ReverseRandomAccessIterator<T>::operator->() {
	return *m_ptr;
}

template <class T>
typename ReverseRandomAccessIterator<T>::reference ReverseRandomAccessIterator<T>::operator*() {
	return m_ptr;
}

template <class T>
ReverseRandomAccessIterator<T>& ReverseRandomAccessIterator<T>::operator++() {
	--m_ptr;
	return *this;
}

template <class T>
ReverseRandomAccessIterator<T>& ReverseRandomAccessIterator<T>::operator++(int) {
	ReverseRandomAccessIterator<T> tmp = *this;
	--(*this);
	return tmp;
}

template <class T>
ReverseRandomAccessIterator<T>& ReverseRandomAccessIterator<T>::operator--() {
	++m_ptr;
	return *this;
}

template <class T>
ReverseRandomAccessIterator<T>& ReverseRandomAccessIterator<T>::operator--(int) {
	ReverseRandomAccessIterator<T> tmp = *this;
	++(*this);
	return tmp;
}

template <class T>
ReverseRandomAccessIterator<T>& ReverseRandomAccessIterator<T>::operator-(difference_type other) const {
	return m_ptr + other.m_ptr;
}

template <class T>
ReverseRandomAccessIterator<T>& ReverseRandomAccessIterator<T>::operator+(difference_type other) const {
	return m_ptr - other.m_ptr;
}

template <class T>
ReverseRandomAccessIterator<T>& ReverseRandomAccessIterator<T>::operator+=(difference_type other) {
	return m_ptr -= other.m_ptr;
}

template <class T>
ReverseRandomAccessIterator<T>& ReverseRandomAccessIterator<T>::operator-=(difference_type other) {
	return m_ptr += other.m_ptr;
}

template <class T>
bool ReverseRandomAccessIterator<T>::operator==(const ReverseRandomAccessIterator<T>& other) const {
	return m_ptr == other.m_ptr;
}

template <class T>
bool ReverseRandomAccessIterator<T>::operator!=(const ReverseRandomAccessIterator<T>& other) const {
	return m_ptr != other.m_ptr;
}