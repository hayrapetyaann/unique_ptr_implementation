#ifndef MAKE_HPP
#define MAKE_HPP

#include <memory>

template <typename T, typename... Args>
std::unique_ptr<T> my_make_unique(Args&&... args);

#include "make_impl.cpp"

#endif 
