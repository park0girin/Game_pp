#include <iostream>
#include <conio.h>

//#define DEBUG

char key = 0;

void title_screen()
{
    std::cout << "****************************************" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*              지렁이 게임             *" << std::endl;
    std::cout << "*             (Snake Bite)             *" << std::endl;
#ifdef DEBUG
    std::cout << "*             -디버그 모드-            *" << std::endl;
#else
    std::cout << "*                                      *" << std::endl;
#endif // DEBUG
    std::cout << "*     1. 게임 시작                     *" << std::endl;
    std::cout << "*     2. 게임 설명                     *" << std::endl;
    std::cout << "*     3. 게임 랭킹 보기                *" << std::endl;
    std::cout << "*     4. 게임 종료 (esc)               *" << std::endl;
    std::cout << "****************************************" << std::endl;
}

//void gotoxy(int x, int y)
//{
//
//}
//int title_screen(int stage_width, int stage_height)
//{
//
//}

char intro_screen()
{
    std::cout << "****************************************" << std::endl;
    std::cout << "타이틀 화면으로 돌아갈까요? (Y/N)" << std::endl;
    key = _getch();
    std::cout << ">>" << key << std::endl;
    return key;
}


int main()
{
    int game_state = 0;
    int is_game_running;

    while (1)
    {
        switch (game_state)
        {
            case 0:
                title_screen();
                key = _getch();
                switch (key)
                {
                    case '1':
                        std::cout << "게임 시작" << std::endl;
                        break;

                    case '2':
                        game_state = 2;
                        break;

                    case '3':
                        std::cout << "게임 랭킹 보기" << std::endl;
                        break;

                    case '4':
                    case 27:
                        is_game_running = 0;
                        return is_game_running;

                    default:
                        break;
                }
                break;

            case 2:
                intro_screen();
                key = _getch();
                switch (key)
                {
                    case 'Y':
                    case 'y':
                        game_state = 0;
                        break;

                    case 'N':
                    case 'n':
                        game_state = 2;
                        break;

                    default:
                        break;
                }
                break;

            case 4:
                break;

            default:
                break;
        }
    }
    return 0;
}
