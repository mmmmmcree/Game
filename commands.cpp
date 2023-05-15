#include"commands.h"
#include"controller.h"
#include"knight.h"
#include<iostream>
#include<conio.h>

void loop_control(std::vector<Command*> &slots, int (*trans)(char)){
    int i;
    for(char c; std::cout << "command: ", c = _getche(), std::cout << std::endl, c != '~';){
        i = trans(c);
        if(i < slots.size() && i >= 0){slots[trans(c)]->execute();}
        else{std::cout << "无效命令" << std::endl;}
    }
}

void loop_control(std::vector<Command*> &slots, int (*trans)(char), int n){
    int i;
    for(char c; std::cout << "command: ", c = _getche(), std::cout << std::endl, c != '~';){
        i = trans(c);
        if(i < slots.size() && i >= 0){slots[trans(c)]->execute(n);}
        else{std::cout << "无效命令" << std::endl;}
    }
} 

Main_Command::Main_Command():
    slots{new Character_Command}{}

void Main_Command::execute(){
    std::cout << "MODE: Main_Command" << std::endl;
    loop_control(slots, trans_main);
}

Character_Command::Character_Command():
    slots{new Create_Command, new Attack_Command, }{}

int Character_Command::choose_position(){ //todo 妈的，这里必须改
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
    loop_control(slots, trans_character, n);
    std::cout << "Mode: Main_Mode" << std::endl;
}

void Create_Command::execute(int n){
    if(Controller::troop[n]){
        std::cout << "当前位置已有士兵，无法创建新的士兵" << std::endl;
        return;
    }
    std::string name;
    std::cout << "输入士兵[" << n << "]的名字: ";
    std::getline(std::cin, name);
    Controller::troop[n] = new Knight(name);
}

void Attack_Command::execute(int n){
    Controller::troop[n]->attack();
}


int trans_main(char c){
    switch (c){
    case 'p':
        return 0;
    default:
        return -1;
    }    
}

int trans_character(char c){
    switch (c){
    case 'c':
        return 0;
    case 'j':
        return 1;
    default:
        return -1;
    }
}