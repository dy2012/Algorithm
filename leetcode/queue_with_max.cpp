#include <iostream>
#include <deque>

using namespace std;

template<typename T>
class QueueWithMax {
 public:
  QueueWithMax() : currentIndex(0) {
  }

  void push_back(T number) {
    while (!maximums.empty() && number >= maximums.back().number) {
      maximums.pop_back();
    }

    InternalData internalData = {number, currentIdx};
    maximums.push_back(internalData);
    data.push_back(internalData);
    ++currentIdx;
  }

  void pop_front() {
      if (maximums.empty()) {
          return;
      }

      if (maximums.front().index == data.front().index) {
          maximums.pop_front();
      }
      data.pop_front();
  }

  T max() const {
    return maximums.front().number;
  }


 private:
  struct InternalData {
    T number;
    int index;
  };

  deque<internalData> data;
  deque<InternalData> maximums;
  int currentIdx;
};

int main(int argc, char* argv[]) {
    return 0;
}
