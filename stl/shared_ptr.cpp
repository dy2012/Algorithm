#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

template <class T>
class SharedPtr {
 public:
  SharedPtr(T* ptr = nullptr) 
       : ptr_(ptr),
         ref_cnt_(new int(1)),
         mutex_(new mutex) {
  }

  SharedPtr(const SharedPtr<T>& sp) 
       : ptr_(sp.ptr_),
         ref_cnt_(sp.ref_cnt_),
         mutex_(sp.mutex_) {
    add_ref_count();
  }

  ~SharedPtr() {
    release();
  }

  SharedPtr<T>& operator=(const SharedPtr<T>& sp) {
    if (ptr_ != sp.ptr_) {
        release();
        ptr_ = sp.ptr_;
        ref_cnt_ = sp.ref_cnt_;
        mutex_ = sp.mutex_;
        add_ref_count();
    }
    return *this;
  }

  T& operator*() {
    return *ptr_;
  }

  T* operator->() {
    return ptr_;
  }

  int use_count() {
    return *ref_cnt_;
  }

  T* get() {
    return ptr_;
  }

  void add_ref_count() {
    mutex_->lock();
    ++(*ref_cnt_);
    mutex_->unlock();
  }

 private:
  void release() {
    bool delete_flag = false;
    mutex_->lock();
    if (--(*ref_cnt_) == 0) {
      delete ref_cnt_;
      delete ptr_;
      delete_flag = true;
    }
    mutex_->unlock();
    if (delete_flag == true) {
      delete mutex_;
    }
  }

  int* ref_cnt_;
  mutex* mutex_;
  T* ptr_;
};

int main(int argc, char* argv[]) {
    SharedPtr<int> sp1(new int(10));
    SharedPtr<int> sp2(sp1);
    *sp2 = 20;

    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;

    SharedPtr<int> sp3(new int(10));
    sp2 = sp3;
    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;

    sp1 = sp3;
    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;
    return 0;
}