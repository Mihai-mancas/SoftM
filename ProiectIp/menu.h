#pragma once
#include"draw_airplanes.h"
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<ctime>

#pragma warning(disable:4996)

void clearscreen(int x, int y) {
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void ShowConsoleCursor() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorinfo;
	GetConsoleCursorInfo(out, &cursorinfo);
	cursorinfo.bVisible = 0;
	SetConsoleCursorInfo(out, &cursorinfo);
}

int menu(int nr_airplanes, char ** matrix, int x, int y, int lines, int columns) {
	int index = 0;
	draw_airplane(matrix, x, y);
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}
	while (true) {
		//system("cls");

		char select = ' ';
		if (_kbhit())
			select = getch();
		if (select == 's')
			return index;

		if (GetAsyncKeyState(VK_RIGHT)) {
			if (index < nr_airplanes - 1)
				index++;
			//system("cls");
			switch (index) {
			case 0: {
				clear_airplane(matrix, x, y);
				clear_airplane_ip(matrix, x, y);
				clear_airplane_acso(matrix, x, y);
				//system("cls");
				clearscreen(0, 0);
				//clear_airplane(matrix, x, y);
				draw_airplane(matrix, x, y);
				for (int i = 0; i < lines; i++) {
					for (int j = 0; j < columns; j++)
						printf("%c", matrix[i][j]);
					printf("\n");
				}
				break;
			}
			case 1: {
				clear_airplane(matrix, x, y);
				clear_airplane_ip(matrix, x, y);
				clear_airplane_acso(matrix, x, y);
				//system("cls");
				clearscreen(0, 0);
				//clear_airplane_ip(matrix, x, y);
				draw_airplane_ip(matrix, x, y);
				for (int i = 0; i < lines; i++) {
					for (int j = 0; j < columns; j++)
						printf("%c", matrix[i][j]);
					printf("\n");
				}
				break;
			}
			case 2: {
				clear_airplane(matrix, x, y);
				clear_airplane_ip(matrix, x, y);
				clear_airplane_acso(matrix, x, y);
				//system("cls");
				clearscreen(0, 0);
				//clear_airplane_acso(matrix, x, y);
				draw_airplane_acso(matrix, x, y);
				for (int i = 0; i < lines; i++) {
					for (int j = 0; j < columns; j++)
						printf("%c", matrix[i][j]);
					printf("\n");
				}
				break;
			}
			default:
				break;
			}
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			if (index > 0)
				index--;
			//system("cls");
			switch (index) {
			case 0: {
				clear_airplane(matrix, x, y);
				clear_airplane_ip(matrix, x, y);
				clear_airplane_acso(matrix, x, y);
				//system("cls");
				clearscreen(0, 0);
				//clear_airplane(matrix, x, y);
				draw_airplane(matrix, x, y);
				for (int i = 0; i < lines; i++) {
					for (int j = 0; j < columns; j++)
						printf("%c", matrix[i][j]);
					printf("\n");
				}
				break;
			}
			case 1: {
				clear_airplane(matrix, x, y);
				clear_airplane_ip(matrix, x, y);
				clear_airplane_acso(matrix, x, y);
				//system("cls");
				clearscreen(0, 0);
				//clear_airplane_ip(matrix, x, y);
				draw_airplane_ip(matrix, x, y);
				for (int i = 0; i < lines; i++) {
					for (int j = 0; j < columns; j++)
						printf("%c", matrix[i][j]);
					printf("\n");
				}
				break;
			}
			case 2: {
				clear_airplane(matrix, x, y);
				clear_airplane_ip(matrix, x, y);
				clear_airplane_acso(matrix, x, y);
				//system("cls");
				clearscreen(0, 0);
				//clear_airplane_acso(matrix, x, y);
				draw_airplane_acso(matrix, x, y);
				for (int i = 0; i < lines; i++) {
					for (int j = 0; j < columns; j++)
						printf("%c", matrix[i][j]);
					printf("\n");
				}
				break;
			}
			default:
				break;
			}
		}
		Sleep(500);
	}
	clear_airplane(matrix, x, y);
	clear_airplane_ip(matrix, x, y);
	clear_airplane_acso(matrix, x, y);
}