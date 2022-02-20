#include <memory>
#include <thread>
#include <mutex>
#include <vector>

class Observer;

class Observable {
public:
    void register_(const std::weak_ptr<Observer>& ob);
    void notifyAll();

private:
    mutable std::mutex mu_;
    std::vector<std::weak_ptr<Observer>> observers_;
};