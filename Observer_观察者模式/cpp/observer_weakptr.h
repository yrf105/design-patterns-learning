#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

class Observable;

class Observer : public std::enable_shared_from_this<Observer> {
public:
    void observe(const std::shared_ptr<Observable>& observablePtr);
    virtual void update() const = 0;
    virtual ~Observer();

private:
    std::weak_ptr<Observable> obeservable_;
};