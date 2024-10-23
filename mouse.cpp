#include <graphics.h>
#include <stdio.h>
int chEck(int chess[19][19], int a, int b);
void mouseCheck()
{
	int chess[19][19] = { 0 };
	ExMessage m;
	int x0 = 0, y0 = 0;
	int temp = 2;
	while (1)
	{
		m = getmessage(EX_MOUSE | EX_KEY);
		if ((m.x <= 600 && m.x >= 150) && (m.y <= 500 && m.y >= 50) && (temp != 1) && (temp != 0))
		{
			switch (m.message)
			{
			case WM_LBUTTONDOWN:
			{
				setfillcolor(WHITE);
				int x1 = 0, y1 = 0, p, q;
				for (p = 0, q = 0; p <= 18 && q <= 18; p++, q++)
				{
					if ((m.x - 137.5) / 25 >= p && (m.x - 162.5) / 25 < p)
						x1 = 25 * p + 150;
					if ((m.y - 37.5) / 25 >= q && (m.y - 62.5) / 25 < q)
						y1 = 25 * q + 50;
				}
				x0 = (x1 - 150) / 25;
				y0 = (y1 - 50) / 25;
				chess[x0][y0] = 1;
				solidcircle(x1, y1, 10);
				temp = chEck(chess, x0 + 1, y0 + 1);
				if (temp == 1)
				{
					TCHAR b[100] = _T("Winner is White!");
					settextstyle(24, 0, _T("ºÚÌå"), 0, 0, 50, 0, 0, 0);
					outtextxy(675, 260, b);
				}
				break;
			}
			case WM_RBUTTONDOWN:
			{
				setfillcolor(BLACK);
				int x2 = 0, y2 = 0, r, s;
				for (r = 0, s = 0; r <= 18 && s <= 18; r++, s++)
				{
					if ((m.x - 137.5) / 25 >= r && (m.x - 162.5) / 25 < r)
						x2 = 25 * r + 150;
					if ((m.y - 37.5) / 25 >= s && (m.y - 62.5) / 25 < s)
						y2 = 25 * s + 50;
				}
				x0 = (x2 - 150) / 25;
				y0 = (y2 - 50) / 25;
				chess[x0][y0] = 2;
				solidcircle(x2, y2, 10);
				temp = chEck(chess, x0 + 1, y0 + 1);
				if (temp == 0)
				{
					TCHAR b[100] = _T("Winner is Black!");
					settextstyle(24, 0, _T("ºÚÌå"), 0, 0, 50, 0, 0, 0);
					outtextxy(675, 260, b);
				}
				break;
			}
			case WM_KEYDOWN:
				if (m.vkcode = VK_ESCAPE)
					closegraph();
			}
		}
	}
}