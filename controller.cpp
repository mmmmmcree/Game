#include"controller.h"
#include"knight.h"
#include"commands.h"
#include<iostream>
#include<conio.h>

Controller* Controller::controller = new Controller;

int Controller::current_choice = -1;

std::vector<Character*> Controller::troop(3, nullptr);

std::vector<Character*> Controller::enemy{new Knight("MotherFucker", "ᕙ(⇀‸↼‵‵)ᕗ", 20, 1000, nullptr)};

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
    controller->~Controller();
}