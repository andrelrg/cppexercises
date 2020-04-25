#include "menu.h"

int yLimUp = 3;
int yLimDown;

void Menu::start() {
    yLimDown = 5;
    menu::section = SECTIONSTART;
    header();
    startOptions(); 
}

void Menu::header(){
    system("clear");
    printf("Program to exercise some basic programming skills(w,a,s,d to navigate): ");
}

void Menu::startOptions(){
     gotoxy(3, 3);
    printf("Big O");
    gotoxy(3, 4);
    printf("Scalability");
    gotoxy(3, 5);
    printf("System Design\n");
    interaction();
}

void Menu::interaction(){
     py = 2;
    movep(1);
    char c;
    while(true){
        c = getch();
        switch(c){
            case 'w':
                movep(-1);
                break;
            case 's':
                movep(1);
                break;
            case 'd':
                enter();
                break;
            case 'a':
                back();
                break;
        }
    }
}

void Menu::back(){
        switch(menu::psection){
            case SECTIONSTART:
                start();
                break;
        }
}

void Menu::enter(){
    switch(menu::section){
        case SECTIONSTART:
            enterstart();
            break;
        case SECTIONBIGO:
            enterbigo();
            break;
    }
}
void Menu::enterstart(){
    menu::psection = 0;
    switch(py){
        case 3:
            menu::section = 1;
            yLimDown = 10;
            header();
            bigoMenu();
            interaction();
            break;
        case 4:
            break;
        case 5:
            break;
    }
}

void Menu::movep(int dir){
    gotoxy(1, py);
    printf(" ");
    py += dir;
    if (py < yLimUp || py > yLimDown){
        py -= dir; 
    }
    gotoxy(1, py);
    printf(">");
}