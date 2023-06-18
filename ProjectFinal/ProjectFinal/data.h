#pragma once

struct Score {
    char name[4];
    int score;
};

void WriteScoresToFile();
void ReadScoresFromFile();
void DisplayScores();
void AddNewScore(char* playerName, int score);