# Hangman Game in C++ using object oriented programming

In the game of Hangman, the computer chooses a word at random from a given list of words. This word is the answer. The player then tries to guess the word, by guessing one letter at a time. Whenever the user guesses a letter that is in the answer, all occurrences of that letter are revealed to the user. The game ends when the user has guessed every letter in the word, before he reaches the allowed number of strikes (usually 5). This program is an interactive Hangman game.

## Setup

Following are the instructions to compile & run the game.

1. Clone this repository into a directory using `git clone https://github.com/SundeepChand/Hangman-Game.git`.
2. Navigate to the directory using `cd Hangman-Game`
3. Compile the program using `g++ main.cpp .\src\GameManager.cpp -std=c++14 -o main`
4. Finally run by using `./main`
