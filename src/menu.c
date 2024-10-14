#include "menu.h"
#include "login.h"
#include "font.h"
#include "xiangqing.h"

char menu_bmp[10][20]={"zhu.bmp","mian.bmp","shao.bmp","tian.bmp","jiu.bmp"};
int strings_x=14;
int strings_y=345;
int input_t=1;
int sum_price=0; //�ѵ��ܼ�

// ����һ�������������ڴ洢��ʽ�����ַ���
char buffer[500];
int offset;

pthread_t ad_tid;
int stop_tid=0;
char ad_bmp[][20]={"guang1.bmp","guang2.bmp","guang3.bmp","guang4.bmp","guang5.bmp","guang6.bmp"};

void menu(void)
{
	Clean_Area(14,345,631,135,0xffffff);
	stop_tid=0;
	show_bmp(0,0,menu_bmp[0]);
	input_t=0;
	int count=1; //��ֹҪ�ٵ�һ�����˲ſ�ʼ���
	while(1)
	{
		if(!stop_tid)pthread_create(&ad_tid,NULL,gesture,NULL);
		if(x>0&&x<94 && y>0&&y<55)
		{
			stop_tid=1;
			memset(arr_Account, 0, sizeof(arr_Account)); //����˻�
			memset(arr_Password, 0, sizeof(arr_Password));//�������
			account=1;//�ص�Ĭ�������˻�
			password=0;
			account_x=120;
			account_y=245;
			if (pthread_join(ad_tid, NULL) != 0) perror("pthread_join");
			break;
		}
		else if(x>170&& x<260)
		{
			if(y>60 && y<100)
			{
				show_bmp(0,0,menu_bmp[0]);//����
				count=1;
			}
			else if(y>100 && y<130)
			{
				printf("1\n");
				show_bmp(0,0,menu_bmp[1]);//���
				count=2;
			}
			else if(y>130 && y<170)
			{
				show_bmp(0,0,menu_bmp[2]);//�տ�
				count=3;
			}
			else if(y>170 && y<220)
			{
				show_bmp(0,0,menu_bmp[3]);//���
				count=4;
			}
			else if(y>220 && y<270)
			{
				show_bmp(0,0,menu_bmp[4]);//��ˮ
				count=5;
			}
		}else
		{
			printf("wating\n");
			gets_pos(&x,&y);
			printf("(%d,%d)\n",x,y);
		}
		if(count==1)zhucai();
		if(count==2)miandian();
		if(count==3)shaokao();
		if(count==4)tiandian();
		if(count==5)jiushui();
		if(x>645&&x<760&&y>410&&y<478)
		{
			int fd = open("./menu.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
			if (fd != -1) 
			{
			    // // ����һ�������������ڴ洢��ʽ�����ַ���
			    //char buffer[100];
			    offset = sprintf(buffer, "�˵�:\n");
			    printf("�ѵ��Ʒ��\n");
				//��ӡ����
			    processMenu(foods_zhucai,sizeof(foods_zhucai) / sizeof(foods_zhucai[0]));
				//��ӡ���
				processMenu(foods_miandian, sizeof(foods_miandian) / sizeof(foods_miandian[0]));
				//��ӡ�տ�
				processMenu(foods_shaokao, sizeof(foods_shaokao) / sizeof(foods_shaokao[0]));
				//��ӡ���
				processMenu(foods_tiandian, sizeof(foods_tiandian) / sizeof(foods_tiandian[0]));
				//��ӡ��ˮ
				processMenu(foods_jiushui, sizeof(foods_jiushui) / sizeof(foods_jiushui[0]));
			    offset += sprintf(buffer + offset, "�ܼ�:%d\n", sum_price);
			    if(sum_price > 300) printf("�ܼۣ�%d\n�˻����㣬���ֵ��\n",sum_price);
				else printf("�ܼƣ�%d, �ѿۿ�\n",sum_price);

			    // ʹ��write�������������е�����д���ļ�
			    write(fd, buffer, offset);
			    // �ر��ļ�
			    close(fd);
			}
		}
	}
}
void processMenu(struct Dish foods[], int size){
    for (int i = 0; i < size; i++) {
        if (foods[i].num != 0) {
			offset += sprintf(buffer + offset, "%s x%d\n", foods[i].name, foods[i].num);
            printf("%s x%d\n", foods[i].name, foods[i].num);
            // �����ܼ�
            sum_price += foods[i].price * foods[i].num;
        }
    }
}
void *gesture(void *arg)
{
	while(1)
	{
		for(int i=0;i<6;i++)
		{
			show_bmp(0,55,ad_bmp[i]);
			sleep(2);
			if(stop_tid)pthread_exit(NULL);
		}
	}
}