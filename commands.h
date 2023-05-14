/*
*   一共有两种Command类: 具槽类和不具槽类
*   具槽类一般是选择命令的状态，如Main_Command模式，在该模式下可以选择其他命令
*   不具槽类一般是基本命令，如Attack_Command
*   具槽类需要具有std::vector<Command*> slots 以及对应字母到数字的转换函数
*/
#ifndef COMMANDS_H
#define COMMANDS_H
#include<vector>
#include"command.h"

class Main_Command : public Command{
    std::vector<Command*> slots;
public:
    Main_Command();
    void execute();
};

class Character_Command : public Command{
    std::vector<Command*> slots;
public:
    Character_Command();
    void execute();
    int choose_position();
};

class Create_Command : public Command{
public:
    void execute(int);
};

class Attack_Command : public Command{
public:
    void execute(int);
};

#endif