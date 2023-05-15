#include"commands.h"
#include"controller.h"
#include"knight.h"
#include<iostream>
#include<conio.h>

void loop_control(std::vector<Command*> &slots, int (*trans)(char)){
    int i;
    for(char c; std::cout << "command: ", c = _getche(), std::cout << std::endl, c != '~';){
        i = trans(c);
        if(i < slots.size() && i >= 0){slots[i]->execute();}
        else{std::cout << "无效命令" << std::endl;}
    }
}

Main_Command::Main_Command():
    slots{new Character_Command, new Clear_Command, }{}

void Main_Command::execute(){
    std::cout << "MODE: Main_Command" << std::endl;
    loop_control(slots, trans_main);
}

Character_Command::Character_Command():
    slots{new Create_Command, new Attack_Command, new Character_Choose_Command, }{}

void Character_Command::execute(){
    std::cout << "MODE: Character_Command" << std::endl;
    slots[2]->execute(); //* 先进入角色选择模式
    loop_control(slots, trans_character);
    Controller::current_choice = -1;
    std::cout << "Mode: Main_Command" << std::endl;
}

void Character_Choose_Command::execute(){
    std::cout << "选择操纵位置(1~" << Controller::troop_size << "): ";
    int &n = Controller::current_choice;
    n = _getche() - '0' - 1;
    for(n; n < 0 || n >= Controller::troop_size; n = _getche() - '0' - 1){
        std::cout << std::endl << "无法操纵该位置，请重新选择: ";
    }
    std::cout << std::endl;
    if(!Controller::troop[Controller::current_choice]){
        std::cout << "当前位置没有士兵，如果想使用，需要创建士兵" << std::endl;
    }
}

void Create_Command::execute(){
    if(Controller::troop[Controller::current_choice]){
        std::cout << "当前位置已有士兵，无法创建新的士兵" << std::endl;
        return;
    }
    std::string name;
    std::cout << "输入士兵[" << Controller::current_choice + 1 << "]的名字: ";
    std::getline(std::cin, name);
    Controller::troop[Controller::current_choice] = new Knight(name);
}

void Attack_Command::execute(){
    if(Controller::troop[Controller::current_choice]){
        Controller::troop[Controller::current_choice]->attack();
    }else{
        std::cout << "无效命令" << std::endl;
    }
}

void Clear_Command::execute(){
    system("cls");
}


int trans_main(char c){
    switch (c){
    case 'p':
        return 0;
    case 'c':
        return 1;
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
    case 'b':
        return 2;
    default:
        return -1;
    }
}