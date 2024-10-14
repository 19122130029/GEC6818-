#ifndef __LOGIN_H__
#define __LOGIN_H__

#include <stdio.h>

void login(void);
void regist(void);
void Num_lock(void);

extern char bmp_01[][15];
extern int arr_Account[4];
extern int arr_Password[4];
extern int return_welcome;
extern char Character_account;

extern int account;
extern int password;
extern int password_x;
extern int password_y;
extern int account_x;
extern int account_y;
#endif