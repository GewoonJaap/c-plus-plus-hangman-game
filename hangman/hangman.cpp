// hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

int lives = 8;
std::vector<char> guessed;
std::string word;

void clear();
void render_game();

int main()
{
	std::cout << "Welcome to the hangman game\n";
	std::cout << "Type your word: \n";
	std::getline(std::cin, word);
	std::cout << "Alright lets start the game\n" << word << "\n";
	clear();
	render_game();
	while (lives > 0)
	{
		clear();
		render_game();
		char letter;
		std::cout << "Guess a letter\n";
		std::cin >> letter;
		letter = std::tolower(letter);
		if (!std::count(guessed.begin(), guessed.end(), letter))
		{
			guessed.push_back(letter);
		}
		else
		{
			lives--;
		}
	}
	std::cout << "You lost!";
}

void render_game()
{
	std::cout << "Lives: " << lives << "\n";
	std::string result;
	for (char i : word)
	{
		if (i == ' ')
		{
			result += " ";
		}
		else if (std::count(guessed.begin(), guessed.end(), std::tolower(i)))
		{
			result += i;
		}
		else
		{
			result += "_";
		}
	}
	std::cout << result << "\n\n\n";
	if (result.find('_') == std::string::npos)
	{
		std::cout << "YOU WON!";
		std::exit(0);
	}
}

void clear()
{
#if defined _WIN32
	system("cls");
	//clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
	system("clear");
#endif
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
