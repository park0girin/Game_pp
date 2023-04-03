#include <iostream>
#include <conio.h>

//#define DEBUG

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

void gotoxy(int x, int y)
{
    
}
int title_screen(int stage_width, int stage_height)
{

}

char intro_screen()
{
    
    std::cout << "****************************************" << std::endl;
    std::cout << "타이틀 화면으로 돌아갈까요? (Y/N)" << std::endl;
    
}


int main()
{
    int game_state = 0;
    int is_game_running;
    
    while (1) 
    {
        char key = 0;
        switch (game_state)
        {
            case 0:
                title_screen();
                key = _getch();
                switch (key)
                {
                case 1:
                    break;
                case 2:
                    game_state = 2;
                    break;
                case 3:
                    break;
                case 4:
                    is_game_running = 0;
                    break;
                case 27:
                    is_game_running = 0;
                    break;
                default:
                    break;
                }
            case 2:
                intro_screen();
                key = _getch();
                switch (key)
                {
                case 'y':
                    game_state = 0;
                case 'n':
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
        /*if (_kbhit()) {
            
            if (key == 27 || key == '4')
            {
                std::cout << "게임 종료" << std::endl; 
                break;
            }
            if (key == '2')
            {
                char key = ' ';
                intro_screen();
                while (key != 'N') {
                    if (_kbhit()) {
                        key = _getch();
                        if (key == 'Y')
                        {
                            break;
                        }
                    }
                }
                return key;
            }
        }*/
        
    }
    return 0;
}

