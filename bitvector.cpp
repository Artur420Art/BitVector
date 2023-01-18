#include "bitvector.h"
#include <iostream>


void BitVector::set(const size_t pos, const int value)
{
    if (m_size < pos) {
        m_size = pos;
        int* tmp = new int[++m_size];
        tmp = std::move(m_arr);
        // delete [] m_arr;
        m_arr = new int[m_size];
        m_arr = std::move(tmp);
        m_arr[pos] = static_cast<bool>(value);
        return;
    }

    m_arr[pos] = static_cast<bool>(value);
}
int BitVector::operator[](size_t pos) 
{
    if (pos >= m_size) {
        throw std::invalid_argument("out of range!");
        return -1;
    }
    return m_arr[pos];
}
int BitVector::get(const size_t pos) 
{
    if(pos >= m_size) {
        throw std::invalid_argument("out of range!");
        return -1;
    }
    return m_arr[pos];
}

BitVector::BitVector() 
{
    m_size = 32;
    m_arr = new int[m_size];
}
BitVector::BitVector(size_t size)
{
    m_size = size;
    m_arr = new int[m_size];
}
BitVector::BitVector(size_t size, const int value) 
{
    m_size = size;
    m_arr = new int[++m_size];
    m_arr[size] = static_cast<bool>(value);
}

BitVector::~BitVector()
{
    delete [] m_arr;
}

BitVector::BitVector(const BitVector& rhs) 
{
    this->m_size = rhs.m_size;
    this->m_arr = new int[m_size];
    for(int i = 0; i <= m_size; i++)
    {
        this->m_arr[i] = rhs.m_arr[i];
    }
}

BitVector::BitVector(BitVector&& rhs) 
{
    this->m_size = rhs.m_size;
    this->m_arr = rhs.m_arr;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
    
}

std::ostream& operator<<(std::ostream& os, const BitVector& rhs) 
{
    for (int i = 0; i < rhs.m_size; ++i) 
    {
        os << rhs.m_arr[i] << " ";
    }
    return os;
}
BitVector& BitVector::operator=(const BitVector& rhs)
{
    if(this->m_size == rhs.m_size)
    {
        this->m_arr = rhs.m_arr;
        return *this;
    }
    this->m_size = rhs.m_size;
    this->m_arr = new int[m_size];
    for(int i = 0; i <= m_size; i++) 
    {
        this->m_arr[i] = rhs.m_arr[i];
    }
    return *this;
}
BitVector& BitVector::operator=(BitVector&& rhs) 
{
    this->m_size = rhs.m_size;
    this->m_arr = rhs.m_arr;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
    return *this;
}
