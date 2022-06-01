#ifndef STD__ARRAY_ARRAY_H
#define STD__ARRAY_ARRAY_H

#include <initializer_list>
#include <ostream>

template <class T>
        class iterator {

        };

template <class T>
class array {
public:
    array();
    array(const array&);  //copy ctor
    array(array&&);  //move ctor
    array(std::initializer_list<T>&);
    ~array();

public:
    //functions
    array<T>& front();
    array<T>& back();
    //array::iterator<T> begin();
    //array::iterator<T> end();
    bool empty();
    std::size_t size();
    T& fill(const T&);
    T& at(array<T>);
    T* data();
    //array::reverse_iterator<T> rbegin();
    //array::reverse_iterator<T> rend();

    // operators
    array<T>& operator=(array<T>&);  //copy operator assignment
    array<T>& operator=(array<T>&&);  //move operator assignment
    friend std::ostream operator<<(std::ostream& out, array<T>&);
    bool operator==(const array<T>&);
    T& operator[](int);
    bool operator!=(const array<T>);
    array<T>& operator+(const array<T>&);
    array<T>& operator+=(const array<T>&);
    bool operator<(const array<T>&);
    bool operator<=(const array<T>&);
    bool operator>(const array<T>&);
    bool operator>=(const array<T>&);

private:

};


#endif //STD__ARRAY_ARRAY_H
