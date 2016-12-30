#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<ctime>

#pragma warning(disable:4996)
void enemyflow(char ** matrix, int lines, int columns) {
	for(int i = lines - 1; i >= 1; i--)
		for(int j = columns - 1; j >= 0; j--)
			if (matrix[i - 1][j] == 2) {
				matrix[i][j] = 2;
				matrix[i - 1][j] = 0;
			}
}
void draw_airplane(char ** matrix, int x, int y) {
	matrix[x - 1][y] = 1;
	matrix[x][y] = 1;
	matrix[x + 1][y] = 1;
	matrix[x + 2][y] = 1;
	matrix[x][y - 1] = 1;
	matrix[x][y + 1] = 1;
	matrix[x + 2][y - 1] = 1;
	matrix[x + 2][y + 1] = 1;
}
void draw_airplane_left(char ** matrix, int x, int y) {
	draw_airplane(matrix, x, y);

	matrix[x - 1][y + 1] = ' ';
	matrix[x][y + 2] = ' ';
	matrix[x + 1][y + 1] = ' ';
	matrix[x + 2][y + 2] = ' ';

}
void draw_airplane_right(char ** matrix, int x, int y) {
	draw_airplane(matrix, x, y);

	matrix[x - 1][y - 1] = ' ';
	matrix[x][y - 2] = ' ';
	matrix[x + 1][y - 1] = ' ';
	matrix[x + 2][y - 2] = ' ';

}
void draw_airplane_up(char ** matrix, int x, int y) {
	draw_airplane(matrix, x, y);

	matrix[x + 1][y - 1] = ' ';
	matrix[x + 1][y + 1] = ' ';
	matrix[x + 3][y - 1] = ' ';
	matrix[x + 3][y] = ' ';
	matrix[x + 3][y + 1] = ' ';
}
void draw_airplane_down(char ** matrix, int x, int y) {
	draw_airplane(matrix, x, y);

	matrix[x - 2][y] = ' ';
	matrix[x - 1][y - 1] = ' ';
	matrix[x - 1][y + 1] = ' ';
	matrix[x + 1][y - 1] = ' ';
	matrix[x + 1][y + 1] = ' ';
}
void shootflow(char ** matrix, int lines, int columns) {

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
	draw_airplane(matrix, poz_x, poz_y);
	while (1) {
		char l = ' ';
		if(_kbhit())
			l = getch();
		//int x = rand() % n;
		//matrix[0][x] = 2;

		enemyflow(matrix, n, m);
		
		if (GetAsyncKeyState(VK_DOWN)) {
			matrix[poz_x][poz_y] = 0;
			if(poz_x <= n - 5)
				poz_x += 1;
			//matrix[poz_x][poz_y] = 1;
			draw_airplane_down(matrix, poz_x, poz_y);
			
		}
		if (GetAsyncKeyState(VK_UP)) {
			matrix[poz_x][poz_y] = 0;
			if(poz_x >= 2)
				poz_x -= 1;
			//matrix[poz_x][poz_y] = 1;
			draw_airplane_up(matrix, poz_x, poz_y);
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			matrix[poz_x][poz_y] = 0;
			if(poz_y <= m - 3)
				poz_y += 1;
			//matrix[poz_x][poz_y] = 1;
			draw_airplane_right(matrix, poz_x, poz_y);
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			matrix[poz_x][poz_y] = 0;
			if(poz_y >= 2)
				poz_y -= 1;
			//matrix[poz_x][poz_y] = 1;
			draw_airplane_left(matrix, poz_x, poz_y);
		}
		if (l != 'a' && l != 's' && l != 'd' && l != 'w') {
			matrix[poz_x][poz_y] = 1;
		}
		system("cls");

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (l == 'a') {
					matrix[i][j] = 0;
					printf("%c ", matrix[i][j]);
				}
				else
					printf("%c ", matrix[i][j]);
			}
			printf("\n");
		}
		if (l == 'q')
			break;
		Sleep(20);
	}
	
	return 0;
}