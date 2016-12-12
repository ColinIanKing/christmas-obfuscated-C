#define _XOPEN_SOURCE_EXTENDED 1

/* (C) Colin Ian King 2016 */

#include <ncursesw/curses.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <signal.h>

#define BLACK_BLACK	0
#define WHITE_BLACK	1
#define BLACK_RED	2
#define PILEFACTOR	15

typedef struct {
	char t; /* type */
	int x;
	int y;
	int stop;
	int start;
} flake_info_t;

typedef struct {
	int x;
	int y;
} star_info_t;

flake_info_t *fi;
star_info_t *si;
char flakes[] = ".',^\"$%*#";
int  nflakes = 0;
struct winsize ws;
int  *pile;
int wx, wdx, wy;
int resized;

#define FLSZ (sizeof(flakes) - 1)
#define ST    8
#define MAX(a,b) ((a > b) ? (a) : (b))

static void get_ws(void)
{
	(void)ioctl(fileno(stdin), TIOCGWINSZ, &ws);
}

static int r(int max)
{
	srandom(getpid() * random());
	return random() % max;
}

static void wind(void)
{
	wx = r(60);
	wdx = r(2) == 1 ? -1 : 1;
	wy = r(ws.ws_row);
}

static void sigwinch(int dummy)
{
	(void)dummy;
	resized = 1;
}

static void new_flakes(void)
{
	int i;
	get_ws();
	nflakes = (ws.ws_row * ws.ws_col) / 7;
	free(pile);
	pile = (int *)calloc(ws.ws_col, sizeof(int));
	free(fi);
	fi =  (flake_info_t*)calloc(nflakes, sizeof(flake_info_t));
	for (i = 0; i < nflakes; i++) {
		fi[i].t = r(FLSZ);
		fi[i].x = r(ws.ws_col * FLSZ);
		fi[i].y = r(ws.ws_row * FLSZ);
	}
	free(si);
	si = (star_info_t*)calloc(nflakes / ST, sizeof(star_info_t));
	for (i = 0; i < nflakes / ST; i++) {
		si[i].x = r(ws.ws_col);
		si[i].y = r(ws.ws_row);
	}
	pile[0] = PILEFACTOR;
	for (i = 1; i < ws.ws_col; i++)
		pile[i] = pile[i-1] + r(5) - 2;
		if (pile[i] <= 0)
			pile[i] = 1;
}

int main(void)
{
	int stop, frames;
        initscr();
        start_color();
        cbreak();
        noecho();
        nodelay(stdscr, 1);
        curs_set(0);

	signal(SIGWINCH, sigwinch);
	setlocale(LC_ALL, "");
	init_pair(BLACK_BLACK, COLOR_BLACK, COLOR_BLACK);
	init_pair(WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(BLACK_RED, COLOR_RED, COLOR_BLACK);

restart:
	stop = frames = resized = 0;
	new_flakes();
	resizeterm(ws.ws_row, ws.ws_col);
	wind();

	do {
		int i,j,x,y;

		attron(COLOR_PAIR(0));
		for (y=0;y<ws.ws_row;y++)
			for (x=0;x<ws.ws_col;x++)
				mvaddch(y, x, ' ');

		attron(COLOR_PAIR(1));
		for (i=0;i<nflakes/ST;i++)
			mvaddch(si[i].y,si[i].x, "+-"[r(2)]);

		for (j=0; j < FLSZ; j++) {
			for (i=0;i<nflakes;i++) {
				if ((fi[i].t != j) || (fi[i].stop))
					continue;
				if (fi[i].start)
					mvaddch(fi[i].y / FLSZ,fi[i].x / FLSZ,flakes[fi[i].t]);
				if (!fi[i].stop) {
					fi[i].y += fi[i].t + 3;
					if (fi[i].y / FLSZ >= (ws.ws_row) - (pile[fi[i].x / FLSZ] / PILEFACTOR / 2)) {
						fi[i].y = 0;
						if (fi[i].start)
							pile[fi[i].x / FLSZ] += fi[i].t / 2;
						fi[i].start = 1;
						if (stop)
							fi[i].stop = 1;
						fi[i].x = r(ws.ws_col * FLSZ);
					}
					if (wx < 20)
						if (fi[i].y / FLSZ  > wy)
							fi[i].x += (wx * wdx);
					fi[i].x -= r(FLSZ) - (FLSZ / 2);
					if (fi[i].x < 0)
						fi[i].x = (ws.ws_col * FLSZ) - 1;
					if (fi[i].x >= (ws.ws_col * FLSZ))
						fi[i].x = 0;
				}
			}
		}
		wx--;
		if (wx <= 0)
			wind();
		attron(COLOR_PAIR(0) | A_BOLD);
		for (x=0;x<ws.ws_col;x++) {
			int yy, yp;
			if (x > 0 && pile[x] > pile[x-1] + 1) {
				pile[x-1] += 1;
				pile[x] -= 1;
			}
			if (x < ws.ws_col - 1 && pile[x] > pile[x+1] + 1) {
				pile[x+1] += 1;
				pile[x] -= 1;
			}
			yy = pile[x] / PILEFACTOR;
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
		if (frames > 100) {
			int y = (frames - 100)/3;
			y = y <  ws.ws_row / 2 ? y : ws.ws_row / 2;
			attron(COLOR_PAIR(2) | A_BOLD);
			mvprintw(y, (ws.ws_col - 16)/2, "Happy Christmas!");
		}
		refresh();
		if (resized)
			goto restart;
		usleep(90000);
		frames++;
		if (frames == 200)
			stop = 1;
	} while (frames < 500);
	clear();
	endwin();
	return 0;
}
