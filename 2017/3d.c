#include <ncurses.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define END 1.0E6

float typedef F;

typedef struct {
	F x;
	F y;
	F z;
} p_t;

WINDOW *w;

void transform(p_t *p,
	       F c_psi, F c_theta, F c_phi,
	       F s_psi, F s_theta, F s_phi,
	       F depth, F zoom)
{
	char buf[256];
	F xx, yy, zz, zd;
	F x = p->x * zoom;
	F y = p->y * zoom;
	F z = p->z * zoom;
	int i;

	F c_psi_c_theta = c_psi * c_theta;
	F s_psi_c_theta = s_psi * c_theta;

 	xx = (((c_psi_c_theta * c_phi) - (s_psi * s_phi)) * x) +
	      (((-c_psi_c_theta * s_phi) - (s_psi * c_phi)) * y) +
		((c_psi * s_theta) * z);

	yy = (((s_psi_c_theta * c_phi) + (c_psi * s_phi)) * x) +
	     (((-s_psi_c_theta * s_phi) + (c_psi * c_phi)) * y) +
	     ((s_psi * s_theta) * z);

	zz = ((-s_theta * c_phi) * x) +
	     ((s_theta * s_phi) * y) +
	     (c_theta * z);

	zd = zz + depth;
	xx = xx * depth / zd;
	yy = yy * depth / zd;

	xx = xx + (COLS / 4);
	yy = yy + (LINES / 2);

	i = (10+zz/3);
	if (i < 0)
		i = 0;
	if (i > 11)
		i = 11;

	mvwprintw(w, (int)yy, (int)xx *2, "%c", "@#£O%**o+~,.."[i]);

}

#define P(p, xx, yy, zz)\
{			\
	p->x = xx;	\
	p->y = yy;	\
	p->z = zz;	\
	p++;		\
}

void make_cube(p_t *p)
{
	int i;

	for (i= -10; i <= 10; i++) {
		P(p, i, 10, 10);
		P(p, i, -10, 10);
		P(p, i, 10, -10);
		P(p, i, -10, -10);
		P(p, 10, i, 10);
		P(p, -10, i, 10);
		P(p, 10, i, -10);
		P(p, -10, i, -10);
		P(p, 10, 10, i);
		P(p, -10, 10, i);
		P(p, 10, -10, i);
		P(p, -10, -10, i);
	}
	P(p, END, END, END);
}

void make_snow(p_t *p)
{
	int i;

	for (i = 0; i < 2000; i++) {
		F x, y, z;

redo:
		x = -100.0 + (random() % 2000) / 10;
		y = -100.0 + (random() % 2000) / 10;
		z = -100.0 + (random() % 2000) / 10;
		if (((x * x) + (y * y) + (z * z)) > 10000)
			goto redo;
		P(p, x, y, z);
	}
	P(p, END, END, END);
}

void make_globe(p_t *p)
{
	F i;

	for (i = 0.0; i < 2 * M_PI; i += 0.1) {
		F x, y;
		x = 10 * sin(i);
		y = 10 * cos(i);

		P(p, x, y, 0);
		P(p, 0, x, y);
		P(p, y, 0, x);
	}
	P(p, END, END, END);
}

void make_star(p_t *p)
{
	int i;
	F o = 6;
	for (i = -10; i <= 10; i++) {
		P(p, i, - o, 0);
		P(p, (- i + 10)/2,  -o + ((i+10) * sqrt(3)/2) , 0);
		P(p, (i - 10)/2, -o + ((i+10) * sqrt(3)/2), 0);

		P(p, i, + o, 0);
		P(p, (- i + 10)/2,  +o + ((-i-10) * sqrt(3)/2) , 0);
		P(p, (i - 10)/2, +o + ((-i-10) * sqrt(3)/2), 0);

	}
	P(p, END, END, END);
}

void make_tree(p_t *p)
{
	int o = -10;
	int i, j;

	P(p, 0, o++, 0);
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 3; j++) {
			P(p, 0 - i - j, o, 0);
			P(p, 0 + i + j, o, 0);
			P(p, 0, o, 0 - i - j);
			P(p, 0, o, 0 + i + j);
			o++;
		}
	}
	for (i = -7; i <= 7; i++) {
		P(p, i, o, 0);
		P(p, 0, o, i);
	}
	for (i = -10; i < o + 7; i++)
		P(p, 0, i, 0);

	P(p, END, END, END);
}

void make_flake(p_t *p)
{
	F i, k = 0.866;

	for (i = 0.0; i < 12.0; i += 1.0) {
		P(p, 0, i, 0);
		P(p, 0, -i, 0);
		P(p, k * i, i / 2.0, 0);
		P(p, -0.866 * i, -i / 2.0, 0);
		P(p, 0.866 * i, -i / 2.0, 0);
		P(p, -0.866 * i, i / 2.0, 0);
	}
	for (i = 0.0; i < 4.0; i += 1.0) {
		P(p, (0.866 * i), - 5.0 - i, 0);
		P(p, -(0.866 * i), - 5.0 - i, 0);
		P(p, (0.866 * i), 5.0 + i, 0);
		P(p, -(0.866 * i), 5.0 + i, 0);

		P(p, (0.866 * 5) + (i / 2.0), 2.5 + (0.866 * i), 0);
		P(p, (0.866 * 5) + (i / 2.0), - 2.5 - (0.866 * i), 0);
		P(p, -(0.866 * 5) - (i / 2.0), 2.5 + (0.866 * i), 0);
		P(p, -(0.866 * 5) - (i / 2.0), - 2.5 - (0.866 * i), 0);

		P(p, (0.866 * 5) + i, 2.5, 0);
		P(p, (0.866 * 5) + i, -2.5, 0);
		P(p, -(0.866 * 5) - i, 2.5, 0);
		P(p, -(0.866 * 5) - i, -2.5, 0);
	}
	P(p, END, END, END);
}

int main()
{
	F psi = 0.0, theta = 0.0, phi = 0.0;
	F ax = 0.0, bx = 0.0, cz = 2.0;

	F x, y, z;
	F depth = 200;
	F zoom, dz = 0.003;
	p_t cube[7][5000];
	int c;

	initscr();
        cbreak();
        noecho();
        nodelay(stdscr, 1);
        keypad(stdscr, 1);
        curs_set(0);

	w = newwin(LINES, COLS, 0, 0);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	wattrset(w, COLOR_PAIR(0) | A_BOLD);

	make_cube(cube[0]);
	make_star(cube[1]);
	make_snow(cube[2]);
	make_globe(cube[3]);
	make_tree(cube[4]);
	make_flake(cube[5]);

	c = 0;
	zoom = 0.0;
	for (;;) {
		p_t *p;
		F i;

		wclear(w);
		psi += M_PI / 210;
		theta += M_PI / 500;
		phi += M_PI / 750;

		F c_psi = cos(psi);
		F c_theta = cos(theta);
		F c_phi = cos(phi);
		F s_psi = sin(psi);
		F s_theta = sin(theta);
		F s_phi = sin(phi);

		for (p = cube[c]; p->x < END; p++)
			transform(p, c_psi, c_theta, c_phi, s_psi, s_theta, s_phi, depth, zoom);

		zoom += dz;
		if (zoom > 1.8)
			dz = -0.02;
		if (zoom <= 0.0) {
			dz = 0.003;
			c = (c + 1) % 6;
			zoom = 0.0;
		}

		wrefresh(w);
		refresh();
		usleep(10000);

	}

	wrefresh(w);
	delwin(w);
	refresh();
        clear();
        endwin();
	return 0;
}
