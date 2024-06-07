#include <iostream>
#include "make.hpp"

int main() {
    auto ptr = my_make_unique<int>(11);
    std::cout << *ptr << std::endl;
    return 0;
}
