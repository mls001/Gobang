#include <stdio.h>
int chEck(int chess[19][19],int d, int c)
{
	//棋子定义：黑=2，白=1，空=0；
	int a,b;
	int y1, y2, x1, x2;
	int m1, m2, n1, n2;
	a = d - 1;
	b = c - 1;
	y1 = b - a;
	y2 = 18 + b - a;
	x1 = a - b;
	x2 = 18 + a - b;
	m1 = a + b;
	n1 = a + b;
	m2 = a + b - 18;
	n2 = a + b - 18;
	int i, j, k, l;
	int line1[19] = { 0 };		//反斜杠方向的棋盘信息
	int line2[19] = { 0 };		//斜杠方向的棋盘信息
	int line3[19] = { 0 };		//横向信息
	int line4[19] = { 0 };		//竖向信息
	for (i = 0; i < 19; i++)
	{
		k = chess[i][b];
		line3[i] = k;
	}
	for (i = 0; i < 19; i++)
	{
		k = chess[a][i];
		line4[i] = k;
	}
	if (b - a >= 0 && a + b < 19)			//当某点在棋盘的上方时
	{
		for (i = 0, j = y1; i < x2 + 1 && j < 19; i++, j++)
		{
			k = chess[i][j];
			line1[i] = k;
			printf("%d ", line1[i]);		//测试用，输出反斜杠方向的棋盘信息
		}
		printf("line1\n");
		for (i = 0, j = n1; i < m1 + 1 && j >= 0; i++, j--)
		{
			l = chess[i][j];
			line2[i] = l;
			printf("%d ", line2[i]);		//测试用，输出斜杠方向的棋盘信息
		}
		printf("line2\n");
	}
	if (b - a >= 0 && a + b > 19)			//当某点在棋盘的右方时
	{
		for (i = 0, j = y1; i < x2 + 1 && j < 19; i++, j++)
		{
			k = chess[i][j];
			line1[i] = k;
			printf("%d ", line1[i]);		//测试用，反斜杠方向的棋盘信息
		}
		printf("line1\n");
		for (i = m2, j = 18; i < 19 && j >= 0; i++, j--)
		{
			l = chess[i][j];
			line2[i] = l;
			printf("%d ", line2[i]);		//测试用，斜杠方向的棋盘信息
		}
		printf("line2\n");
	}
	if (b - a < 0 && a + b <= 19)			//当某点在棋盘的左方时
	{
		for (i = x1, j = 0; i < 19 && j < y2 + 1; i++, j++)
		{
			k = chess[i][j];
			line1[i] = k;
			printf("%d ", line1[i]);		//测试用，反斜杠方向的棋盘信息
		}
		printf("line1\n");
		for (i = 0, j = n1; i < m1 + 1 && j >= 0; i++, j--)
		{
			l = chess[i][j];
			line2[i] = l;
			printf("%d ", line2[i]);		//测试用，斜杠方向的棋盘信息
		}
		printf("line2\n");
	}
	if (b - a < 0 && a + b >=19)			//当某点在棋盘的下方时
	{
		for (i = x1, j = 0; i < 19 && j < y2 + 1; i++, j++)
		{
			k = chess[i][j];
			line1[i] = k;
			printf("%d ", line1[i]);		//测试用，反斜杠方向的棋盘信息
		}
		printf("line1\n");
		for (i = m2, j = 18; i < 19 && j >= 0; i++, j--)
		{
			l = chess[i][j];
			line2[i] = l;
			printf("%d ", line2[i]);		//测试用，斜杠方向的棋盘信息
		}
		printf("line2\n");
	}
	int count1 = 1;				//连续白个数
	int count2 = 1;				//连续黑个数
	int chEcked = 2;			//初始化check值
	for (i = 0; i < 19; i++)
	{
		int temp1;
		temp1 = line1[i];
		if (temp1 == 2 || temp1 == 1)
		{
			if (temp1 == 2 && line1[i + 1] == 2)
			{
				count2++;
				if (count2 == 5)
					return chEcked = 0;
			}
			else
			{
				count2 = 1;
			}
			if (temp1 == 1 && line1[i + 1] == 1)
			{
				count1++;
				if (count1 == 5)
					return chEcked = 1;
			}
			else
			{
				count1 = 1;
			}
		}
	}
	for (i = 0; i < 19; i++)
	{
		int temp2;
		temp2 = line2[i];
		if (temp2 == 2||temp2 ==1)
		{
			if (temp2 == 2 && line2[i + 1] == 2)
			{
				count2++;
				if (count2==5)
					return chEcked = 0;
			}
			else
			{
				count2 = 1;
			}
			 if (temp2 == 1 && line2[i + 1] == 1)
			{
				count1++;
				if (count1 == 5)
					return chEcked = 1;
			}
			 else
			 {
				 count1 = 1;
			 }
		}
	}
	for (i = 0; i < 19; i++)
	{
		int temp3;
		temp3 = line3[i];
		if (temp3 == 2 || temp3 == 1)
		{
			if (temp3 == 2 && line3[i + 1] == 2)
			{
				count2++;
				if (count2 == 5)
					return chEcked = 0;
			}
			else
			{
				count2 = 1;
			}
			if (temp3 == 1 && line3[i + 1] == 1)
			{
				count1++;
				if (count1 == 5)
					return chEcked = 1;
			}
			else
			{
				count1 = 1;
			}
		}
	}
	for (i = 0; i < 19; i++)
	{
		int temp4;
		temp4 = line4[i];
		if (temp4 == 2 || temp4 == 1)
		{
			if (temp4 == 2 && line4[i + 1] == 2)
			{
				count2++;
				if (count2 == 5)
					return chEcked = 0;
			}
			else
			{
				count2 = 1;
			}
			if (temp4 == 1 && line4[i + 1] == 1)
			{
				count1++;
				if (count1 == 5)
					return chEcked = 1;
			}
			else
			{
				count1 = 1;
			}
		}
	}
	return 5;
}
