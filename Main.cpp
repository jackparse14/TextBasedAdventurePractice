#include "TextBasedAdventurePractice.h"
#include <windows.h>

TextBasedAdventurePractice* game =  new TextBasedAdventurePractice;


void clear_screen(char fill = ' ') {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

int main() {
	bool isRunning = true;
	std::cout << "Welcome to My Text Based Mining Game:" << std::endl;
	game->choose_difficulty();
	game->delay_seconds(2);
	clear_screen();
	while(isRunning) {
		game->start_mining();
		game->finished_mining();
		clear_screen();
	}
	return 0;
}