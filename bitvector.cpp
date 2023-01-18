#include "bitvector.h"
#include <iostream>


BitVector::BitVector() 
: m_size{1}
{
    this->m_arr = new int[m_size];
}

BitVector::BitVector(const int size)
: m_size{size}
{
    this->m_arr = new int[m_size];
}

BitVector::~BitVector() {
    this->clear();
}

void BitVector::set(const int position, const bool value) {
    if (position >= m_size * sizeof(int) * 8) {
        this->resize(position);
    }
    int ind = position / sizeof(int) * 8;
    int pos = position - (ind * (sizeof(int) * 8));
    m_arr[ind] |= (1 << pos);
}

bool BitVector::get(const int position) {
    int ind = position / sizeof(int) * 8;
    int pos = position - (ind * (sizeof(int) * 8));
    return m_arr[ind] &= (1 << pos); 
}

const int BitVector::size() const {
    return this->m_size;
}

void BitVector::resize(const int new_size) {

    int tmp_size = (new_size / (sizeof(int) * 8));
    int* tmp = new int[++tmp_size];
    for (int i = 0; i < m_size; ++i) {
        tmp[i] = m_arr[i];
    }
    this->clear();
    m_arr = tmp;
    tmp = nullptr;
    this->m_size = tmp_size;
}

void BitVector::clear() {
    delete this->m_arr;
    this->m_arr = nullptr;
    this->m_size = 0;
}
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
