#include <stdio.h>
#define CSLEFT  '<'
#define CSRIGHT '>'
#define CINC    '+'
#define CDEC    '-'
#define CLBEGIN '['
#define CLEND   ']'
#define CPRINT  '.'
#define CINPUT  ','

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
    if (tape[cc] == -1){
        printf("EOF");
    }
    else{
        printf("%c", tape[cc]);
    }
}

void input(){
    char c;
    scanf("%c", &c);
    tape[cc] = c;
    if ('~' == c){
        tape[cc] = -1;
    }
}

void run(){
    int loop_stack[1000];
    int loop_depth = -1;
    int i = 0;
    int looking_for_bracket = -1;
    char c;    
    while ((c = getc(fptr)) != EOF){
        if (looking_for_bracket >= 0){
            if (c == CLBEGIN){
                ++looking_for_bracket;
            }
            if (c == CLEND){
                --looking_for_bracket;
            }
            continue;
        }
        switch(c){
            case CSLEFT:
                shift(-1);
                break;
            case CSRIGHT:
                shift(1);
                break;
            case CINC:
                mod(1);
                break;
            case CDEC:
                mod(-1);
                break;
            case CLBEGIN:
                if (tape[cc]){
                    ++loop_depth;
                    loop_stack[loop_depth] = ftell(fptr);                                                     
                }
                else{
                    looking_for_bracket = 0;
                }
                break;
            case CLEND:
                if (tape[cc]){
                    fseek(fptr, loop_stack[loop_depth], 0);
                }
                else{
                    --loop_depth;
                }
            break;
            case CPRINT:
                print();
                break;
            case CINPUT:
                input();
                break;
        }
        ++i;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 1) return 1;
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) return 2;
    run();
    fclose(fptr);
    return 0;
}