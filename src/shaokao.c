#include "menu.h"
#include "xiangqing.h"

struct Dish foods_shaokao[4]={
	{"���ƹ�Ƭ", 0, 3},
	{"���ཷ", 0, 3},
	{"������", 0, 18},
	{"���ʳ�", 0, 12},
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
				//�����Ʒ����
				//dazhaxie();
			}
			else if(x>381&&x<432)//��բз������С��Ϻ
			{
				//��բз��1
				foods_shaokao[0].num++;
				Display_characterX(strings_x,strings_y,foods_shaokao[0].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_shaokao[0].name);
				strings_y+=20;
			}
			else if(x>432&&x<489)
			{
				//��բз��һ
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
				//�����Ʒ����
				//xiaolongxia();
			}
			else if(x>666&&x<695)
			{
				//С��Ϻ��һ
				foods_shaokao[1].num++;
				Display_characterX(strings_x,strings_y,foods_shaokao[1].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_shaokao[1].name);
				strings_y+=20;
			}
			else if(x>710&&x<759)
			{
				//С��Ϻ��һ
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
		else if(y>200&&y<325)//����ţ���Һ͵�����
		{
			if(x>260&&x<381)
			{
				//�����Ʒ����
				//fanqie();
			}
			else if(x>381&&x<432)
			{
				//����ţ���Ҽ�1
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
				//�����Ʒ����
				//daoxiangrou();
			}
			else if(x>666&&x<695)
			{
				//�������һ
				foods_shaokao[3].num++;
				Display_characterX(strings_x,strings_y,foods_shaokao[3].name,0x000000,1);
				Display_characterX(strings_x+86,strings_y,strings_1,0x000000,1);
				printf("%s +1\n", foods_shaokao[3].name);
				strings_y+=20;
			}
			else if(x>710&&x<759)
			{
				//�������һ
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