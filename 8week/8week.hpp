#pragma once // #define _IS_THIS_HEADER_INCLUDED

#define Key_ESC 27
#define Key_RIGHT 'd'
#define Key_LEFT 'a'
#define Key_ENTER 13

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

int esc = 0;
namespace NameSpace
{
	void gotoxy(int x, int y) {
		//x, y ��ǥ ����
		COORD pos = { x,y };
		//Ŀ�� �̵�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	class GameLoop
	{
	public:

		bool isGameRunning = false;

		GameLoop() {}
		~GameLoop() {}

		void Initialize()
		{
			isGameRunning = true;
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "�ʱ�ȭ �Ϸ�" << std::endl;
		}

		void Release()
		{
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "�ý��� ���� �Ϸ�" << std::endl;
		}

		void Update()
		{
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "������Ʈ�� �Ϸ�" << std::endl;
			if (_kbhit())
			{

				keyEvent(_getch());
			}

		}
		void Render()
		{
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "������ �Ϸ�" << std::endl;
		}

		void Run()
		{
			Initialize();

			while (isGameRunning)
			{
				Update();
				Render();
			}

			Release();

		}

		void keyEvent(char KeyInput)
		{
			switch (KeyInput)
			{
			case Key_LEFT:	//���� ȭ��ǥŰ
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"������ ���ȴ�!  " << std::endl;
				esc = 0;
				break;
			case Key_RIGHT:	//������ ȭ��ǥŰ
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"�������� ���ȴ�!" << std::endl;
				esc = 0;
				break;
				/* 27 : esc �� ���� ����Ű �Դϴ�.
				 *	�ѹ� �������� �Ͻ�����
				 *  �ι� �������� ���� ����
				 */
			case Key_ESC:
				esc++;
				if (esc == 1)
				{
					gotoxy(2, 5);
					std::cout << ANSI_COLOR_CYAN"esc�� ���ȴ�!   " << std::endl;
					break;
				}
				if (esc == 2)
				{
					gotoxy(2, 5);
					std::cout << ANSI_COLOR_CYAN"������ ����Ǿ���!" << std::endl;
					esc = 0;
					isGameRunning = false;
				}
				//gotoxy(5, 6);
				//std::cout << ANSI_COLOR_GREEN"esc=" + esc << std::endl;
				break;
			case Key_ENTER:
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"���Ͱ� ���ȴ�!  " << std::endl;
				esc = 0;
				break;
			default:
				gotoxy(2, 5);
				esc = 0;
				break;
			}
		}
	};
}