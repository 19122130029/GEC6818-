#include "menu.h"
#include "xiangqing.h"

struct Dish foods_jiushui[3]={
	{"Ã·¼û", 0, 25},
	{"RIO", 0, 15},
	{"ÈøÀ¼Í¤°×ÑæÆÏÌÑ¾Æ", 0, 135},
};

void jiushui()
{
	strings_x=14;
	strings_y=345;
	while(1)
	{
		gets_pos(&x,&y);
		if(strings_y>480)
		{
			 strings_x+=170;
			 strings_y=345;
		}
		if(x<250)break;
		if(y>60 && y<180)//
		{
			if(x>260&&x<381)
			{
				//½øÈë²ËÆ·ÏêÇé
				//dazhaxie();
			}
			else if(x>381&&x<432)//´óÕ¢Ð·ºÍÂéÀ±Ð¡ÁúÏº
			{
				//´óÕ¢Ð·¼Ó1
				foods_jiushui[0].num++;
				Display_characterX(strings_x,strings_y,foods_jiushui[0].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_jiushui[0].name);
				strings_y+=20;
			}
			else if(x>432&&x<489)
			{
				//´óÕ¢Ð·¼õÒ»
				if(foods_jiushui[0].num>0)
				{
					foods_jiushui[0].num--;
					Display_characterX(strings_x,strings_y,foods_jiushui[0].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_jiushui[0].name);
					strings_y+=20;
				}
			}
			else if(x>526&&x<642)
			{
				//½øÈë²ËÆ·ÏêÇé
				//xiaolongxia();
			}
			else if(x>666&&x<695)
			{
				//Ð¡ÁúÏº¼ÓÒ»
				foods_jiushui[1].num++;
				Display_characterX(strings_x,strings_y,foods_jiushui[1].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_jiushui[1].name);
				strings_y+=20;
			}
			else if(x>710&&x<759)
			{
				//Ð¡ÁúÏº¼õÒ»
				if(foods_jiushui[1].num>0)
				{
					foods_jiushui[1].num--;
					Display_characterX(strings_x,strings_y,foods_jiushui[1].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_jiushui[1].name);
					strings_y+=20;
				}
			}
		}
		else if(y>200&&y<325)//·¬ÇÑÅ£ëîìÒºÍµ¾ÏãÈâ
		{
			if(x>260&&x<381)
			{
				//½øÈë²ËÆ·ÏêÇé
				//fanqie();
			}
			else if(x>381&&x<432)
			{
				//·¬ÇÑÅ£ëîìÒ¼Ó1
				foods_jiushui[2].num++;
				Display_characterX(strings_x,strings_y,foods_jiushui[2].name,0x000000,1);
				Display_characterX(strings_x+130,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_jiushui[2].name);
				strings_y+=20;
			}
			else if(x>432&&x<489)
			{
				if(foods_jiushui[2].num>0)
				{
					foods_jiushui[2].num--;
					Display_characterX(strings_x,strings_y,foods_jiushui[2].name,0x000000,1);
					Display_characterX(strings_x+130,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_jiushui[2].name);
					strings_y+=20;
				}
			}
		}else break;
	}
}