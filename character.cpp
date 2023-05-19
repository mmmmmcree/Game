#include"character.h"

Character::Character(const std::string& _name, const std::string& img = NULL, int ap = 100, int hp = 100, Weapon* _weapon = nullptr):
    name(_name), image(img), attack_power(ap), hit_point(hp), weapon(_weapon){}

Character::Character(): Character("nobody"){}

Character::~Character(){
    std::cout << this->name << ": fuck, I'm dead" << std::endl;
}

void Character::describe(){
    std::cout << this->name << ":\n{\n\t当前攻击力 " << get_ap() 
        << "(人物:" << attack_power << ", 武器: " << weapon->add_ap()
        << ");\n\t当前生命值 " << hit_point << ";\n}" << std::endl;
}

void Character::attack(){
    std::cout << get_image();
    weapon->attack(get_ap());
}

void Character::attack(Character&enemy){
    std::cout << get_image();
    weapon->attack(enemy, get_ap());
}

std::string Character::get_name(){
    return name;
}

std::string Character::get_image(){
    return image;
}

int Character::get_ap(){
    return weapon->add_ap() + attack_power;
}

int Character::get_hp(){
    return hit_point;
}

void Character::set_ap(int n){
    attack_power = n;
}

void Character::set_weapon(Weapon *weapon){
    if(this->weapon){delete this->weapon;}
    this->weapon = weapon;  
}

void Character::change_hp(int x){
    hit_point += x;
    std::cout << name << ": hp changed(" << x << ")"  << std::endl;
}

void Character::name_wrapper(const std::string &type){
    name = "<" + type + ">" + name;
}

void Character::set_image(const std::string& img){
    image = img;
}
