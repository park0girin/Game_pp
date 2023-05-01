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
		//x, y 좌표 설정
		COORD pos = { x,y };
		//커서 이동
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
			std::cout << ANSI_COLOR_MAGENTA "초기화 완료" << std::endl;
		}

		void Release()
		{
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "시스템 해제 완료" << std::endl;
		}

		void Update()
		{
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "업데이트중 완료" << std::endl;
			if (_kbhit())
			{

				keyEvent(_getch());
			}

		}
		void Render()
		{
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "렌더링 완료" << std::endl;
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
				std::cout << ANSI_COLOR_YELLOW"[예]";
				std::cout << ANSI_COLOR_RESET"   [아니오]";
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
				std::cout << ANSI_COLOR_RESET"[예]";
				std::cout << ANSI_COLOR_YELLOW"   [아니오]";
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
			case Key_LEFT:	//왼쪽 화살표키
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"왼쪽이 눌렸다!  " << std::endl;
				break;
			case Key_RIGHT:	//오른쪽 화살표키
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"오른쪽이 눌렸다!" << std::endl;
				break;
				/* 27 : esc 고 게임 종료키 입니다.
				 *	한번 눌렀을땐 일시정지
				 *  두번 눌렀을땐 게임 종료
				 */
			case Key_ESC:
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_RESET"종료하시겠습니까?" << std::endl;
				gotoxy(2, 6);
				std::cout << ANSI_COLOR_RESET"[예]";
				std::cout << ANSI_COLOR_RESET"   [아니오]";
				YorN();
				break;
				//gotoxy(5, 6);
				//std::cout << ANSI_COLOR_GREEN"esc=" + esc << std::endl;
			case Key_ENTER:
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"엔터가 눌렸다!  " << std::endl;
				break;
			default:
				gotoxy(2, 5);
				break;
			}
		}
	};
}