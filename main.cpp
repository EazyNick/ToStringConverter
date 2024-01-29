#include "ToStringConverter.h"
#include <iostream>

//int main() {
//    ToStringConverter converter;
//
//    // int ∫§≈Õ
//    std::vector<int> intVec = { 1, 2, 3, 4, 5 };
//    std::string intVecString = converter.convert(intVec);
//    std::cout << "Int vector to string: " << intVecString << std::endl;
//
//    // std::string ∫§≈Õ
//    std::vector<std::string> stringVec = { "Hello", "World", "from", "C++" };
//    std::string stringVecString = converter.convert(stringVec);
//    std::cout << "String vector to string: " << stringVecString << std::endl;
//
//    return 0;
//}

// √‚∑¬∞™, ∂ÁæÓæ≤±‚∑Œ ≥ª∫Œ ∞™ ±∏∫–
// Int vector to string: 1 2 3 4 5
// String vector to string : Hello World from C++

int main() {
    ToStringConverter converter;

    // 2¬˜ø¯ int ∫§≈Õ
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::string matrixString = converter.convert(matrix);
    std::cout << "2D Int vector to string:\n" << matrixString << std::endl;

    return 0;
}

// 2D Int vector to string :
// 1 2 3
// 4 5 6
//7 8 9