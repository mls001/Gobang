#include<graphics.h>
void paiNt()
{
	initgraph(900, 550,SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	//setfillcolor(RGB(255, 192, 203));
	IMAGE img1;
	loadimage(&img1, _T("Image.PNG"), 900, 550);
	putimage(0, 0, &img1);
	//rectangle(150, 50, 600, 500);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	//fillrectangle(150, 50, 600, 500);
	setlinestyle(PS_SOLID, 1);
	setfillcolor(BLACK);
	solidcircle(225, 125, 3); solidcircle(375, 125, 3); solidcircle(525, 125, 3);
	solidcircle(225, 275, 3); solidcircle(375, 275, 3); solidcircle(525, 275, 3);
	solidcircle(225, 425, 3); solidcircle(375, 425, 3); solidcircle(525, 425, 3);
	int y, x;
	for (y = 50; y <= 500; y = y + 25)
	{
		line(150, y, 600, y);
	}
	for (x = 150; x <= 600; x = x + 25)
	{
		line(x, 50, x, 500);
	}
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	TCHAR hang[19] = _T("0");
	int i = 0, j = 0;
	for (x = 150; x <= 600; x++)
	{
		if (x % 25 == 0)
		{
			hang[i] = i + 65;
			outtextxy(x, 25, hang[i]);
			i++;
		}
	}
	for (y = 50; y <= 500; y++)
	{
		if (y % 25 == 0)
		{
			hang[j] = j + 65;
			outtextxy(130, y - 5, hang[j]);
			j++;
		}
	}
}



