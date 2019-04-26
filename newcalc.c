#include <stdio.h>
#include <string.h>
#include <ctype.h> //https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
#include <stdlib.h>

struct Pilha{
    int topo;
    unsigned capacidade;
    int *array;
}Pilha;

struct Pilha* criaPilha(unsigned capacidade){
    struct Pilha* pilha = (struct Pilha*) malloc(sizeof(struct Pilha));

    if(!pilha)
        return NULL;

    pilha->topo = -1;
    pilha->capacidade = capacidade;
    pilha->array = (int*) malloc(pilha->capacidade * sizeof(int));

    if(!pilha->array)
        return NULL;

    return pilha;
}

int vazio(struct Pilha* pilha){
    return pilha->topo == -1;
}

char verificar(struct Pilha* pilha){
    return pilha->array[pilha->topo];
}

char pop(struct Pilha* pilha){
    if(!vazio(pilha))
        return pilha->array[pilha->topo--];

    return '$';
}

void push(struct Pilha* pilha, char operacao){
    pilha->array[++pilha->topo] = operacao;
}

int precedencia(char symbol){
    if(symbol == '*' || symbol == '/'){
        return(2);
    } else if(symbol == '+' || symbol == '-'){
        return(1);
    } else{
        return(0);
    }
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	    return 0;
	}
}

/*Função para passar as entradas expInixas para posfixas*/
char posfixa(struct Pilha *expPos, char *expIn){
    struct Pilha* pilha = criaPilha(strlen(expPos));
    char *posf;
    int i;
    int j;

    expPos = strlen(expIn);
    posf = malloc(expPos+1 * sizeof(char));

    push(pilha, expIn[0]); /*para impilhar (*/

    for(j=0, i=1; expIn[i] != '\0'; ++i){
        switch(expIn[i]){
            char pl;

            case '(': push(pilha, expIn[i]);
                    break;

            case ')': pop(pilha);
                    while(pl != '('){
                        posf[j++] = pl;
                        pl = pop(pilha);
                    } break;

            case '+':
            case '-': pl = pop(pilha);
                    while(pl != '('){
                        posf[j++] = pl;
                        pl = pop(pilha);
                    } push(pilha, pl);
                    push(pilha, expIn[i]);
                    break;

            case '*':
            case '/': pl = pop(pilha);
                    while(pl != '(' && pl != '+' && pl != '-'){
                        posf[j++] = pl;
                        pl = pop (pilha);
                    } push(pilha, pl);
                    push(pilha, expIn[i]);
                    break;

            default: posf[j++] = expIn[i];
        }

    }

    posf[j] = '\0';
    return posf;
}

int avaliacao(char * expPos){
    struct Pilha* pilha = criaPilha(strlen(expPos));
    int i;

    if(!pilha) return -1;

    for(i = 0; expPos[i]; ++i){
        if(isdigit(expPos[i]))
            push(pilha, expPos[i] - '0');
        else{
            int valor1 = pop(pilha);
            int valor2 = pop(pilha);

            switch(expPos[i]){
                case '+':
                    push(pilha, valor2+valor1);
                    break;
                case '-':
                    push(pilha, valor2-valor1);
                    break;
                case '*':
                    push(pilha, valor2*valor1);
                    break;
                case '/':
                    push(pilha, valor2/valor1);
                    break;
            }
        }
    }

    return pop(pilha);
}

int main(){
    char expPos[30];
    char expIn[30];
    printf("Insira a expressão: \n");
    scanf("%s", &expIn);
    posfixa(expIn, expPos);
    printf("postfix evaluation: %d", avaliacao(expPos));
    return 0;
}