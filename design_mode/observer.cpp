#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>

class Observer
{
public:
    virtual void handler(int msgid) = 0;
};

class Observer1 : public Observer
{
public:
    void handler(int msgid) {
        switch(msgid) {
            case 1:
                std::cout << "Observer1 处理 1" << std::endl;
                break;
            case 2:
                std::cout << "Observer1 处理 2" << std::endl;
                break;
            default:
                break;
        }
    }
};

class Observer2 : public Observer
{
public:
    void handler(int msgid) {
        switch(msgid) {
            case 2:
                std::cout << "Observer2 处理 2" << std::endl;
                break;
            case 3:
                std::cout << "Observer3 处理 3" << std::endl;
                break;
            default:
                break;
        }
    }
};

// 监听者模式
class Subject
{
public:
    // 添加观察者对象 , 绑定对应的信号
    void add_observer(Observer* p , int msgid) {
        m_map[msgid].push_back(p);
    }

    // 通知观察者处理事件
    void notify_observer(int msgid) {
        auto it = m_map.find(msgid);
        if(it != m_map.end()) {
            // 执行函数
            for(Observer* i : it->second) {
                i->handler(msgid);
            }
        }
    }
private:
    std::unordered_map<int , std::list<Observer*>> m_map;
};


int main() {
    std::unique_ptr<Subject> mysub(new Subject);
    Observer1* myobserver1 = new Observer1;
    Observer2* myobserver2 = new Observer2;    
    mysub->add_observer(myobserver1 , 1);
    mysub->add_observer(myobserver1 , 2);
    mysub->add_observer(myobserver2 , 2);

    while(1) {
        int msgid = 0;
        std::cin >> msgid;
        mysub->notify_observer(msgid);
    }

    return 0;
}