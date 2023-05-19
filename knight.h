#ifndef KNIGHT_H
#define KNIGHT_H
#include"character.h"
#include"gun.h"
class Knight: public Character{
public:
    Knight(const std::string& _name, const std::string& img = "ξ(✿ ❛‿❛)ξ", int ap = 20, int hp = 100, Weapon* _weapon = new Gun):
        Character::Character(_name, img , ap , hp , _weapon){
            name_wrapper("knight");
            std::cout << name << " is created..." << std::endl;
            std::cout << get_image() << std::endl;
        }
    Knight(): Knight("nobody"){}
};
#endif