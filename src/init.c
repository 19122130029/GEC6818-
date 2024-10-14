#include "init.h"

int lcd_fd=-1,ts_fd=-1;//文件描述符
int *p=NULL; //野指针，可能会指向不可访问区域，导致程序崩溃


int x,y;

//打开LCD、触摸屏、图片
void init(void)
{
	//打开lcd
	lcd_fd = open("/dev/fb0",O_RDWR);
	if(lcd_fd < 0)   //打开失败
	{
		perror("open lcd failed");
		return;
	}
	//进行内存映射
	p = mmap(NULL,800*480*4,PROT_READ | PROT_WRITE,MAP_SHARED,lcd_fd,0);
	if(p == NULL)
	{
		perror("mmap failed");
		return;
	}

	//路径：/dev/input/event0
	ts_fd = open("/dev/input/event0",O_RDWR);
	if (ts_fd < 0)
	{
		perror("open ts_fd failed");//打印错误信息
		return;
	}
}

////解除映射，关闭lcd和触摸屏
void uninit(void)
{
	close(lcd_fd);
	close(ts_fd);
}

void show_bmp(int x0,int y0,char *bmp_name)
{
	//打开bmp
	int bmp_fd = open(bmp_name,O_RDWR);
	if(bmp_fd < 0)   //打开失败
	{
		perror("open bmp failed");
		return;
	}
	
	//读取前54个字节，获取图片的宽度和高度
	char head[54];
	read(bmp_fd,head,54);
	//宽度：第18~21字节
	int width = head[18] | head[19] << 8 | head[20] << 16 | head[21] << 24;
	//高度：第22~25字节
	int height = head[22] | head[23] << 8 | head[24] << 16 | head[25] << 24;
	//printf("w = %d,h = %d\n",width,height);
	//判断图片越界
	if(width+x0 > 800 || height+y0 > 480)
	{
		printf("out of range\n");
		return;
	}
	
	//读取图片数据
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

//获取x，y坐标
void gets_pos(int *x,int *y)
{
	//读取触摸屏数据，获取坐标
	struct input_event buf;
	while(1)
	{
		read(ts_fd,&buf,sizeof(buf));
		if(buf.type == EV_ABS) //触摸屏事件
		{
			if(buf.code == ABS_X) //x轴
			{
				*x = buf.value*800/1024;
			}
			if(buf.code == ABS_Y) //Y轴
			{
				*y = buf.value*480/600;
			}
		}
		//判断手指松开
		if(buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 0) break;
	}
}