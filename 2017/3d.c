#include <ncurses.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#define P(a,b,c){p->x=a,p->y=b,p->z=c;p++;}
#define L 1E6
float typedef F;int typedef I;typedef struct{F x;F y;F z;}p_t;
WINDOW *w;void J(p_t*p,F cP,F cQ,F cR,F sP,F sQ,F sR,F A, F Z)
{F o,O,u,zd,x=p->x*Z,y=p->y*Z,z=p->z*Z,cP_cQ=cP*cQ,sP_cQ=sP*cQ
;I i;o=(((cP_cQ*cR)-(sP*sR))*x)+(((-cP_cQ*sR)-(sP*cR))*y)+((cP
*sQ)*z);O=(((sP_cQ*cR)+(cP*sR))*x)+(((-sP_cQ*sR)+(cP*cR))*y)+(
(sP*sQ)*z);u=((-sQ*cR)*x)+((sQ*sR)*y)+(cQ*z);zd=u+A;o=o*A/zd;O
=O*A/zd;o=o+(COLS/4);O=O+(LINES/2);i=10+u/3;if(i<0)i=0;if(i>11
)i=11;mvwprintw(w,(I)O,(I)o*2,"%c","@#£O%**o+~,.."[i]);}void \
G(p_t*p){I i;for(i=-10;i<11;i++){P(i,10,10);P(i,-10,10);P(i,10
,-10);P(i,-10,-10);P(10,i,10);P(-10,i,10);P(10,i,-10);P(-10,i,
-10);P(10,10,i);P(-10,10,i);P(10,-10,i);P(-10,-10,i);}P(L,L,L)
;}void S(p_t*p){I i;for(i=0;i<1500;i++){F x,y,z;j:x=-100+(ran\
dom()%2000)/10;y=-100+(random()%2000)/10;z=-100+(random()%200\
0)/10;if(((x*x)+(y*y)+(z*z))>10000)goto j;P(x,y,z);}P(L,L,L);}
void V(p_t*p){F i,x,y;for(i=0.;i<2*M_PI;i+=0.1){x=10*sin(i);y=
10*cos(i);P(x,y,0);P(0,x,y);P(y,0,x);}P(L,L,L);}void H(p_t*p){
I i;F o=6,E=sqrt(3)/2;for(i=-10;i<11;i++){P(i,-o,0);P((-i+10)/
2,-o+((i+10)*E),0);P((i-10)/2,-o+((i+10)*E),0);P(i,o,0);P((-i+
10)/2,o+((-i-10)*E),0);P((i-10)/2,o+((-i-10)*E),0);}P(L,L,L);}
void U(p_t*p){I o=-10,i,j;P(0,o++,0);for(i=0;i<6;i++){for(j=0;
j<3;j++){P(-i-j,o,0);P(i+j,o,0);P(0,o,-i-j);P(0,o,i+j);o++;}}\
for(i=-7;i<=7;i++){P(i,o,0);P(0,o,i);}for(i=-10;i<18;i++)P(0,i
,0);P(L, L, L);}void E(p_t*p){F i,k=0.866;for(i=0.;i<12.;i+=1.
){P(0,i,0);P(0,-i,0);P(k*i,i/2.,0);P(-k*i,-i/2.,0);P(k*i,-i/2.
,0);P(-k*i,i/2.,0);}for(i=0.;i<4.;i+=1.){F d=k*i,T=2.5;P(d,-5.
-i,0);P(-d,-5.-i,0);P(d,5.+i,0);P(-d,5.+i,0);P((k*5)+(i/2.),T+
d,0);P((k*5)+(i/2.),-T-d,0);P(-(k*5)-(i/2.),T+d,0);P(-(k*5)-(i
/2.),-T-d,0);P((k*5)+i,T,0);P((k*5)+i,-T,0);P(-(k*5)-i,T,0);P(
-(k*5)-i,-T,0);}P(L, L, L);}I main(){F k=0.,l=0.,m=0.,ax=0.,bx
=0.,cz=2.,x,y,z,A=200,Z,dz=0.003;p_t _[7][5000];I c;initscr();
cbreak();noecho();nodelay(stdscr,1);keypad(stdscr,1);curs_set(
0);w=newwin(LINES,COLS,0,0);init_pair(0,COLOR_WHITE,COLOR_BLA\
CK);wattrset(w,COLOR_PAIR(0)|A_BOLD);H(_[1]);U(_[4]);G(_[5]);\
V(_[3]);S(_[2]);E(_[0]);c=0;Z=0.;for(;;){p_t*p;F i,cP=cos(k),\
cQ=cos(l),cR=cos(m),sP=sin(k),sQ=sin(l),sR=sin(m);k+=M_PI/210;
l+=M_PI/500;m+=M_PI/750;wclear(w);for(p=_[c];p->x<L;p++)J(p,cP
,cQ,cR,sP,sQ,sR,A,Z);Z+=dz;if(Z>1.8)dz=-0.02;if(Z<=0.){dz=0.0\
03;c=(c+1)%6;Z=0.;}wrefresh(w);refresh();usleep(10000);}wrefr\
esh(w);delwin(w);refresh();clear();endwin();return 0;}//ciking
