#include<iostream>
#include<memory>
#include"knight.h"
#include"controller.h"
using namespace std;

int main(){
    //? system("start README.md");
    Controller::controller->control();
}

/*
todo: 需要一个生产角色的工厂
todo: 需要一个可以控制角色创造、死亡的调度器
todo: 角色生命值降为0以下时，需要销毁角色
*/