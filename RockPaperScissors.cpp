//Ashley Rena
//Rock, paper, scissors lab

#include <Windows.h>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

//specificies that total is only to be used for draw, win and loss
enum total{draw, win, loss};
const string str[6] = { "Rock", "Scissors", "Paper", "\tTie!", "\t WINNER WINNER!", "\tYOU LOSE!" };

int main()
{
	//initializes the random num generator at the beginning
	srand(time(0));
	//inputs and outputs the user's decision
	cout << "\nChoose your fighter: [r] rock [p] paper [s] scissors\n\n";
	int scores[3] = {};

	// defines when the program will exit and begin
	for (char input, exit = false; !exit; Sleep(10))
	{
		cout << "> ";
		cin >> input;
		int result, comp = rand() % 3;
		//defining what the decision does within the program
		switch (input) {
		case 'r': case 'p': case 's':
		{
			int user = abs(input - 'r');
			result = (2 * user + comp) % 3;
			scores[result]++;
			
			cout << '\t' << str[user] << " vs " << str[comp] << '\n' << str[result + 3] << endl;
			break;
		}
		//exits program 
		case 'e':
			exit = true;
			break;
		default:
			cout << "\tERROR CODE!" << endl;
		}
		//lists off the results of the game 
		
		if (!exit)
			cout << "\n___________________________"
			<< "\n[e]nd game [r] rock [p] paper [s] scissors\n " << endl;

	}
//deciding if the user or computer won the game
	if (scores[win] == scores[loss])
		cout << "\n\t!________TIE!_______";
	else if (scores[win] > scores[loss])
		cout << "\n\t__WINNER WINNER CHICKEN DINNER___";
	else
		cout << "\n\t__THE COMPUTER HAS PREVAILED!__";

	cout << "\n\tWin: " << scores[win] << ", Draw: " << scores[draw] << ", Loss: " << scores[loss];
	cout << "\n\nPress enter to end the program..." << endl;

// ignores anything that's left in the stream
	cin.sync();
// ignores the newline in the stream
	cin.ignore();
//makes sure the program doesnt return another value
	return 0;


}