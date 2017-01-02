#pragma once

// Standart plane
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
void draw_airplane_defensive(char ** matrix, int x, int y) {
	draw_airplane(matrix, x, y);

	matrix[x - 2][y] = '-';
	matrix[x - 2][y - 1] = '-';
	matrix[x - 2][y + 1] = '-';
	matrix[x - 2][y - 2] = '-';
	matrix[x - 2][y + 2] = '-';
}
void draw_airplane_defensive_up(char ** matrix, int x, int y) {
	draw_airplane_up(matrix, x, y);
	draw_airplane_defensive(matrix, x, y);

	matrix[x - 1][y - 2] = ' ';
	matrix[x - 1][y - 1] = ' ';
	matrix[x - 1][y + 1] = ' ';
	matrix[x - 1][y + 2] = ' ';
}
void draw_airplane_defensive_down(char ** matrix, int x, int y) {
	draw_airplane_down(matrix, x, y);
	draw_airplane_defensive(matrix, x, y);

	matrix[x - 3][y - 2] = ' ';
	matrix[x - 3][y - 1] = ' ';
	matrix[x - 3][y] = ' ';
	matrix[x - 3][y + 1] = ' ';
	matrix[x - 3][y + 2] = ' ';
}
void draw_airplane_defensive_left(char ** matrix, int x, int y) {
	draw_airplane_left(matrix, x, y);
	draw_airplane_defensive(matrix, x, y);

	matrix[x - 2][y + 3] = ' ';
}
void draw_airplane_defensive_right(char ** matrix, int x, int y) {
	draw_airplane_right(matrix, x, y);
	draw_airplane_defensive(matrix, x, y);

	matrix[x - 2][y - 3] = ' ';
}
void draw_airplane_power2(char ** matrix, int x, int y) {
	matrix[x - 1][y - 1] = 1;
	matrix[x - 1][y + 1] = 1;
}
void draw_airplane_power3(char ** matrix, int x, int y) {
	draw_airplane_power2(matrix, x, y);
	matrix[x][y - 2] = 1;
	matrix[x][y + 2] = 1;
}
void draw_airplane_offensive(char ** matrix, int x, int y, int power) {
	draw_airplane(matrix, x, y);

	switch (power) {
	case 2: {
		draw_airplane_power2(matrix, x, y);
		break;
	}
	case 3: {
		draw_airplane_power3(matrix, x, y);
		break;
	}
	default:
		break;
	}
}

// IP plane

//--------------------------------------------------------------------------------

// ACSO plane

//--------------------------------------------------------------------------------

// SD plane

//--------------------------------------------------------------------------------

//LOGIC plane

//--------------------------------------------------------------------------------

