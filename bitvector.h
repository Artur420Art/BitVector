#ifndef BIT
#define BIT
#include <iostream>

class BitVector {
public:
    BitVector();
    BitVector(const int);
    ~BitVector();

public:
    void set(const int, const bool val = true);
    bool get(const int);
    const int size() const;
    void clear();
    
private:
    void resize(const int);

private:
    int* m_arr;
    int m_size;
};

#endif
