//whlie문 짜기

#include <iostream>
#include <conio.h>


int main(){
	char key;
	while (true) {
		if(_kbhit()){ //키가 눌렸다면
			key = _getch();  // 문자 입력 받기
			if (key == 27) {  // esc 키를 눌렀을 때
                        std::cout << "종료키를 누름." << std::endl;
			break;}
		std::cout << "종료 키: " << key << std::endl;}
  		std::cout << "★"<<std::endl;}
	return 0;}
