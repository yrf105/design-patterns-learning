## 面向对象的六大设计原则

### 单一职责原则（Single Responsibility Principle）
一个类应该只负责一个职责，一个类中应该是一组相关性很高的函数及数据的封装。

### 开闭原则（Open Close Principle）
一个软件实体应当对扩展开放，对修改关闭。即软件实体应尽量在不修改原有代码的情况下进行扩展。

提倡一个类一旦开发完成，后续增加新的功能就不应该通过修改这个类来完成，而是通过继承，增加新的类。

### 里氏替换原则（Liskov Substitution Principle）

所有引用基类（父类）的地方必须能透明地使用其子类的对象。

### 依赖倒置原则（Dependence Inversion Principle）

抽象不应该依赖于细节，细节应当依赖于抽象。换言之，要针对接口编程，而不是针对实现编程。

关键点：
- 高层模块不应该依赖低层模块，两者都应该依赖其抽象
- 抽象不应该依赖细节
- 细节应该依赖抽象

### 接口隔离原则（Interface Segregation Principle）

使用多个专门的接口，而不使用单一的总接口，即客户端不应该依赖那些它不需要的接口。

### 迪米特原则（Law of Demeter 又名 Least Knowledge Principle）

一个软件实体应当尽可能少地与其他实体发生相互作用。一个类应该对自己需要调用的类知道得最少，类的内部如何实现、如何复杂都与调用者或者依赖者没关系，调用者或者依赖者只需要知道他需要的方法即可，其他的我一概不关心。

## Proxy_代理模式

### 示例
[cpp](Proxy_代理模式/cpp/main.cc)

### 参考
https://refactoringguru.cn/design-patterns/proxy

## Strategy_策略模式

### 示例
[cpp](Strategy_策略模式/cpp/main.cc)

### 参考
https://refactoringguru.cn/design-patterns/strategy

##

### 示例
[cpp]