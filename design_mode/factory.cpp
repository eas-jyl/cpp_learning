#include <iostream>
#include <memory>

using namespace std;


class Car
{
public:
    Car(std::string name) : m_name(name)
    {}
    virtual void show() = 0;
protected:
    std::string m_name;
};


class Bwm : public Car
{
public:
    Bwm(std::string name) : Car(name)
    {}

    void show() {std::cout << m_name << std::endl;}
};

class Audi : public Car
{
public:
    Audi(std::string name) : Car(name)
    {}

    void show() {std::cout << m_name << std::endl;}
};

// /**简单工厂 */
// enum CarType
// {
//     BWM ,
//     AUDI
// };
// class SimpleFactory
// {
// public:
//     Car* create(CarType type) {
//         switch(type) {
//             case BWM:
//                 return new Bwm("baoma");
//             case AUDI:
//                 return new Audi("audi");
//             default:
//                 std::cout << "无法生产该型号的车"<< std::endl;
//         }
//         return nullptr;
//     } 
// };

// /**工厂方法 */
// class Factory
// {
// public:
//     virtual Car* create(std::string name) = 0;
// };

// class Bwm_Factory : public Factory
// {
// public:
//     Car* create(std::string name) {
//         return new Bwm(name);
//     }
// };

// class Audi_Factory : public Factory
// {
// public:
//     Car* create(std::string name) {
//         return new Audi(name);
//     }
// };

int main() {

}