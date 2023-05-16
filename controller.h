#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"character.h"
#include<vector>
class Controller{
    Controller();
    ~Controller();
public:
    void control();
    static Controller* controller;
    static int current_choice;
    static std::vector<Character*> troop;
};
#endif