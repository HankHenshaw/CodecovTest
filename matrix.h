#ifndef MATRIX_H
#define MATRIX_H

#include <map>
#include <array>
#include <iostream>
#include <type_traits>

template<typename T, int VAL = 0, size_t DIM = 2>
class Matrix
{
    using index = std::array<T, DIM>;
    std::map<index, int> map;

    template<typename ...Args>
    index createIdx(Args&&... args) const
    {
        index tmp;
        size_t i = 0;
        ((tmp[i++] = args),...);

        return tmp;
    }

    class Iterator {
        //TODO
    };

public:  
    struct Proxy {
        Matrix &realMatrix;
        index proxyIdx;
        size_t counter;

        Proxy(Matrix &add, index proxyIndex) : realMatrix(add), proxyIdx(proxyIndex){}
        Proxy(Matrix &add, size_t val) : realMatrix(add), counter(0)
        {
            proxyIdx[counter++] = val;
        }
        T operator=(T val)
        {
            realMatrix.map.emplace(proxyIdx, val);
            return val;

        }
        operator T() const
        {
            return std::as_const(realMatrix)(proxyIdx);
        }

        Proxy& operator[](size_t val)
        {
            while(counter != DIM)
            {
                proxyIdx[counter++] = val;
                return *this;
            }
            return *this;
        }
    };

    template<typename ...Args>
    T operator()(Args&& ...args) const
    {
        if(sizeof... (args) > DIM)
            throw std::logic_error("size of indexes greater than dimention of matrix");

        std::cout << '\n' << __PRETTY_FUNCTION__ << '\n';
        index tmp = createIdx(std::forward<Args>(args)...);
        auto it = map.find(tmp);
        if(it != map.end())
        {
            return it->second;
        }
        return VAL;
    }
    template<typename ...Args>
    Proxy operator()(Args&& ...args)
    {
        return Proxy(*this, createIdx(std::forward<Args>(args)...));
    }
    Proxy operator[](size_t val)
    {
        return {*this, val};
    }

    T operator()(const index& idx) const
    {
        auto it = map.find(idx);
        if(it != map.end())
        {
            return it->second;
        }
        return VAL;
    }

    size_t size() const noexcept
    {
        return map.size();
    }
};



#endif // MATRIX_H