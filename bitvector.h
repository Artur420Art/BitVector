#ifndef BIT
#define BIT
#include <iostream>

class BitVector {
public: 
    BitVector();
    BitVector(size_t size);
    BitVector(const BitVector& rhs);
    BitVector& operator=(const BitVector& rhs);
    BitVector(BitVector&& rhs);
    BitVector& operator=(BitVector&& rhs);
    BitVector(size_t size, int value);
    ~BitVector();
    void set(size_t, const int);
    int get(const size_t pos);
    void print();
    int operator[](size_t pos);
    friend std::ostream& operator<<(std::ostream& os, const BitVector& rhs);
private:
    int* m_arr;
    size_t m_size;
};

#endif 