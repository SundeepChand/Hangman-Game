#include "../headers/GameManager.h"

GameManager::GameManager(): MAX_TRIES(5)
{
    words[0] = "india";
	words[1] = "pakistan";
	words[2] = "nepal";
	words[3] = "malaysia";
	words[4] = "philippines";
	words[5] = "australia";
	words[6] = "iran";
	words[7] = "ethiopia";
	words[8] = "oman";
	words[9] = "indonesia";
}

void GameManager::showTitle()
{
    cout<<"\t *    *     **     **    *  *****   **   **     **     **    *"<<endl;
    cout<<"\t *    *    *  *    * *   * *        * * * *    *  *    * *   *"<<endl;
    cout<<"\t ******   ******   *  *  * *  ***** *  *  *   ******   *  *  *"<<endl;
    cout<<"\t *    *  *      *  *   * * *      * *     *  *      *  *   * *"<<endl;
    cout<<"\t *    * *        * *    **  ******  *     * *        * *    **"<<endl;
}

void GameManager::showRules()
{
    // welcome the user
    cout<<endl;
    cout<<"\t\t\t HOW TO PLAY"<<endl;
    cout<<"\t\t\t-------------"<<endl;
	cout<<"Welcome to hangman."<<endl;
    cout<<"You have to guess a country Name."<<endl;
	cout<<"Each letter is represented by a star."<<endl;
	cout<<"You have to type only one letter in one try."<<endl;
	cout<< "You have "<<MAX_TRIES<<" tries to try and guess the word."<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Press any key to continue."<<endl;
    cin.ignore();
    cin.get();
}

void GameManager::startGame()
{
    int num_of_wrong_guesses = 0;
    //choose and copy a word from array of words randomly
	srand(time(NULL));
	int n = rand() % 10;
	word = words[n];

    string unknown = string(word.length(), '*');

    // Loop until the guesses are used up
    system("cls");
	while (num_of_wrong_guesses < MAX_TRIES)
	{
        cout<<endl;
		cout<<unknown<<endl;
		cout<<"Guess a letter: ";
        char letter;
		cin>>letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
        cout<<endl;
		if (letterFill(letter, word, unknown) == 0)
		{
			cout<<"Whoops! That letter isn't in there!"<<endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout<<"You found a letter! Isn't that exciting!"<<endl;
		}
		// Tell user how many guesses has left.
		cout<<"You have "<<MAX_TRIES - num_of_wrong_guesses;
		cout<<" guesses left."<<endl;
		// Check if user guessed the word.
		if (word == unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
}

int GameManager::letterFill(char guess, string secretword, string &guessword)
{
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i < len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}