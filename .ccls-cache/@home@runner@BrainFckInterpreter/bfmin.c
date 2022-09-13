#include <stdio.h>
FILE *f;int t[30000];int p=0;
void s(int d){p+=d;if(p<0)p=29999;else if(p>29999)p=0;}
void m(int a){t[p]+=a;}
void o(){if(t[p]==-1)printf("EOF");else printf("%c",t[p]);}
void i(){char c[1];scanf("%s",c);t[p]=c[0];if('~'==c[0])t[p]=-1;}
void run(){
    int ls[1000],ld=-1,lb=-1;char c;
    while((c=getc(f))!=EOF){
        if(lb>=0){if('['==c)++lb;if(']'==c)--lb;continue;}
        switch(c){
            case'<':s(-1);break;
            case'>':s(1);break;
            case'+':m(1);break;
            case'-':m(-1);break;
            case'.':o();break;
            case',':i();break;
            case'[':if(t[p]){++ld;ls[ld]=ftell(f);}else lb=0;break;
            case']':if(t[p])fseek(f,ls[ld],0);else --ld;break;}}}
int main(int c,char *v[]){if(c < 1)return 1;f=fopen(v[1],"r");if(f==NULL)return 2;run();fclose(f);return 0;}