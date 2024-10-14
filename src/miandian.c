#include "menu.h"
#include "xiangqing.h"

struct Dish foods_miandian[4]={
	{"蛋黄流沙包", 0, 23},
	{"慕斯香蕉包", 0, 18},
	{"酱汁叉烧包", 0, 12},
	{"卡通包", 0, 15},
};


void miandian()
{
	strings_x=14;
	strings_y=345;
	while(1)
	{
		printf("2  wating\n");
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
				//进入菜品详情
				//dazhaxie();
			}
			else if(x>381&&x<432)//大闸蟹和麻辣小龙虾
			{
				//大闸蟹加1
				foods_miandian[0].num++;
				Display_characterX(strings_x,strings_y,foods_miandian[0].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_miandian[0].name);
				strings_y+=20;
			}
			else if(x>432&&x<489)
			{
				//大闸蟹减一
				if(foods_miandian[0].num>0)
				{
					foods_miandian[0].num--;
					Display_characterX(strings_x,strings_y,foods_miandian[0].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_miandian[0].name);
					strings_y+=20;
				}
			}
			else if(x>526&&x<642)
			{
				//进入菜品详情
				//xiaolongxia();
			}
			else if(x>666&&x<695)
			{
				//小龙虾加一
				foods_miandian[1].num++;
				Display_characterX(strings_x,strings_y,foods_miandian[1].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_miandian[1].name);
				strings_y+=20;
			}
			else if(x>710&&x<759)
			{
				//小龙虾减一
				if(foods_miandian[1].num>0)
				{
					foods_miandian[1].num--;
					Display_characterX(strings_x,strings_y,foods_miandian[1].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_miandian[1].name);
					strings_y+=20;
				}
			}
		}
		else if(y>200&&y<325)//番茄牛腩煲和稻香肉
		{
			if(x>260&&x<381)
			{
				//进入菜品详情
				//fanqie();
			}
			else if(x>381&&x<432)
			{
				//番茄牛腩煲加1
				foods_miandian[2].num++;
				Display_characterX(strings_x,strings_y,foods_miandian[2].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_miandian[2].name);
				strings_y+=20;
			}
			else if(x>432&&x<489)
			{
				if(foods_miandian[2].num>0)
				{
					foods_miandian[2].num--;
					Display_characterX(strings_x,strings_y,foods_miandian[2].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_miandian[2].name);
					strings_y+=20;
				}
			}
			else if(x>526&&x<642)
			{
				//进入菜品详情
				//daoxiangrou();
			}
			else if(x>666&&x<695)
			{
				//稻香肉加一
				foods_miandian[3].num++;
				Display_characterX(strings_x,strings_y,foods_miandian[3].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_miandian[3].name);
				strings_y+=20;
			}
			else if(x>710&&x<759)
			{
				//稻香肉减一
				if(foods_miandian[3].num>0)
				{
					foods_miandian[3].num--;
					Display_characterX(strings_x,strings_y,foods_miandian[3].name,0x000000,1);
					Display_characterX(strings_x+86,strings_y,strings_2,0x000000,1);
					printf("%s -1\n", foods_miandian[3].name);
					strings_y+=20;
				}
			}
		}else break;
	}
}