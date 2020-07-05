#include <iostream>
#include <map>
#include "matrix.h"

int main()
{
    Matrix<int, 22> mat;
   std::cout << "SIZE = " << mat.size() << '\n';

   auto a = mat(1,1);
   std::cout << "A = " << a << '\n';
   std::cout << "SIZE = " << mat.size() << '\n';

   mat(1, 1) = 5;
   std::cout << "SIZE = " << mat.size() << '\n';
   std::cout << "mat(1, 1) = " << mat(1, 1) << '\n';

    return 0;
}
