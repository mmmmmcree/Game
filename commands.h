/*
*   一共有两种Command类: 具槽类和不具槽类
*   具槽类一般是选择命令的状态，如Main_Command模式，在该模式下可以选择其他命令
*   不具槽类一般是基本命令，如Attack_Command
*   具槽类需要具有std::vector<Command*> slots 以及对应字母到数字的转换函数(转换函数不做为成员，而是单独定义)
*/
#ifndef COMMANDS_H
#define COMMANDS_H
#include<vector>
#include"command.h"

void loop_control(std::vector<Command*> &, int (*)(char)); //* 用于具槽命令类的循环控制

class Main_Command : public Command{
    std::vector<Command*> slots;
public:
    Main_Command();
    void execute();
};

int trans_main(char);

class Character_Command : public Command{
    std::vector<Command*> slots;
public:
    Character_Command();
    void execute();
};

int trans_character(char); //* Character_Command的转换函数

class Character_Choose_Command : public Command{
public: 
    void execute();
};

class Create_Command : public Command{
public:
    void execute();
};

class Attack_Command : public Command{
public:
    void execute();
};
class Clear_Command : public Command{
public:
    void execute();
};

#endif