#ifndef UNIQUE_HPP
#define UNIQUE_HPP

#include <iostream>

template <typename T>
struct Deleter {
    void operator()(T* ptr) {
        if (ptr) {
            delete ptr;
        }
    }
};

template <typename T, typename Deleter = Deleter<T>>
class unique_ptr {
private:
    T* m_ptr;
    Deleter deleter;
public:
    constexpr unique_ptr() noexcept;
    constexpr unique_ptr(std::nullptr_t new_p) noexcept;
    explicit unique_ptr(T* ptr);

    unique_ptr(const unique_ptr& other) = delete;
    T& operator=(const unique_ptr& other) = delete;

    unique_ptr(unique_ptr&& other);
    unique_ptr& operator=(unique_ptr&& other);

    T* get() const;
    T& operator*() const noexcept;
    T* operator->() const noexcept;
    explicit operator bool() const;

    void reset(T* ptr);
    T* release();
    constexpr void swap(unique_ptr& other) noexcept;

    ~unique_ptr();
};

#include "unique_impl.cpp"

#endif 
