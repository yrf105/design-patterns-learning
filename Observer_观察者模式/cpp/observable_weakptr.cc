#include "observable_weakptr.h"
#include "observer_weakptr.h"

void Observable::register_(const std::weak_ptr<Observer>& ob) {
    std::lock_guard<std::mutex> lock(mu_);
    observers_.push_back(ob);
}

void Observable::notifyAll() {
    std::lock_guard<std::mutex> lock(mu_);
    auto it = observers_.begin();
    while (it != observers_.end()) {
        std::shared_ptr<Observer> ptr(it->lock());
        if (ptr) {
            ptr->update();
            ++it;
        } else {
            it = observers_.erase(it);
        }
    }
}