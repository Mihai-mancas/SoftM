#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<ctime>
#include<stdlib.h>

#include "draw_airplanes.h"
#include "menu.h"
#include "score_table.h"


#pragma warning(disable:4996)

#define HEIGHT 55  // lines
#define WIDTH 75   // columns



void drawstart321(char ** matrix) {
	// somehow print to the screen the number 3 2 1 and then go on the matrix
	for (int i = 3; i >= 0; i--)
		if (i == 0) {
			printf("GO ... GO ... GO\n");
			Sleep(1000);
		}
		else {
			system("cls");
			printf("%d\n", i);
			Sleep(1000);
			system("cls");
		}
}

void enemyflowandfireflow(char ** matrix, int lines, int columns) {
	// enemy forwarding
	for(int i = lines - 1; i >= 1; i--)
		for (int j = columns - 1; j >= 0; j--) {
			if (matrix[i - 1][j] == 2) {
				matrix[i][j] = 2;
				matrix[i - 1][j] = 0;
			}
		}
	// fire forwarding
	for (int i = 0; i < lines - 2; i++) {
		for(int j = 0; j < columns - 1; j++)
			if (matrix[i][j] == '*' && i >= 1) {
				matrix[i - 1][j] = '*';
				matrix[i][j] = ' ';
			}
	}
}
void colisionfirewithenemy(char ** matrix, int lines, int columns) {
	for (int i = 1; i < lines - 5; i++) {
		for (int j = 0; j < columns - 1; j++) {
			if (matrix[i][j] == 2 && matrix[i + 1][j] == '*') {
				matrix[i][j] = ' ';
				matrix[i + 1][j] = ' ';
			}
		}
	}
}
bool colisionwitheairplane(char ** matrix, int x, int y) {
	if (matrix[x - 2][y] == 2 || matrix[x - 1][y - 1] == 2 || matrix[x - 1][y + 1] == 2)
		return true;
	return false;
}

void selectrightairplane(int index_airplane, int level_airplane, char ** matrix, int x, int y) {
	switch (index_airplane) {
	case 0: {
		switch (level_airplane) {
		case 0: {
			draw_airplane(matrix, x, y);
			break;
		}
		case 1: {
			draw_airplane_power2(matrix, x, y);
			break;
		}
		case 2: {
			draw_airplane_power3(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_ip(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 2: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_acso(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
void draw_right_airplane_up(int index_airplane, int level_airplane, char ** matrix, int x, int y) {
	switch (index_airplane) {
	case 0: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_up(matrix, x, y);
			break;
		}
		case 1: {
			draw_airplane_power2_up(matrix, x, y);
			break;
		}
		case 2: {
			draw_airplane_power3_up(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_ip_up(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 2: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_acso_up(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
void draw_right_airplane_down(int index_airplane, int level_airplane, char ** matrix, int x, int y) {
	switch (index_airplane) {
	case 0: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_down(matrix, x, y);
			break;
		}
		case 1: {
			draw_airplane_power2_down(matrix, x, y);
			break;
		}
		case 2: {
			draw_airplane_power3_down(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_ip_down(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 2: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_acso_down(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
void draw_right_airplane_right(int index_airplane, int level_airplane, char ** matrix, int x, int y) {
	switch (index_airplane) {
	case 0: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_right(matrix, x, y);
			break;
		}
		case 1: {
			draw_airplane_power2_right(matrix, x, y);
			break;
		}
		case 2: {
			draw_airplane_power3_right(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_ip_right(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 2: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_acso_right(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
void draw_right_airplane_left(int index_airplane, int level_airplane, char ** matrix, int x, int y) {
	switch (index_airplane) {
	case 0: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_left(matrix, x, y);
			break;
		}
		case 1: {
			draw_airplane_power2_left(matrix, x, y);
			break;
		}
		case 2: {
			draw_airplane_power3_left(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_ip_left(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 2: {
		switch (level_airplane) {
		case 0: {
			draw_airplane_acso_left(matrix, x, y);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
void draw_fire(int index_airplane, int level_airplane, char ** matrix, int x, int y) {
	switch (index_airplane) {
	case 0: {
		switch (level_airplane) {
		case 0: {
			matrix[x - 2][y] = '*';
			break;
		}
		case 1: {
			matrix[x - 2][y] = '*';
			matrix[x - 2][y - 2] = '*';
			matrix[x - 2][y + 2] = '*';
			break;
		}
		case 2: {
			matrix[x - 2][y] = '*';
			matrix[x - 2][y - 2] = '*';
			matrix[x - 2][y + 2] = '*';
			matrix[x][y - 3] = '*';
			matrix[x][y + 3] = '*';
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (level_airplane) {
		case 0: {
			matrix[x - 2][y] = '*';
			break;
		}
		default:
			break;
		}
		break;
	}
	case 2: {
		switch (level_airplane) {
		case 0: {
			matrix[x - 2][y] = '*';
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}


int main() {
	char nameplayer[30];
	printf("name  = "); scanf("%s", nameplayer);

	//int n, m; //scanf("%d %d", &n, &m);
	//n = HEIGHT; m = WIDTH;
	char ** matrix = (char **)malloc(sizeof(char *) * HEIGHT);
	for (int i = 0; i < HEIGHT; i++) {
		matrix[i] = (char *)malloc(sizeof(char) * WIDTH);
		for (int j = 0; j < WIDTH; j++)
			matrix[i][j] = ' ';
	}
	system("cls");
	int poz_x = HEIGHT / 2;
	int poz_y = WIDTH / 2;
	int level_airplane = 0;
	int index_airplane = -1;


	// menu

menu:
	printf("\n\n\n     1 - Play\n     2 - Instructions\n     3 - Score board\n     4 - Exit\n");
	printf("\n\n\n     Select a option\n");
	ShowConsoleCursor();
	char l = getch();
	
	switch (l) {
	case '1': {
		system("cls");
		goto start;
		break;
	}
	case '2': {
		system("cls");
		goto inst;
		break;
	}
	case '3': {
		system("cls");
		goto scoreb;
		break;
	}
	case '4': {
		system("cls");
		return 0;
		break;
	}
	default: {
		system("cls");
		goto menu;
		break;
	}
	}
	char letter;
scoreb:
	ShowConsoleCursor();
	print_score_board();
	printf("\nPress b for back ...");
	letter = getch();
	if (letter == 'b') {
		system("cls");
		goto menu;
	}
	//Sleep(5000);
inst:
	ShowConsoleCursor();
	printf("\n     f - fire\n     arrow key - move the airplane\n     a - kill all enemy\n");
	printf("\nPress b for back ...");
	letter = getch();
	if (letter == 'b') {
		system("cls");
		goto menu;
	}
	//Sleep(5000);


start:

	// end menu


	system("cls");
	index_airplane = menu(3, matrix, poz_x, poz_y, HEIGHT, WIDTH);
	
	drawstart321(matrix);

	// implement somekind of menu or ... i don't know


	clear_airplane(matrix, poz_x, poz_y);
	clear_airplane_ip(matrix, poz_x, poz_y);
	clear_airplane_acso(matrix, poz_x, poz_y);

	selectrightairplane(index_airplane, level_airplane, matrix, poz_x, poz_y);

	int first_power_up = rand() % 1000;
	first_power_up = 100;
	int time_power_up = 0;

	int distance = 0;
	bool enemyapp = true;



	while (true) {
		char l = ' ';
		if (_kbhit())
			l = getch();

		int px, py;
		if (enemyapp == true) {
			int x = rand() % HEIGHT;
			matrix[0][x] = 2;
			enemyapp = false;
		}
		else
			enemyapp = true;

		// level up
		if (distance == first_power_up) {
			px = rand() % WIDTH;
			py = rand() % HEIGHT;
			matrix[px][py] = 5;
			time_power_up = HEIGHT - 5;
		}
		if (distance > first_power_up && time_power_up == 0)
			first_power_up += rand() % first_power_up + 1000;
		time_power_up--;

		if (time_power_up > 0) {
			if (matrix[px + 1][py] == '*' && matrix[px][py] == 5) {
				matrix[px][py] = ' ';
				matrix[px + 1][py] = ' ';
				switch (index_airplane) {
				case 0: {
					if (level_airplane < 2)
						level_airplane++;
					break;
				}
				default:
					break;
				}
			}
		}

		enemyflowandfireflow(matrix, HEIGHT, WIDTH);

		if (GetAsyncKeyState(VK_DOWN)) {
			matrix[poz_x][poz_y] = 0;
			if (poz_x <= HEIGHT - 5)
				poz_x += 1;
			draw_right_airplane_down(index_airplane, level_airplane, matrix, poz_x, poz_y);
		}
		if (GetAsyncKeyState(VK_UP)) {
			matrix[poz_x][poz_y] = 0;
			if (poz_x >= 3)
				poz_x -= 1;
			draw_right_airplane_up(index_airplane, level_airplane, matrix, poz_x, poz_y);
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			matrix[poz_x][poz_y] = 0;

			// switch after the type of the plane and then after the level of the airplane
			switch (level_airplane) {
			case 0: {
				if (poz_y <= WIDTH - 3)
					poz_y++;
				break;
			}
			case 1: {
				if (poz_y <= WIDTH - 4)
					poz_y++;
				break;
			}
			case 2: {
				if (poz_y <= WIDTH - 5)
					poz_y++;
				break;
			}
			default:
				break;
			}
			draw_right_airplane_right(index_airplane, level_airplane, matrix, poz_x, poz_y);
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			matrix[poz_x][poz_y] = 0;

			// switch after the type of the airplane and then after the level
			switch (level_airplane) {
			case 0: {
				if (poz_y >= 2)
					poz_y--;
				break;
			}
			case 1: {
				if (poz_y >= 3)
					poz_y--;
				break;
			}
			case 2: {
				if (poz_y >= 4)
					poz_y--;
				break;
			}
			default:
				break;
			}
			draw_right_airplane_left(index_airplane, level_airplane, matrix, poz_x, poz_y);
		}

		colisionfirewithenemy(matrix, HEIGHT, WIDTH);

		clearscreen(0, 0);
		if (colisionwitheairplane(matrix, poz_x, poz_y) == true) {
			printf("END GAME");
			break;
		}
		if (l == 'f') {
			draw_fire(index_airplane, level_airplane, matrix, poz_x, poz_y);
		}

		

		for (int i = 1; i < HEIGHT - 1; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (l == 'a') {
					matrix[i][j] = 0;
					printf("%c", matrix[i][j]);
				}
				else {
					if (matrix[i][j] == 2) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
						printf("%c", matrix[i][j]);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
					}
					else
						if (matrix[i][j] == '*') {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
							printf("%c", matrix[i][j]);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
						}
						else
							printf("%c", matrix[i][j]);
					
				}
			}
			printf("\n");
		}
		if (l == 'q')
			break;
		distance++;
		printf("\n          Distance = %d\n          Level airplane = %d", distance, level_airplane);
		Sleep(10);
	}
	player last;
	strcpy(last.name, nameplayer);
	last.score = distance;

	table_score(last);

	return 0;
}