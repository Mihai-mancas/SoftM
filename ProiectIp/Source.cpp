#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<ctime>

#include "draw_airplanes.h"
#include "menu.h"

#pragma warning(disable:4996)

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
	for (int i = 2; i < lines - 5; i++) {
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


int main() {
	int n, m; scanf("%d %d", &n, &m);
	char ** matrix = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++) {
		matrix[i] = (char *)malloc(sizeof(char) * m);
		for (int j = 0; j < m; j++)
			matrix[i][j] = ' ';
	}
	system("cls");
	int poz_x = n / 2;
	int poz_y = m / 2;
	int level_airplane = 1;
	int index_airplane = -1;

	index_airplane = menu(3, matrix, poz_x, poz_y, n, m);
	index_airplane;
	drawstart321(matrix);
	// implement somekind of menu or ... i don't know
	clear_airplane(matrix, poz_x, poz_y);
	clear_airplane_ip(matrix, poz_x, poz_y);
	clear_airplane_acso(matrix, poz_x, poz_y);
	switch (index_airplane) {
	case 0: {
		draw_airplane(matrix, poz_x, poz_y);
		break;
	}
	case 1: {
		draw_airplane_ip(matrix, poz_x, poz_y);
		break;
	}
	case 2: {
		draw_airplane_acso(matrix, poz_x, poz_y);
		break;
	}
	default:
		break;
	}
	while (true) {
		char l = ' ';
		if(_kbhit())
			l = getch();
		// implement the powerup

		//int x = rand() % n;
		//matrix[0][x] = 2;

		enemyflowandfireflow(matrix, n, m);
		
		if (GetAsyncKeyState(VK_DOWN)) {
			matrix[poz_x][poz_y] = 0;
			if(poz_x <= n - 5)
				poz_x += 1;
			switch (index_airplane) {
			case 0: {
				draw_airplane_down(matrix, poz_x, poz_y);
				break;
			}
			case 1: {
				draw_airplane_ip_down(matrix, poz_x, poz_y);
				break;
			}
			case 2: {
				draw_airplane_acso_down(matrix, poz_x, poz_y);
				break;
			}
			default:
				break;
			}
		}
		if (GetAsyncKeyState(VK_UP)) {
			matrix[poz_x][poz_y] = 0;
			if(poz_x >= 3)
				poz_x -= 1;
			switch (index_airplane) {
			case 0: {
				draw_airplane_up(matrix, poz_x, poz_y);
				break;
			}
			case 1: {
				draw_airplane_ip_up(matrix, poz_x, poz_y);
				break;
			}
			case 2: {
				draw_airplane_acso_up(matrix, poz_x, poz_y);
				break;
			}
			default:
				break;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			matrix[poz_x][poz_y] = 0;
			
			// switch after the type of the plane and then after the level of the airplane
			switch (level_airplane) {
			case 1: {
				if (poz_y <= m - 3)
					poz_y++;
				break;
			}
			case 2: {
				if (poz_y <= m - 4)
					poz_y++;
				break;
			}
			case 3: {
				if (poz_y <= m - 5)
					poz_y++;
				break;
			}
			default:
				break;
			}

			switch (index_airplane) {
			case 0: {
				draw_airplane_right(matrix, poz_x, poz_y);
				break;
			}
			case 1: {
				draw_airplane_ip_right(matrix, poz_x, poz_y);
				break;
			}
			case 2: {
				draw_airplane_acso_right(matrix, poz_x, poz_y);
				break;
			}
			default:
				break;
			}
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			matrix[poz_x][poz_y] = 0;
			
			// switch after the type of the airplane and then after the level
			switch (level_airplane) {
			case 1: {
				if (poz_y >= 2)
					poz_y--;
				break;
			}
			case 2: {
				if (poz_y >= 3)
					poz_y--;
				break;
			}
			case 3: {
				if (poz_y >= 4)
					poz_y--;
				break;
			}
			default:
				break;
			}
			switch (index_airplane) {
			case 0: {
				draw_airplane_left(matrix, poz_x, poz_y);
				break;
			}
			case 1: {
				draw_airplane_ip_left(matrix, poz_x, poz_y);
				break;
			}
			case 2: {
				draw_airplane_acso_left(matrix, poz_x, poz_y);
				break;
			}
			default:
				break;
			}
		}

		//matrix[poz_x][poz_y] = 1;
		//draw_airplane(matrix, poz_x, poz_y);

		colisionfirewithenemy(matrix, n, m);
		system("cls");
		if (colisionwitheairplane(matrix, poz_x, poz_y) == true) {
			printf("END GAME");
			break;
		}
		for (int i = 1; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (l == 'a') {
					matrix[i][j] = 0;
					printf("%c", matrix[i][j]);
				}
				else
					printf("%c", matrix[i][j]);
			}
			printf("\n");
		}
		if (l == 'q')
			break;
		if (l == 'f') {
			
			// switch after the type of the airplane and then after the level
			switch (level_airplane) {
			case 1: {
				matrix[poz_x - 2][poz_y] = '*';
				break;
			}
			case 2: {
				matrix[poz_x - 2][poz_y] = '*';
				matrix[poz_x + 1][poz_y - 2] = '*';
				matrix[poz_x + 1][poz_y + 2] = '*';
				break;
			}
			case 3: {
				matrix[poz_x - 2][poz_y] = '*';
				matrix[poz_x + 1][poz_y - 2] = '*';
				matrix[poz_x + 1][poz_y + 2] = '*';
				matrix[poz_x - 1][poz_y - 3] = '*';
				matrix[poz_x - 1][poz_y + 3] = '*';
				break;
			}
			default:
				break;
			}
		}
			
		Sleep(20);
	}
	
	return 0;
}