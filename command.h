#ifndef COMMAND_H
#define COMMAND_H
#include<string>
class Command{
public:
    virtual void execute(){}
    virtual void execute(int){}
};
#endif