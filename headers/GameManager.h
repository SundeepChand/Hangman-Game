#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class GameManager
{
    private:
        const int MAX_TRIES;
        int num_of_wrong_guesses, n;
        string name;
        char letter;
        string word;
        string words[10];
        string unknown;

    public:
        void showMenu();
        void startGame();
        int letterFill (char, string, string&);

    public:
        GameManager();
};

#endif