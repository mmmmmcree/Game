#ifndef WEAPON_H
#define WEAPON_H
#include<iostream>
class Character;
class Weapon{
public:
    virtual void attack(int){}
    virtual void init(){}
    void attack(Character&, int);
    int add_ap();
    void set_ap(int);
    void set_image(const std::string&);
    void print_image();

protected:
    int attack_power;
    std::string image;

};
#endif