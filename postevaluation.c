#include <stdio.h>
#include <stdlib.h>

int main()
{

char operador, resposta;
float num1, num2, resultado;

resposta='S';

printf("######################\n");
printf("#CALCULADORA POLONESA# \n");
printf("######################\n\n");

/* Inicia a calculadora */
while (resposta=='S' || resposta=='s')
{
printf("Escvreva uma operacao:\n"); scanf("%f %f %c", &num1, &num2, &operador);

/* Verifica se os operadores são validos */
while(! num1 || ! num2 || ! operador)
{
printf("Operador invalido\n");
/* Limpa o buffer do teclado */
fflush(stdin);
printf("Escvreva uma operacao:\n"); scanf("%f %f %c", &num1, &num2, &operador);
}

/* Escolhe a operacao aritmetica */
switch (operador)
{
case '+': resultado=num1+num2;
break;
case '-': resultado=num1-num2;
break;
case '*': resultado=num1*num2;
break;
case '/': resultado=num1/num2;
break;
}
/* Escreve na tela o resultado */
// aqui você declaro como float  a varialvel e  uso %d 
printf("%.2f %c %2.f = %.2f\n", num1, operador, num2, resultado);
/* Pergunta se deseja continuar */
printf("Deseja continuar?(S/N)"); scanf(" %c", &resposta);
/* Limpa a tela e limpa o buffer do teclado */
system("cls"); fflush(stdin);

system("pause"); // faltou você pausa o sistema <====
}
}