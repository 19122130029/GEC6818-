#include "menu.h"
#include "xiangqing.h"

struct Dish foods_zhucai[4]={
	{"´óÕ¢Ð·", 0, 198},
	{"ÂéÀ±Ð¡ÁúÏº", 0, 78},
	{"·¬ÇÑÅ£ëîìÒ", 0, 158},
	{"µ¾ÏãÈâ", 0, 78},
};

char *strings_1="+1";
char *strings_2="-1";

void zhucai()
{
	strings_x=14;
	strings_y=345;
	while(1)
	{
		printf("1   wating\n");
		gets_pos(&x,&y);
		printf("(%d,%d)\n",x,y);
		if(strings_y>480)
		{
			 strings_x+=150;
			 strings_y=345;
		}
		if(x<250)break;
		if(y>60 && y<180)//
		{
			if(x>260&&x<381)
			{
				//½øÈë²ËÆ·ÏêÇé
				dazhaxie();
			}
			else if(x>381&&x<432)//´óÕ¢Ð·ºÍÂéÀ±Ð¡ÁúÏº
			{
				//´óÕ¢Ð·¼Ó1
				foods_zhucai[0].num++;
				Display_characterX(strings_x,strings_y,foods_zhucai[0].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_zhucai[0].name);
				strings_y+=20;
			}
			else if(x>432&&x<489)
			{
				//´óÕ¢Ð·¼õÒ»
				if(foods_zhucai[0].num>0)
				{
					foods_zhucai[0].num--;
					Display_characterX(strings_x,strings_y,foods_zhucai[0].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_zhucai[0].name);
					strings_y+=20;
				}
			}
			else if(x>526&&x<642)
			{
				//½øÈë²ËÆ·ÏêÇé
				xiaolongxia();
			}
			else if(x>666&&x<695)
			{
				//Ð¡ÁúÏº¼ÓÒ»
				foods_zhucai[1].num++;
				Display_characterX(strings_x,strings_y,foods_zhucai[1].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_zhucai[1].name);
				strings_y+=20;
			}
			else if(x>710&&x<759)
			{
				//Ð¡ÁúÏº¼õÒ»
				if(foods_zhucai[1].num>0)
				{
					foods_zhucai[1].num--;
					Display_characterX(strings_x,strings_y,foods_zhucai[1].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_zhucai[1].name);
					strings_y+=20;
				}
			}
		}
		else if(y>200&&y<325)//·¬ÇÑÅ£ëîìÒºÍµ¾ÏãÈâ
		{
			if(x>260&&x<381)
			{
				//½øÈë²ËÆ·ÏêÇé
				fanqie();
			}
			else if(x>381&&x<432)
			{
				//·¬ÇÑÅ£ëîìÒ¼Ó1
				foods_zhucai[2].num++;
				Display_characterX(strings_x,strings_y,foods_zhucai[2].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_zhucai[2].name);
				strings_y+=20;
			}
			else if(x>432&&x<489)
			{
				if(foods_zhucai[2].num>0)
				{
					foods_zhucai[2].num--;
					Display_characterX(strings_x,strings_y,foods_zhucai[2].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_zhucai[2].name);
					strings_y+=20;
				}
			}
			else if(x>526&&x<642)
			{
				//½øÈë²ËÆ·ÏêÇé
				daoxiangrou();
			}
			else if(x>666&&x<695)
			{
				//µ¾ÏãÈâ¼ÓÒ»
				foods_zhucai[3].num++;
				Display_characterX(strings_x,strings_y,foods_zhucai[3].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_zhucai[3].name);
				strings_y+=20;
			}
			else if(x>710&&x<759)
			{
				//µ¾ÏãÈâ¼õÒ»
				if(foods_zhucai[3].num>0)
				{
					foods_zhucai[3].num--;
					Display_characterX(strings_x,strings_y,foods_zhucai[3].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_zhucai[3].name);
					strings_y+=20;
				}
			}
		}else break;
	}
}