#ifndef KNIGHT_H
#define KNIGHT_H
#include"character.h"
#include"gun.h"
class Knight: public Character{
public:
    Knight(){init();}
    Knight(std::string name): Character::Character(name){init();}
private:
    void init(){
        set_ap(20);
        set_weapon(new Gun);
        set_image("ξ(✿ ❛‿❛)ξ");
        name_wrapper("knight");
        std::cout << name << " is created..." << std::endl;
    }
};
#endif