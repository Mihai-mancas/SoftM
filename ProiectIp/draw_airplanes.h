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
void clear_airplane(char ** matrix, int x, int y) {
	matrix[x - 1][y] = ' ';
	matrix[x][y] = ' ';
	matrix[x + 1][y] = ' ';
	matrix[x + 2][y] = ' ';
	matrix[x][y - 1] = ' ';
	matrix[x][y + 1] = ' ';
	matrix[x + 2][y - 1] = ' ';
	matrix[x + 2][y + 1] = ' ';
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
	draw_airplane(matrix, x, y);
	matrix[x - 1][y - 2] = 1;
	matrix[x - 1][y + 2] = 1;
}
void draw_airplane_power2_up(char ** matrix, int x, int y) {
	draw_airplane_power2(matrix, x, y);

	matrix[x + 3][y - 1] = ' ';
	matrix[x + 3][y] = ' ';
	matrix[x + 3][y + 1] = ' ';

	matrix[x + 1][y - 1] = ' ';
	matrix[x + 1][y + 1] = ' ';

	matrix[x][y - 2] = ' ';
	matrix[x][y + 2] = ' ';
}
void draw_airplane_power2_down(char ** matrix, int x, int y) {
	draw_airplane_power2(matrix, x, y);

	matrix[x - 2][y] = ' ';
	matrix[x - 2][y - 2] = ' ';
	matrix[x - 2][y + 2] = ' ';

	matrix[x + 1][y - 1] = ' ';
	matrix[x + 1][y + 1] = ' ';
	matrix[x - 1][y - 1] = ' ';
	matrix[x - 1][y + 1] = ' ';
}
void draw_airplane_power2_left(char ** matrix, int x, int y) {
	draw_airplane_power2(matrix, x, y);

	matrix[x][y + 2] = ' ';
	matrix[x + 2][y + 2] = ' ';
	matrix[x - 1][y + 3] = ' ';
	matrix[x - 1][y + 1] = ' ';
	matrix[x + 1][y + 1] = ' ';
	matrix[x - 1][y - 1] = ' ';
}
void draw_airplane_power2_right(char ** matrix, int x, int y) {
	draw_airplane_power2(matrix, x, y);

	matrix[x][y - 2] = ' ';
	matrix[x + 2][y - 2] = ' ';
	matrix[x - 1][y - 3] = ' ';
	matrix[x - 1][y - 1] = ' ';
	matrix[x + 1][y - 1] = ' ';
	matrix[x - 1][y + 1] = ' ';
}

void draw_airplane_power3(char ** matrix, int x, int y) {
	draw_airplane_power2(matrix, x, y);
	matrix[x + 1][y - 3] = 1;
	matrix[x + 1][y + 3] = 1;
}
void clear_airplane_power3(char ** matrix, int x, int y) {
	matrix[x - 1][y - 2] = ' ';
	matrix[x - 1][y] = ' ';
	matrix[x - 1][y + 2] = ' ';
	matrix[x][y - 1] = ' ';
	matrix[x][y] = ' ';
	matrix[x][y + 1] = ' ';
	matrix[x + 1][y - 3] = ' ';
	matrix[x + 1][y] = ' ';
	matrix[x + 1][y + 3] = ' ';
	matrix[x + 2][y - 1] = ' ';
	matrix[x + 2][y] = ' ';
	matrix[x + 2][y + 1] = ' ';
}
void draw_airplane_power3_up(char ** matrix, int x, int y) {
	int xs = x + 1;
	clear_airplane_power3(matrix, xs, y);
	draw_airplane_power3(matrix, x, y);
}
void draw_airplane_power3_down(char ** matrix, int x, int y) {
	int xs = x - 1;
	clear_airplane_power3(matrix, xs, y);
	draw_airplane_power3(matrix, x, y);
}
void draw_airplane_power3_left(char ** matrix, int x, int y) {
	int ys = y + 1;
	clear_airplane_power3(matrix, x, ys);
	draw_airplane_power3(matrix, x, y);
}
void draw_airplane_power3_right(char ** matrix, int x, int y) {
	int ys = y - 1;
	clear_airplane_power3(matrix, x, ys);
	draw_airplane_power3(matrix, x, y);
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


void draw_airplane_ip(char ** matrix, int x, int y) {
	matrix[x - 1][y] = 1;
	matrix[x][y] = 1;
	matrix[x + 1][y - 1] = 1;
	matrix[x + 1][y] = 1;
	matrix[x + 1][y + 1] = 1;
	matrix[x + 2][y] = 1;
}
void draw_airplane_ip_up(char ** matrix, int x, int y) {
	draw_airplane_ip(matrix, x, y);

	matrix[x + 2][y - 1] = ' ';
	matrix[x + 3][y] = ' ';
	matrix[x + 2][y + 1] = ' ';
}
void draw_airplane_ip_down(char ** matrix, int x, int y) {
	draw_airplane_ip(matrix, x, y);

	matrix[x - 2][y] = ' ';
	matrix[x][y - 1] = ' ';
	matrix[x][y + 1] = ' ';
}
void draw_airplane_ip_left(char ** matrix, int x, int y) {
	draw_airplane_ip(matrix, x, y);

	matrix[x - 1][y + 1] = ' ';
	matrix[x][y + 2] = ' ';
	matrix[x + 1][y + 2] = ' ';
	matrix[x + 2][y + 1] = ' ';
}
void draw_airplane_ip_right(char ** matrix, int x, int y) {
	draw_airplane_ip(matrix, x, y);

	matrix[x - 1][y - 1] = ' ';
	matrix[x][y - 2] = ' ';
	matrix[x + 1][y - 2] = ' ';
	matrix[x + 2][y - 1] = ' ';
}
void clear_airplane_ip(char ** matrix, int x, int y) {
	matrix[x - 1][y] = ' ';
	matrix[x][y] = ' ';
	matrix[x + 1][y - 1] = ' ';
	matrix[x + 1][y] = ' ';
	matrix[x + 1][y + 1] = ' ';
	matrix[x + 2][y] = ' ';
}

//--------------------------------------------------------------------------------

// ACSO plane

void draw_airplane_acso(char ** matrix, int x, int y) {
	matrix[x - 1][y] = 1;
	matrix[x][y - 1] = 1;
	matrix[x][y + 1] = 1;
	matrix[x + 1][y - 1] = 1;
	matrix[x + 1][y + 1] = 1;
	matrix[x + 2][y - 1] = 1;
	matrix[x + 2][y] = 1;
	matrix[x + 2][y + 1] = 1;
}
void draw_airplane_acso_up(char ** matrix, int x, int y) {
	draw_airplane_acso(matrix, x, y);

	matrix[x + 3][y - 1] = ' ';
	matrix[x + 3][y] = ' ';
	matrix[x + 3][y + 1] = ' ';
	matrix[x][y] = ' ';
}
void draw_airplane_acso_down(char ** matrix, int x, int y) {
	draw_airplane_acso(matrix, x, y);

	matrix[x - 2][y] = ' ';
	matrix[x - 1][y - 1] = ' ';
	matrix[x - 1][y + 1] = ' ';
	matrix[x + 1][y] = ' ';
}
void draw_airplane_acso_left(char ** matrix, int x, int y) {
	draw_airplane_acso(matrix, x, y);

	matrix[x - 1][y + 1] = ' ';
	matrix[x][y + 2] = ' ';
	matrix[x + 1][y + 2] = ' ';
	matrix[x + 2][y + 2] = ' ';
	matrix[x][y] = ' ';
	matrix[x + 1][y] = ' ';

}
void draw_airplane_acso_right(char ** matrix, int x, int y) {
	draw_airplane_acso(matrix, x, y);

	matrix[x - 1][y - 1] = ' ';
	matrix[x][y - 2] = ' ';
	matrix[x + 1][y - 2] = ' ';
	matrix[x + 2][y - 2] = ' ';
	matrix[x][y] = ' ';
	matrix[x + 1][y] = ' ';
}
void clear_airplane_acso(char ** matrix, int x, int y) {
	matrix[x - 1][y] = ' ';
	matrix[x][y - 1] = ' ';
	matrix[x][y + 1] = ' ';
	matrix[x + 1][y - 1] = ' ';
	matrix[x + 1][y + 1] = ' ';
	matrix[x + 2][y - 1] = ' ';
	matrix[x + 2][y] = ' ';
	matrix[x + 2][y + 1] = ' ';
}
//--------------------------------------------------------------------------------

// SD plane



//--------------------------------------------------------------------------------

//LOGIC plane

//--------------------------------------------------------------------------------

