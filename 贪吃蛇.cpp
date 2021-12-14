#include<stdio.h>
#include<math.h>
#include <easyx.h>
#include<conio.h>
#include<time.h>
struct WZ
{
	int x;
	int y;
};
struct She
{
	WZ wz[1000];
	int cd;
	int fx;
}she;
enum tfx
{
	UP, DOWN, LEFT, RIGHT
};
void initshe()
{
	she.cd = 3;
	she.fx = RIGHT;

	she.wz[0].x = 20;
	she.wz[0].y = 0;

	she.wz[1].x = 10;
	she.wz[1].y = 0;

	she.wz[2].x = 0;
	she.wz[2].y = 0;

}
void drawshe()
{
	static int I = 1;
	static int p = 1;
	ExMessage msg;
	cleardevice(); 
	setlinestyle(PS_SOLID, 2);
	settextstyle(19, 0, "楷书");
	char w[]= "空格暂停";
	rectangle(515, 10, 595, 35);
	int x = 515 + (40 - (textwidth(w) / 2));
	int y = 10 + (13 - (textheight(w) / 2));
	outtextxy(x, y, w);
	rectangle(498, 48, 533,66);
	int i = (she.cd - 3)%10;
	int m = (she.cd - 3) / 10;
	int k = (she.cd - 3) / 100;
	int l = (she.cd - 3) / 1000;
	char b[12] = " 1234567890";
	char a[11] = "    ";
	if (she.cd - 3 >= 0)
	{
		a[3] = b[i];
		a[2] = b[m];
		a[1] = b[k];
		a[0] = b[l];
		if (i == 0)
			a[3] = b[10];
		if ((i == 0) && (she.cd >= 103))
			a[2] = b[10];
		if ((k == 0) && (she.cd >= 1003))
			a[1] = b[10];
		settextstyle(15, 0, a);
		 outtextxy(500, 50, a);
	}
	for (int i = 0; i < she.cd; i++)
	{
		if (i == 0)
		{
			setfillcolor(RGB(0, 150, 0));
			fillrectangle(she.wz[i].x, she.wz[i].y, she.wz[i].x + 10, she.wz[i].y + 10);
		}
		else
		{
			setfillcolor(RGB(80, 250, 80));
			fillrectangle(she.wz[i].x, she.wz[i].y, she.wz[i].x + 10, she.wz[i].y + 10);
		}
	}
		if (p == 1)
		{
			setlinestyle(PS_SOLID, 3);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(240, 240, 240));
			setlinecolor(RGB(250, 250, 250));
			settextstyle(30, 0, "黑体");
			char a[] = "开始游戏";
			setfillcolor(RGB(240, 70, 40));
			fillroundrect(210, 250, 380, 290, 20, 20);
			int x = 190 + (105 - (textwidth(a)/ 2));
			int y = 250 + (20 - (textheight(a)/ 2));
			outtextxy(x, y, a);
			while (1==p)
			{
				
				if (peekmessage(&msg,EM_MOUSE))
				{
					
					switch (msg.message)
					{
					 case WM_LBUTTONDOWN:
						if (msg.x >= 210 && msg.x <= 380 && msg.y >= 250 && msg.y <= 290)
							goto AAA;
					 default :
						break;
					}
				}
			}
		}
	AAA:
		p++;
	if (I == 1)
	{
		Sleep(200);
	}
	I++;
	setlinestyle(PS_SOLID, 1);
	setlinecolor(RGB(250, 250, 250));
	settextcolor(RGB(255, 255, 255));
}
void sheyd()
{
	for (int i = she.cd - 1; i > 0; i--)
	{
		she.wz[i].x = she.wz[i - 1].x;
		she.wz[i].y = she.wz[i - 1].y;
	}
	switch (she.fx)
	{
	case UP:
		{
			she.wz[0].y -= 10;
		}
		break;
	case DOWN:
		{
			she.wz[0].y += 10;
		}
		break;
	case LEFT:
	    { 
			she.wz[0].x -= 10;
		}
		break;
	case RIGHT:
		{
			she.wz[0].x += 10;
		}
		break;
	default:
		break;
	}
}
void drawfoods()
{
	int a = 0,b=0;
	static int d = 1, f = 1, c = 1;
	static int A = 1, B = 0, k = 1;
	int t = rand() % 100-1;
	a = (t * 6)%10;
	t = (t * 6 )- a;
	int T = rand() % 100-1;
	b = (T * 6)%10;
	T = T*6 - b;
	if (f == 1)
	{
		A = t;
		B = T;
		f = f - 1;
	}
	if ((she.wz[0].x == A) && (she.wz[0].y == B))
	{
		A = t;
		B = T;
		if (d == 1 || d == k + 1)
		{
			k = d;
		}
		she.cd++;
		c++;
	}
	c = c % 10;
	for (int i = 0; i <= (she.cd-1); i++)
	{
		if ((A == she.wz[i].x) && (B == she.wz[i].y))
		{
			f = f + 1;
			drawfoods();
		}
	}
	switch (c)
	{
	case 1:
		setfillcolor(RGB(255, 0, 0));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	case 2:
		setfillcolor(RGB(255,150, 150));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	case 3:
		setfillcolor(RGB(250, 250, 0));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	case 4:
		setfillcolor(RGB(130, 0, 250));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	case 5:
		setfillcolor(RGB(0, 0, 130));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	case 6:
		setfillcolor(RGB(230, 0, 120));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	case 7:
		setfillcolor(RGB(180, 40, 180));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	case 8:
		setfillcolor(RGB(20, 250, 250));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	case 9:
		setfillcolor(RGB(240,240, 240));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	case 0:
		setfillcolor(RGB(40, 40, 40));
		fillrectangle(A, B, A + 10, B + 10);
		break;
	}
	d++;
}
void usekey()
{
	if (_kbhit())
	{
		char key = _getch();
		switch (key)
		{
		case 'w':
		case 'W':
		case 72:
			if (she.fx != DOWN)
				she.fx = UP;
			break;
		case 'd':
		case 'D':
		case 77:
			if (she.fx != LEFT)
				she.fx = RIGHT;
			break;
		case 's':
		case 'S':
		case 80:
			if (she.fx != UP)
				she.fx = DOWN;
			break;
		case 'a':
		case 'A':
		case 75:
			if (she.fx != RIGHT)
				she.fx = LEFT;
			break;
		case ' ':
			while (1)
			{
				char k = _getch();
				if (k == ' ')
					break;
			}
			break;
		default:
			break;
		}
	}
}
void game()
{
	initgraph(600, 600);
	setbkcolor(RGB(90, 220, 160));
	cleardevice();
}
int main()
{
	int D = 0;
	game();
	initshe();
	srand((unsigned int)time(NULL));
	while (1)
	{
		drawshe();
		drawfoods();
		FlushBatchDraw();
		EndBatchDraw();
		usekey();
		sheyd();
		if (she.cd <= 63)
		{
			D = 180 -(( she.cd - 3 ));
		}
		if (she.cd >= 63)
		{
			D = 120 - (she.cd - 3) / 5;
		}
		Sleep(D);
		if ((she.wz[0].x == 600 || she.wz[0].x + 10 == 0) || (she.wz[0].y == 600 || she.wz[0].y + 10 == 0))
		{
			setlinestyle(PS_SOLID, 3);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(240, 240, 240));
			setlinecolor(RGB(250, 250, 250));
			settextstyle(30, 0, "黑体");
			char a[] = "重新开始";
			setfillcolor(RGB(240, 70, 40));
			fillroundrect(210, 250, 380, 290, 20, 20);
			int x = 190 + (105 - (textwidth(a) / 2));
			int y = 250 + (20 - (textheight(a) / 2));
			outtextxy(x, y, a);
			while (1)
			{
				ExMessage msg;
				if (peekmessage(&msg, EM_MOUSE))
				{
					switch (msg.message)
					{
					case WM_LBUTTONDOWN:
						if (msg.x >= 210 && msg.x <= 380 && msg.x && msg.y >= 250 && msg.y <= 290)
						{
							main();
						}
					default:
						break;
					}
				}
			}
		}
		for (int i = 1; i < she.cd; i++)
		{
			if ((she.wz[0].x == she.wz[i].x) && (she.wz[0].y == she.wz[i].y))
			{ 
				setlinestyle(PS_SOLID, 3);
				setbkmode(TRANSPARENT);
				settextcolor(RGB(240, 240, 240));
				setlinecolor(RGB(250, 250, 250));
				settextstyle(30, 0, "黑体");
				char a[] = "重新开始";
				setfillcolor(RGB(240, 70, 40));
				fillroundrect(210, 250, 380, 290, 20, 20);
				int x = 190 + (105 - (textwidth(a) / 2));
				int y = 250 + (20 - (textheight(a) / 2));
				outtextxy(x, y, a);
				while (1)
				{
					ExMessage msg;
					if (peekmessage(&msg, EM_MOUSE))
					{

						switch (msg.message)
						{
						case WM_LBUTTONDOWN:
							if (msg.x >= 210 && msg.x <= 380 && msg.x && msg.y >= 250 && msg.y <= 290)
							{
								main();
								Sleep(300);
							}
						default:
							break;
						}
					}
				}
				
			 }
		}
	}
	closegraph();
	return 0;
}