#include"commands.h"
#include"controller.h"
#include"knight.h"
#include<iostream>
#include<conio.h>

#define sodier_under_control Controller::troop[Controller::current_choice]

bool check(bool t, const std::string& msg = "无效命令"){
    if(t){std::cout << msg << std::endl;}
    return t;
}

void loop_control(std::vector<Command*> &slots, void (*trans)(int&)){
    for(int i; (i = _getch()) != '~';){
        trans(i);
        if(check(i == -1)){continue;} //* -1为switch语句的默认返回值
        else{slots[i]->execute();}
    }
}

Main_Command::Main_Command():
    slots{new Character_Command, new Clear_Command, }{}

void Main_Command::execute(){
    std::cout << "MODE: Main_Command" << std::endl;
    loop_control(slots, trans_main);
}

Character_Command::Character_Command():
    slots{new Create_Command, new Attack_Command, new Character_Choose_Command, new Delete_Command, }{}

void Character_Command::execute(){
    std::cout << "MODE: Character_Command" << std::endl;
    slots[2]->execute(); //* 先进入角色选择模式
    loop_control(slots, trans_character);
    std::cout << "Mode: Main_Command" << std::endl;
}

void Character_Choose_Command::execute(){
    std::cout << "选择操纵位置(1~" << Controller::troop.size() << ")" << std::endl;
    for(int &i = Controller::current_choice; i = _getch() - '0' - 1, 
        check(i < 0 || i >= Controller::troop.size(), "无法操纵该位置，请重新选择"););
    if(check(!sodier_under_control, "当前位置没有士兵，如果想使用，需要创建士兵")){
    }else{
        std::cout << sodier_under_control->get_name() << " is under control..." << std::endl;
        std::cout << sodier_under_control->get_image() << std::endl;
    }
}

void Delete_Command::execute(){
    if(check(!sodier_under_control, "当前位置还没有士兵，无法删除士兵")){return;}
    delete sodier_under_control;
    sodier_under_control = nullptr;
}

void Create_Command::execute(){
    if(check(sodier_under_control, "当前位置已有士兵，无法创建新的士兵")){return;}
    std::string name;
    std::cout << "输入士兵[" << Controller::current_choice + 1 << "]的名字: ";
    std::getline(std::cin, name);
    sodier_under_control = new Knight(name);
}

void Attack_Command::execute(){
    if(check(!sodier_under_control)){return;}
    if(Controller::enemy.size()){
        sodier_under_control->attack(*Controller::enemy[0]);
    }else{
        sodier_under_control->attack();
    }
    
}

void Clear_Command::execute(){
    system("cls");
}

void trans_main(int& ch){
    switch (ch){
    case 'p': // Character_Command
        ch = 0; break;
    case 'c':  // Clear_Command
        ch = 1; break;
    default:
        ch = -1; break;
    }    
}

void trans_character(int& ch){
    switch (ch){
    case 'c': // Create_Command
        ch = 0; break;
    case 'j': // Attack_Command
        ch = 1; break;
    case 'b': // Choose_Character_command
        ch = 2; break;
    case 'd': // Delete_Command
        ch = 3; break;
    default:
        ch = -1; break;
    }
}