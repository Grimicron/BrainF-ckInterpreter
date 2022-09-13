#include <stdio.h>
#define CSLEFT  <
#define CSRIGHT >
#define CINC    +
#define CDEC    -
#define CLBEGIN [
#define CLEND   ]
#define CPRINT  .
#define CINPUT  ,

FILE *fptr;
int tape[30000];
int cc = 0;

void shift(int d){
    cc += d;
    if (cc < 0) cc = 29999;
    else if (cc > 29999) cc = 0;
}

void mod(int a){
    tape[cc] += a;
}

void print(){
    printf("%c", tape[cc]);
}

void input(){
    char c;
    scanf("%c", &c);
    tape[cc] = c;
}

int main(int argc, char** argv) {
    if (argc < 1){
        printf("Please enter BrainF*ck file name as an argument.");
        return 1;
    }
    fptr = fopen(argv[0], "r");
    if (!fptr){
        printf("Invalid file name.");
        return 1;
    }
    for(int i = 0; i < 30000; i++){
        tape[i] = 0;
    }
    return 0;
}