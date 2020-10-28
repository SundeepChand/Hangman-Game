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
    player_name = "default";

    // Make sure the high-score file exists, if not then create one
    ifstream fin("./data/scores.txt");
    if (!fin)
    {
        // File doesn't exist.
        system("mkdir data");
        ofstream fout("./data/scores.txt");
        fout.close();
    }
    fin.close();
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
    int num_of_wrong_guesses = 0, cur_score = 100;  // Initialize the current score to 100.
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
		if (letterFill(letter, unknown) == 0)
		{
			cout<<"Whoops! That letter isn't in there!"<<endl;
			num_of_wrong_guesses++;
            cur_score -= 10;    // If player gives a wrong guess deduct 10 pts.
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
			cout<<word<<endl;
			cout<<"Woohoo! You got it!"<<endl;
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout<<"\nSorry, you lose...you've been hanged."<<endl;
		cout<<"The word was : "<<word<<endl;
        cur_score -= 20;    // If player is unable to guess the country then deduct 20 more.
	}
    if (cur_score < 0)
        cur_score = 0;

    cout<<"You scored: "<<cur_score<<endl;
    cout<<endl;
    updateHighScores(cur_score);    // Update the scores in the file.
}

int GameManager::letterFill(char guess, string &guessword)
{
	int i;
	int matches = 0;
	int len = word.length();
	for (i = 0; i < len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == word[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

void GameManager::getPlayerName()
{
    cout<<"Please enter your name: ";
    cin>>player_name;
}

void GameManager::updateHighScores(int current_score)
{
    // Stores the top 10 high scores
    ifstream fin("./data/scores.txt");

    priority_queue<pair<int, string>> pq;
    string name;
    int score;
    fin>>name;
    while (!fin.eof())
    {
        fin>>score;
        pq.push({ score, name});
        fin>>name;
    }
    pq.push({ current_score, player_name });
    fin.close();

    ofstream fout("./data/scores.txt");
    for (int i = 0; !pq.empty() && i < 5; i++)
    {
        fout<<pq.top().second<<" "<<pq.top().first<<endl;
        pq.pop();
    }
    fout.close();
}

void GameManager::showHighScores()
{
    ifstream fin("data/scores.txt");
    system("cls");
    cout<<"\tTOP SCORERS"<<endl;

    string n;
    int score;
    fin>>n;
    int i = 1;
    while (!fin.eof())
    {
        fin>>score;
        cout<<i<<". "<<n<<"   "<<score<<endl;
        fin>>n;
        i++;
    }
    if (i == 1)
    {
        cout<<"No entries yet."<<endl;
        cout<<"Be the first one to get your name listed."<<endl;
        cout<<"Hurry up!"<<endl;
    }

    cout<<"---------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Press any key to continue."<<endl;
    cin.ignore();
    cin.get();
}