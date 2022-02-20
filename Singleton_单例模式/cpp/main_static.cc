#include <iostream>
#include <memory>
#include <thread>
#include <string>

template<typename T>
class Singleton {
public:
    static T* GetInstance() {
        static T obj;
        return &obj;
    }
};

template <typename T>
class SingletonPtr {
public:
    static std::shared_ptr<T> GetInstance() {
        static std::shared_ptr<T> ptr(new T);
        return ptr;
    }
};

class A {
public:
    std::string str;
};


void foo1() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    A* a = Singleton<A>::GetInstance();
    std::cout << a->str << std::endl;
}

int main(int argc, char** argv) {
    A* a = Singleton<A>::GetInstance();
    a->str = "main";

    std::thread t1(foo1);
    std::thread t2(foo1);


    t1.join();
    t2.join();

    return 0;
}