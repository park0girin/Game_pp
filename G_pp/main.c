#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "screen.h"
#include "util.h"

struct SnakeBody
{
	int posX;
	int posY;
	int active;
};

struct Apple
{
	int posX;
	int posY;
	int active;
};

struct Player
{
	int posX;
	int posY;
};

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	Pause
};

enum Direction snakeDirection = DOWN;

#define BODY_LENGTH 1400
int deltaTime;
char key = '\0';

int Initialize();
int Release();
int DrawBuffer(int DeltaTime);
int DrawMenu(int DeltaTime);

int isGameRunning = 1;
int GameState = 0;

struct SnakeBody skin[BODY_LENGTH];
struct Apple apple;
struct Player player;

int snakeBodyLength = 2;
int MovingTime = 1000;
int deltaTimeSum = 0;

int main()
{
	isGameRunning = 1;
	GameState = 0;
	CHECKERROR(Initialize());

	unsigned long time_end = GetTickCount();
	deltaTime = GetTickCount();

	key = 'a'; // 키 입력 값 초기화

	while (isGameRunning)
	{
		if (_kbhit()) 
		{
			printf("ㅠ"); 
			key = _getch();
		}
		switch (GameState)
		{
		case 0:
			switch (snakeDirection)
			{
			case UP:
				setCursorPos(100, 0);
				printf("위로 이동 %c",key);
				setCursorPos(100, 2);
				printf("             ");
				setCursorPos(100, 4);
				printf("             ");
				setCursorPos(100, 6);
				printf("             ");
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = LEFT;
					break;
				case 'd':
				case 'D':
					snakeDirection = RIGHT;
					break;
				case 's':
				case 'S':
					snakeDirection = Pause;
					break;
				default:
					snakeDirection = UP;
					break;
				}
				key = '\0';
				break;
			case DOWN:
				setCursorPos(100, 0);
				printf("             ");
				setCursorPos(100, 2);
				printf("아래로 이동 %c", key);
				setCursorPos(100, 4);
				printf("             ");
				setCursorPos(100, 6);
				printf("             ");
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = RIGHT;
					break;
				case 'd':
				case 'D':
					snakeDirection = LEFT;
					break;
				case 's':
				case 'S':
					snakeDirection = Pause;
					break;
				default:
					snakeDirection = DOWN;
					break;
				}
				key = '\0';
				break;
			case LEFT:
				setCursorPos(100, 0);
				printf("             ");
				setCursorPos(100, 2);
				printf("             ");
				setCursorPos(100, 4);
				printf("왼쪽으로 이동 %c", key);
				setCursorPos(100, 6);
				printf("             ");
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = DOWN;
					break;
				case 'd':
				case 'D':
					snakeDirection = UP;
					break;
				case 's':
				case 'S':
					snakeDirection = Pause;
					break;
				default:
					snakeDirection = LEFT;
					break;
				}
				key = '\0';
				break;
			case RIGHT:
				setCursorPos(100, 0);
				printf("             ");
				setCursorPos(100, 2);
				printf("             ");
				setCursorPos(100, 4);
				printf("             ");
				setCursorPos(100, 6);
				printf("오른쪽으로 이동 %c", key);
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = UP;
					break;
				case 'd':
				case 'D':
					snakeDirection = DOWN;
					break;
				case 's':
				case 'S':
					snakeDirection = Pause;
					break;
				default:
					snakeDirection = RIGHT;
					break;
				}
				key = '\0';
				break;
			default:
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = LEFT;
					break;
				case 'd':
				case 'D':
					snakeDirection = RIGHT;
					break;
				default:
					break;
				}
				key = '\0';
				break;
			}
			UpdateSnake();
			DrawMenu(deltaTime);

			break;

		case 1:
			switch (snakeDirection)
			{
			case UP:
				setCursorPos(100, 0);
				printf("위로 이동");
				setCursorPos(100, 2);
				printf("             ");
				setCursorPos(100, 4);
				printf("             ");
				setCursorPos(100, 6);
				printf("             ");
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = LEFT;
					break;
				case 'd':
				case 'D':
					snakeDirection = RIGHT;
					break;
				case 's':
				case 'S':
					snakeDirection = Pause;
					break;
				default:
					snakeDirection = UP;
					break;
				}
				key = '\0';
				break;
			case DOWN:
				setCursorPos(100, 0);
				printf("             ");
				setCursorPos(100, 2);
				printf("아래로 이동");
				setCursorPos(100, 4);
				printf("             ");
				setCursorPos(100, 6);
				printf("             ");
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = RIGHT;
					break;
				case 'd':
				case 'D':
					snakeDirection = LEFT;
					break;
				case 's':
				case 'S':
					snakeDirection = Pause;
					break;
				default:
					snakeDirection = DOWN;
					break;
				}
				key = '\0';
				break;
			case LEFT:
				setCursorPos(100, 0);
				printf("             ");
				setCursorPos(100, 2);
				printf("             ");
				setCursorPos(100, 4);
				printf("왼쪽으로 이동");
				setCursorPos(100, 6);
				printf("             ");
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = DOWN;
					break;
				case 'd':
				case 'D':
					snakeDirection = UP;
					break;
				case 's':
				case 'S':
					snakeDirection = Pause;
					break;
				default:
					snakeDirection = LEFT;
					break;
				}
				key = '\0';
				break;
			case RIGHT:
				setCursorPos(100, 0);
				printf("             ");
				setCursorPos(100, 2);
				printf("             ");
				setCursorPos(100, 4);
				printf("             ");
				setCursorPos(100, 6);
				printf("오른쪽으로 이동");
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = UP;
					break;
				case 'd':
				case 'D':
					snakeDirection = DOWN;
					break;
				case 's':
				case 'S':
					snakeDirection = Pause;
					break;
				default:
					snakeDirection = RIGHT;
					break;
				}
				key = '\0';
				break;
			default:
				switch (key)
				{
				case 'a':
				case 'A':
					snakeDirection = LEFT;
					break;
				case 'd':
				case 'D':
					snakeDirection = RIGHT;
					break;
				default:
					break;
				}
				key = '\0';
				break;
			}
			UpdateSnake();
			DrawBuffer(deltaTime);
			break;
		}
		deltaTime = GetTickCount() - time_end;
		time_end = GetTickCount();
		if (deltaTime < 33)
			Sleep(33 - deltaTime);

		// 입력 버퍼 비우기
		while (_kbhit()) _getch();
	}
	CHECKERROR(Release());

	exit(1);
	return 0;
}

int UpdateSnake()
{
	deltaTimeSum += deltaTime;

	// MovingTime을 초과한 시간이 지나면 뱀을 이동시킴
	if (deltaTimeSum >= MovingTime)
	{
		deltaTimeSum = 0;

		// 방향에 따라 뱀의 위치 조정
		switch (snakeDirection)
		{
		case UP:
			player.posY--;
			break;
		case DOWN:
			player.posY++;
			break;
		case LEFT:
			player.posX--;
			break;
		case RIGHT:
			player.posX++;
			break;
		}

		int i = snakeBodyLength - 1;
		while (i >= 0)
		{
			if (i > 0)
			{
				skin[i].posX = skin[i - 1].posX;
				skin[i].posY = skin[i - 1].posY;
			}
			else
			{
				skin[i].posX = player.posX;
				skin[i].posY = player.posY;
			}
			i = i - 1;
		}
	}
	return 0;
}


void initApplePos()
{
	srand(time(NULL));

	//사과 데이터 초기화
	apple.active = 0;
	apple.posX = rand() % 70;
	apple.posY = rand() % 20;
	int i = 0;
	while (i < BODY_LENGTH)
	{
		if (skin[i].posX == apple.posX && skin[i].posY == apple.posY)
		{
			apple.posX = rand() % 70;
			apple.posY = rand() % 20;
			i = 0;
		}
		else
		{
			i = i + 1;
		}
	}
}


int Initialize()
{
	//게임 상태
	GameState = 0;
	deltaTimeSum = 0;
	MovingTime = 300;

	//플레이어 초기화
	player.posX = 35;
	player.posY = 10;

	//뱀 데이터 초기화
	snakeBodyLength = 2;
	int i = 0;
	while (i < BODY_LENGTH)
	{
		skin[i].active = 0;
		skin[i].posX = player.posX;
		skin[i].posY = player.posY;

		i = i + 1;
	}

	//사과 초기화
	initApplePos();

	//사용할 뱀 데이터 초기화
	snakeBodyLength = 2;
	i = 0;
	while (i < snakeBodyLength)
	{
		skin[i].active = 1;
		skin[i].posX = player.posX;
		skin[i].posY = player.posY - i;

		i = i + 1;
	}

	//화면 초기화
	setScreenSize(70, 20);
	setCursorIcon(0);
	ClearBuffer();

	return 0;
}

int Release()
{
	return 0;
}

int DrawMenu(int DeltaTime)
{
	//배경 그리기
	SetColor(0b1111, 0b0000);
	setCursorPos(0, 0);
	printf("%s", ScreenBuffer);

	//PRESS A OR D
	SetColor(0b1111, 0b0000);
	setCursorPos(29, 5);
	printf("PRESS A OR D");

	//뱀 그리기
	SetColor(0b1111, 0b1010);
	int i = snakeBodyLength - 1;
	while (i >= 0)
	{
		setCursorPos(skin[i].posX, skin[i].posY);
		printf("O");
		i = i - 1;
	}

	//START
	setCursorPos(32, 7);
	SetColor(0b1111, 0b0100);
	printf("START!");

	//색상 초기화
	SetColor(0b0000, 0b0111);
	setCursorPos(0, 22);
	if (DeltaTime != 0)
		printf("Delta Time : %d              \nfps :%d\n          ", DeltaTime, 1000 / DeltaTime);
	return 0;
}

int DrawBuffer(int DeltaTime)
{
	//배경 그리기
	SetColor(0b1111, 0b0000);
	setCursorPos(0, 0);
	printf("%s", ScreenBuffer);

	//뱀 그리기
	SetColor(0b1111, 0b1010);
	int i = snakeBodyLength - 1;
	while (i >= 0)
	{
		setCursorPos(skin[i].posX, skin[i].posY);
		printf("O");
		i = i - 1;
	}

	//사과 그리기
	setCursorPos(apple.posX, apple.posY);
	SetColor(0b1111, 0b0100);
	printf("＠");

	//색상 초기화
	SetColor(0b0000, 0b0111);
	setCursorPos(0, 22);
	if (DeltaTime != 0)
		printf("Delta Time : %d              \nfps :%d\n          ", DeltaTime, 1000 / DeltaTime);

	return 0;
	}