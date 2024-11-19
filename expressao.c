#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "expressao.h"

void inicializaPilha(struct pilha *P){
    P->topo = NULL;
}

short pilhaVazia (struct pilha *P){
    if(P->topo == NULL)
        return(1);
    return(0); 
}

void push (struct pilha *P, int elem){ //Insere elemento no topo da pilha
    struct no *novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->elem = elem;
    novoNo->prox = P->topo;
    P->topo = novoNo;
}

int pop (struct pilha *P){ //Remove o elemento do topo da pilha
    int x;
    struct no *ptr = P->topo;
    if(pilhaVazia(P)) //Pilha vazia
        return(0);
    x = ptr->elem;
    P->topo = ptr->prox;
    free(ptr);
    return(x); //Removeu com sucesso
}

int dimensaoStr(char *Str){
    return(strlen(Str));
}

//char caractere(char *Str, int pos){
    //int i;
    //i = *(Str + pos);
  //  return(*(Str + pos));
//}
