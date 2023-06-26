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

enum Direction snakeDirection = Pause;

#define BODY_LENGTH 1400
int deltaTime;
char key;

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

	key = '\0'; // 키 입력 값 초기화

	while (isGameRunning)
	{
		if (_kbhit()) // 키 입력 확인
		{
			setCursorPos(50, 50);
			printf("key");
			key = _getch(); // 입력된 키 값 받기
		}
		switch (snakeDirection)
		{
		case UP:
			if (key == 'a')
				snakeDirection = LEFT;
			else if (key == 'd')
				snakeDirection = RIGHT;
			break;

		case DOWN:
			if (key == 'a')
				snakeDirection = RIGHT;
			else if (key == 'd')
				snakeDirection = LEFT;
			break;

		case LEFT:
			if (key == 'a')
				snakeDirection = DOWN;
			else if (key == 'd')
				snakeDirection = UP;
			break;

		case RIGHT:
			if (key == 'a')
				snakeDirection = UP;
			else if (key == 'd')
				snakeDirection = DOWN;
			break;

		default:
			if (key == 'a')
				snakeDirection = LEFT;
			else if (key == 'd')
				snakeDirection = RIGHT;
			break;
		}
		switch (GameState)
		{
		case 0:
			UpdateSnake();
			DrawMenu(deltaTime);
			break;

		case 1:
			UpdateSnake();
			DrawBuffer(deltaTime);
			break;
		}
		deltaTime = GetTickCount() - time_end;
		time_end = GetTickCount();
		if (deltaTime < 33)
			Sleep(33 - deltaTime);

		// 입력 버퍼 비우기
		while (_kbhit())
			_getch();

		key = '\0'; // 키 초기화
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