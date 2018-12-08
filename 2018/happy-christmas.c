#include <unistd.h>
#define  Y typedef
unsigned char Y C;unsigned Y short S;Y unsigned int I;struct{C val;S L:4 __\
attribute__((packed));S B:12 __attribute__((packed));}typedef D;void O(void*
o,C*P,int n){C*Q=o;while(n--)*Q++=*P++;}I main(void){C H[78],N[1<<15],W[1<<
16],R[4096],*P=R,*E,_;I i,j,k,n,b,r;D X[256];C*g=W;read(0,R,0x4a7);while(1){
int l;C in[5];I G=0;n=read(0,in,1);if(n<1)break;if(in[0]<16)continue;if(in[0]
!=122){read(0,1+in,4);for(l=4;l>=0;l--){I v=in[l]==0176?'/':in[l];G=(G*'U')+
(v-33);}}*((I*)g)=G;g+=sizeof(I);}E=g+j;g=W;_=*(g++);O(&X,g,_*sizeof(D));g+=
_*sizeof(D);O(&H,g,sizeof(H)),g+=sizeof(H);O(R,g,E-g);E=R+(E-g);j=k=b=0;whi\
le(P<E){I Q=-1,T=255;S K=0;C*tmp=P;for(i=0;i<16;i++){I bp=b+i;I F=*(P+(bp/8)
)&(1<<(bp&7));K<<=1;K|=(F?1:0);}for(i=0;i<_;i++){unsigned long x;D*d=&X[i];S
B=d->B<<4;if(d->L<T){S q=16-d->L;S m=((1UL<<T)-1)<<q;if((K&m)==B){Q=i;T=d->L;
}}}N[j]=X[Q].val;b+=T;k+=T;if(b>7){P+=b/8;b&=7;}j++;}r=write(1,H,sizeof H);
for(i=0;i<j*2;i+=2){C W[2];I v,s,z,n;v=N[i>>1];s=(v>>7)&1;z=(v>>4)&7;n=128+
((1<<z)*(s?-1:1));n&=0xff;W[0]=n;s=(v>>3&1);z=(v>>0)&7;n=128+((1<<z)*(s?-1:1
));n&=0xff;W[1]=n;z=write(1,W,2);};}/*(C)Colin Ian King-Happy Christmas2018
LLF]^cN!g!__!$Me>JX@"Y\s#asVR#Y4GF'qu'V&C-nq"%LNX*g$Fh(nmq8#k_Rj?7\&D+HcKs"
P=a-&d>Pb,`%n-9I5"T'qs9S.Bq^FCPZQ>@7U(91$)@u"Gi>^1bj<+3;5[#X`"UB~6^#\5gtnTl
&cCM'p"$l6!iqX#Qd7'AC3u><6p`B4")uO@#NZPJ""I_#u&f;~uu(*Mor8`#7lcb@m-(XON(.a#
ia3k@%t%"QuuJF#tp!F0_gc#SF,6.Xj!8I~%A"1U.XY%mm9!WAKinHWQn)-#5C@R#B'\[YfH$UC
9is[@B:SR\6SEe#L!cEB^M.k]QV5&~GhcsW*$r$bI94g#ASR!3ik94eVg!&9[:h<WZ'3Bhig_i>
$EDPA3\C:me@i!DhK-S7;P;$!edB^<YVYDFQQ!!!#-<<!+H=$!+H=$!*lOQ#[\ACF29:$!N4W:J
$0N:J%6W:J$9iUJ$9iUJ$6W:J&<iUJ%?rUJP`,+sk>B.s^TT(H5^S8shX~cneig2Qa9STZMiX=]
Tle)J%HfS4R!$c:*1#$Uk%!8dOP@1jrYTCBNqr8OL?NCI0$3Y$Z2FmQZ10.L!30ZMe^9.r+IUj8
HO)h!VdNrSHcRL@316DdIY~t=\WFC;=UCR654>8U$l<<m-LXhR9ndaGa@2E+)Ys(T>U$-;9ka@G
%4D\>2CF;Z&k@nU[UPV.IfgY[5Qd1:5^`F8>4\13i~->8[ffaGGN>d:C0]B;ot,-Ac@3W.1XU<J
%GJLe>_Cm!+fjjO<?c%PrRYIMm*kQ>@u;VXmcnN6'"Sa6`F8T#S8M-V9)"\B>I\~9l+FY"Wf^QM
A=4bMk5ls(sYtl5#sf"]o`JFV!;s\_Rnp_$d@XR#R*4B[hJ`o&#Im1`g~4=,;7,DMhdm$d>,cWQ
hdE<4.?uWbKb+g"dHEK"HO4F9O3DuN^KH>`K0fe=g%kRH(?>S~)Y@\REUl"N$<_ldT?P>$TsZI1
(`KpLPbHb)G-?~!QNrF+EhiB[ht%@V#nSYf?Fce`=Vf728W"E)S~8R>A~EIeXuB^6G6F0WLtVLK
6*U~B]SsE~a7KOVqgJ_A0:l#Y##lA[CD'gb9#@D*XpVF9PLT``VY~1]!GTaR?aM*'*bN_Xe'?]N
Z+Q,j2qlr8(s%h(R?=)L"B.V&\"Ns6Q~p`ONA5ohl1eMcnN$bc5]gB\J^=0sU~4=oXtgi;ujQqp
Y9YP5mHg8OTfG8sCJQJ,J9.c$2-gi$#JYT(KSs~H2W1.suie~))kl9,I&lBC3OC.NtD^m%$0F21
#7%tF:fkWKm$qif_kn=J',hXRBE`J1)_QsicTMrio?Yri.a.m5#O*r+?`@%P\~9`f5&[""0!@7e
~&Obm2%ZjXR^3^65kg)C*3oBd\;b(YuUE+;GTb,e=.5FCUQ3skc8Z6:FLn-;%qu_r6E\8$RsWj%
1V5>@L8-#-hu3e*<'G\<(G!eg78)PGIu*cn-G\WP!I-GPA:H.YkLqC"`P_lkb8#;"-iV^X79LeA
2X"E)A4QKCUetL@G']eJ15L'[?A40;UM`$)j9?6Qe._3'~7BA[>fCgAAnQ=lNWbcMPoRpZ@3!>d
+MLEpi1F:)!"EX#X443V%G<Z_llOBDRe"VkD"II[IqY-Loh1H+AUW2beh'M6NM<Pc(*`npo\;~4
!3F<6s,W8s!-W8s!-W8sS8V8s!-W8sKQf,JU.*9+UQF%SqPAQ5au(#Y?epKEg#emM8As%G"b&)O
3=u6ml%2pji@4B."8[M=,i~="sjdll(6\1p`R:@)4KZH"kYL\`Wo^3Z`tp&.Wf`(39UpUPfB*Q&
KQE`~n*U*=a%hAef)H?]3_tE"5M~h_'X\QgC9X(bZ&+??&Qg#>>EW5I$F#mFpg$h(elYbUZJ\lE
5Me_d?eBi8,tA:"AHli'=VaV#RL:rc$G81!VZ"Z6"OU&6JRte^=@NT+bpAoe(64B[(b(<=>3m0&
%8WVO23G=,),qXLR`hs,IGe0W*]S"6tmTYb~WGLQ4:o3ejr)Q_H.!Pf%6R~?\-F@'c+^DVL@HbW
=TERGLk'?3hBMs0'G@g(^\3F!TKF&M1[\k"jrrXYg6SI98E3B$K&eq6p[;Hn9hWS,L)@#=O6hW`
K:=0a+(eHJoDP>$lfd62:*-Z$'oI36m[)%,a<\KU5?e-RZI4$<:D)[JHl+G$sM=5?=jl4CW=lWO
FuM7&rql`jl3%\a=G?#7hj1X4^KoS-pH"RZEAnh1$*emcLd35CDMYKU]uHk1FigF=O_CYnEX%k$
YG:o&H*#,a(k7nT&]t,P=@>"3c(XjL?l52_:LHA_!2W^n@eK>"47M>%!q1&bBdtJH(icCild3YP
(@+?="D=F&EN+A%Vi>"b^V(\hTIA&ip#3u40.LL))%(L$&`)TV~dDE&-abM%TroWMMZK$%2rojZ
'>tVZ:Z-PMXc.Q(2FZ'p#e7Va8+LYMIYi~Jmd^AN]hA-,)!(*#:.\9(?#ds,afNU:743K:2BKN!
1'no_-0)IcXRMTrZC"a%%;Hb&@]'@dXnlsM87:W!*r$aP`LN@RdBd(:'fNW3~la`=`!tIajElmT
5":`b3'DV1"~\8jZ~]8jb=3$jH9;ic!-W8s7nEuIJ(KJ'2k[#9JWU8s?^]Tns+(qiDS3$jW7r~]
*,p+sZFW"e=G4o5\!j?OAVC>+!Fj.&foc^~)X"E)pPm0>1i3FQiOd3A&0fKC(8ueL2t.m50X5bN
u_m,_G_DGN@+jmY1HZj(TQE]N]"~9=f1.BdHm*9]`StpenjR`5iSK~~j_!3%uY=Z_X)963~*I-j
eQN<!.<g4eh>QeO5lOo$15<mYth&EPCg!:,>ccJC#<[T$An8=b@=g3C=JZ]&0`4J_'PQte[CA7g
CdM!f*XLY"p%U1>5*GS#k6nj9h;%tA%b`h!5%!3%&~D)6'uMfj[NP`T>cf3-%~0d#@[6;Eg*Qt(
)@iZEFkE62aKVHJ>\`t?BV9%=_('m2?~I>XXG"?.E\".DPM5BRqYAmPqV6)7kL!q$WJOB<G7'4V
E_#G(kR[QMd<ZM@5=-93c:Cf!:-FNNj(@f<RS)T)58TJ0SQSu?^qPH~3h%;&X8@93qeM~~Li<8-
s%I[_r0n[>I+&Eo_brAe=ob12%~2)^)@mB+"ung(?AAj$\$Bm5+nY'T"*3,Y)'3[0<I)AHD0_3K
.S7dK$a0m5Qk'G+_&eTGEQ%k~*1o]6cZ;'#cQoNLRb.fWO\<cl4(pL*r8t_eqtmVoXBu&5?~3:E
%.+\2hNP*72T=%UFU8~L1.HZP1"1q7rCZ4;AUfrUWheFWLNd:#[?(.]Q$e[SR<cKWJcek&=)E<A
!+D(`7#9%9%pI#,MF09OLoC!o;(n^3^&j]R[~c!IkRDg!-_+Hd#q0i=G%]Jrm[<5al=UlUEsu6r
_Y-m^q`sOS~@n^I8rp6cfg8gRl)'i6n*Aa*:m!uqZ9`mqlE(5\U+&'GaSuR\JOF':&hnFkDu1Tf
"t!.7Ce,rAe<#,o1*juL?42]TSWJe3A(sP%9lj$Q^!+<6$~9c;\%[SP?-;V^$irgS)YjepB;uT'
9XXLSrE:S.,odip8Ruljetr(>@KXU]P~I*1^kPb^%n~@r_E";l-k5eMe"Y*M>e&UgZi:*)Dhr-M
S*jDp_ZnnLOB[$0BR4l8*Lj1l:m=,5cm4\I]V*;UgQA3S[Ut_P0qlNaa,n9U%4EcRVk-HRDbkSr
634`WbHq8*hN2.a)(r4c"=6XErUs%Ln#nSU7!!!!*/
