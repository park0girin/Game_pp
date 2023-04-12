#include <iostream>
#include <conio.h>
#include <Windows.h>

//#define DEBUG
int width = 50;
int height = 28;
int S_posX = 0;
int S_posY = 0;

char key = 0;
int game_state = 0;
int is_game_running;

void gotoxy(int x, int y)
{
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void title_screen()
{
    gotoxy(0, 0);

    std::cout << "****************************************" << std::endl;
    std::cout << "*                                      *" << std::endl;
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
    std::cout << "*                                      *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "****************************************" << std::endl;
}

int game_screen(int stage_width, int stage_height)
{
    gotoxy(0, 0);

    for (int y = 0; y < stage_height; y++) {
        for (int x = 0; x < stage_width; x++) {

            if (y == 0 || y == stage_height - 1 ||
                x == 0 || x == stage_width - 1) {
                std::cout << "*";
            }

            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    gotoxy(1, 1);

    return 0;
}

void game_play_A(int posX, int posY)
{
    while (posX != width - 1 && posX != 0 && posY != height - 1 && posY != 0)
    {
        gotoxy(posX, posY);
        std::cout << " ";
        posX++;
        gotoxy(posX, posY);
        std::cout << "O";
        Sleep(200);
    }
 }
void GAMEOVER()
{
    gotoxy(width/2 - 10, height/2 - 1);
    std::cout << "GAME OVER" << std::endl;
    gotoxy(width / 2 - 10, height / 2 + 1);
    std::cout << "Re? ( Y / N )" << std::endl;
}

int Yes_or_No(int yes,int no)
{
    key = _getch();
    switch (key)
    {
    case 'Y':
    case 'y':
        game_state = yes;
        break;

    case 'N':
    case 'n':
        game_state = no;
        break;

    default:
        break;
    }

    return game_state;
}

char intro_screen()
{
    gotoxy(0, 2);
    std::cout << "*              게임 설명  " << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << "* 뱀은 A, D로 방향을 바꿀 수 있습니다." << std::endl;
    std::cout << "* 뱀은 계속 직진합니다." << std::endl;
    std::cout << "* 뱀은 @를 먹고 성장합니다." << std::endl;
    std::cout << "* 뱀의 머리가 벽이나 자신의 몸과 " << std::endl;
    std::cout << "* 충돌 시 게임이 끝납니다." << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << "*                                      *" << std::endl;
    std::cout << "*   타이틀 화면으로 돌아갈까요?(Y/N)   *" << std::endl;
    return 0;
}

int main()
{
    

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
                        game_state = 1;
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
                        break;

                    default:
                        break;
                }
                break;

            case 1:
                game_screen(width, height);
                key = _getch();
                S_posX = width / 2;
                S_posY = height / 2;
                gotoxy(S_posX,S_posY);
                switch (key)
                {
                    case 27:
                        game_state = 0;

                    case 'A':
                    case 'a':
                        game_play_A(S_posX, S_posY);
                        GAMEOVER();
                        Yes_or_No(1, 0);
                        
                        break;

                    case 'D':
                    case 'd':

                        break;

                    default:
                        break;
                }
                break;

            case 2:
                intro_screen();
                Yes_or_No(0, 2);
                break;

            default:
                break;
        }
    }
    return 0;
}
