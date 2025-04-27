#include <iostream>
#include <memory>

class Customer
{
public:
    virtual void free_movie() = 0;
    virtual void vip_movie() = 0;
    virtual void ticket_movie() = 0;
};


class Boss : public Customer
{
public:
    void free_movie() {
        std::cout << "正在观看免费电影" << std::endl;
    }

    void vip_movie() {
        std::cout << "正在观看vip电影" << std::endl;
    }

    void ticket_movie() {
        std::cout << "正在观看用券电影" << std::endl;
    }
};

class FreeProxy : public Customer
{
public:
    FreeProxy() {
        m_proxy = new Boss();
    }

    ~FreeProxy() {
        delete m_proxy;
    }

    void free_movie() {
        m_proxy->free_movie();
    }

    void vip_movie() {
        std::cout << "没有办法观看vip电影" << std::endl;
    }

    void ticket_movie() {
        std::cout << "没有办法观看用券电影" << std::endl;
    }
private:
    Customer* m_proxy;
};

class VipProxy : public Customer
{
public:
    VipProxy() {
        m_proxy = new Boss();
    }

    ~VipProxy() {
        delete m_proxy;
    }

    void free_movie() {
        m_proxy->free_movie();
    }

    void vip_movie() {
        m_proxy->vip_movie();
    }

    void ticket_movie() {
        std::cout << "没有办法观看用券电影" << std::endl;
    }
private:
    Customer* m_proxy;
};

class TicketProxy : public Customer
{
public:
    TicketProxy() {
        m_proxy = new Boss();
    }

    ~TicketProxy() {
        delete m_proxy;
    }

    void free_movie() {
        m_proxy->free_movie();
    }

    void vip_movie() {
        std::cout << "没有办法观看vip电影" << std::endl;
    }

    void ticket_movie() {
        m_proxy->ticket_movie();
    }
private:
    Customer* m_proxy;
};


void watchMovie(std::unique_ptr<Customer>& c1) {
    c1->free_movie();
    c1->vip_movie();
    c1->ticket_movie();
    std::cout << std::endl;
}

int main() {
    std::unique_ptr<Customer> p1(new FreeProxy());
    std::unique_ptr<Customer> p2(new VipProxy());

    watchMovie(p1);
    watchMovie(p2);
}