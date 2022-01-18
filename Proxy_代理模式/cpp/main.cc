#include <iostream>

// ISubject 是抽象了 RealSubject 和 ProxySubject 共有操作的接口
class ISubject {
public:
    virtual ~ISubject() = 0;
    virtual void request() const = 0;
};

// 抽象类的析构函数可以是纯虚函数，但是必须提供其实现
// 可见纯虚函数也可以有函数体
ISubject::~ISubject() {}

// RealSubject 中包含核心业务逻辑
// RealSubjects 通常处理一些重要但是很慢（视频文件下载）或者很敏感（需要合适的输出）
// 有了 ProxySubjects 就可以在不修改 RealSubject 代码的情况下处理「慢、敏感」的问题
class RealSubject : public ISubject {
public:
    void request() const override {
        std::cout << "RealSubject::request handling requests\n";
    }
};


// Proxy 中持有 RealSubject 对象的引用
// 任何使用 RealSubject 的地方都可以被 ProxySubject 代替
class ProxySubject : public ISubject {
public:
    // RealSubject 对象即可以由客户端传给 ProxySubject，
    // 也可以由 ProxySubject 通过懒加载创建。
    ProxySubject(RealSubject* real_subject) : real_subject_(new RealSubject(*real_subject)) {}
    ~ProxySubject() {
        delete real_subject_;
    }

    // 代理模式的应用通常是懒加载（lazy loading），缓存（caching），访问控制（controlling the access），
    // 日志（logging）等。
    void request() const override {
        if (checkAccess()) {
            real_subject_->request();
            logAccess();
        }
    }
private:
    bool checkAccess() const {
        std::cout << "ProxySubject: 在触发实际请求之前检查访问权限\n";
        return true;
    }
    void logAccess() const {
        std::cout << "ProxySubject: 志记访问时间\n";
    }

private:
    RealSubject* real_subject_;
};

void client(const ISubject& subject) {
    subject.request();
}

int main(int argc, char** argv) {

    std::cout << "Client: 使用 real subject 执行客户端代码\n";
    RealSubject* realSubject = new RealSubject();
    client(*realSubject);

    std::cout << "******************************" << std::endl;

    std::cout << "Client: 使用 proxy subject 执行相同的客户端代码\n";
    ProxySubject* proxySubject = new ProxySubject(realSubject);
    client(*proxySubject);

    delete realSubject;
    delete proxySubject;

    return 0;
}