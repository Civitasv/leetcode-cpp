#pragma once
#include <cstddef>
#include <iostream>
#include <memory>
#include <mutex>
#include <sys/types.h>
#include <thread>

template <typename T> class UniquePtr {
private:
  T *ptr;
  // Copy constructor
  UniquePtr(const UniquePtr &obj) {}

  // Assignment operator
  UniquePtr &operator=(const UniquePtr &obj) {}

public:
  UniquePtr(T *ptr) : ptr(ptr) {}

  // Move constructor
  UniquePtr(UniquePtr &&obj) {
    std::cout << "MOVE CONSTRUCTOR" << '\n';
    ptr = obj.ptr;

    obj.ptr = nullptr;
  }

  // Move assignment
  UniquePtr &operator=(UniquePtr &&obj) {
    std::cout << "MOVE ASSIGNMENT" << '\n';
    if (this == &obj)
      return *this;

    std::cout << "DELETE IN MOVE ASSIGNMENT" << '\n';
    delete ptr;

    ptr = obj.ptr;

    obj.ptr = nullptr;
    return *this;
  }

  T *operator->() const { return ptr; }

  T &operator*() const { return *ptr; }

  T *Get() const { return ptr; }

  ~UniquePtr() {
    if (ptr) {
      std::cout << "DELETE IT" << '\n';
      delete ptr;
    }
  }
};