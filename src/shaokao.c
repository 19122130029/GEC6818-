#include "menu.h"
#include "xiangqing.h"

struct Dish foods_shaokao[4]={
	{"¿¾»Æ¹ÏÆ¬", 0, 3},
	{"¿¾Çà½·", 0, 3},
	{"¿¾öÏÓã", 0, 18},
	{"¿¾·Ê³¦", 0, 12},
};

void shaokao()
{
	strings_x=14;
	strings_y=345;
	
	while(1)
	{
		printf("3  wating\n");
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
				//dazhaxie();
			}
			else if(x>381&&x<432)//´óÕ¢Ð·ºÍÂéÀ±Ð¡ÁúÏº
			{
				//´óÕ¢Ð·¼Ó1
				foods_shaokao[0].num++;
				Display_characterX(strings_x,strings_y,foods_shaokao[0].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_shaokao[0].name);
				strings_y+=20;
			}
			else if(x>432&&x<489)
			{
				//´óÕ¢Ð·¼õÒ»
				if(foods_shaokao[0].num>0)
				{
					foods_shaokao[0].num--;
					Display_characterX(strings_x,strings_y,foods_shaokao[0].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_shaokao[0].name);
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
				foods_shaokao[1].num++;
				Display_characterX(strings_x,strings_y,foods_shaokao[1].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_shaokao[1].name);
				strings_y+=20;
			}
			else if(x>710&&x<759)
			{
				//Ð¡ÁúÏº¼õÒ»
				if(foods_shaokao[1].num>0)
				{
					foods_shaokao[1].num--;
					Display_characterX(strings_x,strings_y,foods_shaokao[1].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_shaokao[1].name);
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
				foods_shaokao[2].num++;
				Display_characterX(strings_x,strings_y,foods_shaokao[2].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_shaokao[2].name);
				strings_y+=20;
			}
			else if(x>432&&x<489)
			{
				if(foods_shaokao[2].num>0)
				{
					foods_shaokao[2].num--;
					Display_characterX(strings_x,strings_y,foods_shaokao[2].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_shaokao[2].name);
					strings_y+=20;
				}
			}
			else if(x>526&&x<642)
			{
				//½øÈë²ËÆ·ÏêÇé
				//daoxiangrou();
			}
			else if(x>666&&x<695)
			{
				//µ¾ÏãÈâ¼ÓÒ»
				foods_shaokao[3].num++;
				Display_characterX(strings_x,strings_y,foods_shaokao[3].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_shaokao[3].name);
				strings_y+=20;
			}
			else if(x>710&&x<759)
			{
				//µ¾ÏãÈâ¼õÒ»
				if(foods_shaokao[3].num>0)
				{
					foods_shaokao[3].num--;
					Display_characterX(strings_x,strings_y,foods_shaokao[3].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_shaokao[3].name);
					strings_y+=20;
				}
			}
		}else break;
	}
}