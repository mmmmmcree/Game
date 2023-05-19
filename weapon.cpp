#include "weapon.h"
#include"character.h"

void Weapon::attack(Character& enemy, int ap){
    attack(ap);
    std::cout << enemy.get_image() << std::endl;
    enemy.change_hp(-ap);
}

void Weapon::set_ap(int n){
    attack_power = n;
}

int Weapon::add_ap(){
    return attack_power;
}

void Weapon::set_image(const std::string &img){
    image = img;
}

void Weapon::print_image(){
    std::cout << image;
}