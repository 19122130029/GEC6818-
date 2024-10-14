#include "init.h"
#include "login.h"
#include "font.h"


int main(int argc, char const *argv[])
{
	init();
	Init_Font(); 
	while(1)
	{
		show_bmp(0,0,bmp_01[0]);//»¶Ó­Ò³Ãæ
		gets_pos(&x,&y);
		//printf("(%d,%d)\n",x,y);
		if(x>login_min_X&&x<login_max_X && y>login_min_y&y<login_max_y)
		{
			login();
		}
		if(x>regist_min_X&&x<regist_max_X && y>regist_min_y&y<regist_max_y)
		{
			regist();
		}
		Clean_Area(100,250,20,20,0xffffff);
		Clean_Area(100,314,20,20,0xffffff);
	}
	uninit();
	return 0;
}
