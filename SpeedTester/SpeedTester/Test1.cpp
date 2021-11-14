//standart
#include <iostream>

//allow using stopwatch
#include <thread>
#include <chrono>

//allow using string class (char replacement)
#include <string>

//allow console changes
#include <windows.h>

//allow using _getch()
#include <conio.h>

//allow use files from outside 
#include <fstream>

using namespace std;

//string for random numbers
int arr[10]{};

int score = 0;

//strings for random array and written by player array
string finalArr[10]{};
string examArr[10]{};

//Helps count time
auto start = chrono::high_resolution_clock::now();
auto stop = start;

//Says to program what level player choose
int regulator = 0;

void Menu();
void Help();
void EasyGenerator();
void MediumGenerator();
void HardGenerator();
void RandomArray();
void FinalMoves();
void FinalMenu();
int ScoreCounter(int score, int regulator);

int main()
{
	//console scenery
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out, 0x9 | 0x70);
	system("color 3");
	/////////////////
	cout << "\n\t\t\t\t\t\tHello\n\t\t\t\tLet's check how fast are your fingers\n\t\t\t\t\tSelect the difficulty\n";
	cout << "\t\t\t\t\t\t1.Easy\n\t\t\t\t\t\t2.Medium\n\t\t\t\t\t\t3.Hard\n";
	cout << "\t\t\t\t\t  For help click \"4\"\n\n\n";

	Menu();
	system("pause");
	return 0;
}

//simple menu
void Menu()
{
	switch (_getch())
	{
	case '1':
		EasyGenerator();
		break;
	case '2':
		MediumGenerator();
		break;
	case '3':
		HardGenerator();
		break;
	case '4':
		Help();
		Menu();
		break;
	}
}

//extracting a file with help text
void Help()
{
	char word;
	ifstream iFile("help.txt");
	word = iFile.get();
	while (iFile)
	{

		cout << word;
		word = iFile.get();
	}
	iFile.close();
	_getch();
}

//selects and writes words
void EasyGenerator()
{
	regulator = 1;
	start = chrono::high_resolution_clock::now();
	string easyArray[] = { "match","cower","block","cane","way","sell","low","coast","gloom","false","sock","organ","bite","tire","riot","table","chain","pace","door","price","choke","lion","sugar","wound","damn","prey","calf","tick","kneel","jest","twist","core","doubt","Venus","chest","gun","gun","form","bacon","slide","fence","club","limit","me","brush","cash","live","bar","neck" };
	RandomArray();
	system("CLS");
	cout << "\n\t\t\t\tRewrite that word's as fast as you can\n\n\n";

	for (int i = 0; i < 10; i++)
	{
		finalArr[i] = easyArray[arr[i]];

		cout << "    \t";

		if (i == 5)
			cout << "\n\t";

		cout << i + 1 << "." << finalArr[i];
	}
	cout << "\n\n";
	FinalMoves();
}

//selects and writes words
void MediumGenerator()
{
	regulator = 2;
	start = chrono::high_resolution_clock::now();
	string mediumArray[] = { "sentiment","literature","restaurant","incongruous","electronics","improvement","chemistry","encourage","interactive","incentive","champagne","structure","guerrilla","eliminate","referral","extinct","forestry","slippery","clarify","witness","confession","settlement","conception","omission","scenario","delivery","husband","consider","dividend","peasant","triangle","ecstasy","fragment","kukurydza","delicate","bedroom","meeting","forward","weakness","instinct","champion","museum","steward","unlikely","recover","training","judicial","nuclear","domestic","advocate" };
	RandomArray();
	system("CLS");
	cout << "\n\t\t\t\tRewrite that word's as fast as you can\n\n\n\t";

	for (int i = 0; i < 10; i++)
	{
		finalArr[i] = mediumArray[arr[i]];

		if (i == 5)
			cout << "\n\t";

		cout << i + 1 << "." << finalArr[i];

		cout << "  \t";
	}
	cout << "\n\n";
	FinalMoves();
}
//selects and writes words
void HardGenerator()
{
	regulator = 3;
	start = chrono::high_resolution_clock::now();
	string hardArray[] = { "dismissal","reporter","mastermind","protection","isolation","handicap","environment","insistence","separation","describe","exchange","credibility","undermine","coincidence","legislation","publication","miscarriage","atmosphere","champagne","concentration","acceptable","orientation","domination","autonomy","progressive","depressed","refrigerator","formation","intervention","motorcycle","brilliance","constellation","clearance","fluctuation","craftsman","knowledge","strategic","assertive","relationship","destruction","gregarious","temperature","telephone","disposition","consensus","cooperative","automatic","architecture","criticism","prevalence" };
	system("CLS");
	RandomArray();
	cout << "\n\t\t\t\tRewrite that word's as fast as you can\n\n\n";

	for (int i = 0; i < 10; i++)
	{
		finalArr[i] = hardArray[arr[i]];

		cout << "\t";

		if (i == 5)
			cout << "\n\t";

		cout << i + 1 << "." << finalArr[i];
	}
	cout << "\n\n";
	FinalMoves();
}

//makes an array with random numbers
void RandomArray()
{
	srand(time(NULL));
	for (int i = 0; i < 10;)
	{
		bool randomSet = false;
		int someNumber = rand() % 49;
		arr[i] = rand() % 49;
		for (int k = 0; k < i; k++)
		{
			if (arr[k] == someNumber)
			{
				randomSet = true;
				break;
			}
		}
		if (randomSet != true)
		{
			arr[i] = someNumber;
			i++;
		}
	}
}

//reads the entered words and counts the result
void FinalMoves()
{
	for (int l = 0; l < 10; l++)
	{
		cout << "\t" << l + 1 << ".";

		cin >> examArr[l];

	}
	for (int r = 0; r < 10; r++)
	{
		if (examArr[r] == finalArr[r])
			score += 3;
		else
			score -= 5;
	}
	stop = chrono::high_resolution_clock::now();
	system("CLS");
	FinalMenu();
}

//writes the result
void FinalMenu()
{
	score = ScoreCounter(score, regulator);
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\tYour score is : " << score;
	cout << "\n\t\t\t\t\tIn : " << chrono::duration_cast<chrono::seconds>(stop - start).count() << " seconds" << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(100));

	if (score > 24)
		cout << "\t\t\t\t   Very nice, it\'s good result\n\n\n\n";
	else if (score <= 24 && score > 16)
		cout << "\t\t\t\t    Not bad, you have potential\n\n\n\n";
	else if (score <= 16 && score > 0)
		cout << "\t\t      It's looks like you see the keyboard at the first time\n\n\n\n";
	else if (score < 0)
		cout << "\t\t\t\tOMG man just try to write something\n\n\n\n";
	else if (score == 0)
		cout << "\t\t\t  You are not so smart, don't lie to me any more\n\n\n\n";
}

//There score is modificated by writing time
int ScoreCounter(int score, int regulator)
{
	int someTime = chrono::duration_cast<chrono::seconds>(stop - start).count();

	if (someTime < 6)
		return 0;

	if (regulator == 1)
		someTime -= 10;
	else if (regulator == 2)
		someTime -= 20;
	else if (regulator == 3)
		someTime -= 30;

	score = score - (someTime * 7);

	return score;
}