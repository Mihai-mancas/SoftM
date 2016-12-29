#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<ctime>

#pragma warning(disable:4996)

int main() {
	int n, m; scanf("%d %d", &n, &m);
	char ** matrix = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++) {
		matrix[i] = (char *)malloc(sizeof(char) * m);
		for (int j = 0; j < m; j++)
			matrix[i][j] = 0;
	}
	system("cls");
	int poz_x = n / 2;
	int poz_y = m / 2;

	int ** enemy = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++) {
		enemy[i] = (int *)malloc(sizeof(int *) * n);
		for (int j = 0; j < m; j++)
			enemy[i][j] = 0;
	}


	while (_kbhit) {
		char l = getch();
		
		if (l == 's') {
			matrix[poz_x][poz_y] = 0;
			poz_x += 1;
			matrix[poz_x][poz_y] = 1;
		}
		if (l == 'w') {
			matrix[poz_x][poz_y] = 0;
			poz_x -= 1;
			matrix[poz_x][poz_y] = 1;
		}
		if (l == 'd') {
			matrix[poz_x][poz_y] = 0;
			poz_y += 1;
			matrix[poz_x][poz_y] = 1;
		}
		if (l == 'a') {
			matrix[poz_x][poz_y] = 0;
			poz_y -= 1;
			matrix[poz_x][poz_y] = 1;
		}
		system("cls");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				printf("%d ", matrix[i][j]);
			printf("\n");
		}

		Sleep(20);
	}
	return 0;
}