#ifndef __Text_Based_Adventure_Practice__
#define __Text_Based_Adventure_Practice__
#include <iostream>

class TextBasedAdventurePractice{
	private:
		char playerInput;
		int get_random_number(int, int);
		void get_player_input(char*);
		struct ore {
			std::string name;
			int* currentAmount = 0;
		}Gold,Iron,Copper,Diamond,Emerald,Redstone,LapisLazuli,Coal;
		void mine_ore(int, int, ore);
		void initialize_ores();
	public:
		void choose_difficulty();
		void start_mining();
		void finished_mining();
		void delay_seconds(int);
};

#endif	
