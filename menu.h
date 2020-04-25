#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdlib.h>
#include "essentials.h"
#include "bigo.h"

const int SECTIONSTART = 0;
const int SECTIONBIGO = 1;
typedef struct menu{
    int py;
    int section;
    int psection;
    void start();
    void header();
    void startOptions();
    void interaction();
    void back();
    void enter();
    void enterstart();
    void movep(int dir);
} Menu;

#endif // HEADER_FLAG

