#include"controller.h"
#include"knight.h"
#include"commands.h"
#include<iostream>
#include<conio.h>

Controller* Controller::controller = new Controller;
int Controller::current_choice = -1;
std::vector<Character*>::size_type Controller::troop_size = 3;
std::vector<Character*> Controller::troop(Controller::troop_size, nullptr);

Controller::Controller(){
    std::cout << "Game start!" << std::endl;
}

Controller::~Controller(){
    for(Character* i : troop){
        if(i){delete i;}
    }
    std::cout << "Game over!" << std::endl;
}

void Controller::control(){
    Main_Command command;
    command.execute();
    QUIT: controller->~Controller();
}