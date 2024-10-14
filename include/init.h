#ifndef __INIT_H__
#define __INIT_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <linux/input.h>

void init(void);
void uninit(void);
void show_bmp(int x0,int y0,char *bmp_name);
void gets_pos(int *x,int *y);

extern char bmp_NUM[][10];
extern int lcd_fd;
extern int ts_fd;
extern int *p;
extern int x; //触摸屏当前的x坐标
extern int y; //触摸屏当前的y坐标

//登录按钮坐标
#define login_min_X 126
#define login_max_X 354
#define login_min_y 380
#define login_max_y 431

//注册按钮坐标
#define regist_min_X 490
#define regist_max_X 723
#define regist_min_y 380
#define regist_max_y 431

//登录和注册页面的返回欢迎页坐标
#define return_min_x 385
#define return_max_x 472
#define return_min_y 361
#define return_max_y 422

#endif