#include <iostream>

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

class MainForm {
public:
    void buttomClick() {
        ISplitter* splitter = new BinSplitter(); // 依赖具体类
        splitter->split();
        delete splitter;
    }
};



int main(int argc, char** argv) {

    return 0;
}