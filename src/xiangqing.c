#include "menu.h"
#include "xiangqing.h"
#include "init.h"
void dazhaxie()
{
	pthread_cancel(ad_tid);
	stop_tid=1;
	char cmd[64]="mplayer -slave -quiet -geometry 0:0 -zoom -x 800 -y 480 d.avi &";
	system(cmd);
	while(1)
	{
		gets_pos(&x,&y);
		if(x||y)
		{
			char cmd[25]="killall -SIGKILL mplayer";
			system(cmd);
			show_bmp(0,0,menu_bmp[0]);
			stop_tid=0;
			break;
		}
	}
}
void xiaolongxia()
{
	
}
void fanqie()
{
	
}
void daoxiangrou()
{
	
}