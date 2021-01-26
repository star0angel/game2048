#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//取消scanf返回值的警告

#include <stdio.h>
#include <easyx.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <math.h>
//#include <easyx.h>
#define  SIZE 50  //格子宽度
#define   MAX_SIZE 4
#define INTERVAL 15//间隔
int arr[MAX_SIZE][MAX_SIZE] = {0};
IMAGE  img[14];
int kx = 0;
int ky = 0;

void loadmap()
{

	loadimage(&img[0], _T("./res/0.png"), SIZE, SIZE);
	loadimage(&img[1], _T("./res/2.png"), SIZE, SIZE);
	loadimage(&img[2], _T("./res/4.png"), SIZE, SIZE);
	loadimage(&img[3], _T("./res/8.png"), SIZE, SIZE);
	loadimage(&img[4], _T("./res/16.png"), SIZE, SIZE);
	loadimage(&img[5], _T("./res/32.png"), SIZE, SIZE);
	loadimage(&img[6], _T("./res/64.png"), SIZE, SIZE);
	loadimage(&img[7], _T("./res/128.png"), SIZE, SIZE);
	loadimage(&img[8], _T("./res/256.png"), SIZE, SIZE);
	loadimage(&img[9], _T("./res/512.png"), SIZE, SIZE);
	loadimage(&img[10], _T("./res/1024.png"), SIZE, SIZE);
	loadimage(&img[11], _T("./res/2048.png"), SIZE, SIZE);
	loadimage(&img[12], _T("./res/4096.png"), SIZE, SIZE);
	loadimage(&img[13], _T("./res/8192.png"), SIZE, SIZE);
	//loadimage(&img[12], _T("./res/win.png"), SIZE * ROW, SIZE * COL);

}

void InitBoard()
{

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
			arr[i][j] = 0;
	}
}
int InitGame(int n)//初始化游戏面板数组
{
	int key = 0;
	int result=0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
			if(arr[i][j]==0 )key++;
	}
	if (key == 0)
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			for (int j = 0; j < MAX_SIZE - 1; j++)
			{
				if (arr[i][j] == arr[i][j + 1])
					result++;
			}
			for (int i = 0; i < MAX_SIZE ; i++)
			{
				for (int j = 0; j < MAX_SIZE-1; j++)
				{
					if (arr[j][i] == arr[j+1][i ])
						result++;
				}
			}
		}
	}
			if (key >= n)
			{
				while (n)
				{
					int x = rand() % MAX_SIZE;
					int y = rand() % MAX_SIZE;
					if (arr[x][y] == 0)
					{
						if (x == 3)//低概率=2
						{
							arr[x][y] = 4;
						}
						else
						{
							arr[x][y] = 2;
						}

						n--;
					}
				}
			}
		if (key!=0)
		{
			return 1;
		}
	return result;
}
void printUI()
{
	int n=0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)

		{
			if (arr[i][j]==0)
			{
				putimage(j * SIZE, i * SIZE, &img[0]);
			}
			else if (arr[i][j] == 2) {
				putimage(j * SIZE, i * SIZE, &img[1]);
				
			}
			else if (arr[i][j] == 4) {
				putimage(j * SIZE, i * SIZE, &img[2]);

			}
			else if (arr[i][j] == 8) {
				putimage(j * SIZE, i * SIZE, &img[3]);

			}
			else if (arr[i][j] == 16) {
				putimage(j * SIZE, i * SIZE, &img[4]);

			}
			else if (arr[i][j] == 32) {
				putimage(j * SIZE, i * SIZE, &img[5]);

			}
			else if (arr[i][j] == 64) {
				putimage(j * SIZE, i * SIZE, &img[6]);

			}
			else if (arr[i][j] == 128) {
				putimage(j * SIZE, i * SIZE, &img[7]);

			}
			else if (arr[i][j] == 256) {
				putimage(j * SIZE, i * SIZE, &img[8]);

			}
			else if (arr[i][j] == 512) {
				putimage(j * SIZE, i * SIZE, &img[9]);

			}
			else if (arr[i][j] == 1024) {
				putimage(j * SIZE, i * SIZE, &img[10]);

			}
			else if (arr[i][j] == 2048) {
				putimage(j * SIZE, i * SIZE, &img[11]);

			}
			else if (arr[i][j] == 4096) {
				putimage(j * SIZE, i * SIZE, &img[12]);

			}
			else if (arr[i][j] == 8192) {
				putimage(j * SIZE, i * SIZE, &img[13]);

			}
			
			
				//putimage(j  * SIZE, i * SIZE, &img[0]);
			
			
				
			
		}
	}
}
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void playup()
{
	for (int i=0;i<MAX_SIZE;i++)
	{
		for (int j = 1; j < MAX_SIZE; j++)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (arr[j][i]==0)
				{
					continue;
				} 
				else if (arr[j][i] == arr[k][i])
				{
					arr[k][i] *= 2;
					arr[j][i] = 0;
					break;
				}
				else if (arr[j][i]!=0&&arr[k][i]==0)
				{
					swap(arr[j][i], arr[k][i]);
					j=k;
					continue;
				}
				else if (arr[j][i] != 0 && arr[k][i] != 0)
				{
					break;
				}

			}
			
			//if (arr[j][i]== arr[j+1][i])//如果相等合并
			//{
			//	if (j>=0&&j<MAX_SIZE)
			//	{
			//		arr[j][i] = arr[j][i] + arr[j + 1][i];
			//		arr[j + 1][i] = 0;//处理合并空出来的
			//		up_remove();
			//	}
			//	
			}
		}
	}
void playleft()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 1; j < MAX_SIZE; j++)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (arr[i][j] == 0)
				{
					continue;
				}
				else if (arr[i][j] == arr[i][k])
				{
					arr[i][k] *= 2;
					arr[i][j] = 0;
					break;
				}
				else if (arr[i][j] != 0 && arr[i][k] == 0)
				{
					swap(arr[i][j], arr[i][k]);
					j=k;
					continue;
				}
				else if (arr[j][i] != 0 && arr[k][i] != 0)
				{
					break;
				}
			}
		}
	}
}
void playdown()
{
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 2; j >= 0; j--)
		{
			for (int k = j + 1; k < MAX_SIZE; k++)
			{
				if (arr[j][i] == 0)
				{
					continue;
				}
				else if (arr[j][i] == arr[k][i])
				{
					arr[k][i] *= 2;
					arr[j][i] = 0;
					break;
				}
				else if (arr[j][i] != 0 && arr[k][i] == 0)
				{
					swap(arr[j][i], arr[k][i]);
					j=k;
					continue;
				}
				else if (arr[j][i] != 0 && arr[k][i] != 0)
				{
					break;
				}
			}
		}
	}
}
void playright()
{
	for (int i = 0; i <MAX_SIZE; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			for (int k = j + 1; k < MAX_SIZE; k++)
			{
				if (arr[i][j] == 0)
				{
					continue;
				}
				else if (arr[i][j] == arr[i][k])
				{
					arr[i][k] *= 2;
					arr[i][j] = 0;
					//j--;
					break;
				}
				else if (arr[i][j] != 0 && arr[i][k] == 0)
				{
					swap(arr[i][j], arr[i][k]);
					j=k;
					continue;
				}
				else if (arr[j][i] != 0 && arr[k][i] != 0)
				{
					break;
				}
			}
		}
	}
}
void  playGame()
{
	 
	char key;
	while (1)
	{
		printUI();
		key = getch();
		switch (key)//按下wsad有数字的坐标变化
		{
		case 'w':
			playup();
				break;
		case 's':
			playdown();
			break;
		case 'a':
			playleft();
		     break;
		case 'd':
			playright();
			break;
		default:
			break;
		
		}
		if(!InitGame(1))
			break;
	}
	MessageBox(NULL,_T("你输了提示："),_T("you lose!"),MB_OK);
}
int main()
{
	srand((unsigned int)time(NULL));//随机数种子
	initgraph(SIZE*4,SIZE*4,2);
	loadmap();//加载扫雷图片
	//InitBoard();//初始化数组
	//gameDraw();
	InitGame(3);

	//printUI();
	playGame();
	system("pause");
	//closegraph();
	return 0;
}