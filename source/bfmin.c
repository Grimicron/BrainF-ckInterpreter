#include <stdio.h>
FILE *f;int t[30000];int p=0,l[1000],ld=-1,lb=0;char c;
void s(int d){if(!lb){p+=d;if(p<0)p=29999;else if(p>29999)p=0;}}void sl(){s(-1);};void sr(){s(1);};
void m(int a){if(!lb)t[p]+=a;}void mp(){m(1);};void mm(){m(-1);};
void o(){if(!lb)if(t[p]>=0&&t[p]<128)putchar(t[p]);}
void i(){if(!lb){t[p]=getchar();getchar();}}
void b(){if(!lb){if(t[p]){++ld;l[ld]=ftell(f);}else ++lb;}else ++lb;}
void e(){if(!lb){if(t[p])fseek(f,l[ld],0);else --ld;}else --lb;}
void(*lu[])()={&mp,&i,&mm,&o,0,0,0,0,0,0,0,0,0,0,0,0,0,&sl,0,&sr,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,&b,0,&e};
int main(int w,char **v){if(!w)return 1;f=fopen(v[1],"r");if(!f)return 2;while((c=getc(f))+1){if((c-=43)>-1&&c<51&&lu[c])lu[c]();}return fclose(f);};