#ifndef __STRVECLIB_H__
#define __STRVECLIB_H__

#include <algorithm>
#include <cstddef>
#include <memory>
#include <string>
#include <utility>

class StrVec {
  public:
    StrVec() : elements_(nullptr), first_free_(nullptr), cap_(nullptr) {}
    ~StrVec() { free(); }
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    StrVec(StrVec &&) noexcept;
    StrVec &operator=(StrVec &&) noexcept;

    void push_back(const std::string &);
    void push_back(std::string &&);

    std::size_t size() const { return first_free_ - elements_; }
    std::size_t capacity() const { return cap_ - elements_; }
    bool empty() const { return size() == 0; }

    std::string *begin() const { return elements_; }
    std::string *end() const { return first_free_; }

  private:
    void free();
    std::pair<std::string *, std::string *> alloc_n_copy(std::string *,
                                                         std::string *);
    void check_n_alloc() { if (size() == capacity()) reallocate(); }
    void reallocate();
    static std::allocator<std::string> alloc;
    std::string *elements_;
    std::string *first_free_;
    std::string *cap_;
};

#endif // __STRVEC_H__