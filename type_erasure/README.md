
## 继承虚基类

* 经典的定义一个虚基类
* 继承，然后实现方法

## 指定策略

* 通常有标签分发
    * 如各std::advance()根据不同的迭代器类型，利用重载，变换策略
* 模板指定
    * 比如priority_queue可以在模板参数中指定，是大根堆 还是小根堆
* 代码中的例子，利用一个特殊的策略成员，只需要实现不同的策略，就可以拥有不同的行为
    

## 现代的解决办法
* 两个特殊的类型 concept 和 model
* concept指定应该接口
* model继承自concept并定义实现
* 此时可以调用free function ，最大程度解耦

## 第二种版本
* 用一个类 进行包装
* 不需要暴露实现细节
* 拷贝需要，提供clone函数，保持正确语义