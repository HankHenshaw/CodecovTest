#include <iostream>
#include "matrix.h"

std::ostream& operator<<(std::ostream &os, const typename Matrix<int>::index& arr)
{
    os << "[";
    for(size_t i = 0; i < arr.size();)
    {
        os << arr[i];
        if(++i < arr.size())
            os << ", ";
    }
    os << "]";
    return os;
}

int main()
{
    /*----------ONE-----------*/
    Matrix<int> mat;
    std::cout << "SIZE = " << mat.size() << '\n';

    auto a = mat(1,1);
    std::cout << "A = " << a << '\n';
    std::cout << "SIZE = " << mat.size() << '\n';

    mat(1, 1) = 5;
    std::cout << "SIZE = " << mat.size() << '\n';
    std::cout << "mat(1, 1) = " << mat(1, 1) << '\n';

    /*----------TWO-----------*/
    Matrix<int> mat2;
    const int SIZE = 10;

    for(int i = 0; i < SIZE; i += 2)
    {
        for(int j = 0; j < SIZE; j += 2)
        {
            mat2[i][j] = i*j;
            mat2[i+1][j+1] = i*j;
        }
    }

    for(const auto &val : mat2)
    {
        std::cout << val.first << " = " << val.second << "\n";
    }

    std::cout << "SIZE = " << mat2.size() << '\n';
    return 0;
}
