#include "TextBasedAdventurePractice.h"
#include "stdio.h"
#include <time.h>
#include <windows.h>
#include <random>
#include <thread>

void TextBasedAdventurePractice::choose_difficulty() {
	std::cout << "What difficulty would you like to play on?" << std::endl;
	std::cout << "[1] Hard" << std::endl;
	std::cout << "[2] Normal" << std::endl;
	std::cout << "[3] Easy" << std::endl;
	get_player_input(&playerInput);
	if (playerInput == '1') {
		std::cout << "Hard Difficulty Chosen" << std::endl;
	}
	else if (playerInput == '2') {
		std::cout << "Normal Difficulty Chosen" << std::endl;
	}
	else if (playerInput == '3') {
		std::cout << "Easy Difficulty Chosen" << std::endl;
	}
	else {
		std::cout << "Invalid Answer :(" << std::endl;
		choose_difficulty();
	}
}

int TextBasedAdventurePractice::get_random_number(int begginingRange, int endingRange) {
	std::random_device ranNumDev;
	std::mt19937::result_type seed = ranNumDev();
	std::mt19937 gen(seed);
	std::uniform_int_distribution<std::mt19937::result_type> range(begginingRange, endingRange);
	return range(gen);
}

void TextBasedAdventurePractice::get_player_input(char* playerInput) {
	std::cin >> playerInput;
}

void TextBasedAdventurePractice::start_mining() {
	initialize_ores();
	std::cout << "Mining";
	delay_seconds(1);
	std::cout << ".";
	delay_seconds(1);
	std::cout << ".";
	delay_seconds(1);
	std::cout << "." << std::endl;
}
void TextBasedAdventurePractice::initialize_ores() {
	ore Gold = { "Gold" }, Coal = { "Coal" }, Iron = { "Iron" }, Diamond = { "Diamond" }, Copper = { "Copper" }
	, Redstone = { "Redstone" }, LapisLazuli = { "Lapis Lazuli" }, Emerald = { "Emerald" };
}
void TextBasedAdventurePractice::finished_mining() {
	std::cout << "You Mined: ";
	int randNum100 = get_random_number(1, 100);
	if (randNum100 > 0 && randNum100 <= 10) {
		mine_ore(1,5,Iron);
	}
	else if (randNum100 > 10 && randNum100 <= 20) {
		//std::cout << get_random_number(1, 5) << " Copper" << std::endl;
		mine_ore(1, 5, Copper);
	}
	else if (randNum100 > 20 && randNum100 <= 30) {
		//std::cout << get_random_number(1, 5) << " Coal" << std::endl;
		mine_ore(1, 5, Coal);
	}
	else if (randNum100 > 30 && randNum100 <= 40) {
		//std::cout << get_random_number(1, 5) << " Gold" << std::endl;
		mine_ore(1, 5, Gold);
	}
	else if (randNum100 > 40 && randNum100 <= 50) {
		//std::cout << get_random_number(1, 5) << " Diamonds" << std::endl;
		mine_ore(1, 5, Diamond);
	}
	else if (randNum100 > 50 && randNum100 <= 60) {
		//std::cout << get_random_number(1, 5) << " Redstone" << std::endl;
		mine_ore(1, 5, Redstone);
	}
	else if (randNum100 > 60 && randNum100 <= 70) {
		//std::cout << get_random_number(1, 5) << " Lapis Lazuli" << std::endl;
		mine_ore(1, 5, LapisLazuli);
	}
	else if (randNum100 > 70 && randNum100 <= 80) {
		//std::cout << get_random_number(1, 5) << " Emeralds" << std::endl;
		mine_ore(1, 5, Emerald);
	}
	else {
		std::cout << "Nothing :(" << std::endl;
	}
	delay_seconds(1);
}

void TextBasedAdventurePractice::delay_seconds(int numOfSecs) {
	std::this_thread::sleep_for(std::chrono::seconds(numOfSecs));
}

void TextBasedAdventurePractice::mine_ore(int minMined,int maxMined, ore ore) {
	int amountMined = get_random_number(minMined, maxMined);
	int* newAmount = ore.currentAmount + amountMined;
	ore.currentAmount = newAmount;
	std::cout << amountMined << " " << ore.name << std::endl;
	std::cout << "Total " << ore.name << ": " << ore.currentAmount << std::endl;
}

