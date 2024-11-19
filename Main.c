#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "expressao.c"

//constantes do tipo string
#define STR1 "Por favor, Introduza a operacao usando notacao polonesa (pos-fixada):"
#define MAX 100


int main(void){
    setlocale(LC_ALL, "Portuguese");
    struct pilha P1;
    inicializaPilha(&P1);

    char str[MAX];
    printf("\n %s", STR1);
    gets(str);

    int dimStr, i, n1, n2, ff, operando;
    dimStr=dimensaoStr(str);

    for(i=0; i<dimStr; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            operando = str[i] - '0'; //convertendo char para int
            push(&P1, operando);
        }
        else if(str[i] == '*'){
            n1 = pop(&P1);
            n2 = pop(&P1);
            push(&P1, (n1*n2));
            }
        else if(str[i] == '+'){
            n1 = pop(&P1);
            n2 = pop(&P1);
            push(&P1, (n1+n2));
            }
        else if(str[i] == '-'){
            n1 = pop(&P1);
            n2 = pop(&P1);
            push(&P1, (n1-n2));
        }
        else if(str[i] == '/'){
            n1 = pop(&P1);
            n2 = pop(&P1);
            push(&P1, (n1/n2));
        }
    } //For que percorre a String

    ff = pop(&P1);
    printf("\n\n O resultado da operacao: %d", ff);
}
