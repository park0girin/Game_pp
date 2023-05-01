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

		bool YorN() {
			char KeyInput = _getch();
			switch (KeyInput)
			{
			case Key_LEFT:
				gotoxy(2, 6);
				std::cout << ANSI_COLOR_YELLOW"[��]";
				std::cout << ANSI_COLOR_RESET"   [�ƴϿ�]";
				KeyInput = _getch();
				switch (KeyInput)
				{
				case Key_ENTER:
					isGameRunning = false;
					break;
				default:
					break;
				}
				break;
			case Key_RIGHT:
				gotoxy(2, 6);
				std::cout << ANSI_COLOR_RESET"[��]";
				std::cout << ANSI_COLOR_YELLOW"   [�ƴϿ�]";
				KeyInput = _getch();
				switch (KeyInput)
				{
				case Key_ENTER:
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			return isGameRunning;
		}
		void keyEvent(char KeyInput)
		{
			switch (KeyInput)
			{
			case Key_LEFT:	//���� ȭ��ǥŰ
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"������ ���ȴ�!  " << std::endl;
				break;
			case Key_RIGHT:	//������ ȭ��ǥŰ
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"�������� ���ȴ�!" << std::endl;
				break;
				/* 27 : esc �� ���� ����Ű �Դϴ�.
				 *	�ѹ� �������� �Ͻ�����
				 *  �ι� �������� ���� ����
				 */
			case Key_ESC:
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_RESET"�����Ͻðڽ��ϱ�?" << std::endl;
				gotoxy(2, 6);
				std::cout << ANSI_COLOR_RESET"[��]";
				std::cout << ANSI_COLOR_RESET"   [�ƴϿ�]";
				YorN();
				break;
				//gotoxy(5, 6);
				//std::cout << ANSI_COLOR_GREEN"esc=" + esc << std::endl;
			case Key_ENTER:
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"���Ͱ� ���ȴ�!  " << std::endl;
				break;
			default:
				gotoxy(2, 5);
				break;
			}
		}
	};
}