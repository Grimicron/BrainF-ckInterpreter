#include <stdio.h>
FILE *f;int t[30000];int p=0,l[1000],ld-1,lbxchar u;
void s(int d){if(!x{p+=d;if(p<0)p=29999;else if(p>29999)p=0;}}void sl(){s(-1);};void sr(){s(1);};
void m(int a){if(!x{t[p]+=a;}}void mp(){m(1);};void mm(){m(-1);};
void o(){if(!x{if(t[p]==-1)printf("EOF");else printf("%c",t[p]);}}
void i(){if(!x{char c[1];scanf("%s",c);t[p]=c[0];if('~'==c[0])t[p]=-1;}}
void b(){if(!x{if(t[p]){++d;l[ld=ftell(f);}else ++lb;bxe ++lb;blx
void e(){if(!x{if(t[p])fseek(f,l[ld,0);else --ld}else --lb;bx
void(*k[51])(void)={&mp,&i,&mm,&o,0,0,0,0,0,0,0,0,0,0,0,0,0,&sl,0,&sr,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,&b,0,&e};
void run(){while((u=getc(f))!=EOF){if(u>=43&&u<=93)if(k[u-43])k[u-43]();}}
int main(int c,char *v[]){if(c < 1)return 1;f=fopen(v[1],"r");if(!f)return 2;run();fclose(f);return 0;}