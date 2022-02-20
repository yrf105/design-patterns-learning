#include <thread>

class singleton {
private:
    singleton(); //私有构造函数，不允许使用者自己生成对象
    singleton(const singleton &other);

    //要写成静态方法的原因：类成员函数隐含传递this指针（第一个参数）
    static void init() {
        p = new singleton;
    }

    static pthread_once_t ponce_;
    static singleton *p; //静态成员变量
public:
    static singleton *instance() {
        // init函数只会执行一次
        pthread_once(&ponce_, &singleton::init);
        return p;
    }
};


singleton::singleton() {

}

singleton::singleton(const singleton &other) {
    
}

pthread_once_t singleton::ponce_;
singleton* singleton::p = nullptr;