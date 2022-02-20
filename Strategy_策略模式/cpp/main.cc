#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

/*
- Strategy 接口声明了完成相同任务的不同算法的统一接口 DoAlgorithm
- Context 通过该接口调用具体策略定义的算法
*/
class Strategy {
public:
    virtual ~Strategy() {}
    virtual std::string DoAlgorithm(const std::vector<std::string>& strs) const = 0;
};

/*
- Context 定义了客户端感兴趣的接口
*/
class Context {
public:
    Context(Strategy* strategy = nullptr) : strategy_(strategy) {}
    ~Context() {
        delete strategy_;
    }

    // 允许在运行时修改具体策略
    void set_Strategy(Strategy* strategy) {
        delete strategy_;
        strategy_ = strategy;
    }

    void DoSomeBusinessLogic() const {
        //...
        std::cout << "具体结果由 strategy_ 所指向的具体策略所实现的算法决定...\n";
        std::cout << strategy_->DoAlgorithm({"a", "b", "c", "d", "e"}) << std::endl;
        //...
    }

private:
    // Context 包含一个 Strategy 的引用
    Strategy* strategy_;
};

class ConcreteStrategyA : public Strategy {
public:
    std::string DoAlgorithm(const std::vector<std::string>& strs) const override {
        std::string result;
        std::for_each(std::begin(strs), std::end(strs), [&result](const std::string& letter){
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));
        return result;
    }
private:
};

class ConcreteStrategyB : public Strategy {
public:
    std::string DoAlgorithm(const std::vector<std::string>& strs) const override {
        std::string result;
        std::for_each(std::begin(strs), std::end(strs), [&result](const std::string& letter){
            result += letter;
        });
        std::reverse(std::begin(result), std::end(result));
        return result;
    }
private:
};

void clientCode() {
    Context* context = new Context();

    context->set_Strategy(new ConcreteStrategyA);
    context->DoSomeBusinessLogic();

    context->set_Strategy(new ConcreteStrategyB);
    context->DoSomeBusinessLogic();

    delete context;
}

int main() {
    clientCode();
    return 0;
}