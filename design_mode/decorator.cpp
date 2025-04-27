#include <iostream>
#include <memory>

class Beverage {
    public:
        virtual std::string getDescription() const = 0; // 描述
        virtual double cost() const = 0;    // 花费
};

// 原来的接口
class Coffee : public Beverage {
    public:
        std::string getDescription() const override {
            return "基础咖啡";
        }
        double cost() const override {
            return 10.0;
        }
};


/**新的接口 */

// 抽象类接口
class CondimentDecorator : public Beverage {
    protected:
        Beverage* beverage; // 被装饰的饮料
    public:
        CondimentDecorator(Beverage* b) : beverage(b) {}
};


// 派生类接口
class Milk : public CondimentDecorator {
    public:
        Milk(Beverage* b) : CondimentDecorator(b) {}
        std::string getDescription() const override {
            return beverage->getDescription() + ", 加奶";
        }
        double cost() const override {
            return beverage->cost() + 2.0; // 加奶额外收费2元
        }
};
    
class Sugar : public CondimentDecorator {
    public:
        Sugar(Beverage* b) : CondimentDecorator(b) {}
        std::string getDescription() const override {
            return beverage->getDescription() + ", 加糖";
        }
        double cost() const override {
            return beverage->cost() + 1.0; // 加糖额外收费1元
        }
};


int main() {
    // std::unique_ptr<Beverage>(new Coffee);
    Beverage* mywater = new Coffee;
    Milk* add_milk = new Milk(mywater);
    Sugar* add_sugar = new Sugar(mywater);
    std::cout << add_milk->getDescription() << " " << "现在的价格是：" << add_milk->cost() << std::endl;
    std::cout << add_sugar->getDescription() << " " << "现在的价格是：" << add_sugar->cost() << std::endl;  
    return 0;
}