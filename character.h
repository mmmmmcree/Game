#ifndef CHARACTER_H
#define CHARACTER_H
#include"weapon.h"
#include<iostream>
#include<string>
class Character{
public:
    Character(const std::string&, const std::string&, int, int, Weapon*); //* name, image, attack_point, hit_point, weapon
    Character();
    ~Character();
    void describe(); //todo 描述角色信息
    int get_ap();  //* 获得攻击力数值
    int get_hp(); //* 获得生命值信息
    void attack(); //* 攻击空气    (角色的攻击行为通过调用武器来完成)
    std::string get_name(); //* 获得角色名字
    std::string get_image(); //* 获得角色头像
    void attack(Character&); //* 攻击另一个角色
    void set_ap(int); //* 人物攻击力设置
    void set_weapon(Weapon*); //* 武器切换
    void change_hp(int); //* 血量更改
protected:
    void name_wrapper(const std::string&);  //* 角色名字装饰，加上兵种信息
    void set_image(const std::string&); //* 设置头像
    std::string name; //* 角色名字，默认为nobody
    std::string image; //* 角色头像
    int attack_power; //* 角色攻击力(不包括武器)
    int hit_point; //* 角色血量
    Weapon *weapon; //* 角色武器
};
#endif