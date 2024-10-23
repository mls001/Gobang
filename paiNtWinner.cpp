#include <stdio.h>
#include <graphics.h>
//0ÎªºÚÓ®£¬1Îª°×Ó®
int paiNtWinner(int winner)
{
	if (winner == 0)
	{
		TCHAR b[100] = _T("Winner is Black!");
		outtextxy(0, 0, b);
		return 0;
	}
	if (winner == 1)
	{
		TCHAR b[100] = _T("Winner is White!");
		outtextxy(0, 0, b);
		return 0;
	}
}