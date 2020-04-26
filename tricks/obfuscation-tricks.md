A primer on some C obfuscation tricks.

Typedef abuse:

#### 1) normal expected form:

``` C
typedef signed int my_int;
```

#### 2) abuse it by:

``` C
signed int typedef my_int;
int typedef signed my_int;
```

#### 3) or since int is default type, one can do:

``` C
typedef my_int;
```

Array abuse:

``` C
char x[];
int index;
```

`x[index]` is `*(x+index)`
`index[x]` is legal C and equivalent too

Literal string abuse, like above in principle

``` C
int index = 0;

printf("%c\n", index["MyString"]);
```

#### 4) Abuse unexpected results:

``` C
#include <stdio.h>

#define X (-2147483648)

int foo(void) { return -X; }
```

"-2147483648 is positive.  This is because 2147483648 cannot fit in the type int,
so (following the ISO C rules) its data type is unsigned long int. Negating this
value yields 2147483648 again."

#### 5) Surprising math:

``` C
int x = 0xfffe+0x0001;
```

looks like 2 hex constants, but in fact it is not.

#### 6) Abuse the pre-processor

``` C
#define  A case _COUNTER_: n = (__COUNTER__ - 1) & 0xfffff;break;
#define B A A A A A A A A A A A A A A A A
#define C B B B B B B B B B B B B B B B B
#define D C C C C C C C C C C C C C C C C
#define E D D D D D D D D D D D D D D D D
#define F E E E E E E E E E E E E E E E E
main(){ int n = 0; for (;;) switch(n) { F } }
```

#### 7) indirection on function pointers with comments.. 

<!-- The C highlighting of GitHub thinks this is an error, and
will paint a red background on it, so I replaced it with another
highlight which belongs to an even more cursed language. -->

``` JavaScript
(**/**/**/**/**/**/**write)(1, "Hello World\n", 12);
```

#### 8) Do confusing things:

``` C
unsigned char count = 1;

printf("%d %d\n", 0 == sizeof(count = 2, count++), count);
```

#### 9) Make it hard to be traced:

``` C
#include <unistd.h>
#include <sys/ptrace.h>
#include <signal.h>
#include <setjmp.h>

sigjmp_buf e;

void h(int sig) { siglongjmp(e, 1); }

int main(void)
{
        signal(SIGTRAP, h);
        if (sigsetjmp(e, 0) != 1)
                while (1)__asm__("int3");
        if (!ptrace(PTRACE_TRACEME, 0, 1, 0))
                write(1, "gdb or strace me\n", 17);
        return 0;
}
```

#### 10) insert URLs for fun:

``` C
int main(int argc, char *argv[])
{
        http://smackerelofopinion.blogspot.co.uk/search/label/C

        return 0;
}
```

#### 11) URL comments ;-)

Useful background reading:

[How To Write Unmaintainable Code](http://www.se.rit.edu/~tabeec/RIT_441/Resources_files/How%20To%20Write%20Unmaintainable%20Code.pdf)

#### 12) Fun with predefined values (yep, this compiles)

``` C
int main(){ return linux > unix; }
```

#### 13) Break code over lines. Makes it hard to grep

``` C
ret\
urn 0;
```

#### 14) Make macros with `(` `{` `;` imbalancing to make it more confusing

``` C
#define P	printf(
#define X	);}

main() {
	P("Hello Word" X
```

#### 15) Use gcc alternate digraphs for fun!


<!--
    Digraph:        <%  %>  <:  :>  %:  %:%:
    Punctuator:     {   }   [   ]   #    ##

    When will GitHub update
        https://github.github.com/gfm/#tables-extension-
    and support <thead>-less tables?
-->
<table><tr>
        <td>Digraph</td>
        <td><code><%</code></td>
        <td><code>%></code></td>
        <td><code><:</code></td>
        <td><code>:></code></td>
        <td><code>%:</code></td>
        <td><code>%:%:</code></td>
</tr><tr>
        <td>Punctuator</td>
        <td><code>{</code></td>
        <td><code>}</code></td>
        <td><code>[</code></td>
        <td><code>]</code></td>
        <td><code>#</code></td>
        <td><code>##</code></td>
</tr></table>

#### 16) Use macro definitions of numbers in roman numerals (and make them wrong to confuse the reader)

``` C
#define XII	(10+3)
```

#### 17) use offputting variable names, eg;

``` C
float Not, And, Or;
double Int8;
int _, __, o, O; Oo, Oo, OO, oo;
```

so you end up with code like:

``` C
while (!Not & And != (Or | 2))...
```

#### 18) Shove all variables into one array

don't have lots of ints; just have one array of ints and
reference these using:

`x[0]`, `1[x]`, `*(x+4)`, `*(8+x)`.. etc

#### 19) Use cpp pasting `##` and stringification for fun and laughs

#### 20) Abuse switch and while;

``` C
void sw(int s)
{
  switch (s) while (0) {
  case 0:
          printf("zero\n");
          continue;
  case 1:
          printf("one\n");
          continue;
  case 2:
          printf("two\n");
          continue;
  default:
          printf("something else\n");
          continue;
  }
}
```

#### 21) Use confusing coding idioms:

Replace:

``` C
if (c)   
    x = v;  
else  
    y = v;  
```

With:

``` C
*(c ? &x : &y) = v;
```

#### 22) don't use loops, abuse goto, setjmp, longjmp, recursion

make it confusing, don't make it obvious

#### 23) use smart algorithms

make it so smart that it is hard to figure out
what the code is really doing

#### 24) Abuse sizeof

``` C
int foo(const int i) 
{
        char x[i];

        return sizeof x;
}

int
main(void)
{
        printf("%d\n", foo(-1));
}
```

#### 25) A void function that returns void(!)

``` C
void a (void) { }
void b (void) { return a(); };
```

#### 26) Make it look different, format code into pictures

Example:

``` C
 #include <stdio.h>  
 #include <stdlib.h>  
 #define K continue  
 #define t /*|+$-*/9  
 #define _l /*+$*/25  
 #define s/*&|+*/0xD  
 #define _/*&|+*/0xC  
 #define _o/*|+$-*/2  
 #define _1/*|+$-*/3  
 #define _0/*|+$*/16  
 #define J/*&|*/case  
 char typedef signed   
  B;typedef H;H main(  
  ){B I['F'],V=0,E[]=  
   {s,0,s,31,t,1,s,111  
   ,_,t,-3,_,s,50,_l,-  
    1,t,1,s,0x48>>2,_l,  
    -2,_,_1,5,_o,s,0,_1  
     ,-8,s,0,s,-65,t,75,  
     s,100,_,t,8,_,_1,-5  
      ,s,82,t,32,s,111,s,  
      20,_l,-2,t,7,_,_1,5  
       ,_o,s,0,_1,-8,s,0,\  
      _0,};B*P=E;while(P)  
      {B L=*P,l=*(P+1),U=  
     I[V-1],A=(L>>2)&1,C  
     =(V-(1-A)),i;switch  
    (L)while(0){J _l:i=  
    l>0?U>>l:U<<-l;K;J\  
   t:i=U+l;K;J _:i=U;  
   K;J s:i=l;K;J _o:  
  putchar(U);K;J _1:  
  P+=U?0:l;K;J _0:e\  
 xit(0);}C[I]=(L&8)?  
 i:I[C];P+=(L&1)+1;V  
 +=A-((L&2)>>1);}re\  
 turn/*c.i.king*/0;}  
```

#### 27) Doing nothing

``` C
({_:&&_;});

({});

({;});

switch (0);
```

#### 28) abusing `__VA_ARGS__`

One can pass an entire function body into a macro using `__VA_ARGS__`

``` C
#define F(f, ...) f __VA_ARGS__

F(void foo(void) { printf("foo\n"); })
```

#### 29) Turn array to a pointer using `+`

``` C
foo(&array[0]);
```

instead use:

``` C
foo(+array);
```

#### 30)

``` C
int x = 1;

foo(&x);
```

use:

``` C
foo( (int[]){1} );
```

#### 30) Zero'ing

``` C
a ^= a;
a = '-'-'-';
```

#### 31) Variable names:

``` C
char broiled;
double burger;
short cake;
float icecream;
long story;
signed sincerely;
static electricity;
auto mechanic;
volatile substance;
register electorat;
unsigned autobiography;
void *gazing_back;
char witness;
const*able;
union dues {};
```

#### 32) Precendence rules abuse:

``` C
#include <stdio.h>
int main(void) { int array[] = {1, 2, 3}; int *p = &array[1]; printf("%d\n", -1[p]); }

-1[p] is -(*(1 + p)) and not *(-1 + p)
```

#### 33) Make simple expressions more complex

``` C
u8 val;

tricky				simple
if (val && ~val)		if (val)
	break;				break;
```

#### 34) Fun ways to increment:

``` C
i-=-1;
```

#### 35) Yes/No?

``` C
return (char *[]){"No", "Yes"}[!!x];
```
