#include<stdlib.h>
#include<stdio.h>

#pragma once

struct player {
	char name[30];
	int score;
};


void table_score(player last) {
	FILE *f = fopen("TextFile.txt", "rt");
	player * players = (player *)malloc(11 * sizeof(player));
	for (int i = 0; i < 10; i++) {
		fscanf(f, "%s%d", players[i].name, players[i].score);
	}
	for (int i = 0; i < 10; i++)
		printf("%s - %d\n", players[i].name, players[i].score);
	players[10] = last;

	// sort the array



	// print in the file the first ten names and scores

	FILE *fout = fopen("TextFile.txt", "w");
	for (int i = 0; i < 10; i++) {
		fprintf(fout, "%s %d", players[i].name, players[i].score);
	}
}

void print_score_board() {
	FILE *f = fopen("TextFile.txt", "r");
	char name[30]; int score;
	for (int i = 0; i < 10; i++) {
		fscanf(f, "%s %d", name, &score);
		printf("%d - %s = %d\n", i + 1, name, score);
	}
}