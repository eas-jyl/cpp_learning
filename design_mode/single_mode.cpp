#include <iostream>
#include <string>

/**饿汉模式 */
class Singleton
{
public:
    // 静态成员函数：只能使用静态成员变量
    static Singleton* get() {
        return instance;
    }
private:
    Singleton() {}
    // 禁止拷贝构造和赋值重载
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance;
};

Singleton* Singleton::instance = new Singleton();   // 饿汉模式事先创建好对象

/**懒汉模式 */
class LazyMan {
public:
    static LazyMan* get_LazyMan() {
        static LazyMan m_lazy;
        return &m_lazy;
    }
private:
    LazyMan() {}
    LazyMan(const LazyMan&) = delete;
    LazyMan& operator=(const LazyMan&) = delete;
};




int main() {
    LazyMan* l1 = LazyMan::get_LazyMan();
    LazyMan* l2 = LazyMan::get_LazyMan();   

    std::cout << l1 << " " << l2 << std::endl;

    return 0;
}