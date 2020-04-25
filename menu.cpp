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

void Menu::resetP(){
    py = 2;
    movep(1);
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
    resetP();
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
            case SECTIONSOMEBIGO:
                menu::psection = SECTIONBIGO;
                yLimDown = 10;
                header();
                bigoMenu();
                resetP();
                break;
        }
}

void Menu::enter(){
    switch(menu::section){
        case SECTIONSTART:
            enterstart();
            break;
        case SECTIONBIGO:
            menu::psection = SECTIONSOMEBIGO;
            enterbigo(py);
            break;
    }
}

void Menu::enterstart(){
    menu::psection = SECTIONSTART;
    switch(py){
        case 3:
            menu::section = SECTIONBIGO;
            yLimDown = 10;
            header();
            bigoMenu();
            resetP();
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