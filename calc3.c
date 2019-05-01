#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char pilha[50];
int s[50];
char post[50];
int p = -1;
int top = -1;
int rtop = -1;
int xtop=-1;

void xpush(int elem){
    s[++xtop]=elem;
}

int xpop(){
    return(s[xtop--]);
}

void push(char x){
    pilha[++top] = x;
}

char pop(){
    if(top == -1)
        return -1;
    else
     return pilha[top--];
}

int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

void input(){
    top = -1;
    int i = 0, flag = 1;
    char string[100], check;

    printf("Insira uma expressão para ser avaliada: ");
    scanf("%s", &string);

    while(string[i] != '\0'){
        if(string[i] == '(' || string[i] == '[' || string[i] == '{')
            push(string[i]);

        if(string[i] == ')'){
            if(check = pop() != '(')
                flag = 0; break;
        }

        if(string[i] == ']'){
            if(check = pop() != '['){
                flag = 0; break;
            }
        }

        if(string[i] == '}'){
            if(check = pop() != '{'){
                flag = 0; break;
            }
        }
        i++;
    }

    if(top != -1 || flag == 0){
        printf("Equação não balanceada");
        exit(0);
    }
}

void postfix(){
    p=-1;
    char exp[20];
    char *e, x;
    printf("Insira a expressão validada: ");
    scanf("%s",exp);
    printf("\nA expressão posfixa é: ");
    e = exp;

    while(*e != '\0'){
        if(isalnum(*e)){
            printf("%c",*e);
            post[++p]=*e;
        } else if(*e == '(')
            push(*e);
        else if(*e == ')'){
            while((x = pop()) != '('){
                printf("%c", x);
                post[++p]=x;
            }
        } else{
            while(priority(pilha[top]) >= priority(*e)){
                char a;
                a= pop();
                printf("%c",a);
                post[++p]=a;
            }
            push(*e);
        }
        e++;
    }

    while(top != -1){
        char b;
        b=pop();

        printf("%c",b);
        post[++p]=b;
    }

///////////evaluation//////////
    int i=0,op1,op2;
    char ch;

    while(i != (p+1)){
        ch=post[i];
        i++;

        if(isdigit(ch))
            xpush(ch-'0');
        else{
            op2=xpop();
            op1=xpop();

            switch(ch){
                case '+':xpush(op1+op2);break;
                case '-':xpush(op1-op2);break;
                case '*':xpush(op1*op2);break;
                case '/':xpush(op1/op2);break;
            }
        }
    }
    printf("\n\nResultado da expressão: %d\n",s[xtop]);
}

void main(){
    int choice;

    do{
        printf("\n\n----MENU----\n1.INFIXO - POSFIXO\n2.SAIR\n");
        printf("Escolha uma opção\n");
        scanf("%d",&choice);

        switch(choice){
            case 1 : 
                input();
                postfix();
                break;
            case 2 : printf("~~~~~ Obrigado ~~~~~\n");break;
            default: printf("ENTRADA INVALIDA !!!!\n");
        }
    }while(choice!=2);
}