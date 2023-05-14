#include"controller.h"
#include"knight.h"
#include"commands.h"
#include<iostream>
#include<conio.h>

Controller* Controller::controller = new Controller;

std::vector<Character*> Controller::troop(3, nullptr);

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