#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "data.h"

#define MAX_SCORES 10

struct Score scores[MAX_SCORES];

void WriteScoresToFile() {
    FILE* file = fopen("scores.txt", "w");
    if (file == NULL) {
        printf("WriteScoresToFile() ERROR\n");
        return;
    }

    for (int i = 0; i < MAX_SCORES; i++) {
        fprintf(file, "%s %d\n", scores[i].name, scores[i].score);
    }

    fclose(file);
}

void ReadScoresFromFile() {
    FILE* file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("ReadScoresFromFile() ERROR\n");
        return;
    }

    for (int i = 0; i < MAX_SCORES; i++) {
        fscanf(file, "%s %d\n", scores[i].name, &scores[i].score);
    }

    fclose(file);
}

void DisplayScores(int setScreenWidth, int setScreenHeight, void (*setCursorPos)(int, int)) {
    setCursorPos((setScreenWidth / 2) - 5, (setScreenHeight / 2) - 6);
    printf("[Top %d Scores]", MAX_SCORES);
    for (int i = 0; i < MAX_SCORES; i++) {
        setCursorPos((setScreenWidth / 2), (setScreenHeight / 2) - 4 + i);
        printf("%s: %d", scores[i].name, scores[i].score);
    }
}

void AddNewScore(char* playerName, int score) {
    int i = 0;

    // 점수를 넣을 위치 찾기
    for (; i < MAX_SCORES; i++) {
        if (score > scores[i].score) {
            break;
        }
    }

    // 점수가 상위 점수에 해당하지 않는 경우 return 때려버리기
    if (i == MAX_SCORES) {
        return;
    }

    // 모든 점수를 새 점수 아래로 이동
    for (int j = MAX_SCORES - 1; j > i; j--) {
        scores[j] = scores[j - 1];
    }

    // 새 점수 삽입
    strcpy(scores[i].name, playerName);
    scores[i].score = score;
}

