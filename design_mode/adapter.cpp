#include <iostream>
#include <string>
#include <memory>

class VGA {
public:
    virtual void play() = 0;
};

class TV01_video : public VGA {
public:
    void play() {std::cout << "使用VGA接口进行播放" << std::endl;}
};

class Computer {
    // Computer只能使用VGA接口
public:
    void playvideo(VGA* pVGA){
        pVGA->play();
    }
};


// Computer如何使用HDMI接口(暂时不想重构代码)
class HDMI {
public:
    virtual void play() = 0;
};

class TV02_video : public HDMI {
public:
    void play() {std::cout << "使用HDMI接口进行播放" << std::endl;}
};


// 使用适配器类
class Adapter : public VGA
{
public:
    Adapter(HDMI* hdmi) : m_hdmi(hdmi)
    {}
    void play() {
        m_hdmi->play();
    }
private:
    HDMI* m_hdmi;    
};

int main() {
    std::unique_ptr<Computer> my_computer(new Computer);
    my_computer->playvideo(new Adapter(new TV02_video()));
    return 0;
}