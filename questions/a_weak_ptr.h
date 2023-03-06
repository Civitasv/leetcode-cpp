#pragma once
#include <cstddef>
#include <iostream>
#include <memory>
#include <mutex>
#include <sys/types.h>
#include <thread>

template <typename T> class WeakPtr {
private:
  T *ptr;
  uint *ref_count; // shared between different `WeakPtr` objects, so it must
                   // be a pointer.

public:
  WeakPtr(T *ptr) : ptr(ptr), ref_count(new uint(1)) {}

  // Copy constructor
  WeakPtr(const WeakPtr &obj) {
    std::cout << "COPY CONSTRUCTOR" << '\n';
    ptr = obj.ptr;
    ref_count = obj.ref_count;
    if (obj.ptr) {
      // if the pointer isn't null, increment the ref count
      (*ref_count)++;
    }
  }

  // Assignment operator
  WeakPtr &operator=(const WeakPtr &obj) {
    std::cout << "COPY ASSIGNMENT" << '\n';
    if (this == &obj) // 如果是自己，那么不做什么
      return *this;
    if (obj.ptr) {
      // if the pointer isn't null, increment the ref count
      (*obj.ref_count)++;
    }

    if (--(*ref_count) == 0) {
      std::cout << "DELETE IN COPY ASSIGNMENT" << '\n';
      delete ptr;
      delete ref_count;
    }

    ptr = obj.ptr;
    ref_count = obj.ref_count;
    return *this;
  }

  // Move constructor
  WeakPtr(WeakPtr &&obj) {
    std::cout << "MOVE CONSTRUCTOR" << '\n';
    ptr = obj.ptr;
    ref_count = obj.ref_count;

    obj.ptr = nullptr;
    obj.ref_count = nullptr;
  }

  // Move assignment
  WeakPtr &operator=(WeakPtr &&obj) {
    std::cout << "MOVE ASSIGNMENT" << '\n';
    if (this == &obj)
      return *this;

    if (--(*ref_count) == 0) {
      std::cout << "DELETE IN MOVE ASSIGNMENT" << '\n';
      delete ptr;
      delete ref_count;
    }

    ptr = obj.ptr;
    ref_count = obj.ref_count;

    obj.ptr = nullptr;
    obj.ref_count = nullptr;
    return *this;
  }

  T *operator->() const { return ptr; }

  T &operator*() const { return *ptr; }

  uint GetCount() const { return *(ref_count); }

  T *Get() const { return ptr; }

  ~WeakPtr() {
    if (ptr && --*ref_count == 0) {
      std::cout << "DELETE IT" << '\n';
      delete ptr;
      delete ref_count;
    }
  }
};