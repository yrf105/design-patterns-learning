#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <boost/circular_buffer.hpp>

template <typename T>
class BoundedBuffer {
public:
    BoundedBuffer(size_t n) : n_(n), array_(n) {}

    void put(const T& p) {
        std::unique_lock<std::mutex> lock(mu_);
        notFull_.wait(lock, [=]{ return array_.size() < n_; });

        array_.push_back(p);

        notEmpty_.notify_one();
    }

    T take() {
        std::unique_lock<std::mutex> lock(mu_);
        notEmpty_.wait(lock, [=]{ return array_.size() > 0; });

        T ret = array_.front();
        array_.pop_front();

        notFull_.notify_one();

        return ret;
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mu_);
        return array_.size();
    }

private:
    size_t n_;
    boost::circular_buffer<T> array_;
    mutable std::mutex mu_;
    std::condition_variable notFull_;
    std::condition_variable notEmpty_;
};

BoundedBuffer<int> bb(10);

void productor() {
    std::cout << "producer \n";

    int i = 0;
    while (i < 10) {
        bb.put(i);
        std::cout << "put " << i << std::endl;
        // std::this_thread::sleep_for(std::chrono::milliseconds(50));
        ++i;
    }
};

void consumer() {
    // std::cout << "consumer \n";
    int i = 0;
    while (i < 10) {
        std::cout << "take " << bb.take() << std::endl;
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ++i;
    }
}

int main(int argc, char** argv) {
    std::vector<std::thread> thrs;
    for (int i = 0; i < 2; ++i) {
        if (i & 1) {
            thrs.push_back(std::thread(productor));
        } else {
            thrs.push_back(std::thread(consumer));
        }
    }

    for (int i = 0; i < 2; ++i) {
        thrs[i].join();
    }

    // std::cout << bb.size() << std::endl;

    return 0;
}