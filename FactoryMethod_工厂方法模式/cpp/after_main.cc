#include <iostream>
#include <memory>

// 假设正在开发一个文件分割器的桌面应用

class ISplitter {
public:
    virtual ~ISplitter() {}
    virtual void split() = 0;
};

class BinSplitter : public ISplitter {
public:
    void split() override {
        std::cout << "bin\n";
    }
};

class TextSplitter : public ISplitter {
public:
    void split() override {
        std::cout << "text\n";
    }
};

class ISplitterFactory {
public:
    virtual ~ISplitterFactory() {}
    virtual std::unique_ptr<ISplitter> createSplitter() = 0;
};

class BinSpliterFactory : public ISplitterFactory {
public:
    std::unique_ptr<ISplitter> createSplitter() override {
        return std::make_unique<BinSplitter>();
    }
};

class TextSplitterFactory : public ISplitterFactory {
public:
    std::unique_ptr<ISplitter> createSplitter() override {
        return std::make_unique<TextSplitter>();
    }
};

class MainForm {
public:
    MainForm(ISplitterFactory* factory) : factory_(factory) {} // 将创建具体对象的工作延迟

    void buttomClick() {
        std::unique_ptr<ISplitter> splitter = factory_->createSplitter(); // 多态 new
        splitter->split();
    }
private:
    std::unique_ptr<ISplitterFactory> factory_;
};

int main(int agrc, char** argv) {

    return 0;
}