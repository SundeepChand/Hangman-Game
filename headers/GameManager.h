#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>
using namespace std;

class GameManager
{
    private:
        const int MAX_TRIES;
        string word;
        string words[10];
        string player_name;

    private:
        int letterFill (char, string&);
        void updateHighScores(int current_score);

    public:
        GameManager();
        void getPlayerName();
        void showRules();
        void startGame();
        void showTitle();
        void showHighScores();
};

#endif