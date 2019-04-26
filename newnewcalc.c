#include <stdio.h>
#include <string.h>
#include <ctype.h> //https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
#include <stdlib.h>

struct Pilha{
    int topo;
    unsigned capacidade;
    int *array;
};

int empilhar(struct Pilha*, int);

int main(){
    struct Pilha *pilha;
    int j, o, p, q;
    scanf("%d %d %d %d", &j, &o, &q, &p);
    empilhar(pilha, j);
    empilhar(pilha, o);
    empilhar(pilha, q);
    empilhar(pilha, p);

    for(int i = 0; i <= pilha->topo; i++){
        printf("%d", pilha[i]);
    }
    return 0;
}

int empilhar(struct Pilha *pilha, int j){
    pilha->array[pilha->topo--];
    sizeof(pilha);
}