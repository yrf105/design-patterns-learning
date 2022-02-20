#include <iostream>
#include "observer_weakptr.h"
#include "observable_weakptr.h"

class ObserverFoo : public Observer {
public:
    void update() const override {
        std::cout << "Foo \n";
    }
};

class ObserverBar : public Observer {
public:
    void update() const override {
        std::cout << "Bar \n";
    }
};

int main(int argc, char** agrv) {

    std::shared_ptr<Observable> observable(new Observable);

    std::shared_ptr<Observer> observerFoo(new ObserverFoo);
    observerFoo->observe(observable);

    std::shared_ptr<Observer> observerBar(new ObserverBar);
    observerBar->observe(observable);

    observable->notifyAll();

    return 0;
}