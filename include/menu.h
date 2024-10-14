#ifndef __MENU_H__
#define __MENU_H__

#include "init.h"
#include "font.h"
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct Dish {
    char name[50];
    int num;
    int price;
};
extern int strings_x;
extern int strings_y;
extern struct Dish foods_zhucai[4];
extern struct Dish foods_miandian[4];
extern struct Dish foods_shaokao[4];
extern struct Dish foods_tiandian[4];
extern struct Dish foods_jiushui[3];
extern char *strings_1;
extern char *strings_2;
extern pthread_t ad_tid;
extern int stop_tid;
extern char menu_bmp[10][20];

void menu();
void zhucai();
void miandian();
void shaokao();
void tiandian();
void jiushui();
void processMenu(struct Dish foods[], int size);
void *gesture(void *arg);

#endif