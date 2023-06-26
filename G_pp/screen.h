<<<<<<< HEAD
#pragma once

char ScreenBuffer[65536];

void setScreenSize(int width, int height);
void setCursorIcon(int isActive);
void setCursorPos(int x, int y);
void SetColor(unsigned short backgroundColor, unsigned short textColor);

void ClearBuffer();
=======
#pragma once

char ScreenBuffer[65536];

void setScreenSize(int width, int height);
void setCursorIcon(int isActive);
void setCursorPos(int x, int y);
void SetColor(unsigned short backgroundColor, unsigned short textColor);

void ClearBuffer();
>>>>>>> 78f931ab14a97fc7ff776d9425ac7fe48ac315d8
int WriteToBuffer(int x, int y, const char* str);