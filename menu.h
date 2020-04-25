#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include "essentials.h"

int yLimUp = 3;
int yLimDown;
const int SECTIONSTART = 0;
const int SECTIONBIGO = 1;

typedef struct menu{
    int py;
    int section;
    int psection;

    void gotoxy(int x,int y)    
    {
        printf("%c[%d;%df",0x1B,y,x);
    }

    void start(){
        yLimDown = 5;
        menu::section = SECTIONSTART;
        header();
        startOptions(); 
    }
    void header(){
        system("clear");
        printf("Program to exercise some basic programming skills(w,a,s,d to navigate): section:%d\n\n", menu::section);
    }

    void startOptions(){
        gotoxy(3, 3);
        printf("Big O");
        gotoxy(3, 4);
        printf("Scalability");
        gotoxy(3, 5);
        printf("System Design\n");
        interaction();
    }
    void interaction(){
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

    void back(){
        switch(menu::psection){
            case SECTIONSTART:
                start();
                break;
        }
    }

    void enter(){
        switch(menu::section){
            case SECTIONSTART:
                enterstart();
                break;
            case SECTIONBIGO:
                enterbigo();
                break;
        }
        
    }

    void enterbigo(){

    }

    void enterstart(){
        menu::psection = 0;
        switch(py){
            case 3:
                menu::section = 1;
                bigoMenu();
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }

    void bigoMenu(){
        yLimDown = 10;
        header();
        gotoxy(3,3);
        printf("O(1)");
        gotoxy(3,4);
        printf("O(log n)");
        gotoxy(3,5);
        printf("O(n)");
        gotoxy(3,6);
        printf("O(n log n)");
        gotoxy(3,7);
        printf("O(n^2)");
        gotoxy(3,8);
        printf("O(n^3)");
        gotoxy(3,9);
        printf("O(2^n)");
        gotoxy(3,10);
        printf("O(n!)");
        interaction();
    }

    void movep(int dir){
        gotoxy(1, py);
        printf(" ");
        py += dir;
        if (py < yLimUp || py > yLimDown){
           py -= dir; 
        }
        gotoxy(1, py);
        printf(">");
    }
} Menu;

#endif // HEADER_FLAG

