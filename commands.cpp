#include"commands.h"
#include"controller.h"
#include"knight.h"
#include<iostream>
#include<conio.h>

Main_Command::Main_Command():
    slots{new Character_Command}{}

void Main_Command::execute(){
    std::cout << "MODE: Main_Command" << std::endl;
    for(char c;std::cout << "command: ", c = _getche(), std::cout << std::endl, c != '~';){
        slots[0]->execute();
    }
}

Character_Command::Character_Command():
    slots{new Create_Command, new Attack_Command, }{}

int Character_Command::choose_position(){
    ENTER: std::cout << "选择操纵位置: ";
    std::vector<Character*>::size_type n = _getche() - '0' - 1;
    for(n; n < 0 || n > 2; n = _getche() - '0' - 1){
        std::cout << std::endl << "无法操纵该位置，请重新选择: ";
    }
    std::cout << std::endl;
    if(!Controller::troop[n]){
        std::cout << "当前位置没有士兵，是否创建士兵？(y or n)\nyour choice: ";
        char c = _getche();
        std::cout << std::endl;
        switch (c){
        case 'y':
            slots[0]->execute(n);
            break;
        default:
            goto ENTER;
        }
    }
    return n;
}

void Character_Command::execute(){
    std::cout << "MODE: Character_Command" << std::endl;
    int n = choose_position();
    for(char c; std::cout << "command: ", c = _getche(), std::cout << std::endl, c != '~';){
        slots[1]->execute(n);
    }
    std::cout << "Mode: Main_Mode" << std::endl;
}

void Create_Command::execute(int n){
    std::string name;
    std::cout << "输入士兵[" << n << "]的名字: ";
    std::getline(std::cin, name);
    Controller::troop[n] = new Knight(name);
}

void Attack_Command::execute(int n){
    Controller::troop[n]->attack();
}