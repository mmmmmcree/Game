#ifndef GUN_H
#define GUN_H
#include"weapon.h"
#include<Windows.h>
class Gun: public Weapon{
public:
    Gun(){init();}
    void attack(int){
        print_image();
        for(int i = 7; i >= 0; --i){
            std::cout << "\b\b" << "       ⚫" + i;
            Sleep(10);
        }
        std::cout << std::endl;
    }
    void init(){
        set_ap(100);
        set_image("▄︻┻┳═一 ");
    }
};
#endif