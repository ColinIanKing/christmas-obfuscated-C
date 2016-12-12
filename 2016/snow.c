#define _XOPEN_SOURCE_EXTENDED 1

/* (C) Colin Ian King 2016 */

#include <ncursesw/curses.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <signal.h>
#include <string.h>

#define L	15

typedef struct {
	short I[5];
} F;

F *Q[2];
char o[] = ".',^\"$%*#";
struct winsize ws;
int *P;
int I[7];

#define l (sizeof(o) - 1)
#define a    8
#define u(a,b) (a > b ? a : b)

int r(int x)
{
	srandom(getpid() * random());
	return random() % x;
}

void E(void)
{
	I[0]=r(60);
	I[5]=r(2)==1?-1:1;
	4[I]=r(ws.ws_row);
}

void h(int _)
{
	3[I] = 1;
}

static void e(void)
{
	int i;
	ioctl(0, TIOCGWINSZ, &ws);
	I[1] = (ws.ws_row * ws.ws_col) / 7;
	free(P);
	P = (int *)calloc(ws.ws_col, sizeof(int));
	free(1[Q]);
	1[Q] =  (F*)calloc(I[1], sizeof(F));
	for (i = 0; i < I[1]; i++) {
		1[Q][i].I[0] = r(l);
		1[Q][i].I[1] = r(ws.ws_col * l);
		1[Q][i].I[2] = r(ws.ws_row * l);
	}
	free(Q[0]);
	Q[0] = (F*)calloc(I[1] / a, sizeof(F));
	for (i = 0; i < I[1] / a; i++) {
		Q[0][i].I[0] = r(ws.ws_col);
		Q[0][i].I[1] = r(ws.ws_row);
	}
	P[0] = L;
	for (i = 1; i < ws.ws_col; i++)
		P[i] = P[i-1] + r(5) - 2;
		if (P[i] <= 0)
			P[i] = 1;
}

int main(void)
{
        initscr();
        start_color();
        cbreak();
        noecho();
        nodelay(stdscr, 1);
        curs_set(0);

	signal(SIGWINCH, h);
	setlocale(LC_ALL, "");
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
_:
	memset(I,0,sizeof I);
	e();
	resizeterm(ws.ws_row, ws.ws_col);
	E();

	do {
		int i,j,x,y;

		attron(COLOR_PAIR(0));
		for (y=0;y<ws.ws_row;y++)
			for (x=0;x<ws.ws_col;x++)
				mvaddch(y, x, ' ');

		attron(COLOR_PAIR(1));
		for (i=0;i<I[1]/a;i++)
			mvaddch(Q[0][i].I[1],Q[0][i].I[0], "+-"[r(2)]);

		for (j=0; j < l; j++) {
			for (i=0;i<I[1];i++) {
				if ((1[Q][i].I[0] != j) || (1[Q][i].I[3]))
					continue;
				if (1[Q][i].I[4])
					mvaddch(1[Q][i].I[2] / l,1[Q][i].I[1] / l,o[1[Q][i].I[0]]);
				if (!1[Q][i].I[3]) {
					1[Q][i].I[2] += 1[Q][i].I[0] + 3;
					if (1[Q][i].I[2] / l >= (ws.ws_row) - (P[1[Q][i].I[1] / l] / L / 2)) {
						1[Q][i].I[2] = 0;
						if (1[Q][i].I[4])
							P[1[Q][i].I[1] / l] += 1[Q][i].I[0] / 2;
						1[Q][i].I[4] = 1;
						if (6[I])
							1[Q][i].I[3] = 1;
						1[Q][i].I[1] = r(ws.ws_col * l);
					}
					if (I[0] < 20)
						if (1[Q][i].I[2] / l  > 4[I])
							1[Q][i].I[1] += (I[0] * I[5]);
					1[Q][i].I[1] -= r(l) - (l / 2);
					if (1[Q][i].I[1] < 0)
						1[Q][i].I[1] = (ws.ws_col * l) - 1;
					if (1[Q][i].I[1] >= (ws.ws_col * l))
						1[Q][i].I[1] = 0;
				}
			}
		}
		I[0]--;
		if (I[0] <= 0)
			E();
		attron(COLOR_PAIR(0) | A_BOLD);
		for (x=0;x<ws.ws_col;x++) {
			int yy, yp;
			if (x > 0 && P[x] > P[x-1] + 1) {
				P[x-1] += 1;
				P[x] -= 1;
			}
			if (x < ws.ws_col - 1 && P[x] > P[x+1] + 1) {
				P[x+1] += 1;
				P[x] -= 1;
			}
			yy = P[x] / L;
			yp = 2 * ws.ws_row - 1;
			for (y=0; y < yy; y++, yp--) {
				cchar_t w;
				w.attr = COLOR_PAIR(1);
				w.chars[1] = 0;
				w.chars[0] = 0x2588;
				if ((y == yy - 1) && (!(y & 1)))
					w.chars[0] = 0x2584;
				mvadd_wch(yp / 2, x, &w);
			}
		}
		if (I[2] > 100) {
			int y = (I[2] - 100)/3;
			y = y <  ws.ws_row / 2 ? y : ws.ws_row / 2;
			attron(COLOR_PAIR(2) | A_BOLD);
			mvprintw(y, (ws.ws_col - 16)/2, "Happy Christmas!");
		}
		refresh();
		if (3[I])
			goto _;
		usleep(90000);
		I[2]++;
		if (I[2] == 200)
			I[6] = 1;
	} while (I[2] < 400);
	clear();
	endwin();
	return 0;
}
