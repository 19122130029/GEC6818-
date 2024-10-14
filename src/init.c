#include "init.h"

int lcd_fd=-1,ts_fd=-1;//�ļ�������
int *p=NULL; //Ұָ�룬���ܻ�ָ�򲻿ɷ������򣬵��³������


int x,y;

//��LCD����������ͼƬ
void init(void)
{
	//��lcd
	lcd_fd = open("/dev/fb0",O_RDWR);
	if(lcd_fd < 0)   //��ʧ��
	{
		perror("open lcd failed");
		return;
	}
	//�����ڴ�ӳ��
	p = mmap(NULL,800*480*4,PROT_READ | PROT_WRITE,MAP_SHARED,lcd_fd,0);
	if(p == NULL)
	{
		perror("mmap failed");
		return;
	}

	//·����/dev/input/event0
	ts_fd = open("/dev/input/event0",O_RDWR);
	if (ts_fd < 0)
	{
		perror("open ts_fd failed");//��ӡ������Ϣ
		return;
	}
}

////���ӳ�䣬�ر�lcd�ʹ�����
void uninit(void)
{
	close(lcd_fd);
	close(ts_fd);
}

void show_bmp(int x0,int y0,char *bmp_name)
{
	//��bmp
	int bmp_fd = open(bmp_name,O_RDWR);
	if(bmp_fd < 0)   //��ʧ��
	{
		perror("open bmp failed");
		return;
	}
	
	//��ȡǰ54���ֽڣ���ȡͼƬ�Ŀ�Ⱥ͸߶�
	char head[54];
	read(bmp_fd,head,54);
	//��ȣ���18~21�ֽ�
	int width = head[18] | head[19] << 8 | head[20] << 16 | head[21] << 24;
	//�߶ȣ���22~25�ֽ�
	int height = head[22] | head[23] << 8 | head[24] << 16 | head[25] << 24;
	//printf("w = %d,h = %d\n",width,height);
	//�ж�ͼƬԽ��
	if(width+x0 > 800 || height+y0 > 480)
	{
		printf("out of range\n");
		return;
	}
	
	//��ȡͼƬ����
	char bmp_buf[width*height*3];
	read(bmp_fd,bmp_buf,width*height*3);
	
	int x,y,color,i=0;
	char r,g,b;
	for(y=0;y<height;y++)
	{
		for(x=0;x<width;x++)
		{
			b = bmp_buf[i++];
			g = bmp_buf[i++];
			r = bmp_buf[i++];
			color = b | g << 8 | r << 16;
			*(p+800*(height-1-y+y0)+x+x0) = color;  
		}
	}
	close(bmp_fd);
}

//��ȡx��y����
void gets_pos(int *x,int *y)
{
	//��ȡ���������ݣ���ȡ����
	struct input_event buf;
	while(1)
	{
		read(ts_fd,&buf,sizeof(buf));
		if(buf.type == EV_ABS) //�������¼�
		{
			if(buf.code == ABS_X) //x��
			{
				*x = buf.value*800/1024;
			}
			if(buf.code == ABS_Y) //Y��
			{
				*y = buf.value*480/600;
			}
		}
		//�ж���ָ�ɿ�
		if(buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 0) break;
	}
}