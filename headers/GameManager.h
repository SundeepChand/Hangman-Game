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
        string name;
        string word;
        string words[10];

    private:
        int letterFill (char, string, string&);

    public:
        GameManager();
        void showRules();
        void startGame();
        void showTitle();
};

#endif