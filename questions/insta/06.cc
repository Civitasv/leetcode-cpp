#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
std::string flag("A");

void PrintA() {
  while (true) {
    std::unique_lock<std::mutex> lck(mtx);

    while (flag == "B" || flag == "C") {
      cv.wait(lck);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "A" << std::endl;
    flag = "B";
    cv.notify_all();
  }
}

void PrintB() {
  while (true) {
    std::unique_lock<std::mutex> lck(mtx);

    while (flag == "A" || flag == "C") {
      cv.wait(lck);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "B" << std::endl;
    flag = "C";
    cv.notify_all();
  }
}

void PrintC() {
  while (true) {
    std::unique_lock<std::mutex> lck(mtx);

    while (flag == "A" || flag == "B") {
      cv.wait(lck);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "C" << std::endl;
    flag = "A";
    cv.notify_all();
  }
}

int main() {
  std::thread a(PrintA);
  std::thread b(PrintB);
  std::thread c(PrintC);

  a.join();
  b.join();
  c.join();

  return 0;
}