#include "unique_ptr.hpp"

int main() {
    unique_ptr<int> uptr1(new int(10));
    unique_ptr<double> uptr2(new double(23.9));
    std::cout << *(uptr1.get()) << std::endl;
    std::cout << *(uptr2.get()) << std::endl;

    unique_ptr<int> uptr3(std::move(uptr1));
    std::cout << *uptr3 << std::endl;
    // std::cout << *uptr1 << std::endl; // Segmentation fault 

    uptr3.release();
    // std::cout << *uptr3 << std::endl; // Segmentation fault

    unique_ptr<int> uptr4(new int(10));
    unique_ptr<int> uptr5(new int(9));
    uptr4.reset(uptr5.release());
    std::cout << *uptr4 << std::endl;
    // std::cout << *uptr5 << std::endl; // Segmentation fault

    return 0;
}
