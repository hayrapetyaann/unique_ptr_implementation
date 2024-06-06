#include "unique_ptr.hpp"

template <typename T, typename Deleter>
constexpr unique_ptr<T, Deleter>::unique_ptr() noexcept : m_ptr(nullptr) {}

template <typename T, typename Deleter>
constexpr unique_ptr<T, Deleter>::unique_ptr(std::nullptr_t new_p) noexcept : m_ptr(new_p) {}

template <typename T, typename Deleter>
unique_ptr<T, Deleter>::unique_ptr(T* ptr) : m_ptr(ptr) {}

template <typename T, typename Deleter>
unique_ptr<T, Deleter>::unique_ptr(unique_ptr&& other) : m_ptr(other.release()) {}

template <typename T, typename Deleter>
unique_ptr<T, Deleter>& unique_ptr<T, Deleter>::operator=(unique_ptr&& other) {
    if (this != &other) {
        reset(other.release());
    }
    return *this;
}

template <typename T, typename Deleter>
T* unique_ptr<T, Deleter>::get() const { return m_ptr; }

template <typename T, typename Deleter>
T& unique_ptr<T, Deleter>::operator*() const noexcept { return *m_ptr; }

template <typename T, typename Deleter>
T* unique_ptr<T, Deleter>::operator->() const noexcept { return m_ptr; }

template <typename T, typename Deleter>
unique_ptr<T, Deleter>::operator bool() const {
    return m_ptr != nullptr;
}

template <typename T, typename Deleter>
void unique_ptr<T, Deleter>::reset(T* ptr) {
    if (ptr != m_ptr) {
        deleter(m_ptr);
        m_ptr = ptr;
    }
}

template <typename T, typename Deleter>
T* unique_ptr<T, Deleter>::release() {
    T* old_ptr = m_ptr;
    m_ptr = nullptr;
    return old_ptr;
}

template <typename T, typename Deleter>
constexpr void unique_ptr<T, Deleter>::swap(unique_ptr& other) noexcept {
    using std::swap;
    swap(m_ptr, other.m_ptr);
}

template <typename T, typename Deleter>
unique_ptr<T, Deleter>::~unique_ptr() {
    if (m_ptr != nullptr) {
        deleter(m_ptr);
    }
}
