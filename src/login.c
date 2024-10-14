#include "login.h"
#include "init.h"
#include "font.h"
#include "menu.h"
char bmp_01[][15]={"welcome.bmp","login.bmp","regist.bmp"};

int return_welcome=0;

int arr_Account[4];
int arr_Password[4];

char Character_account;
char Character_password='*';

int account=1;
int password=0;
int account_x=120,account_y=245;
int password_x=120,password_y=305;
int input_i=0;
int input_j=0;
//µÇÂ¼Ò³Ãæ
void login(void)
{
	show_bmp(0,0,bmp_01[1]);
	input_i=0;
	input_j=0;
	return_welcome=0;
	account_x=120;
	account_y=245;
	while(1)
	{
		gets_pos(&x,&y);
		//printf("(%d,%d)\n",x,y);
		if(x>100 && x<330)
		{
			if(y>250&&y<300)//ÊäÈëÕË»§
			{
				account=1;
				password=0;
				input_i=0;
				account_x=120;
				account_y=245;
			}
			if(y>314 && y<365)//ÊäÈëÃÜÂë
			{
				account=0;
				password=1;
				input_j=0;
				password_x=120;
				password_y=305;
			}
		}
		Num_lock();
		if (x>25&&x<355&&y>400&&y<444)
		{
			for(int i=0;i<4;i++)
				{
					printf("%d",arr_Account[i]);
				}
				printf("\n");
				for(int i=0;i<4;i++)
				{
					printf("%d",arr_Password[i]);
				}
			if(arr_Account[0]==1&&arr_Account[1]==2&&arr_Account[2]==3&&arr_Account[3]==4 &&
			arr_Password[0]==1&&arr_Password[1]==2&&arr_Password[2]==3&&arr_Password[3]==4)
				menu();
			show_bmp(0,0,bmp_01[1]);
		}
		if(return_welcome)break;
	}
}

//×¢²áÒ³Ãæ
void regist(void)
{
	show_bmp(0,0,bmp_01[2]);
	input_i=0;
	input_j=0;
	account_x=120;
	account_y=245;
	return_welcome=0;
	while(1)
	{
		gets_pos(&x,&y);
		printf("(%d,%d)\n",x,y);
		if(x>100 && x<330)
		{
			if(y>250&&y<300)//ÊäÈëÕË»§
			{
				account=1;
				password=0;
				account_x=120;
				account_y=245;
			}
			if(y>314 && y<365)//ÊäÈëÃÜÂë
			{
				account=0;
				password=1;
				password_x=120;
				password_y=305;
			}
		}
		Num_lock();
		//if(arr_Account)
		{
			if (x>25&&x<355&&y>400&&y<444)
			{
				printf("×¢²áÕË»§£º%s\n×¢²áÃÜÂë£º%s\n",arr_Account,arr_Password);
				if(arr_Account[1]!=0 &&arr_Password[1]!=0) menu();
				show_bmp(0,0,bmp_01[1]);
			}
		}
		if(return_welcome)break;
	}
}
//¼üÅÌ
void Num_lock(void)
{
	if(y>120 && y<208)//1 2 3
	{
		if(x>389 && x<503)
		{
			if(account)
			{
				arr_Account[input_i]=1;
				//user[input_i].account[input_i]=1
				Character_account='1';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2); 
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=1;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_j++;
			}
		}
		else if(x>503 && x<630)
		{
			if(account)
			{
				arr_Account[input_i]=2;
				Character_account='2';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2);
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=2;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_j++;
			}
		}
		else if(x>630 && x<762)
		{
			if(account)
			{
				arr_Account[input_i]=3;
				Character_account='3';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2); 
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=3;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_j++;
			}
		}
	}
	else if(y>208 && y<275)//4 5 6
	{
		if(x>389 && x<503)
		{
			if(account)
			{
				arr_Account[input_i]=4;
				Character_account='4';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2); 
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=4;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_j++;
			}

		}
		else if(x>503 && x<630)
		{
			if(account)
			{
				arr_Account[input_i]=5;
				Character_account='5';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2); 
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=5;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_j++;
			}
			
		}
		else if(x>630 && x<762)
		{
			if(account)
			{
				arr_Account[input_i]=6;
				Character_account='6';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2); 
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=6;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_i++;
			}
		}
	}
	else if(y>275 && y<360)//7 8 9
	{
		if(x>389 && x<503)
		{
			if(account)
			{
				arr_Account[input_i]=7;
				Character_account='7';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2); 
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=7;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_j++;
			}
		}
		else if(x>503 && x<630)
		{
			if(account)
			{
				arr_Account[input_i]=8;
				Character_account='8';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2); 
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=8;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_j++;
			}
		}
		else if(x>630 && x<762)
		{
			if(account)
			{
				arr_Account[input_i]=9;
				Character_account='9';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2); 
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=9;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_j++;
			}
		}
	}
	else if(y>360 && y<422)
	{
		if(x>389 && x<503)
		{
			return_welcome=1;
		}
		else if(x>503 && x<630)
		{
			if(account)
			{
				arr_Account[input_i]=0;
				Character_account='0';
				Display_characterX(account_x,account_y,&Character_account,0x000000,2); 
				account_x+=20;
				input_i++;
			}
			if(password)
			{
				arr_Password[input_j]=0;
				Display_characterX(password_x,password_y,&Character_password,0x000000,3); 
				password_x+=20;
				input_j++;
			}
		}
	}
}