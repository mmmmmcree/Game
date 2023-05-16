#ifndef KNIGHT_H
#define KNIGHT_H
#include"character.h"
#include"gun.h"
class Knight: public Character{
public:
    Knight(const std::string& _name):
        Character::Character(_name, "ξ(✿ ❛‿❛)ξ" , 20 , 100 , new Gun){
            name_wrapper("knight");
            std::cout << name << " is created..." << std::endl;
            print_image();
            std::cout << std::endl;
        }
    Knight(): Knight("nobody"){}
};
#endif