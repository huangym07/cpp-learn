#include "StrVecLib.h"
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

std::allocator<std::string> StrVec::alloc;

void StrVec::free() {
#ifndef NDEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    if (elements_) {
        for (auto p = first_free_; p != elements_; /* empty */) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements_, cap_ - first_free_);
    }
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(std::string *b,
                                                             std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

StrVec::StrVec(const StrVec &other) {
    auto new_data = alloc_n_copy(other.begin(), other.end());
    elements_ = new_data.first;
    first_free_ = cap_ = new_data.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements_ = new_data.first;
    first_free_ = cap_ = new_data.second;
    return *this;
}

StrVec::StrVec(StrVec &&other) noexcept
    : elements_(other.elements_), first_free_(other.first_free_),
      cap_(other.cap_) {
    other.elements_ = other.first_free_ = other.cap_ = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements_ = rhs.elements_;
        first_free_ = rhs.first_free_;
        cap_ = rhs.cap_;
        rhs.elements_ = rhs.first_free_ = rhs.cap_ = nullptr;
    }
    return *this;
}

void StrVec::push_back(const std::string &value) {
#ifndef NDEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    check_n_alloc();
    alloc.construct(first_free_++, value);
}
void StrVec::push_back(std::string &&value) {
#ifndef NDEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    check_n_alloc();
    alloc.construct(first_free_++, std::move(value));
}

void StrVec::reallocate() {
#ifndef NDEBUG
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    auto new_capacity = size() ? 2 * size() : 1;
#ifndef NDEBUG
    std::cout << "new_capacity is " << new_capacity << std::endl;
#endif
    auto elements = alloc.allocate(new_capacity);
#ifndef NDEBUG
    std::cout << "elements allocate is ok" << std::endl;
#endif
    auto first_free =
        std::uninitialized_copy(std::make_move_iterator(begin()),
                                std::make_move_iterator(end()), elements);
#ifndef NDEBUG
    std::cout << "After uninitialized_copy: " << std::endl;
    for (auto p = elements; p != first_free; ++p) {
        std::cout << *p << std::endl;
    }
#endif
    free();
#ifndef NDEBUG
    std::cout << "After free: " << std::endl;
    for (auto p = elements; p != first_free; ++p) {
        std::cout << *p << std::endl;
    }
#endif
    elements_ = elements;
    first_free_ = first_free;
    cap_ = elements_ + new_capacity;
#ifndef NDEBUG
    if (new_capacity == 1)
        std::cout << (elements_ == first_free_ ? "elements_ = first_free_"
                                               : "elements_ != first_free_")
                  << std::endl;
#endif
}